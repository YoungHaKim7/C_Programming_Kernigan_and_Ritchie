# link

- [justfile(Metal-cpp version)](#justfilemetal-cpp-version-261120-)


<hr />

# `just cr` 성공과 `just r` 차이점 공부하기 좋다.
- Good news: this is the last piece of the metal-cpp puzzle, and the two recipes disagree for exactly one reason. Look at which symbols are missing: `NS::Private::Selector::s_kalloc`, `s_kinit`, `s_krelease`, `s_kUTF8String`, `NS::Private::Class::s_kNSAutoreleasePool`, `MTL::Private::Selector::s_kname`, and the body of `MTL::CreateSystemDefaultDevice()`. Those are **metal-cpp's private implementation symbols** — and per the metal-cpp README (we read it earlier in this thread):

> *To ensure that the selector and class symbols are linked, add to one of your cpp files:* `#define NS_PRIVATE_IMPLEMENTATION`, `#define MTL_PRIVATE_IMPLEMENTATION`

metal-cpp is header-only, but its inline definitions (the selector/class constants, the wrappers over `MTLCreateSystemDefaultDevice`) are guarded behind those macros. Declarations are always visible — that's why compiling works — but the *definitions* are only emitted in a TU that defines the macros before including. 

- **`just cr` works** because your CMake build compiles `src/implementation.cpp`, which carries the defines.
- **`just r` fails** because it compiles only `./src/main.cpp`, which doesn't have them → nothing ever emits those symbols.

# `just r`이 성공한 코드

- **Fix — add the defines at the top of `main.cpp`:**

```cpp
#define NS_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION

#include <Metal/Metal.hpp>

#include <cstdio>
#include <iostream>

int main() {
    NS::AutoreleasePool *pool = NS::AutoreleasePool::alloc()->init();

    MTL::Device *metalDevice = MTL::CreateSystemDefaultDevice();
    if (!metalDevice) {
        std::puts("no Metal device");
        return 1;
    }

    std::printf("GPU: %s\n", metalDevice->name()->utf8String());
    std::cout << "Hello, World from Metal-CPP!\n";

    metalDevice->release();
    pool->release();
    return 0;
}
```

Two rules to keep in mind:

1. **Exactly one TU defines them.** The moment you re-add `implementation.cpp` (like the a02 project had), the defines move there and must be *removed* from `main.cpp` — defining them in two TUs gives duplicate-symbol errors at link. If `implementation.cpp` is in your ver2 `CMakeLists.txt` and already has the defines, then `just cr` currently works *because* of it — and if you also put the defines in `main.cpp`, `just cr` will break with duplicates. Pick one home for the defines.
2. When you reach the GUI part and include `QuartzCore/QuartzCore.hpp` for `CA::MetalLayer`, that TU also needs `#define CA_PRIVATE_IMPLEMENTATION`.

If you'd rather keep the scalable layout, the alternative is the a02 pattern: a dedicated `src/implementation.cpp` holding only the defines + includes, and change the `r` recipe's compile line to `{{src_dir}}/*.cpp`. Either way, after this `just r` will print the same as `cr`: `GPU: Apple M4 Max` followed by the hello line.

<hr />

# Cmake 고치니 해결

The compile now succeeds — this is a new, different failure: **linking**. metal-cpp is a header-only C++ wrapper over Apple's Objective-C frameworks, so all those undefined `_MTL*` / `_NS*` / `_objc_*` symbols are framework symbols you never linked. Let me confirm the exact framework list from Apple's README:
Diagnosis confirmed. The compile errors from before are gone (you commented out the warning flags), and now you're at the **link stage**, which metal-cpp projects always hit: metal-cpp is a header-only C++ wrapper — it only *declares* the Apple frameworks. All those undefined symbols map cleanly to frameworks you never linked:

| Undefined symbols | Belong to |
|---|---|
| `_MTLCreateSystemDefaultDevice`, `_MTLCopyAllDevices`, `_MTLCommonCounter*`, `_MTL*Domain` | **Metal** framework |
| `_NSCocoaErrorDomain`, `_NSBundleDidLoadNotification`, `_NS*ErrorKey`, … | **Foundation** framework |
| `_objc_lookUpClass`, `_objc_getProtocol`, `_sel_registerName` | **libobjc** (re-exported by Foundation) |
| (none yet, but `CA::MetalLayer` when you do the GUI part) | **QuartzCore** framework |

That's also why the errors only point at `implementation.cpp.o`: that's the one TU where you defined `NS_PRIVATE_IMPLEMENTATION` / `MTL_PRIVATE_IMPLEMENTATION`, which instantiates all these extern-C symbols.

Here's the fixed CMakeLists.txt — it also restores your warning flags (safe now) and keeps the `SYSTEM` include fix from the previous error:

```cmake
cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES CXX)

# Force GCC 15(LinuxOS)
# set(CMAKE_CXX_COMPILER "/opt/gcc-15/bin/g++")
# Force Clang 20(LinuxOS)
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++-21")
# Force Clang 20(macOS)
# set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang")

# Common compile flags
# NOTE: -lm is a linker input, not a compiler flag -> removed (was the
#       "'linker' input unused" warning). -pedantic is redundant next to
#       -pedantic-errors. Safe to use -pedantic-errors because Apple's
#       headers are included as SYSTEM below (verified: suppression works
#       even under -pedantic-errors / -Werror).
add_compile_options(
    -pedantic-errors
    -pthread
    -Wall
    -Wextra
    -ggdb
)

# Main executable with C++ sources
add_executable(${ProjectId}
    src/main.cpp
    src/implementation.cpp
)

target_link_options(${ProjectId} PRIVATE -pthread -lm)

if(APPLE)
    find_library(METAL_FW      Metal      REQUIRED)
    find_library(FOUNDATION_FW Foundation REQUIRED)
    find_library(QUARTZCORE_FW QuartzCore REQUIRED)
    target_link_libraries(${ProjectId} PRIVATE
        ${METAL_FW} ${FOUNDATION_FW} ${QUARTZCORE_FW}
    )
endif()

# ---- Fetch metal-cpp into include/metal-cpp ----
include(FetchContent)

FetchContent_Declare(
    metal_cpp
    GIT_REPOSITORY https://github.com/apple/metal-cpp.git
    GIT_TAG        main
    SOURCE_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/include/metal-cpp"
)
FetchContent_MakeAvailable(metal_cpp)

# SYSTEM => all diagnostics originating inside Apple's headers (anonymous
# structs in MTLAccelerationStructureTypes.hpp etc.) are suppressed.
target_include_directories(${ProjectId} SYSTEM PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/metal-cpp"
)

# ---- Link the frameworks metal-cpp wraps (header-only wrapper, not a lib) ----
# Metal       -> MTLCreateSystemDefaultDevice, MTLCopyAllDevices, MTL*Domain...
# Foundation  -> NS*ErrorDomain, NS*Notification, objc_getProtocol/lookUpClass,
#                sel_registerName (libobjc is re-exported via Foundation)
# QuartzCore  -> CA::MetalLayer, needed as soon as you render into a view
# ---- Link the frameworks metal-cpp wraps ----
# SHELL: prefix prevents CMake from de-duplicating the repeated "-framework"
# token (which broke the link line: "-framework Metal Foundation QuartzCore").
if(APPLE)
    target_link_options(${ProjectId} PRIVATE
        "SHELL:-framework Metal"
        "SHELL:-framework Foundation"
        "SHELL:-framework QuartzCore"
    )
endif()

# Output directory
set_target_properties(${ProjectId} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
        "${CMAKE_BINARY_DIR}/$<LOWER_CASE:$<CONFIG>>"
)
```

Two small notes:

1. **Private implementation macros stay as-is** — `#define NS_PRIVATE_IMPLEMENTATION` / `#define MTL_PRIVATE_IMPLEMENTATION` (and `CA_PRIVATE_IMPLEMENTATION` if you include `QuartzCore/QuartzCore.hpp`) must appear in exactly one .cpp file before the includes, which your build already does. Don't put them in a header.

2. **Your `just fm` recipe is a footgun**: `fd -e hpp ... -x clang-format -i` will descend into `include/metal-cpp/` and rewrite Apple's headers in your `.clang-format` style (and `git`-wise dirty the clone). Add an exclusion: `fd -E include/metal-cpp -e c -e h -e cpp -e hpp ... -x clang-format -style=file -i {} \;`.

With the three `-framework` flags added, `just cr` should link cleanly. When you later add MetalFX (`MetalFX/MetalFX.hpp`), add `-framework MetalFX` the same way.

<hr />

# justfile(Metal-cpp version)(261120)[|🔝|](#link)

```justfile
# Detect OS
os := `uname`

# project name
project_name := `basename "$(pwd)"`
full_project_name := `pwd`

# clang & g++ basic & clang-format basic & cmake basic
clang := `which clang`
clangpp := `which clang++`
gpp := `which g++`
clang_format_basic := `which clang-format`
cmake := `which cmake`

# compiler settings
clang_which := if os == "Linux" { \
  "/usr/bin/clang++" \
  } else if os == "Darwin" { \
    "/opt/homebrew/opt/llvm/bin/clang++" \
  } else { \
    clang \
  }
clangpp_which := if os == "Linux" { \
    clangpp \
  } else if os == "Darwin" { \
    "/opt/homebrew/opt/llvm/bin/clang++" \
  } else { \
    clangpp \
  }
gpp_which := if os == "Linux" { \
    "/usr/bin/g++" \
  } else if os == "Darwin" { \
    "/opt/homebrew/opt/gcc@15/bin/g++-15" \
  } else { \
    gpp \
  }

# cmake settings(4.0)
cmake_which := if os == "Linux" { \
    cmake \
  } else if os == "Darwin" { \
    "/opt/homebrew/bin/cmake"
  } else { \
    cmake \
  }

# clang-format 21
clang_format := if os == "Linux" { \
    "clang-format" \
  } else if os == "Darwin" { \
    "/opt/homebrew/opt/llvm/bin/clang-format" \
  } else { \
    clang_format_basic \
  }

# fmt .clang-format(linuxOS / macOS)
fmt_flags := if os == "Linux" { \
    ". -regex '.*\\.\\(cpp\\|hpp\\|cc\\|cxx\\|ixx\\|cppm\\|c\\|h\\)' -exec " \
    +clang_format+ \
    " -style=file -i {} \\;" \
  } else if os == "Darwin" { \
    ". -iname '*.cpp' \
    -o -iname '*.hpp' \
    -o -iname '*.cc' \
    -o -iname '*.c' \
    -o -iname '*.cxx' \
    -o -iname '*.cppm' \
    -o -iname '*.ixx' \
    -o -iname '*.c' \
    -o -iname '*.h' | " \
    +clang_format+ \
    " -style=file -i --files=/dev/stdin" \
  } else { \
    ". -regex '.*\\.\\(cpp\\|hpp\\|cc\\|cxx\\|c\\|h\\)' -exec " \
    +clang_format+ \
    " -style=file -i {} \\;" \
  }

# fast fmt(LinuxOS / macOS)(Install "cargo install fd-find")
fm_flags := "-e c \
  -e h \
  -e cpp \
  -e hpp \
  -e cppm \
  -e ixx \
  -e cc \
  -e cxx -x " \
  +clang_format+  \
  " -style=file -i {} \\;"

# Source and target directories
src_dir := "./src"
target_dir := "./target"

# Files
source := src_dir+"/main.cpp"
target := target_dir+"/"+project_name

# Optimize (O2(RelWithDebInfo), O3(Release))
ldflags_optimize :=  "-std=c++2c -Wall -O2 -pedantic -pthread -pedantic-errors -lm -Wextra -ggdb"
ldflags_optimize03 :=  "-std=c++2b -Wall -O3 -pedantic -pthread -pedantic-errors -lm -Wextra -ggdb"
# Optimize LTO
ldflags_optimize_lto := "-flto"

# Common flags
ldflags_common := "-std=c++2c -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror"
ldflags_debug := "-std=c++2c -pthread -lm -Wall -Wextra -ggdb"
ldflags_emit_llvm := "-S -emit-llvm"
ldflags_assembly := "-Wall -save-temps"
ldflags_fsanitize_address := "-g -fsanitize=address -fno-omit-frame-pointer -c"
ldflags_fsanitize_object := "-g -fsanitize=address"
ldflags_fsanitize_thread := "-g -fsanitize=thread -fno-omit-frame-pointer -c"
ldflags_fsanitize_thread_object := "-g -fsanitize=thread"
ldflags_fsanitize_valgrind := "-fsanitize=address -g3"
ldflags_fsanitize_valgrind_O0 := "-O0 -g -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror"
ldflags_fsanitize_leak := "-fsanitize=leak -g"

# (C)gpp compile(LinuxOS)
r:
	just fm
	rm -rf {{target_dir}}
	mkdir -p {{target_dir}}
	{{gpp_which}} {{ldflags_common}} -o {{target_dir}}/{{project_name}} {{source}}
	{{target}}

# (C)clang compile(Optimization/LinuxOS/ macOS)
ro:
	rm -rf {{target_dir}}
	mkdir -p {{target_dir}}
	{{clang_which}} {{ldflags_optimize}} -o {{target_dir}}/{{project_name}} {{source}}
	{{target}}

# (C)g++ compile(Optimization03) / https://clang.llvm.org/docs/UsersManual.html
ro3:
	rm -rf target
	mkdir -p target
	g++ {{ldflags_optimize03}} -o {{target}} {{source}}
	{{target}}

# (C)g++ compile(Optimization03 + LTO) / https://clang.llvm.org/docs/UsersManual.html
rolto:
	rm -rf target
	mkdir -p target
	g++ {{ldflags_optimize_lto}} {{ldflags_optimize03}} -o {{target}} {{source}}
	{{target}}

# cmake compile debug(LinuxOS) — auto-creates include/ and lets FetchContent clone metal-cpp
cr:
    just fm
    rm -rf target
    mkdir -p target
    mkdir -p include
    @echo "==> include/ ready, CMake FetchContent will clone metal-cpp on first run"
    export CXX={{clangpp}}
    cmake -D CMAKE_BUILD_TYPE=Debug \
          -D CMAKE_CXX_COMPILER={{clangpp}} \
          -G Ninja .
    ninja
    mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake .ninja_deps .ninja_log target
    mv debug target
    ./target/debug/{{project_name}}

# cmake compile release O3(LinuxOS)
cr3:
	just fm
	rm -rf target
	mkdir -p target
	export CXX={{clangpp_which}}
	cmake -D CMAKE_BUILD_TYPE=Release \
	      -D CMAKE_CXX_FLAGS_RELEASE_INIT="-O3 -DNDEBUG" \
	      -D CMAKE_CXX_COMPILER={{clangpp_which}} \
	      -G Ninja .
	ninja
	mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake .ninja_deps .ninja_log target
	mv release target
	./target/release/{{project_name}}

# cmake compile release O2(LinuxOS)
cro:
	rm -rf target
	mkdir -p target
	cmake -D CMAKE_BUILD_TYPE=RelWithDebInfo \
	      -D CMAKE_CXX_COMPILER={{clangpp_which}} \
	      -D CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT="-O2 -g" \
	      -G Ninja .
	ninja
	mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake .ninja_deps .ninja_log target
	mv relwithdebinfo target
	./target/relwithdebinfo/{{project_name}}

# cmake compile release O3(LinuxOS)
cro3:
	rm -rf target
	mkdir -p target
	cmake -D CMAKE_BUILD_TYPE=Release \
	      -D CMAKE_CXX_COMPILER={{clangpp_which}} \
	      -D CMAKE_CXX_FLAGS_RELEASE_INIT="-O3 -DNDEBUG" \
	      -G Ninja .
	ninja
	mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake .ninja_deps .ninja_log target
	mv release target
	./target/release/{{project_name}}

# zig C compile(LinuxOS)
zr:
	rm -rf {{target_dir}}
	mkdir -p {{target_dir}}
	export CXX={{gpp_which}}
	zig c++ {{ldflags_common}} -o {{target}} {{source}}
	{{target}}

# cmake ctest
ctest:
	rm -rf target
	mkdir -p target
	cmake -D CMAKE_CXX_COMPILER={{gpp_which}} \
		  -S . -B target
	cmake --build target
	ctest --test-dir ./target

# clang build(target folder)
b:
	rm -rf {{target_dir}}
	mkdir -p {{target_dir}}
	{{clang_which}} {{ldflags_debug}} -o {{target}} {{source}}

# clangd .cache(c23 LSP build)
clangd:
	rm -rf build target .cache
	{{cmake_which}} -DCMAKE_BUILD_TYPE:STRING=Debug \
					-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
					-DCMAKE_C_COMPILER:FILEPATH={{clang_which}} \
					-DCMAKE_CXX_COMPILER:FILEPATH={{clangpp_which}} --no-warn-unused-cli \
					-S {{full_project_name}} \
					-B {{full_project_name}}/target \
					-G Ninja

# move target
move:
	rm -rf {{target_dir}}
	mkdir {{target_dir}}
	mv CMakeCache.txt CMakeFiles cmake_install.cmake .ninja_deps .ninja_log build.ninja *.bc *.i *.s *.o *.ll a.out target

# .clang-format init(LinuxOS/macOS)
cl:
	rm -rf .clang-format
	{{clang_format}} -style=LLVM -dump-config > .clang-format

# .clang-format fmt(LinuxOS/ macOS)
fmt:
	find {{fmt_flags}}

# (fast).clang-format fmt(cargo install fd-find)(LinuxOS / macOS)
fm:
	fd {{fm_flags}}

# clang LLVM emit-file
ll:
	rm -rf target
	mkdir -p target
	cp -rf {{src_dir}}/*.* ./.
	{{clang_which}} {{ldflags_emit_llvm}} main.c
	mv *.ll {{target_dir}}
	{{clang_which}} {{ldflags_common}} -o {{target}} {{source}}
	mv *.cpp {{target_dir}}
	rm -rf *.out

# Assembly emit-file
as:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_assembly}} -o {{target}} {{source}}
	mv *.i {{target_dir}}
	mv *.o {{target_dir}}
	mv *.s {{target_dir}}
	mv *.bc {{target_dir}}

# Clang Sanitize(ASan=address / LSan=leak / TSan=thread / MSan=memory / UBSan=undefined (Undefined Behavior) / https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html
san SAN:
	rm -rf target
	mkdir -p target
	{{clang_which}} -g -fsanitize={{SAN}} -fno-omit-frame-pointer -c {{source}}
	{{clang_which}} -g -fsanitize={{SAN}} *.o
	mv a.out *.o {{target_dir}}
	{{target_dir}}/a.out

# clang (ASan)fsanitize_address
asan:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_fsanitize_address}} {{source}}
	{{clang_which}} {{ldflags_fsanitize_object}} *.o
	mv a.out *.o {{target_dir}}
	{{target_dir}}/a.out

# clang LSan_Leak_Sanitizer
lsan:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_fsanitize_leak}} {{source}} -o {{target}}
	{{target}}

# clang TSan_Thread_Sanitizer
tsan:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_fsanitize_thread}} {{source}}
	{{clang_which}} {{ldflags_fsanitize_thread_object}} *.o
	mv a.out *.o {{target_dir}}
	{{target_dir}}/a.out

# leak memory check(valgrind)
[linux]
leaks:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_fsanitize_valgrind}} {{source}} -o {{target}}
	valgrind --leak-check=full {{target}}

# leak memory check(leaks / macOS)
[macos]
leaks:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_fsanitize_valgrind}} {{source}} -o {{target}}
	leaks --atExit -- {{target}}

# leak memory check(valgrind)
[linux]
valgrind:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_fsanitize_valgrind_O0}} {{source}} -o {{project_name}}
	mv {{project_name}} {{target_dir}}
	valgrind --leak-check=full {{target_dir }}/{{project_name}}

# valgrind --track-origins=yes
[linux]
valgrind_detail:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_fsanitize_valgrind_O0}} {{source}} -o {{project_name}}
	mv {{project_name}} {{target_dir}}
	valgrind --leak-check=full --track-origins=yes {{target_dir }}/{{project_name}}

# valgrind --tool=memcheck --vgdb=yes --vgdb-error=0
[linux]
valgrind_memcheck:
	rm -rf target
	mkdir -p target
	{{clang_which}} -O0 -g {{source}} -o {{project_name}}
	mv {{project_name}} {{target_dir}}
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --tool=memcheck --vgdb=yes --vgdb-error=0 {{target_dir }}/{{project_name}}

# thread check(data race)
thread:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_fsanitize_thread}} {{source}} -o {{target}}
	{{target}}

# object file emit-file
obj:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_assembly}} -o {{target}} {{source}}
	mv *.ii {{target_dir}}
	mv *.o {{target_dir}}
	mv *.s {{target_dir}}
	mv *.bc {{target_dir}}
	objdump --disassemble -S -C {{target_dir}}/main.o

# hex view("rg -i <search>" | "grep -rni <search>")
[linux]
xx:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_fsanitize_valgrind}} {{source}} -o {{project_name}}
	xxd -c 16 {{project_name}} > hex_print.txt
	mv {{project_name}} hex_print.txt {{target_dir}}

# hex view("rg -i <search>" | "grep -rni <search>")
[macos]
xx:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_fsanitize_valgrind}} {{source}} -o {{project_name}}
	xxd -c 16 {{project_name}} > hex_print.txt
	mv {{project_name}} {{project_name}}.* hex_print.txt {{target_dir}}

# clean files
clean:
	rm -rf {{target_dir}} *.out {{src_dir}}/*.out *.bc {{src_dir}}/target/ *.dSYM {{src_dir}}/*.dSYM *.i *.o *.s
	rm -rf build CMakeCache.txt CMakeFiles .cache build.ninja cmake_install.cmake .ninja_deps .ninja_log target

# C++ 26 init(int main(void))
init:
	mkdir -p src
	echo '# BasedOnStyle: LLVM' > .clang-format
	echo '# LLVM, Google, Chromium, Mozilla, WebKit' >> .clang-format
	echo "" >> .clang-format
	echo 'BasedOnStyle: LLVM' >> .clang-format
	echo 'IndentWidth: 4' >> .clang-format
	echo 'ContinuationIndentWidth: 4' >> .clang-format
	echo 'IndentCaseLabels: false' >> .clang-format
	echo 'IndentCaseBlocks: false' >> .clang-format
	echo 'IndentGotoLabels: true' >> .clang-format
	echo 'IndentPPDirectives: None' >> .clang-format
	echo 'IndentExternBlock: NoIndent' >> .clang-format
	echo '#include <print>' > src/main.cpp
	echo '' >> src/main.cpp
	echo 'int main(void) {' >> src/main.cpp
	echo '        std::print("Hello world Cpp 26 lang ");' >> src/main.cpp
	echo '    return 0;' >> src/main.cpp
	echo '}' >> src/main.cpp

# C++ 20 init(int main(void))
init2:
	mkdir -p src
	echo '# BasedOnStyle: LLVM' > .clang-format
	echo '# LLVM, Google, Chromium, Mozilla, WebKit' >> .clang-format
	echo "" >> .clang-format
	echo 'BasedOnStyle: LLVM' >> .clang-format
	echo 'IndentWidth: 4' >> .clang-format
	echo 'ContinuationIndentWidth: 4' >> .clang-format
	echo 'IndentCaseLabels: false' >> .clang-format
	echo 'IndentCaseBlocks: false' >> .clang-format
	echo 'IndentGotoLabels: true' >> .clang-format
	echo 'IndentPPDirectives: None' >> .clang-format
	echo 'IndentExternBlock: NoIndent' >> .clang-format
	echo '#include <iostream>' > src/main.cpp
	echo '' >> src/main.cpp
	echo 'int main() {' >> src/main.cpp
	echo '        std::cout << ("Hello world Cpp 20 lang ") << std::endl;' >> src/main.cpp
	echo '    return 0;' >> src/main.cpp
	echo '}' >> src/main.cpp

# C++ init(int main(int argc, char* argv[]))
init3:
	mkdir -p src
	echo '# BasedOnStyle: LLVM' > .clang-format
	echo '# LLVM, Google, Chromium, Mozilla, WebKit' >> .clang-format
	echo "" >> .clang-format
	echo 'BasedOnStyle: LLVM' >> .clang-format
	echo 'IndentWidth: 4' >> .clang-format
	echo 'ContinuationIndentWidth: 4' >> .clang-format
	echo 'IndentCaseLabels: false' >> .clang-format
	echo 'IndentCaseBlocks: false' >> .clang-format
	echo 'IndentGotoLabels: true' >> .clang-format
	echo 'IndentPPDirectives: None' >> .clang-format
	echo 'IndentExternBlock: NoIndent' >> .clang-format
	echo '#include <iostream>' > src/main.cpp
	echo '' >> src/main.cpp
	echo 'int main(int argc, char* argv[]) {' >> src/main.cpp
	echo '    std::cout << "Hello world C lang " << std::endl;' >> src/main.cpp
	echo '    int i;' >> src/main.cpp
	echo '    ' >> src/main.cpp
	echo '    for (i=0; i < argc; i++) {' >> src/main.cpp
	echo '        printf("%s", argv[i]);' >> src/main.cpp
	echo '    }' >> src/main.cpp
	echo '    return 0;' >> src/main.cpp
	echo '}' >> src/main.cpp

# C++ init(int main(int argc, char** argv))
init4:
	mkdir -p src
	echo '# BasedOnStyle: LLVM' > .clang-format
	echo '# LLVM, Google, Chromium, Mozilla, WebKit' >> .clang-format
	echo "" >> .clang-format
	echo 'BasedOnStyle: LLVM' >> .clang-format
	echo 'IndentWidth: 4' >> .clang-format
	echo 'ContinuationIndentWidth: 4' >> .clang-format
	echo 'IndentCaseLabels: false' >> .clang-format
	echo 'IndentCaseBlocks: false' >> .clang-format
	echo 'IndentGotoLabels: true' >> .clang-format
	echo 'IndentPPDirectives: None' >> .clang-format
	echo 'IndentExternBlock: NoIndent' >> .clang-format
	echo '#include <iostream>' > src/main.cpp
	echo '#include <vector>' >> src/main.cpp
	echo '#include <algorithm>' >> src/main.cpp
	echo '#include <iterator>' >> src/main.cpp
	echo '' >> src/main.cpp
	echo 'template <typename C>' >> src/main.cpp
	echo 'void reverse_sort(C& c)' >> src/main.cpp
	echo '{' >> src/main.cpp
	echo '    sort(begin(c), end(c), [](auto x, auto y){ return x > y; });' >> src/main.cpp
	echo '}' >> src/main.cpp
	echo '' >> src/main.cpp
	echo 'int main(int argc, char** argv) {' >> src/main.cpp
	echo '    std::cout << "Hello world C++ reverse sort " << std::endl;' >> src/main.cpp
	echo '    std::vector<int> v= {3, 7, 2, 9};' >> src/main.cpp
	echo '    ' >> src/main.cpp
	echo '    std::sort(begin(v), end(v));' >> src/main.cpp
	echo '    std::copy(cbegin(v), cend(v), std::ostream_iterator<int>(std::cout, ", "));' >> src/main.cpp
	echo '    std::cout << std::endl;' >> src/main.cpp
	echo '    ' >> src/main.cpp
	echo '    // sort(begin(v), end(v), [](auto x, auto y){ return x > y; });' >> src/main.cpp
	echo '    reverse_sort(v); ' >> src/main.cpp
	echo '    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, ", "));' >> src/main.cpp
	echo '    std::cout << std::endl;' >> src/main.cpp
	echo '    std::cout << "number of arguments: " << argc << std::endl;' >> src/main.cpp
	echo '    for (int i = 0; i < argc; ++i) {' >> src/main.cpp
	echo '        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;' >> src/main.cpp
	echo '    }' >> src/main.cpp
	echo '    ' >> src/main.cpp
	echo '    if (argc < 2) {' >> src/main.cpp
	echo '        std::cout << "Usage: " << argv[0] << " <name>" << std::endl;' >> src/main.cpp
	echo '        return 1;' >> src/main.cpp
	echo '    }' >> src/main.cpp
	echo '    ' >> src/main.cpp
	echo '    std::cout << "Hello, " << argv[1] << "!" << std::endl;' >> src/main.cpp
	echo '    ' >> src/main.cpp
	echo '    return 0;' >> src/main.cpp
	echo '}' >> src/main.cpp

# Debugging(VSCode codelldb ver)
codelldb:
	rm -rf .vscode
	mkdir -p .vscode
	echo '{' > .vscode/launch.json
	echo '    "version": "0.2.0",' >> .vscode/launch.json
	echo '    "configurations": [' >> .vscode/launch.json
	echo '        {' >> .vscode/launch.json
	echo '            "type": "lldb",' >> .vscode/launch.json
	echo '            "request": "launch",' >> .vscode/launch.json
	echo '            "name": "Launch",' >> .vscode/launch.json
	echo '            "program": "${workspaceFolder}/target/debug/${workspaceFolderBasename}",' >> .vscode/launch.json
	echo '            "args": [],' >> .vscode/launch.json
	echo '            "cwd": "${workspaceFolder}"' >> .vscode/launch.json
	echo '            // "preLaunchTask": "C/C++: clang build active file"' >> .vscode/launch.json
	echo '        },' >> .vscode/launch.json
	echo '        {' >> .vscode/launch.json
	echo '            "name": "g++ - Build and debug active file",' >> .vscode/launch.json
	echo '            "type": "lldb",' >> .vscode/launch.json
	echo '            "request": "launch",' >> .vscode/launch.json
	echo '            "program": "${fileDirname}/target/debug/${workspaceFolderBasename}",' >> .vscode/launch.json
	echo '            "args": [],' >> .vscode/launch.json
	echo '            "stopAtEntry": false,' >> .vscode/launch.json
	echo '            "cwd": "${fileDirname}",' >> .vscode/launch.json
	echo '            "environment": [],' >> .vscode/launch.json
	echo '            "externalConsole": false,' >> .vscode/launch.json
	echo '            "MIMode": "lldb"' >> .vscode/launch.json
	echo '            // "tasks": "C/C++: clang build active file"' >> .vscode/launch.json
	echo '        }' >> .vscode/launch.json
	echo '    ]' >> .vscode/launch.json
	echo '}' >> .vscode/launch.json
	echo '{' > .vscode/tasks.json
	echo '    "tasks": [' >> .vscode/tasks.json
	echo '        {' >> .vscode/tasks.json
	echo '            "type": "C_Cpp_Build",' >> .vscode/tasks.json
	echo '            "label": "C/C++: clang build active file",' >> .vscode/tasks.json
	echo '            "command": "{{clang_which}}",' >> .vscode/tasks.json
	echo '            "args": [' >> .vscode/tasks.json
	echo '                "-c",' >> .vscode/tasks.json
	echo '                "-fcolor-diagnostics",' >> .vscode/tasks.json
	echo '                "-fansi-escape-codes",' >> .vscode/tasks.json
	echo '                "-g",' >> .vscode/tasks.json
	echo '                "${file}",' >> .vscode/tasks.json
	echo '                "-o",' >> .vscode/tasks.json
	echo '                "${fileDirname}/target/debug/${workspaceFolderBasename}"' >> .vscode/tasks.json
	echo '            ],' >> .vscode/tasks.json
	echo '            "options": {' >> .vscode/tasks.json
	echo '                "cwd": "${fileDirname}"' >> .vscode/tasks.json
	echo '            },' >> .vscode/tasks.json
	echo '            "problemMatcher": [' >> .vscode/tasks.json
	echo '                "$gcc"' >> .vscode/tasks.json
	echo '            ],' >> .vscode/tasks.json
	echo '            "group": {' >> .vscode/tasks.json
	echo '                "kind": "build",' >> .vscode/tasks.json
	echo '                "isDefault": true' >> .vscode/tasks.json
	echo '            },' >> .vscode/tasks.json
	echo '            "detail": "Task generated by Debugger."' >> .vscode/tasks.json
	echo '        }' >> .vscode/tasks.json
	echo '    ],' >> .vscode/tasks.json
	echo '    "version": "2.0.0"' >> .vscode/tasks.json
	echo '}' >> .vscode/tasks.json

# Debugging(VSCode)
vscode:
	rm -rf .vscode
	mkdir -p .vscode
	echo '{' > .vscode/launch.json
	echo '    "version": "0.2.0",' >> .vscode/launch.json
	echo '    "configurations": [' >> .vscode/launch.json
	echo '        {' >> .vscode/launch.json
	echo '            "type": "lldb",' >> .vscode/launch.json
	echo '            "request": "launch",' >> .vscode/launch.json
	echo '            "name": "Launch",' >> .vscode/launch.json
	echo '            "program": "${workspaceFolder}/target/${fileBasenameNoExtension}",' >> .vscode/launch.json
	echo '            "args": [],' >> .vscode/launch.json
	echo '            "cwd": "${workspaceFolder}"' >> .vscode/launch.json
	echo '            // "preLaunchTask": "C/C++: clang build active file"' >> .vscode/launch.json
	echo '        },' >> .vscode/launch.json
	echo '        {' >> .vscode/launch.json
	echo '            "name": "g++ - Build and debug active file",' >> .vscode/launch.json
	echo '            "type": "cppdbg",' >> .vscode/launch.json
	echo '            "request": "launch",' >> .vscode/launch.json
	echo '            "program": "${fileDirname}/target/${fileBasenameNoExtension}",' >> .vscode/launch.json
	echo '            "args": [],' >> .vscode/launch.json
	echo '            "stopAtEntry": false,' >> .vscode/launch.json
	echo '            "cwd": "${fileDirname}",' >> .vscode/launch.json
	echo '            "environment": [],' >> .vscode/launch.json
	echo '            "externalConsole": false,' >> .vscode/launch.json
	echo '            "MIMode": "lldb"' >> .vscode/launch.json
	echo '            // "tasks": "C/C++: clang build active file"' >> .vscode/launch.json
	echo '        }' >> .vscode/launch.json
	echo '    ]' >> .vscode/launch.json
	echo '}' >> .vscode/launch.json
	echo '{' > .vscode/tasks.json
	echo '    "tasks": [' >> .vscode/tasks.json
	echo '        {' >> .vscode/tasks.json
	echo '            "type": "cppbuild",' >> .vscode/tasks.json
	echo '            "label": "C/C++: clang build active file",' >> .vscode/tasks.json
	echo '            "command": "{{clang_which}}",' >> .vscode/tasks.json
	echo '            "args": [' >> .vscode/tasks.json
	echo '                "-c",' >> .vscode/tasks.json
	echo '                "-fcolor-diagnostics",' >> .vscode/tasks.json
	echo '                "-fansi-escape-codes",' >> .vscode/tasks.json
	echo '                "-g",' >> .vscode/tasks.json
	echo '                "${file}",' >> .vscode/tasks.json
	echo '                "-o",' >> .vscode/tasks.json
	echo '                "${fileDirname}/target/${fileBasenameNoExtension}"' >> .vscode/tasks.json
	echo '            ],' >> .vscode/tasks.json
	echo '            "options": {' >> .vscode/tasks.json
	echo '                "cwd": "${fileDirname}"' >> .vscode/tasks.json
	echo '            },' >> .vscode/tasks.json
	echo '            "problemMatcher": [' >> .vscode/tasks.json
	echo '                "$gcc"' >> .vscode/tasks.json
	echo '            ],' >> .vscode/tasks.json
	echo '            "group": {' >> .vscode/tasks.json
	echo '                "kind": "build",' >> .vscode/tasks.json
	echo '                "isDefault": true' >> .vscode/tasks.json
	echo '            },' >> .vscode/tasks.json
	echo '            "detail": "Task generated by Debugger."' >> .vscode/tasks.json
	echo '        }' >> .vscode/tasks.json
	echo '    ],' >> .vscode/tasks.json
	echo '    "version": "2.0.0"' >> .vscode/tasks.json
	echo '}' >> .vscode/tasks.json
```

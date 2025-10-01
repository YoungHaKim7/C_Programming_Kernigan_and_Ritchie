# link

- [justfile setting복사해서 쓰기](#justfile)

<hr />

# cmake (ctest 문서)[|🔝|](#link)
- https://cmake.org/cmake/help/latest/manual/ctest.1.html

# Test C code[|🔝|](#link)

- `just ctest`

```bash
$ just ctest

cmake -D CMAKE_C_COMPILER=/opt/gcc-15/bin/gcc -S . -B build
-- The C compiler identification is GNU 15.1.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /opt/gcc-15/bin/gcc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done (8.2s)
-- Generating done (0.0s)
-- Build files have been written to: /home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/002_snippets_C_code/c01_test_c_code/build
cmake --build build
[ 50%] Building C object CMakeFiles/c01_test_c_code.dir/src/main.c.o
[100%] Linking C executable target/c01_test_c_code
[100%] Built target c01_test_c_code
ctest --test-dir ./build
Test project /home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/002_snippets_C_code/c01_test_c_code/build
    Start 1: run_c01_test_c_code
1/1 Test #1: run_c01_test_c_code ..............   Passed    0.68 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.68 sec

```

- `ctest`

```bash
cmake -S . -B build
cmake --build build
cd build
ctest --output-on-failure

# result

$ ctest --output-on-failure
Test project /Users/gy/C_Programming_Kernigan_and_Ritchie/001_C_Training/d01_test_c_code/build
    Start 1: run_d01_test_c_code
1/1 Test #1: run_d01_test_c_code ..............   Passed    0.35 sec

100% tests passed, 0 tests failed out of 1    
```

# Result[|🔝|](#link)

```bash
=== ATOI TESTS ===
[0] '123' => 123
[1] '-456' => -456
[2] '   789' => 789
[3] '+42' => 42
[4] '00099' => 99
[5] '  -0010' => -10
[6] '2147483647' => 2147483647
[7] '-2147483648' => -2147483648
[8] '  +0000123' => 123
[9] '999999999' => 999999999

=== SHELLSORT TESTS ===
[arr1 sorted] 1 2 5 5 6 9
[arr2 sorted] 5 6 7 8 9 10
[arr3 sorted] 1 2 3 4 5 6
[arr4 sorted] 42
[arr5 sorted] -7 -1 0 2 3
```

# justfile[|🔝|](#link)

```justfile

project_name := `basename "$(pwd)"`

# linuxOS
clang_which := "/usr/bin/clang-20"
gcc_which := "/opt/gcc-15/bin/gcc"

# macOS
macos_clang_which := "/opt/homebrew/opt/llvm/bin/clang"
macos_gcc_which := "/opt/homebrew/opt/gcc@15/bin/gcc-15"

# Source and target directories
src_dir := "./src"
target_dir := "./target"

# clang-format 20
clang_format := "clang-format-20"
macos_clang_format := "/opt/homebrew/opt/llvm/bin/clang-format"

# Files
source := src_dir+"/main.c"
target := target_dir+project_name

# Common flags
ldflags_common := "-std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror"
ldflags_debug := "-c -pthread -lm -Wall -Wextra -ggdb"
ldflags_emit_llvm := "-S -emit-llvm"
ldflags_assembly := "-Wall -save-temps"
ldflags_fsanitize_address := "-g -fsanitize=address -fno-omit-frame-pointer -c"
ldflags_fsanitize_object := "-g -fsanitize=address"
ldflags_fsanitize_thread := "-g -fsanitize=thread -fno-omit-frame-pointer -c"
ldflags_fsanitize_thread_object := "-g -fsanitize=thread"
ldflags_fsanitize_valgrind := "-fsanitize=address -g3"
ldflags_fsanitize_valgrind_O0 := "-O0 -g -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror"
ldflags_fsanitize_leak := "-fsanitize=leak -g"
ldflags_optimize :=  "-Wall -O2 -pedantic -pthread -pedantic-errors -lm -Wextra -ggdb"

# fmt .clang-format(linuxOS)
fmt_flags := ". -regex '.*\\.\\(cpp\\|hpp\\|cc\\|cxx\\|c\\|h\\)' -exec "+clang_format+" -style=file -i {} \\;"

# fmt .clang-format(macOS)
macos_fmt_flags := ". -iname '*.cpp' -o -iname '*.hpp' -o -iname '*.cc'  -o -iname '*.c'-o -iname '*.cxx' -o -iname '*.c' -o -iname '*.h' | "+macos_clang_format+" -style=file -i --files=/dev/stdin"

# fast fmt(fd-find)
fm_flags := "-e c -e h -e cpp -e hpp -e cc -e cxx -x "+clang_format+" -style=file -i {} \\;"

# fast fmt(fd-find)
macos_fm_flags := "-e c -e h -e cpp -e hpp -e cc -e cxx -x "+macos_clang_format+" -style=file -i {} \\;"

# (C)gcc compile(LinuxOS)
[linux]
r:
	rm -rf target
	mkdir -p target
	{{gcc_which}} {{ldflags_common}} -o {{target_dir}}/{{project_name}} {{source}}
	{{target_dir}}/{{project_name}}

# (C)gcc compile(macOS)
[macos]
r:
	rm -rf target
	mkdir -p target
	{{macos_gcc_which}} {{ldflags_common}} -o {{target_dir}}/{{project_name}} {{source}}
	{{target_dir}}/{{project_name}}

# (C)clang compile(Optimization/LinuxOS)
[linux]
ro:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_optimize}} -o {{target_dir}}/{{project_name}} {{source}}
	{{target_dir}}/{{project_name}}

# (C)clang compile(Optimization/macOS)
[macos]
ro:
	rm -rf target
	mkdir -p target
	{{macos_clang_which}} {{ldflags_optimize}} -o {{target_dir}}/{{project_name}} {{source}}
	{{target_dir}}/{{project_name}}

# cmake compile(LinuxOS)
[linux]
cr:
	rm -rf build
	mkdir -p build
	export CC={{gcc_which}}
	cmake -D CMAKE_C_COMPILER={{gcc_which}} -G Ninja .
	ninja
	mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
	./build/target/{{project_name}}

# cmake compile(macOS)
[macos]
cr:
	rm -rf build
	mkdir -p build
	export CC={{macos_gcc_which}}
	cmake -D CMAKE_C_COMPILER={{macos_gcc_which}} -G Ninja .
	ninja
	mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
	./build/target/{{project_name}}

# cmake compile(LinuxOS)
[linux]
cro:
	rm -rf build
	mkdir -p build
	cmake -D CMAKE_BUILD_TYPE=RelWithDebInfo \
	      -D CMAKE_C_COMPILER={{gcc_which}} \
	      -D CMAKE_C_FLAGS_RELWITHDEBINFO_INIT="-O2 -g" \
	      -G Ninja .
	ninja
	mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
	./build/target/{{project_name}}
    
# cmake compile(LinuxOS)
[macos]
cro:
	rm -rf build
	mkdir -p build
	cmake -D CMAKE_BUILD_TYPE=RelWithDebInfo \
	      -D CMAKE_C_COMPILER={{macos_gcc_which}} \
	      -D CMAKE_C_FLAGS_RELWITHDEBINFO_INIT="-O2 -g" \
	      -G Ninja .
	ninja
	mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
	./build/target/{{project_name}}

# cmake compile(LinuxOS)
[linux]
cro3:
	rm -rf build
	mkdir -p build
	cmake -D CMAKE_BUILD_TYPE=Release \
	      -D CMAKE_C_COMPILER={{gcc_which}} \
	      -D CMAKE_C_FLAGS_RELEASE_INIT="-O3 -DNDEBUG" \
	      -G Ninja .
	ninja
	mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
	./build/target/{{project_name}}

# cmake compile(macOS)
[macos]
cro3:
	rm -rf build
	mkdir -p build
	cmake -D CMAKE_BUILD_TYPE=Release \
	      -D CMAKE_C_COMPILER={{macos_gcc_which}} \
	      -D CMAKE_C_FLAGS_RELEASE_INIT="-O3 -DNDEBUG" \
	      -G Ninja .
	ninja
	mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
	./build/target/{{project_name}}
	
# cmake ctest(LinuxOS)
[linux]
ctest:
	rm -rf build
	mkdir -p build
	cmake -D CMAKE_C_COMPILER={{gcc_which}} \
		  -S . -B build
	cmake --build build
	ctest --test-dir ./build

# cmake ctest(macOS)
[linux]
ctest:
	rm -rf build
	mkdir -p build
	cmake -D CMAKE_C_COMPILER={{macos_gcc_which}} \
		  -S . -B build
	cmake --build build
	ctest --test-dir ./build

# zig C compile(LinuxOS)
[linux]
zr:
	rm -rf target
	mkdir -p target
	export CC={{gcc_which}}
	zig cc {{ldflags_common}} -o {{target}} {{source}}
	{{target}}

# zig C compile(macOS)
[macos]
zr:
	rm -rf target
	mkdir -p target
	export CC={{macos_gcc_which}}
	zig cc {{ldflags_common}} -o {{target}} {{source}}
	{{target}}

# clang build
b:
	rm -rf target
	mkdir -p target
	{{clang_which}} {{ldflags_debug}} -o {{target}} {{source}}

# move target
move:
	rm -rf target
	mkdir target
	mv CMakeCache.txt CMakeFiles cmake_install.cmake .ninja_deps .ninja_log build.ninja *.bc *.i *.s *.o *.ll a.out target

# .clang-format init(LinuxOS)
[linux]
cl:
	rm -rf .clang-format
	{{clang_format}} -style=WebKit -dump-config > .clang-format

# .clang-format init(macOS)
[macos]
cl:
	rm -rf .clang-format
	{{macos_clang_format}} -style=WebKit -dump-config > .clang-format

# .clang-format fmt(LinuxOS)
[linux]
fmt:
	find {{fmt_flags}}

# .clang-format fmt(macOS)
[macos]
fmt:
	find {{macos_fmt_flags}}

# (fast).clang-format fmt(cargo install fd-find)(LinuxOS)
[linux]
fm:
	fd {{fm_flags}}

# (fast).clang-format fmt(cargo install fd-find)(macOS)
[macos]
fm:
	fd {{macos_fm_flags}}

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

# clang sanitize(ASan=address / LSan=leak / TSan=thread / MSan=memory / UBSan=undefined)
[linux]
san SAN:
	rm -rf target
	mkdir -p target
	{{clang_which}} -g -fsanitize={{SAN}} -fno-omit-frame-pointer -c {{source}}
	{{clang_which}} -g -fsanitize={{SAN}} *.o 
	mv a.out *.o {{target_dir}}
	{{target_dir}}/a.out

# clang sanitize(ASan=address / LSan=leak / TSan=thread / MSan=memory / UBSan=undefined)
[macos]
san SAN:
	rm -rf target
	mkdir -p target
	{{macos_clang_which}} -g -fsanitize={{SAN}} -fno-omit-frame-pointer -c {{source}}
	{{macos_clang_which}} -g -fsanitize={{SAN}} *.o 
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

# leak memory check(valgrind)
[macos]
leaks:
	rm -rf target
	mkdir -p target
	{{macos_clang_which}} {{ldflags_fsanitize_valgrind}} {{source}} -o {{target}}
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
[macos]
thread:
	rm -rf target
	mkdir -p target
	{{macos_clang_which}} {{ldflags_fsanitize_thread}} {{source}} -o {{target}}
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

# hex view
[macos]
xx:
	rm -rf target
	mkdir -p target
	{{macos_clang_which}} {{ldflags_fsanitize_valgrind}} {{source}} -o {{project_name}}
	xxd -c 16 {{project_name}} > hex_print.txt
	mv {{project_name}} {{project_name}}.* hex_print.txt {{target_dir}}


# clean files
clean:
	rm -rf {{target_dir}} *.out {{src_dir}}/*.out *.bc {{src_dir}}/target/ *.dSYM {{src_dir}}/*.dSYM *.i *.o *.s
	rm -rf build CMakeCache.txt CMakeFiles

# C init
init:
	mkdir -p src
	echo '# BasedOnStyle: WebKit' > .clang-format
	echo '# LLVM, Google, Chromium, Mozilla, WebKit' >> .clang-format
	echo "" >> .clang-format
	echo 'BasedOnStyle: WebKit' >> .clang-format
	echo 'IndentWidth: 4' >> .clang-format
	echo 'ContinuationIndentWidth: 4' >> .clang-format
	echo 'IndentCaseLabels: false' >> .clang-format
	echo 'IndentCaseBlocks: false' >> .clang-format
	echo 'IndentGotoLabels: true' >> .clang-format
	echo 'IndentPPDirectives: None' >> .clang-format
	echo 'IndentExternBlock: NoIndent' >> .clang-format
	echo '#include <stdio.h>' > src/main.c
	echo '' >> src/main.c
	echo 'int main(void) {' >> src/main.c
	echo '    printf("Hello world C lang ");' >> src/main.c
	echo '    return 0;' >> src/main.c
	echo '}' >> src/main.c

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
	echo '            "program": "${workspaceFolder}/build/target/${workspaceFolderBasename}",' >> .vscode/launch.json
	echo '            "args": [],' >> .vscode/launch.json
	echo '            "cwd": "${workspaceFolder}"' >> .vscode/launch.json
	echo '            // "preLaunchTask": "C/C++: clang build active file"' >> .vscode/launch.json
	echo '        },' >> .vscode/launch.json
	echo '        {' >> .vscode/launch.json
	echo '            "name": "gcc - Build and debug active file",' >> .vscode/launch.json
	echo '            "type": "lldb",' >> .vscode/launch.json
	echo '            "request": "launch",' >> .vscode/launch.json
	echo '            "program": "${fileDirname}/build/target/${workspaceFolderBasename}",' >> .vscode/launch.json
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
	echo '                "${fileDirname}/build/target/${workspaceFolderBasename}"' >> .vscode/tasks.json
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
	echo '            "name": "gcc - Build and debug active file",' >> .vscode/launch.json
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

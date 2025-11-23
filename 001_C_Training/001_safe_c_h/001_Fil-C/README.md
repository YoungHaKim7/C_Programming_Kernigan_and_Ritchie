# Fil-C: completely compatible memory safety for C and C++
- https://github.com/pizlonator/fil-c/

# Fil-C
- https://fil-c.org/
  - https://github.com/pizlonator/fil-c/ 
- Memory Safety • C/C++ Compatibility • Modern Tooling
  - Welcome to Fil-C, a memory safe implementation of the C and C++ programming languages you already know and love.
- What is Fil-C?
  - Fil-C is a fanatically compatible memory-safe implementation of C and C++. Lots of software compiles and runs with Fil-C with zero or minimal changes. All memory safety errors are caught as Fil-C panics. Fil-C achieves this using a combination of concurrent garbage collection and invisible capabilities (InvisiCaps). Every possibly-unsafe C and C++ operation is checked. Fil-C has no unsafe statement and only limited FFI to unsafe code.
- 메모리 안전 - C/C++ 호환성 - 현대적인 도구
  - 이미 알고 있고 사랑하는 C 및 C++ 프로그래밍 언어의 메모리 안전한 구현인 Fil-C에 오신 것을 환영합니다.
- Fil-C란 무엇인가요?
  - Fil-C는 C와 C++의 광적으로 호환되는 메모리 안전 구현체입니다. 많은 소프트웨어가 Fil-C와 함께 제로 또는 최소한의 변경으로 컴파일 및 실행됩니다. 모든 메모리 안전 오류는 Fil-C 패닉으로 간주됩니다. Fil-C는 동시 쓰레기 수거와 보이지 않는 기능(InvisiCaps)의 조합을 사용하여 이를 달성합니다. 안전하지 않을 가능성이 있는 모든 C와 C++ 작업을 점검합니다. Fil-C에는 안전하지 않은 문장이 없으며, 안전하지 않은 코드에 대한 FFI만 제한되어 있습니다.

# Install

- 내 기준으로 LLVM-18 버젼으로 설치함.. 중간에 에러난건 clang 버젼이 안 맞아져

```bash
# lld 링커 에러나서 이걸로 해결
sudo apt lld

```

- 용량이 커서 gix이용

```bash
gix clone https://github.com/pizlonator/fil-c.git

./build_all.sh.
```


```bash
sudo apt install patchelf
```

# fil-c설명 영상
- https://x.com/filpizlo/status/1976831020566798656

# included file: ‘stdlib.h’ file not found
- https://discourse.llvm.org/t/in-included-file-stdlib-h-file-not-found/1694/2 

# Compile Time
- https://stackoverflow.com/questions/16710047/usr-bin-ld-cannot-find-lnameofthelibrary 

When g++ says `cannot find -l<nameOfTheLibrary>`, it means that g++ looked for the file `lib{nameOfTheLibrary}.so`, but it couldn't find it in the shared library search path, which by default points to `/usr/lib` and `/usr/local/lib` and somewhere else maybe.

To resolve this problem, you should either provide the library file `(lib{nameOfTheLibrary}.so)` in those search paths or use `-L` command option. `-L{path}` tells the g++ (actually `ld`) to find library files in path `{path}` in addition to default paths.

Example: Assuming you have a library at `/home/taylor/libswift.so`, and you want to link your app to this library. In this case you should supply the g++ with the following options:

```cpp

g++ main.cpp -o main -L/home/taylor -lswift
```

- Note 1: `-l` option gets the library name without `lib` and `.so` at its beginning and end.

- Note 2: In some cases, the library file name is followed by its version, for instance `libswift.so.1.2`. In these cases, g++ also cannot find the library file. A simple workaround to fix this is creating a symbolic link to `libswift.so.1.2` called `libswift.so`.

# `-I -I` I 2번 쓰면 내가 연결하고 싶은 include 추가된다.

```make
# 예시
CC = clang++
CFLAGS = -I/path/to/include1 -I/path/to/include2

all: main

main: main.o
	$(CC) $(CFLAGS) main.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

````

# linker 지정
1. 링커를 직접 지정하는 방법

    명령줄에서 링커 지정: clang 명령어에 -fuse-ld= 옵션을 사용하여 링커를 지정할 수 있습니다.
        예시 (lld 사용 시): clang -fuse-ld=lld -o my_program main.c
        예시 (GNU ld 사용 시): clang -fuse-ld=bfd -o my_program main.c
    링커 옵션 추가: ld의 추가적인 옵션을 전달할 때도 -Wl, 접두사를 사용합니다.
        예시: clang -o my_program main.c -Wl,-rpath,/usr/local/lib 

2. 빌드 시스템 설정

    CMake: target_link_libraries() 함수와 함께 링커 라이브러리나 옵션을 지정하거나, CMAKE_C_COMPILER_FLAGS, CMAKE_CXX_COMPILER_FLAGS 변수를 통해 링커 옵션을 설정할 수 있습니다.
    Bazel: cc_toolchain의 linker_flags 속성을 통해 링커를 구성합니다.
        cc_toolchain의 linker_flags에 ["-Wl,-rpath,/usr/local/lib"]와 같은 옵션을 추가합니다.

3. 기타

    LLVM의 lld 사용: Clang은 기본적으로 lld를 링커로 사용합니다. lld는 LLVM 툴체인과의 통합이 잘 되어 있고 빠릅니다.
    크로스 컴파일: 다른 아키텍처를 타겟으로 빌드할 경우, LLVM_TARGETS_TO_BUILD와 같은 옵션으로 링커를 지정할 수 있습니다

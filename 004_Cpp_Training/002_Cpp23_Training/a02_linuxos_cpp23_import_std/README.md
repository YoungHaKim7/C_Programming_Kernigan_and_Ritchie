# Result

```bash
$ export CXX=/usr/bin/clang++-21
$ cmake -D CMAKE_CXX_COMPILER=/usr/bin/clang++-21 -G Ninja .

-- The CXX compiler identification is Clang 21.1.3
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/clang++-21 - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.2s)
-- Generating done (0.0s)
-- Build files have been written to: /home/g/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/004_Cpp_Training/002_Cpp23_Training/a02_linuxos_cpp23_import_std

$ ninja

[6/6] Linking CXX executable target/a02_linuxos_cpp23_import_std

$ mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
$ ./build/./target/a02_linuxos_cpp23_import_std

c23 hello world (import ex)

```

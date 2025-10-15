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

$ ninja

[6/6] Linking CXX executable target/b01_global_module_ixx_cpp23

c23
$ mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
$ ./build/./target/b01_global_module_ixx_cpp23

c23 hello world (import ex)

```

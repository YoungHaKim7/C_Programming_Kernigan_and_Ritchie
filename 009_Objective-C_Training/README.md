# Objective-C
- Objective-C is a high-level general-purpose, object-oriented programming language that adds Smalltalk-style message passing (messaging) to the C programming language.
- https://en.wikipedia.org/wiki/Objective-C
- https://namu.wiki/w/Objective-C

- https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/Introduction/Introduction.html

- https://summerorange.tistory.com/entry/%EB%A7%A5%ED%99%98%EA%B2%BD%EC%97%90%EC%84%9C-C%EC%96%B8%EC%96%B4-%EC%86%8C%EC%8A%A4%EC%BD%94%EB%93%9C-%EC%9E%91%EC%84%B1-Xcode-C-C-Objective-C

# NeXT

- Apple에서 해고 당한 잡스가 Apple의 일부 엔지니어들과 함께 설립한 기업.
- https://namu.wiki/w/NeXT

# Linux는 추가가 필요하다.
- macOS은 그냥 된다.

# linuxOS

```bash
sudo apt install gnustep-devel
```

## cmake

```cmake
find_package(GNUstep REQUIRED)

target_link_libraries(app
    ${GNUstep_LIBRARIES}
)
```

```cmake
cmake_minimum_required(VERSION 3.16)

project(MyObjCProject LANGUAGES C OBJC)

add_executable(app main.m)

if(APPLE)
    target_link_libraries(app "-framework Foundation")
endif()
```

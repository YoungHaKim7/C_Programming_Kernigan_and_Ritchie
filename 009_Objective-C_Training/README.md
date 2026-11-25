# Objective-C
- Objective-C is a high-level general-purpose, object-oriented programming language that adds Smalltalk-style message passing (messaging) to the C programming language.
- https://en.wikipedia.org/wiki/Objective-C
- https://namu.wiki/w/Objective-C

- https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/Introduction/Introduction.html
- https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ObjectiveC/Introduction/introObjectiveC.html

- https://summerorange.tistory.com/entry/%EB%A7%A5%ED%99%98%EA%B2%BD%EC%97%90%EC%84%9C-C%EC%96%B8%EC%96%B4-%EC%86%8C%EC%8A%A4%EC%BD%94%EB%93%9C-%EC%9E%91%EC%84%B1-Xcode-C-C-Objective-C

# playground
- Better playgrounds that work both for Objective-C and Swift
  - https://github.com/krzysztofzablocki/Playgrounds

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

# swift언어 필요 없이 러스트로 가능요 ㅋㅋ(Metal-cpp) 
- Object-C로 만든 기능을 C++로 연결해서
  - 오버해드 거의 없음

- [유튜브 영상2022년 자료) Metal-cpp를 통해 C++로 Metal 프로그래밍](https://youtu.be/h1mOkhFOSPU?si=u9kC4wrRnAyuTEVH)
  - [원본은 2022년 애플 WWDC22에 소개된거임 | Metal-cpp를 통해 C++로 Metal 프로그래밍](https://developer.apple.com/kr/videos/play/wwdc2022/10160)
  - #wwdc22에서 Metal-cpp를 통해 C++로 Metal 프로그래밍을(를) 확인하십시오.

### 내가 만들고 있는거
- ABI-faithful Rust conversion of Apple's metal-cpp (macOS 27 / iOS 27 SDK era, Metal 4), implemented concretely against the Objective-C ABI — the same technique metal-cpp itself uses to bridge C++ to the runtime
  - https://github.com/YoungHaKim7/metal-cpp-rs/

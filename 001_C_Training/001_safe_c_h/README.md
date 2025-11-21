# **[C에 초능력을 부여하기: 사용자 정의 헤더 파일(safe_c.h)](<https://news.hada.io/topic?id=24453&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- **safe_c.h**는 C 언어에 **C++과 Rust의 안전성과 편의 기능**을 추가하는 600줄짜리 사용자 정의 헤더 파일로, 메모리 누수 없는 **스레드 안전 grep(cgrep)** 구현에 사용됨  
- **RAII, 스마트 포인터, 자동 정리(cleanup) 속성**을 통해 수동 free() 호출 없이 자원 관리 자동화  
- **벡터, 뷰, Result 타입, 계약…
- https://hwisnu.bearblog.dev/giving-c-a-superpower-custom-header-file-safe_ch/

# (251117)Giving C a superpower: custom header file (safe_c.h) (hwisnu.bearblog.dev) by mithcs
- https://news.ycombinator.com/item?id=45952428

# C11 has a mutex API (threads.h), so why would it rely on POSIX? Are you sure it's not an runtime detail on one platform? 
- https://devblogs.microsoft.com/cppblog/c11-threads-in-visual-studio-2022-version-17-8-preview-2/

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

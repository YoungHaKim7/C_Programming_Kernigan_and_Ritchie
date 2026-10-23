# cpp기초
- https://github.com/CoffeeBeforeArch/cpp_from_scratch
- https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines

- TigerBeetle's TigerStyle is an example in Zig and Google's 31,000 word C++ style guide is another. 
  - https://google.github.io/styleguide/cppguide.html
    - https://bun.com/blog/bun-in-rust

- The Boost C++ Libraries are open source, peer-reviewed, portable and free
  - https://www.boost.org/

- Recent milestones: C++26 work in progress
  - https://isocpp.org/std/status

- The purpose of TSs is for developers to test new features and uncover kinks and bugs before the features are included in the main standard. The compiler vendors aren’t required to implement TSs, but they usually do. You can find more information at 
  - https://isocpp.org/std/status.
  - TS의 목적은 개발자들이 새로운 기능을 테스트하고 기능이 주요 표준에 포함되기 전에 문제점과 버그를 발견하도록 하는 것입니다. 컴파일러 공급업체는 TS를 구현하도록 요구되지 않지만, 보통은 구현합니다. 자세한 정보는 https://isocpp.org/std/status 에서 확인하실 수 있습니다.
  - 출처 : Functional Programming in C++ | Iban Cukic

# 연습용
- https://github.com/cpp-best-practices/cppbestpractices

# c++26
- https://isocpp.org/blog/tag/experimental

# modern C++예시
- 모던 C++ 입문
https://github.com/petergottschling/discovering_modern_cpp

# 유튜브 영상
- [Modern C++ 유명함 Mike Shah](https://youtube.com/playlist?list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&si=q8NcZEOdHd2KvOBr)
- [(31hr)C++ Programming Course - Beginner to Advanced | freeCodeCamp.org](https://youtu.be/8jLOx1hD3_o?si=5qBWwxb0cPopgjX5)
- Rust관련 영상
  - [(251028)Overengineering max(a, b) - Mixed Comparison Functions, Common References, and Rust's Lifetime | CppNow](https://youtu.be/o2pNg7noCeQ?si=4lAGohHVBjeisPQ2)

```bash
00:04:32 C++ 개발 도구
00:11:06 Windows에 C++ 컴파일러 설치
00:24:27 Windows에 VS Code 설치
00:28:00 Windows에서 Visual Studio Code를 C++용으로 구성
00:57:27 Linux에 C++ 컴파일러 설치
01:04:02 Linux에 Visual Studio Code 설치
01:07:40 Linux에서 Visual Studio Code를 C++용으로 구성
01:22:45 macOS에 C++ 컴파일러 설치
01:28:07 macOS에 Visual Studio Code 설치
01:30:16 macOS에서 Visual Studio Code를 C++용으로 구성
01:35:37 온라인 컴파일러

2장: 본격적으로 시작하기
01:43:01 첫 번째 C++ 프로그램
01:55:56 주석
02:01:56 오류 및 경고
02:13:12 문장과 함수
02:31:34 입출력
02:49:57 C++ 프로그램 실행 모델 및 메모리 모델
02:56:42 C++ 핵심 언어 vs 표준 라이브러리 vs STL

3장: 변수와 ​​데이터 유형
03:00:47 변수와 데이터 유형 소개
03:05:05 수 체계
03:21:52 정수
03:40:44 정수 한정자
03:54:00 소수
04:16:39 불리언
04:24:49 문자와 텍스트
04:32:05 자동
04:38:06 할당
04:45:42 변수와 데이터 유형 요약

4장: 연산 데이터
04:46:45 데이터 연산 소개
04:47:31 기본 연산
04:58:01 연산자 우선순위와 결합 법칙
05:12:06 접두사 및 접미사 + & -
05:23:22 복합 연산자
05:31:43 관계 연산자: 비교하기
05:40:51 논리 연산자
05:56:09 출력 형식 지정
06:33:26 숫자 제한
06:41:10 수학 함수
06:54:23 특수한 정수형
06:59:41 데이터 연산 요약

제5장: 흐름 제어
07:01:58 흐름 제어: 조건부 프로그래밍 소개
07:03:30 if 문
07:20:49 else 문 조건문
07:28:46 Switch 연산자
07:42:44 삼항 연산자
07:52:20 흐름 제어: 조건부 프로그래밍 요약

6장: 반복문
07:53:49 반복문 소개
07:55:20 for 반복문
08:25:20 while 반복문
08:36:54 do while 반복문

7장: 배열
08:47:08 배열 소개
08:48:45 배열 선언 및 사용
09:15:53 ​​배열 크기
09:26:44 문자 배열
09:46:46 배열의 범위

8장: 포인터
09:53:23 포인터 소개
09:56:03 포인터 선언 및 사용
10:14:48 문자 포인터
10:27:26 프로그램 메모리 맵
10:36:30 동적 메모리 할당
11:05:45 댕글링 포인터
11:24:15 `new`가 실패할 경우
11:38:00 널 포인터 안전성
11:45:18 메모리 누수
11:55:44 동적 배열

9장: 참조
12:11:04 참조 소개
12:11:58 참조 선언 및 사용
12:22:28 참조와 포인터 비교
12:37:25 참조와 상수

10장: 문자 조작 및 문자열
12:44:29 문자 조작 및 문자열 소개
12:46:24 문자 조작
13:09:28 C 문자열 조작
13:41:42 C 문자열 연결 및 복사
14:01:19 std::string 소개
14:03:38 std::string 선언 및 사용

제11장: 함수
14:12:47 단일 정의 규칙
14:28:25 함수 직접 실습
15:00:50 함수 선언 및 정의
15:15:30 여러 파일에 걸친 함수 - 컴파일 모델 재검토
15:42:30 값으로 전달
15:50:30 포인터로 전달
15:57:46 참조로 전달

제12장: 함수에서 결과 가져오기
16:03:20 함수에서 결과 가져오기 소개
16:03:58 입력 및 출력 매개변수
16:17:54 함수에서 반환 함수

제13장: 함수 오버로딩
16:32:35 함수 오버로딩 소개
16:34:17 서로 다른 매개변수를 사용한 오버로딩

제14장: 람다 함수
16:49:00 람다 함수 소개
16:49:38 람다 함수 선언 및 사용
17:20:25 캡처 리스트
17:34:24 컨텍스트 내에서 모두 캡처

제15장: 함수 템플릿
17:40:08 함수 템플릿 소개
17:41:45 함수 템플릿 사용해보기
18:19:52 템플릿 타입 추론 및 명시적 인수
18:35:47 참조에 의한 템플릿 타입 매개변수
18:48:55 템플릿 특수화

제16장: 개념
19:04:31 개념 소개
19:06:47 개념
19:25:32 개념: 직접 구현하기
19:42:45 Requires 절: 자세히 살펴보기
19:59:53 개념의 논리적 조합
20:09:39 개념과 자동 완성

제17장: 클래스
20:15:40 클래스 소개
20:16:33 첫 번째 C++ 클래스
20:38:03 생성자
20:53:35 기본 생성자
20:59:42 setter와 getter
21:10:06 여러 파일에 걸친 클래스
21:30:49 포인터를 통한 클래스 객체 관리
21:42:48 소멸자
22:05:44 생성자 및 소멸자 호출 순서
22:11:03 This 포인터
22:33:33 구조체
22:42:37 클래스 객체의 크기

18장: 상속
22:52:43 상속 소개
22:55:59 상속 첫 시도
23:21:10 protected 멤버
23:32:06 기본 클래스 접근 지정자: 자세히 살펴보기
23:36:49 기본 클래스 접근 지정자: 데모
24:07:42 private 상속 자세히 살펴보기
24:26:36 스코프 내 멤버 복원하기
24:46:59 상속을 사용한 기본 인자 생성자
24:57:37 상속을 사용한 사용자 정의 생성자
25:26:56 상속을 사용한 복사 생성자
25:51:53 기본 클래스 상속하기 생성자
26:06:00 소멸자를 사용한 상속
26:12:20 상속에서 재사용되는 심볼

제19장: 다형성
26:21:03 다형성 소개
26:26:54 상속을 사용한 정적 바인딩
26:55:24 가상 함수를 사용한 다형성(동적 바인딩)
27:14:31 다형 객체의 크기와 슬라이싱
27:26:37 컬렉션에 저장된 다형 객체
27:45:42 오버라이드
27:52:45 오버로딩, 오버라이딩 및 숨김
28:07:35 다양한 수준의 상속과 다형성
28:33:03 정적 멤버를 사용한 상속과 다형성
28:49:13 최종
29:07:42 기본 인수를 갖는 가상 함수
29:23:18 가상 소멸자
29:35:38 Dynamic_cast<>()
30:08:17 생성자와 소멸자에서 가상(다형) 함수를 호출하지 마세요
30:24:45 순수 가상 함수와 추상 클래스
30:43:37 추상 클래스
```
- https://youtu.be/8jLOx1hD3_o?si=vJccA8vqN3lUWjaK

<hr />

# Moving from Rust to C++(Apr 1, 2023)
- https://raphlinus.github.io/rust/2023/04/01/rust-to-cpp.html

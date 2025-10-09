# (251005)Smart Pointers in C++ - Khushboo Verma - C++ on Sea 2025 | cpponsea
- https://youtu.be/_hiEjpZje9Q?si=57P57LNtpkZhmLjA

- What We'll Cover
  - Why raw pointers still matter in 2025
  - The three musketeers:
    - `unique_ptr`
    - `shared_ptr`
    - `weak_ptr`
  - Real-world gotchas that cost companies millions
  - Tools to catch these issues early

# Why Start Here?
- Smart pointers are built on raw pointers
- Understanding ownership sementics is crucial
- Performance baseline for comparison
  - 스마트 포인터는 원시 포인터를 기반으로 합니다
  - 소유권 의미론을 이해하는 것은 매우 중요합니다
  - 비교를 위한 성능 기준

```cpp
// Leak Example 1: Early return from function
void processData()
{
    int* data = new int[1000];
    bool errorCondition = true;  // Declare the variable

    if (errorCondition) {
        return; // LEAK! Forgot delete[]
    }

    delete[] data;
}
```

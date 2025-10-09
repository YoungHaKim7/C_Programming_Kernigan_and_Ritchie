# link

# 목차Chapter 3 - Control Flow.

```
Chapter 3 - Control Flow.
  3.1 Statements and Blocks..
  3.2 If-Else.
  3.3 Else-If.
  3.4 Switch.
  3.5 Loops - While and For.
  3.6 Loops - Do-While.
  3.7 Break and Continue.
  3.8 Goto and labels.
```

# (p50)

# C semicolon
- In C, the semicolon is a statement terminator, rather than a separator as it is in languages like
Braces { and } are used to group declarations and statements together into a compound
statement, or block, so that they are syntactically equivalent to a single statement. The braces
that surround the statements of a function are one obvious example; braces around multiple
statements after an if, else, while, or for are another. (Variables can be declared inside any
block; we will talk about this in Chapter 4.) There is no semicolon after the right brace that
ends a block.

- C에서 세미콜론은 다음과 같은 언어에서 구분자가 아닌 문장 종결자입니다
괄호 {와}는 선언문과 명제를 함께 화합물로 그룹화하는 데 사용됩니다
구문적으로 하나의 문장과 동등하도록 문장 또는 블록. 괄호는
함수의 명제를 둘러싼 것은 하나의 명백한 예입니다. 여러 개를 중심으로 괄호를 묶습니다
if, other, while, for 다음 문장들은 다른 문장입니다. (변수는 내부에 선언될 수 있습니다)
블록; 이에 대해서는 4장에서 이야기하겠습니다.) 오른쪽 괄호 뒤에는 세미콜론이 없습니다
블록을 끝냅니다.

<hr />

# 3.5 Loops - While and For

# The structure of the program reflects the form of the input:(p.54)
- 프로그램의 구조는 입력의 형태를 반영합니다:
  - skip white space, if any
  - get sign, if any
  - get integer part and convert it
    - 공백이 있는 경우 건너뛰기
    - 표지판 받기, 만약 있다면
    - 정수 부분을 가져와서 변환합니다

- Each step does its part, and leaves things in a clean state for the next. The whole process terminates on the first character that could not be part of a number.
  - 각 단계는 제 역할을 다하며 다음 단계를 위해 깨끗한 상태로 둡니다. 전체 과정은 숫자의 일부가 될 수 없는 첫 번째 문자로 끝납니다.

# 10 Examples of else if Statements

## 1. JavaScript - Grade Calculator
```javascript
function getGrade(score) {
    if (score >= 90) {
        return "A";
    } else if (score >= 80) {
        return "B";
    } else if (score >= 70) {
        return "C";
    } else if (score >= 60) {
        return "D";
    } else {
        return "F";
    }
}
```

## 2. Python - Temperature Converter
```python
def describe_temperature(celsius):
    if celsius > 30:
        return "Very hot"
    elif celsius > 20:
        return "Warm"
    elif celsius > 10:
        return "Cool"
    elif celsius > 0:
        return "Cold"
    else:
        return "Freezing"
```

## 3. Java - Age Classifier
```java
public class AgeClassifier {
    public static String classifyAge(int age) {
        if (age < 13) {
            return "Child";
        } else if (age < 20) {
            return "Teenager";
        } else if (age < 65) {
            return "Adult";
        } else {
            return "Senior";
        }
    }
}
```

## 4. C++ - Traffic Light System
```cpp
#include <string>

std::string getTrafficLightAction(int duration) {
    if (duration > 60) {
        return "Extend green light";
    } else if (duration > 30) {
        return "Normal operation";
    } else if (duration > 10) {
        return "Prepare to change";
    } else {
        return "Change to yellow/red";
    }
}
```

## 5. C# - Login System
```csharp
public string CheckLoginStatus(int failedAttempts) {
    if (failedAttempts == 0) {
        return "Welcome back!";
    } else if (failedAttempts < 3) {
        return "Please try again";
    } else if (failedAttempts < 5) {
        return "Warning: Multiple failed attempts";
    } else {
        return "Account temporarily locked";
    }
}
```

## 6. PHP - File Size Formatter
```php
function formatFileSize($bytes) {
    if ($bytes >= 1073741824) {
        return number_format($bytes / 1073741824, 2) . ' GB';
    } else if ($bytes >= 1048576) {
        return number_format($bytes / 1048576, 2) . ' MB';
    } else if ($bytes >= 1024) {
        return number_format($bytes / 1024, 2) . ' KB';
    } else {
        return $bytes . ' bytes';
    }
}
```

## 7. Ruby - BMI Calculator
```ruby
def get_bmi_category(bmi)
    if bmi < 18.5
        "Underweight"
    elsif bmi < 25
        "Normal weight"
    elsif bmi < 30
        "Overweight"
    else
        "Obese"
    end
end
```

## 8. Go - Priority Queue
```go
func GetPriorityLevel(score int) string {
    if score >= 90 {
        return "Critical"
    } else if score >= 70 {
        return "High"
    } else if score >= 50 {
        return "Medium"
    } else if score >= 30 {
        return "Low"
    } else {
        return "Minimal"
    }
}
```

## 9. Swift - Weather App
```swift
func getWeatherIcon(condition: String) -> String {
    if condition.contains("rain") {
        return "🌧️"
    } else if condition.contains("snow") {
        return "❄️"
    } else if condition.contains("cloud") {
        return "☁️"
    } else if condition.contains("sun") {
        return "☀️"
    } else {
        return "🌤️"
    }
}
```

## 10. Rust - Shipping Calculator
```rust
fn calculate_shipping_cost(weight: f64) -> f64 {
    if weight > 50.0 {
        25.99
    } else if weight > 20.0 {
        15.99
    } else if weight > 10.0 {
        9.99
    } else if weight > 5.0 {
        5.99
    } else {
        2.99
    }
}
```

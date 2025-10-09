#include <stdio.h>

// Example 1: Grade Calculator
char* getGrade(int score)
{
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

// Example 2: Temperature Classification
void describeTemperature(float celsius)
{
    if (celsius > 30) {
        printf("Very hot weather\n");
    } else if (celsius > 20) {
        printf("Warm weather\n");
    } else if (celsius > 10) {
        printf("Cool weather\n");
    } else if (celsius > 0) {
        printf("Cold weather\n");
    } else {
        printf("Freezing weather\n");
    }
}

// Example 3: Age Category
void categorizeAge(int age)
{
    if (age < 13) {
        printf("Child\n");
    } else if (age < 20) {
        printf("Teenager\n");
    } else if (age < 35) {
        printf("Young Adult\n");
    } else if (age < 65) {
        printf("Adult\n");
    } else {
        printf("Senior\n");
    }
}

// Example 4: Traffic Light System
void trafficLightControl(int carCount)
{
    if (carCount > 20) {
        printf("Extend green light to 60 seconds\n");
    } else if (carCount > 10) {
        printf("Extend green light to 45 seconds\n");
    } else if (carCount > 5) {
        printf("Standard green light duration\n");
    } else if (carCount > 0) {
        printf("Short green light duration\n");
    } else {
        printf("Skip green light if no cars\n");
    }
}

// Example 5: File Size Formatter
void formatFileSize(long bytes)
{
    if (bytes >= 1073741824) {
        printf("%.2f GB\n", (float)bytes / 1073741824);
    } else if (bytes >= 1048576) {
        printf("%.2f MB\n", (float)bytes / 1048576);
    } else if (bytes >= 1024) {
        printf("%.2f KB\n", (float)bytes / 1024);
    } else {
        printf("%ld bytes\n", bytes);
    }
}

// Example 6: BMI Calculator
void calculateBMI(float weight, float height)
{
    float bmi = weight / (height * height);

    if (bmi < 18.5) {
        printf("Underweight (BMI: %.1f)\n", bmi);
    } else if (bmi < 25) {
        printf("Normal weight (BMI: %.1f)\n", bmi);
    } else if (bmi < 30) {
        printf("Overweight (BMI: %.1f)\n", bmi);
    } else {
        printf("Obese (BMI: %.1f)\n", bmi);
    }
}

// Example 7: Shipping Cost Calculator
float calculateShippingCost(float weight)
{
    if (weight > 50.0) {
        return 25.99;
    } else if (weight > 20.0) {
        return 15.99;
    } else if (weight > 10.0) {
        return 9.99;
    } else if (weight > 5.0) {
        return 5.99;
    } else {
        return 2.99;
    }
}

// Example 8: Login Security Check
void checkLoginSecurity(int failedAttempts)
{
    if (failedAttempts == 0) {
        printf("Welcome back!\n");
    } else if (failedAttempts < 3) {
        printf("Please try again\n");
    } else if (failedAttempts < 5) {
        printf("Warning: Multiple failed attempts\n");
    } else {
        printf("Account temporarily locked\n");
    }
}

// Example 9: Priority Queue System
void assignPriority(int urgency)
{
    if (urgency >= 9) {
        printf("Priority: CRITICAL\n");
    } else if (urgency >= 7) {
        printf("Priority: HIGH\n");
    } else if (urgency >= 4) {
        printf("Priority: MEDIUM\n");
    } else if (urgency >= 2) {
        printf("Priority: LOW\n");
    } else {
        printf("Priority: MINIMAL\n");
    }
}

// Example 10: Weather Condition Checker
void weatherAdvice(int humidity, int temperature)
{
    if (humidity > 80 && temperature > 25) {
        printf("Hot and humid - stay hydrated!\n");
    } else if (humidity > 60) {
        printf("Humid conditions\n");
    } else if (temperature > 30) {
        printf("Very hot weather\n");
    } else if (temperature < 10) {
        printf("Cold weather\n");
    } else if (humidity < 30) {
        printf("Dry conditions\n");
    } else {
        printf("Moderate weather conditions\n");
    }
}

int main()
{
    printf("10 Examples of else if statements in C\n");
    printf("=====================================\n\n");

    // Example 1
    printf("Example 1 - Grade Calculator:\n");
    printf("Score 85: %s\n", getGrade(85));
    printf("Score 72: %s\n\n", getGrade(72));

    // Example 2
    printf("Example 2 - Temperature Classification:\n");
    describeTemperature(25.5);
    describeTemperature(5.0);
    printf("\n");

    // Example 3
    printf("Example 3 - Age Category:\n");
    categorizeAge(16);
    categorizeAge(45);
    printf("\n");

    // Example 4
    printf("Example 4 - Traffic Light Control:\n");
    trafficLightControl(15);
    trafficLightControl(3);
    printf("\n");

    // Example 5
    printf("Example 5 - File Size Formatter:\n");
    formatFileSize(2048576);
    formatFileSize(512);
    printf("\n");

    // Example 6
    printf("Example 6 - BMI Calculator:\n");
    calculateBMI(70.0, 1.75);
    calculateBMI(85.0, 1.75);
    printf("\n");

    // Example 7
    printf("Example 7 - Shipping Cost:\n");
    printf("15kg weight: $%.2f\n", calculateShippingCost(15.0));
    printf("3kg weight: $%.2f\n\n", calculateShippingCost(3.0));

    // Example 8
    printf("Example 8 - Login Security:\n");
    checkLoginSecurity(1);
    checkLoginSecurity(6);
    printf("\n");

    // Example 9
    printf("Example 9 - Priority System:\n");
    assignPriority(8);
    assignPriority(3);
    printf("\n");

    // Example 10
    printf("Example 10 - Weather Advice:\n");
    weatherAdvice(85, 28);
    weatherAdvice(45, 15);
    printf("\n");

    return 0;
}

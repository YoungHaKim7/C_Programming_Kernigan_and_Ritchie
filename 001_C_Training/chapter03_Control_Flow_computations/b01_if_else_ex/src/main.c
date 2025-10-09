#include <stdio.h>

char* getTrafficLightAction(int duration)
{
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

int main(void)
{

    int z = 42;
    printf("z : %d\n", z);

    char* res = getTrafficLightAction(90);

    printf("res: %s\n", res);

    return 0;
}

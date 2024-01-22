#include <stdio.h>
#define swap(t, x, y) { t temp = x; x = y; y = temp; }

int main() 
{
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);

    // Using the swap macro
    swap(int, a, b);

    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}


#include <stdio.h>

/**
 * @brief Macro to swap two values of type t.
 * @param[in] t The type of the values to be swapped.
 * @param[in,out] x The first value to be swapped.
 * @param[in,out] y The second value to be swapped.
 */
#define swap(t, x, y) { t temp = x; x = y; y = temp; }

int main() {
    int a = 11, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(int, a, b);

    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}


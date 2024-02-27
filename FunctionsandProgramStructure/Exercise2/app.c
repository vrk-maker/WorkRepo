
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 100

/* Function prototypes */
double custom_atof(char s[]);

/* Main function */
int main() {
    double sum;
    char line[MAXLINE];

    printf("Enter string: ");
    printf("\n");

    fgets(line, MAXLINE, stdin);

    int len = strlen(line);
    printf("Length = %d", len);
    printf("\n");

    sum = 0; // Initialize sum to zero

    sum += custom_atof(line);
    printf("Floating-point value = %lf", sum);

    return 0;
}

/* custom_atof: convert string s to double */
/**
 * @brief Converts a string to a double value.
 * @param[in] s The character array to be converted to a double.
 * @return The double value represented by the input string.
 */
double custom_atof(char s[]) {
    double val, power, res;
    int i, sign;

    // Skip leading white spaces
    for (i = 0; isspace(s[i]); i++)
        ;

    // Determine the sign of the number
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    // Process the digits before the decimal point
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    // Process the decimal point and digits after it
    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    // Process scientific notation (e.g., 123.45e-6)
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        int expSign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
            i++;

        int exponent = 0;
        while (isdigit(s[i])) {
            exponent = 10 * exponent + (s[i] - '0');
            i++;
        }

        res = pow(10, expSign * exponent);
    }

    // Calculate the final floating-point value
    return (val / power) * res;
}

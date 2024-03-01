#include <stdarg.h>
#include <stdio.h>

void minprintf(char *fmt, ...);

int main(void) {
    char a[100];
    printf("Enter a string: ");
    scanf("%s", a);
    minprintf("%s", a);
    printf("\n");
    
    int i;
    printf("Enter an integer: ");
    scanf("%d", &i);
    minprintf("%d", i);
    printf("\n");
    
    int b;
    printf("Enter an integer to convert to octal: ");
    scanf("%d", &b);
    minprintf("%o", b);
    printf("\n");
    
    char c[100];
    printf("Enter a string: ");
    scanf("%s", c);
    minprintf("%s", c);
    printf("\n");
    
    float z;
    printf("Enter a floating-point number: ");
    scanf("%f", &z);
    minprintf("%f", z);
    printf("\n");
    
    return 0;
}

/**
 * @brief Prints formatted output to the standard output stream.
 * @param[in] fmt A format string containing format specifiers.
 * @param[in] ... Variable number of arguments.
 */
void minprintf(char *fmt, ...) {
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'o':
                ival = va_arg(ap, int);
                printf("%o", ival);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* clean up when done */
}


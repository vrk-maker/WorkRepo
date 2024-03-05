#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100   /**< Maximum length of input line */
#define NUMBER '0'    /**< Code indicating a number */
#define MAXVAL 100    /**< Maximum stack depth */

int sp = 0;
//int bufp = 0;

double val[MAXVAL];
//char buf[BUFSIZE];

char variables[26]; // Array to store variables ('a' to 'z')

//int mgetLine(char[], int);

void push(double);
double pop(void);
int getop(char[]);

/* reverse polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXLINE];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
        {
            double num;
            if (sscanf(s, "%lf", &num) == 1) {
                push(num);
            } else {
                printf("Error: Invalid number format\n");
            }
            break;
        }
        // case VARIABLE: // Handle variables
        //     push(variables[s[0]]);
        //     break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(op2-pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '?':
            if (sp >= 2)
            {
                // if (val[sp - 1] == VARIABLE) {
                //     printf("topmost=%c\n", variables[s[0]]);
                //     printf("secondmost=%lf\n", val[sp - 2]);
                // }
                printf("topmost=%lf\n", val[sp - 1]);
                printf("secondmost=%lf\n", val[sp - 2]);
            }
            else
            {
                printf("insufficient elements\n");
            }
            break;
        case 'd':
            if (sp > 0)
            {
                double d = val[sp - 1];
                push(d);
                printf("topmost=%lf\n", val[sp - 1]);
                printf("second topmost=%lf\n", val[sp - 2]);
            }
            else
            {
                printf("error: stack empty\n");
            }
            break;
        case 's':
            if (sp >= 2)
            {
                printf("top=%lf and second=%lf\n", val[sp - 1], val[sp - 2]);
                double topmost = pop();       // Pop the topmost element
                double secondTopmost = pop(); // Pop the second topmost element
                push(topmost);
                push(secondTopmost);
                printf("new topmost=%lf\n", val[sp - 1]);
                printf("new secondmost=%lf\n", val[sp - 2]);
            }
            else
            {
                printf("insufficient elements\n");
            }
            break;
        case 'c':
            printf("stack cleared\n");
            sp = 0;
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/**
 * @brief Pushes a value onto the stack.
 * @param f The value to be pushed onto the stack.
 */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/**
 * @brief Pops a value from the stack.
 * @return The popped value.
 */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/**
 * @brief Gets the next operator or operand from input.
 * @param s The character array to store the input.
 * @return The type of the token read from input.
 */
int getop(char s[])
{
    int c;
    while ((scanf("%s", s)) != EOF)
    {
        if (isdigit(s[0]) || (s[0] == '-' && isdigit(s[1])))
            return NUMBER;
        else
        {
            c = s[0];
            return c;
        }
    }
    return EOF;
}

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100   /**< Maximum size of operand or operator */
#define NUMBER 0    /**< Signal that a number was found */
#define BUFSIZE 100 /**< The size of the input buffer */
#define MAXVAL 100  /**< Maximum depth of val stack */

int sp = 0;
int bufp = 0;

double val[MAXVAL];
char buf[BUFSIZE];

int getch(void);

void ungetch(int);

int getop(char[]);

void push(double);

double pop(void);

/* reverse polish calculator */

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push((op2)-pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error:zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("erro:zero divisor\n");
            break;
    
        case '?':
            printf("topmost=%lf", val[sp-1]);
            printf("\n");
            printf("secondmost=%lf", val[sp-2]);
            break;

        case 'd':
            push(val[sp-1]);
            printf("topmost=%lf", val[sp-1]);
            printf("second topmost=%lf", val[sp - 2]);
            break;

        case 's':
            if (sp >= 2) 
            {
                printf("top=%lf and second=%lf", val[sp-1], val[sp-2]);
                double topmost = pop();     // Pop the topmost element
                double secondTopmost = pop(); // Pop the second topmost element
                push(topmost);
                push(secondTopmost);
                printf("\n");
                printf("new topmost=%lf", val[sp-1]);
                printf("\n");
                printf("new secondmost=%lf", val[sp-2]);   
            }
            else
            {
                printf("insufficient elements");
            }
            break;
        
        case 'c':
            printf("\n");
            sp = 0;
            printf("stack cleared");
            break;

        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/**
 * @brief Pushes a double value onto the stack.
 * @param[in] f The double value to be pushed onto the stack.
 */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, cant push %g\n", f);
}

/**
 * @brief Pops a double value from the stack.
 * @return The double value popped from the stack.
 */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("\n");
        printf("error: stack empty");
        //return 0.0;
    }
}

/**
 * @brief Gets the next operator or operand from input.
 * @param[in] s Pointer to a character array where the operator or operand will be stored.
 * @return `NUMBER` if the input represents a number, or the character itself if it's an operator.
 */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; // not a number
    i = 0;
    if (c == '-' || isdigit(c)) // collect integer part along with '-'
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if (strcmp(s, "-") == 0)
        return '-';
    return NUMBER;
}

/**
 * @brief Pushes a character back into the buffer.
 * @param[in] c is the character to be pushed back.
 */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/**
 * @brief Retrieves a character from input or the buffer.
 * @return The character retrieved.
 */
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }


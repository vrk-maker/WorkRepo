#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100
#define NUMBER '0'

#define BUFSIZE 100

#define MAXVAL 100

int sp = 0;
int bufp = 0;

double val[MAXVAL];
char buf[BUFSIZE];

int mgetLine(char[], int); 

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
            push(pop() - op2);
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
            printf("topmost=%lf\n", val[sp - 1]);
            printf("secondmost=%lf\n", val[sp - 2]);
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

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

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

int mgetLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

char line[MAXLINE];
int li=0;
int getop(char s[])
{
    int i, c;

    if (line[li] == '\0')
        if (mgetLine(line, MAXLINE) == 0)
            return EOF;
        else
            li = 0;

    /* Skip whitespace */
    while ((s[0] = c = line[li++]) == ' ' || c == '\t')
    {
        ;
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    i = 0;

    if (isdigit(c))
        while (isdigit(s[++i] = c = line[li++]))
            ;

    if (c == '.')
        while (isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    li--;
    return NUMBER;
}


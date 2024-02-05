#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'

#define BUFSIZE 100

#define MAXVAL 100

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
            push(pop() - op2);
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

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, cant push %g\n", f);
}

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


int getop(char s[])
{
 int i ;
 int c;
 static int lastc = 0;

 if(lastc == 0)
  c = getch();
 else{
  c = lastc;
  lastc = 0;
 }

 while((s[0] = c) == ' ' || c == 't')
  c = getch();
 s[1] = '\0';

 if(!isdigit(c) && c != '.')
  return c;              
 i = 0;
 if(isdigit(c))
  while(isdigit(s[++i] = c = getch()))
   ;
 if(c == '.')

  while(isdigit(s[++i] = c = getch()))
   ;

 s[i] = '\0';
 if(c != EOF)
  lastc = c;
 return NUMBER;
}

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


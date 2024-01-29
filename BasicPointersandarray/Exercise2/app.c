#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE 1

int bufp = 0;

char buf[BUFSIZE];

int getch(void);
void ungetch(int);
float getfloat(float *);

int main()
{
	int n;
    float array[SIZE];

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);
    
	int array_length = sizeof(array) / sizeof(array[0]);
 
	for(int x=0;x<array_length;x++)
	{
    	printf("%f\t", array[x]);
	}
	return 0;
}

float getfloat(float *pf)
{
    int c, sign;
    double power;

    while (isspace(c = getch())) /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    for (*pf = 0.0; isdigit(c); c = getch())
        (*pf) = 10.0 * (*pf) + (c - '0');

    if (c == '.')
    {
        c = getch();
        for (power = 1.0; isdigit(c); c = getch())
        {
            (*pf) = 10.0 * (*pf) + (c - '0');
            power *= 10.0;
        }
        (*pf) /= power;
    }

    (*pf) *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
    	printf("ungetch: too many characters\n");
	else
    	buf[bufp++] = c;
}

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }


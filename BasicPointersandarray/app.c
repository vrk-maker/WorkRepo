#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE 5

int bufp = 0;

char buf[BUFSIZE];

int getch(void);
void ungetch(int);
int getint(int *);

int main()
{
	int n, array[SIZE];
    
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    	;
    
	int array_length = sizeof(array) / sizeof(array[0]);
 
	for(int x=0;x<array_length;x++)
	{
    	printf("%d\t",array[x]);
	}
	return 0;
}



/* getint: get next integer from input into *pn */

int getint(int *pn)
{
  int c, sign;
  while (isspace(c = getch())) /* skip white space */
  ;
 
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
	//ungetch(c); /* it is not a number */
	return 0;
  }
 
  sign = (c == '-') ? -1 : 1;
 
  if (c == '+' || c == '-')
	c = getch();
 
  if (!isdigit(c))
  {
	ungetch(sign == 1 ? '+' : '-'); /* push back the sign character */
	return 0;
   }
 
  for (*pn = 0; isdigit(c) && c != EOF; c = getch())
	*pn = 10 * (* pn) + (c - '0');
 
  //(*pn) *= sign;
 
  if (c != EOF)
	ungetch(c);
    
  return *pn;
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
    	printf("ungetch: too many characters\n");
	else
    	buf[bufp++] = c;
}

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }


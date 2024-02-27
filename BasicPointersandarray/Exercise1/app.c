#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100 /**< The size of the input buffer. */
#define SIZE 5      /**< The size of the array to store integers. */

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




/**
 * @brief Reads an integer from input.
 * @param[in] pn Pointer to the integer read.
 * @return The integer read, or 0 if it fails to read.
 */
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
 
  (*pn) *= sign;
 
  if (c != EOF)
	ungetch(c);
    
  return *pn;
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


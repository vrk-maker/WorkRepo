#include "head.h"
#include <stdio.h>
int main()
{
	int x= 10, y = 20;
	printf("%d + %d = %d", x, y, add(x, y));
	printf("\n%d - %d = %d", x, y, sub(x, y));
	printf("\n%d * %d = %d", x, y, mul(x, y));
	printf("\n%d / %d = %d", x, y, div(x, y));
	return 0;
}

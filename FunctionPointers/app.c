#include <stdio.h>


/**
 * @brief Adds two integers.
 * @param[in] x An integer.
 * @param[in] y An integer.
 * @return The sum of x and y.
 */
int func(int x,int y)
{
    return x+y;
}
int main()
{
    int (*ptr)(int,int);
    ptr=&func;
    int num1,num2;
    printf("enter first number:");
    scanf("%d",&num1);
    printf("enter second number:");
    scanf("%d",&num2);
    printf("\n");
    int res=ptr(num1,num2);
    printf("sum=%d\n",res);
    return 0;
}
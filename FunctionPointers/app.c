#include <stdio.h>

/**
 * @brief Adds two integers.
 * @param[in] fvalue An integer.
 * @param[in] svalue An integer.
 * @return The sum of fvalue and svalue.
 */
int func(int fvalue,int svalue)
{
    return fvalue + svalue;
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
    int res=(*ptr)(num1,num2);
    printf("sum=%d\n",res);
    return 0;
}
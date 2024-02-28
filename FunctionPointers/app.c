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
    int res=ptr(10,20);
    printf("sum=%d\n",res);
    return 0;
}
#include <stdio.h>

/**
 * @brief Function to calculate the sum of two integers.
 * 
 * @param[in] a First integer.
 * @param[in] b Second integer.
 * @return Sum of the two integers.
 */
int sum(int a,int b)
{
    return a+b;
}

/**
 * @brief Function to get the sum of two integers using a function pointer.
 * 
 * @param[in] ptr Function pointer to the sum function.
 */
void getsum(int (*ptr)(int,int))
{
    int x,y;
    printf("x=");
    scanf("%d",&x);
    printf("y=");
    scanf("%d",&y);
    printf("sum of two values=%d\n",ptr(x,y));
}


int main()
{
    int (*ptr)(int,int);
    ptr=&sum;
    getsum(ptr);
    return 0;
}
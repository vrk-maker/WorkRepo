#include <stdio.h>
#include <math.h>
#define PI 3.14159265 /**< Value of pi */
int main()
{
    double x=12.0,result,y=60.0,ans,val;
    //pow
    printf("Value 2 ^ 3 = %lf\n", pow(2, 3));
    //The ex in mathematics is equal to exp(x)
    result=exp(x);
    printf("exponential value = %lf\n",result);
    //sin cosine
    val = PI / 180.0; 
    ans = cos(y * val); 
    printf("The cosine of %lf is %lf degrees\n", y, ans); 
    ans = sin(y * val);
    printf("The sine of %lf is %lf degrees\n", y, ans);
}


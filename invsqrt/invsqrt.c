#include <stdio.h>
#include <math.h>

float invsqrt(float x)
{
    float xhalf = 0.5f * x;
    long i = *(long*) &x;
    i = 0x5f3759df - (i >> 1);
    x = *(float*) &i;
    x = x * (1.5f - xhalf * x * x);
    //x = x * (1.5f - xhalf * x * x);
    return x;
}

int main()
{
    printf("1/sqrt(2)\n");
    printf("naive: %f\n", 1.0f/sqrt(2.0f));
    printf("approximation: %f\n", invsqrt(2.0f));
    return 0;
}

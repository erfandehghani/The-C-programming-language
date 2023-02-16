/* print Fahrenheit-Celsius table for fahr = 0, 20, 40, ... , 300: floating point version */

#include <stdio.h>;

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* Lower limit of temperature table */
    upper = 300;    /* Upper limit of temperature table */
    step = 20;      /* Step size */

    fahr = lower;

    while(fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n",fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
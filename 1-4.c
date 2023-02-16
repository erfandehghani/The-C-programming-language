/* print Celsius-Fahrenheit table for Celsius = 0, 20, 40, ... , 300: floating point version */

#include <stdio.h>;

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* Lower limit of temperature table */
    upper = 300;    /* Upper limit of temperature table */
    step = 20;      /* Step size */

    celsius = lower;

    printf("Celsius Fahr\n");

    while(celsius <= upper)
    {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n",celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
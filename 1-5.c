/* print Fahrenheit-Celsius table for fahr = 300, 280, 260, ..., 0: for version */

#include <stdio.h>;

#define UPPER   300
#define LOWER   0
#define STEP    20

int main()
{
    int fahr;

    printf("Fahr Celsius\n");

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
        printf("%3d %6.1f\n",fahr, (5.0/9.0) * (fahr - 32.0));

    return 0;
}
// This program was ment for checking the value of EOF

#include "stdio.h"

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }

    return 0;
}
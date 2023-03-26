// Replaces a group of blank spaces with a single blank space

#include "stdio.h"

int main()
{
    int c, lastc;

    while ((c = getchar()) != EOF)
    {

        if (c != 32)
            putchar(c);

        else
            if(lastc != 32)
                putchar(c);

        lastc = c;

    }

    return 0;
}
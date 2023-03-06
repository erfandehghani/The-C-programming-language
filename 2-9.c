#include "stdio.h"
#include "bitcount.c"

int main()
{
    int input;
    while ((input = (getchar() - '0')) != EOF)
        if (input != ('\n' - '0'))
            printf("%3d\n", bitcount(input));
}
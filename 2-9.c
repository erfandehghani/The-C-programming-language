#include "stdio.h"
#include "bitcount.c"

int main()
{
    int input;
    while (1)
    {
        scanf("%d",&input);
        printf("%3d\n", bitcount(input));
    }
}
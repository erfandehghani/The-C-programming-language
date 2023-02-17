// Counting blank spaces, lines and tabs in a text

#include "stdio.h"

int main()
{
    int c;
    int nb, nl, nt = 0;

    while ((c = getchar()) != EOF)
    {
        if(c == 32)
            nb++;
        if(c == 10)
            nl++;
        if(c == 9)
            nt++;
        }

    printf("Number of blank spaces: %d\nNumber of lines: %d\nNumber of tabs: %d", nb, nl, nt);
    getchar();
    return 0;
}
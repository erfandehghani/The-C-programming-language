//This program is designed to replace tabs with \t, replace backspace

#include "stdio.h"

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
            printf("\\t");
        if (c == 8)
            printf("\\b");
        if (c == 92)
            printf("\\\\");
        if (c != 92 && c != 8 && c != 9)
            putchar(c);
    }

}
// this is a program that outputs its input text one word per line

#include "stdio.h"

#define IN 1
#define OUT 0

int main()
{

    int c;
    int state = OUT;

    while ((c = getchar()) != EOF)
    {

        if (c != ' ')
        {
            state = IN;
            putchar(c);
        }
        else
            state = OUT;

        if (state == OUT)
            printf("\n");
    }

}
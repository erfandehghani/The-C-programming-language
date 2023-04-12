#include "stdio.h"

union a {
    float f;
    char ch;
};

int main()
{
    union a test;

    test.f = 152.54;

    unsigned char *character = (unsigned char *) &test.f;

    int x = sizeof(test.f);
    int count = 1;

    while (x-- > 0)
    {
        printf("Byte Number %d: %c\tASCII Code: %4d\tBinary code of: ", count++, *character, (int)*character);
        for (int i = 7; i >= 0; i--) {
            printf("%d", (*character >> i) & 1);
        }
        printf("\n");
        character++;
    }

}
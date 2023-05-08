#include "stdio.h"

union {
    float fp;
    unsigned char ch;
    unsigned char string[4];
    int i;
}test;

int main()
{

    test.fp = 1023;

    int x = sizeof(test);
    int count = 3;

    for (int i = 0; i < 4; ++i) {
        printf("%d\n", test.string[i]);
    }

    printf("\n\n\n");

    while (x-- > 0)
    {
        for (int i = 7; i >= 0; i--) {
            printf("%d", (*(&(test.ch)+count) >> i) & 1);
        }
        printf(",");
        count--;
    }

}
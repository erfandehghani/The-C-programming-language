// This program was ment for checking the value of getchar() != EOF

#include "stdio.h"

int main()
{

    int c = getchar();

    printf("\n%d \n",(c != EOF));

    return 0;
}
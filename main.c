#include "stdio.h"
#include "usefulFuncs.h"
#include "3-1(BinarySearch).h"
#include "escape.h"

#define MAXIMUM_CHARACTER_COUNT 1000

int main()
{

//    Binary search example

//    int array[101];
//    initArray(array, 101);
//    printf("%d\n", binarySearch(0, array, 101));


    char line[MAXIMUM_CHARACTER_COUNT];
    char lineEscaped[MAXIMUM_CHARACTER_COUNT];
    char lineRevEscaped[MAXIMUM_CHARACTER_COUNT];
    int lineSize;

    while ((lineSize = getLine(line, MAXIMUM_CHARACTER_COUNT)) > 1)
    {
        escape(line,lineEscaped);
        reverseEscape(lineEscaped, lineRevEscaped);
    }



    printf("%s\t <-- the escaped line\n",lineEscaped);
    printf("%s\t <-- revEscaped line\n",lineRevEscaped);
}
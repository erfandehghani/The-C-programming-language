#include <stdio.h>
#include "usefulFuncs.h"
#include "Chapter 3/3-1(BinarySearch).h"
#include "Chapter 3/3-2(escape and reverseEscape).h"
#include "Chapter 3/3-3(Expanding- Signs).h"
#include "Chapter 4/4-1(strIndex).h"
#include "Chapter 4/4-2(atof).h"
#include "5-1 (getint).c"

#define MAX_LINE_LENGTH 1000                    /* MAXIMUM INPUT SIZE */

int main() {

//    Binary search example
//    int array[101];
//    initArray(array, 101);
//    printf("%d\n", binarySearch(0, array, 101));


//  Escape and Reverse Escape Example
//    char line[MAXIMUM_CHARACTER_COUNT];
//    char lineEscaped[MAXIMUM_CHARACTER_COUNT];
//    char lineRevEscaped[MAXIMUM_CHARACTER_COUNT];
//    int lineSize;
//    while ((lineSize = getLine(line, MAXIMUM_CHARACTER_COUNT)) > 1)
//    {
//        escape(line,lineEscaped);
//        reverseEscape(lineEscaped, lineRevEscaped);
//    }
//    printf("%s\t <-- the escaped line\n",lineEscaped);
//    printf("%s\t <-- revEscaped line\n",lineRevEscaped);


//  replacing a-z and such symbols with a,b,c,d,...,x,y,z
//    char inputLine[MAX_LINE_LENGTH];
//    char outputLine[MAX_LINE_LENGTH];
//
//    getLine(inputLine,MAX_LINE_LENGTH);
//
//    expandSigns(inputLine,outputLine);
//    printf("%s\n",outputLine);

//    strIndex test
//    char line[MAX_LINE_LENGTH];
//    char pattern[MAX_LINE_LENGTH] = "test";
//
//    while(getLine(line,MAX_LINE_LENGTH) != 0)
//    {
//        printf("%d\n", strIndex(line, pattern));
//    }



//    atof test
//    char line[MAX_LINE_LENGTH];
//    getLine(line, MAX_LINE_LENGTH);
//    printf("%lf", atof(line));


//    test for getint function in 5-1(getint).c
    int x = getint(&x);
    if (x != 0)
        printf("Your number id: %d\n", x);
    else
        printf("No number found\n");

    getchar();
    return 0;
}
#include "stdio.h"
#include "usefulFuncs.h"
#include "3-1(BinarySearch).h"
#include "3-2(escape and reverseEscape).h"
#include "3-3(Expanding- Signs).h"

#define MAX_LINE_LENGTH 1000                    /* MAXIMUM INPUT SIZE */

void expandSigns(char inputLineOfString[], char exportedLineOFString[]);
int isACharacterThatWeCover(char ch);

int main()
{

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
    char inputLine[MAX_LINE_LENGTH];
    char outputLine[MAX_LINE_LENGTH];

    getLine(inputLine,MAX_LINE_LENGTH);

    expandSigns(inputLine,outputLine);
    printf("%s\n",outputLine);

}
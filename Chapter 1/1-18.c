#include "stdio.h"
#include "../usefulFuncs.h"

#define MAX_LINE_LENGTH 1000        /* MAXIMUM INPUT SIZE */
#define MAX_LINE_COUNT 100          /* Maximum number if lines that can be in the input */

void removeBlankSpacesAndTabsFromLine(char line[], int lineSize);

int main()
{
    int length, linesCount;
    int linesLength[MAX_LINE_COUNT];

    char lines[MAX_LINE_COUNT][MAX_LINE_LENGTH];

    for (int i = 0; i < MAX_LINE_COUNT && (length = getLine(lines[i], MAX_LINE_LENGTH)) > 1; ++i)
    {
        linesCount = i + 1;
        linesLength[i] = length;
    }

    for (int i = 0; i < linesCount; ++i) {
        removeBlankSpacesAndTabsFromLine(lines[i],linesLength[i]);
        printf("%s",lines[i]);
    }
}

void removeBlankSpacesAndTabsFromLine(char line[], int lineSize)
{
    for (int i = 0; i < lineSize; ++i)
        if (line[i] == ' ' || line[i] == '\t')
            for (int j = i; j < lineSize; ++j)
                line[j] = line[j+1];
}
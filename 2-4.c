/* Delete all characters from s1 that are in s2 */

#include "stdio.h"
#include "usefulFuncs.h"

#define MAX_LINE_LENGTH 1000        /* MAXIMUM INPUT SIZE */
#define MAX_LINE_COUNT 100          /* Maximum number if lines that can be in the input */

void squeeze(char s1[], char s2[])
{
    int i, j;


    for(i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j])
                s2[j] = s2[j+1];
}

int main()
{
    char inputText[MAX_LINE_COUNT][MAX_LINE_LENGTH];
    int linesLength[MAX_LINE_COUNT];
    int linesCount;

    for (int i = 0; i < (linesCount =  getText(MAX_LINE_LENGTH,MAX_LINE_COUNT,inputText,linesLength)); ++i) {
        printf("%s",inputText[linesCount-1]);
    }
}
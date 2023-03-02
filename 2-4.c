/* Delete all characters from s1 that are in s2 */

#include "stdio.h"
#include "usefulFuncs.h"

#define MAX_LINE_LENGTH 1000                    /* MAXIMUM INPUT SIZE */
#define MAX_LINE_COUNT 100                      /* Maximum number of lines that can be in the input */
#define MAX_REMOVABLE_CHARS_STRING_LENGTH 10

void squeeze(char s1[], char s2[])
{
    int i, j;


    for(i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j]){
                for (int k = j; s2[k] != '\0'; ++k)
                    s2[k] = s2[k+1];
                j--;
            }
}

int main()
{
    char inputText[MAX_LINE_COUNT][MAX_LINE_LENGTH];
    int linesLength[MAX_LINE_COUNT];
    char charsWantRemoved[MAX_REMOVABLE_CHARS_STRING_LENGTH];

    printf("Enter your text:\n");
    int linesCount = getText(MAX_LINE_LENGTH,MAX_LINE_COUNT,inputText,linesLength);

    printf("Enter the string that you want tot remove chars from the text in one line:\n");
    getLine(charsWantRemoved, MAX_REMOVABLE_CHARS_STRING_LENGTH);

    for (int i = 0; i < linesCount; ++i) {
        squeeze(charsWantRemoved,inputText[i]);
    }

    for (int i = 0; i < linesCount; ++i) {
        printf("%s\n",inputText[i]);
    }

    getchar();
}
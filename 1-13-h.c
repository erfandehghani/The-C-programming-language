#include "stdio.h"
#include "usefulFuncs.h"

#define EOF '\n'
#define IN_WORD 1
#define OUT_WORD 0
#define WORD_INPUT_THRESHOLD 10

int main()
{
    int c;
    int inputWordsCharacterCounts[WORD_INPUT_THRESHOLD];
    int state = OUT_WORD;
    int wordsCount = 0;
    int wordCharactersCount = 0;


    initArray(inputWordsCharacterCounts, WORD_INPUT_THRESHOLD);

    while ((c = getchar()) != EOF)
    {
        if (state == OUT_WORD && c != ' ')
            wordsCount++;

        if (c != ' ' && c != '\n' && c != '\t')
        {
            wordCharactersCount++;
            inputWordsCharacterCounts[wordsCount - 1] = wordCharactersCount;
            state = IN_WORD;
        }
        else
        {
            state = OUT_WORD;
            wordCharactersCount = 0;
        }

    }


    for (int i = 0; i < WORD_INPUT_THRESHOLD; ++i)
    {
        for (int j = 0; j < inputWordsCharacterCounts[i]; ++j)
        {
            printf("%c",254);
        }
        printf("\n");
    }

    return 0;
}
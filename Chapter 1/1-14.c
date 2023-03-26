#include "stdio.h"
#include "../usefulFuncs.h"

#define EOF '\n'
#define CHARACTER_MAX_COUNT ('z' - 'a' + 3)
#define SPACE_CHARACTER_INDEX 27
#define TAB_CHARACTER_INDEX 26

int main()
{
    int c;
    int characterCount[CHARACTER_MAX_COUNT];

    initArray(characterCount, CHARACTER_MAX_COUNT);

    while ((c = getchar()) != EOF)
    {
        int characterIndex;

        if (c == ' ')
            characterIndex = SPACE_CHARACTER_INDEX;
        if (c == '\t')
            characterIndex = TAB_CHARACTER_INDEX;
        else
            characterIndex = 25 - ('z' - c);

        characterCount[characterIndex]++;
    }


    for (int i = 0; i < CHARACTER_MAX_COUNT; ++i)
    {
        if (characterCount[i] > 0)
        {
            int characterASCIICode = i + 'a';

            printf("%2c\tcount:%d-> ", characterASCIICode, characterCount[i]);

            for (int j = 0; j < characterCount[i]; ++j)
            {
                printf("%c",254);
            }

            printf("\n");
        }
    }

    return 0;
}
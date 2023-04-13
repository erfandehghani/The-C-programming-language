#include <ctype.h>
#include <stdio.h>
#include "A_Z_SHAPES.c"

#define MAX_NUMBER_OF_CHARS_IN_ONE_LINE 100

void convertToShape(char *character, int fillCharacter);
int getLine(char s[], int lim);


int main()
{
    printf("Please enter your fill character(it will read only one character!): ");
    char chosenCharacter[2];
    getLine(chosenCharacter,2);

    printf("Please enter Your text in one line: ");
    char text[200];
    int length = 0;
    while ((length = getLine(text,200)) != 0)
    {
        printf("\n");
        printf("\n");

        convertToShape(text, chosenCharacter[0]);
    }


    getchar();
    return 0;
}

void convertToShape(char *string, int fillCharacter) {

    char bigLine[10][ROWS][MAX_NUMBER_OF_CHARS_IN_ONE_LINE];
    int letter_index;
    int bigLineOffset = 0;
    int line = 0;

    for (int x = 0; x < 10; ++x) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < MAX_NUMBER_OF_CHARS_IN_ONE_LINE; ++j) {
                bigLine[x][i][j] = ' ';
            }
        }
    }

    while (*string != '\0')
    {
        letter_index = (*string == ' ') ? 26 : toupper(*string) - 'A';

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLUMNS; ++j)
            {
                if (letter_shapes[letter_index][i][j] == 1)
                    bigLine[line][i][bigLineOffset + j] = fillCharacter;
                else
                    bigLine[line][i][bigLineOffset + j] = ' ';
            }

        bigLineOffset += 7;
        if (bigLineOffset > MAX_NUMBER_OF_CHARS_IN_ONE_LINE)
        {
            bigLineOffset = 0;
            line++;
        }

        string++;
    }

    for (int x = 0; x <= line; ++x) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < MAX_NUMBER_OF_CHARS_IN_ONE_LINE; ++j)
                printf("%c", bigLine[x][i][j]);
            printf("\n");
        }
        printf("\n");
    }
}

int getLine(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    s[i] = '\0';
    return i;
}
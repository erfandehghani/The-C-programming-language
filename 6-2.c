#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdlib.h"
#include "usefulFuncs.h"

#define MAXWORD 1000
#define MAX_NUMBER_OF_WORDS_IN_STRUCT 5000
#define MAX_NUMBER_STRUCTS 5000

struct variableGroup {
    char *word[MAX_NUMBER_OF_WORDS_IN_STRUCT];
    int count;
};

struct variableGroup *variableGroupsList[MAX_NUMBER_STRUCTS];
int numberOfSavedVariables = 0;

int getword(char *, int);
char *checkArgs(char *argv[], int argc, char *pattern);

int main(int argc, char *argv[]) {

    int numberOfChars = 2;
    char word[MAXWORD];
    char *variableTypes[] = {
            "int",
            "char",
            "double",
            "float",
    };
    char *arg;

    if ((arg = checkArgs(argv, argc, "-n")) != 0)
    {
        while(*arg++ != '=')
            ;
        if(isdigit(*arg))
        {
            numberOfChars = atoi(arg);
        }
    }

    while (getword(word, MAXWORD) != EOF)
    {
        for (int j = 0; j < 4; ++j)
            if(strcmp(variableTypes[j], word) == 0)
            {
                getword(word, MAXWORD);
                char potentialVariableName[MAXWORD];
                strcpy(potentialVariableName, word);
                if (strlen(word) > numberOfChars && *word != '#' && *word != '/' && *word != '\'' && *word != '\"')
                {
                    getword(word, MAXWORD);
                    if (*word == ';' || *word == '=')
                    {
                        if(numberOfSavedVariables > 0)
                        {
                            int initialNCharsMatch = 0;
                            for (int i = 0; i < numberOfSavedVariables; ++i) {
                                if (strncmp(potentialVariableName, *(*variableGroupsList[i]).word, numberOfChars) == 0)
                                {
                                    initialNCharsMatch = 1;
                                    int foundExactMatch = 0;

                                    for (int k = 0; k < (*variableGroupsList[i]).count; ++k)
                                        if(strcmp((*variableGroupsList[i]).word[k],potentialVariableName) == 0)
                                        {
                                            foundExactMatch = 1;
                                            break;
                                        }

                                    if (foundExactMatch) {
                                        break;
                                    }

                                    char *newWord = malloc(strlen(potentialVariableName) + 1);
                                    strcpy(newWord, potentialVariableName);
                                    (*variableGroupsList[i]).word[(*variableGroupsList[i]).count] = newWord;
                                    (*variableGroupsList[i]).count++;
                                }
                            }
                            if(initialNCharsMatch == 0)
                            {
                                struct variableGroup *newGroup = malloc(sizeof(struct variableGroup));
                                char *newWord = malloc(strlen(potentialVariableName) + 1);
                                strcpy(newWord, potentialVariableName);
                                *(*newGroup).word = newWord;
                                (*newGroup).count = 1;
                                variableGroupsList[numberOfSavedVariables] = newGroup;
                                numberOfSavedVariables++;
                            }
                        }
                        else
                        {
                            struct variableGroup *newGroup = malloc(sizeof(struct variableGroup));
                            char *newWord = malloc(strlen(potentialVariableName) + 1);
                            strcpy(newWord, potentialVariableName);
                            *(*newGroup).word = newWord;
                            (*newGroup).count = 1;
                            variableGroupsList[numberOfSavedVariables] = newGroup;
                            numberOfSavedVariables++;
                        }
                    }
                }
            }
    }

    for (int j = 0; j < numberOfSavedVariables; ++j)
        if((*variableGroupsList[j]).count > 1)
            while ((*variableGroupsList[j]).count-- > 0)
                printf("result: %s\n", (*variableGroupsList[j]).word[(*variableGroupsList[j]).count]);
    getchar();
}

int getword(char *word, int lim)
{
    int c, output;
    char *w = word;
    char *tempChar;

    while (isspace(c = getch()))
        ;

    if (c != EOF)
        *w++ = c;
    else
        return EOF;

    if (!isalpha(c))
    {
        /* Comment handling */
        if (c == '/')
        {
            /* Multiline comments */
            if ((*w++ = c = getch()) == '*')
            {
                while ((*w = getch()) != EOF)
                {
                    if (*w == '*')
                        tempChar = w;

                    if (*w == '/')
                        if ((++tempChar) == w)
                        {
                            w++;
                            break;
                        }

                    w++;
                }
            }

                /* Single line comments */
            else if (c == '/')
            {
                while ((*w++ = getch()) != '\n')
                    ;
                w--;
            }

            output = word[0];
        }

        /* Handling preprocessors */
        else if (c == '#')
        {
            while ((*w++ = getch()) != '\n')
                ;
            w--;
            output = word[0];
        }

        /* Handling strings with double quotations */
        else if (c == '\"')
        {
            while ((*w++ = getch()) != '\"')
                ;
            output = word[0];
        }

        /* Handling strings with quotations */
        else if (c == '\'')
        {
            while ((*w++ = getch()) != '\'')
                ;
            output = word[0];
        }

        else
            output = word[0];

        *w = '\0';
        return output;
    }

    while (--lim > 0)
    {
        if(!isalnum(*w = getch()) && *w != '_')
        {
            ungetch(*w);
            break;
        }
        w++;
    }

    *w = '\0';
    return word[0];
}

char *checkArgs(char *argv[], int argc, char *pattern)
{
    for (int i = 1; i < argc; ++i)
        if (strncmp(argv[i], pattern, 2) == 0)
            return argv[i];
    return 0;
}
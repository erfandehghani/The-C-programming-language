#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "usefulFuncs.h"

#define MAXWORD 100

struct key {
    char *word;
    int count;
} keytab[] = {
        { "auto", 0 }, { "break", 0 }, { "case", 0 }, { "char", 0 },
        { "const", 0 }, { "continue", 0 }, { "default", 0 }, { "double", 0 }, { "else", 0 },
        { "enum", 0 }, { "extern", 0 }, { "float", 0 }, { "for", 0 },
        { "goto", 0 }, { "if", 0 }, { "int", 0 }, { "long", 0 },
        { "register", 0 }, { "return", 0 }, { "short", 0 }, { "signed", 0 },
        { "sizeof", 0 }, { "static", 0 }, { "struct", 0 }, { "switch", 0 },
        { "typedef", 0 }, { "union", 0 }, { "unsigned", 0 }, { "void", 0 },
        { "volatile", 0 }, { "while", 0 }
};

#define NKEYS (sizeof keytab / sizeof keytab[0])

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main()
{
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;

    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);

    getch();
    return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
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
            output = c;

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
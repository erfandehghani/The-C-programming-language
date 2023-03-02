#ifndef THE_C_PROGRAMMING_LANGUAGE_USEFULFUNCS_H
#define THE_C_PROGRAMMING_LANGUAGE_USEFULFUNCS_H
#endif //THE_C_PROGRAMMING_LANGUAGE_USEFULFUNCS_H

int getASCIICode(char character);
void initArray(int array[], int size);
void printArray(int array[], int size);

int getLine(char s[], int lim);
void copy(char to[], char from[]);

int getASCIICode(char character)
{
    printf("%d\n", character);
}

void initArray(int array[], int size)
{
    for (int i = 0; i < size; ++i) {
        array[i] = 0;
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d\t", array[i]);
    }
}

int getLine(char s[], int lim)
{
    int c, i;
    for(i = 0; i < lim && (c = getchar()) != EOF && c != '\n' ; i++)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

int getText(int maxLengthOfALine, int maxLinesCount, char textLineByLine[maxLinesCount][maxLengthOfALine], int textLinesLength[maxLinesCount])
{
    int length,linesCount;

    for (int i = 0; i < maxLinesCount && (length = getLine(textLineByLine[i], maxLengthOfALine)) > 1; ++i)
    {
        linesCount = i + 1;
        textLinesLength[i] = length;
    }
    return linesCount;
}
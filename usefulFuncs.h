#ifndef THE_C_PROGRAMMING_LANGUAGE_USEFULFUNCS_H
#define THE_C_PROGRAMMING_LANGUAGE_USEFULFUNCS_H
#endif //THE_C_PROGRAMMING_LANGUAGE_USEFULFUNCS_H

int getASCIICode(char character);
void initArray(int array[], int size);
void printArray(int array[], int size);
int isCharArrayEqual(char firstArray[] ,char secondArray[]);
int getLine(char s[], int lim);
void copy(char to[], char from[]);
int getCharArraySize(char array[]);

int getASCIICode(char character)
{
    printf("%d\n", character);
}

void initArray(int array[], int size)
{
    for (int i = 0; i < size; ++i) {
        array[i] = i;
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

int isCharArrayEqual(char firstArray[] ,char secondArray[])
{
    int firstArraySize = getCharArraySize(firstArray);
    int secondArraySize = getCharArraySize(secondArray);

    if (firstArraySize == secondArraySize)
        for (int i = 0; firstArray[i] != '\0'  ; ++i) {
            if (firstArray[i] != secondArray[i])
                return 0;
        }
    else
        return 0;

    return 1;
}

int getCharArraySize(char array[])
{
    int i;
    for (i = 0; array[i] != '\0'; ++i)
        ;
    return i;
}
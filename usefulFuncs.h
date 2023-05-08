#ifndef USEFULFUNCS_H
#define USEFULFUNCS_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 100

int nextFreePositionInBuffer = 0;
char buffer[BUFFER_SIZE];

int getASCIICode(char character);
void initArray(int array[], int size);
void printArray(int array[], int size);
int isCharArrayEqual(char firstArray[], char secondArray[]);
int getLine(char s[], int lim);
void copy(char to[], char from[]);
int getCharArraySize(char array[]);
int isInEnglishAlphabet(char ch);
int isDigit(char ch);
int getch(void);
void ungetch(int c);

int getASCIICode(char character) {
    printf("%d\n", character);
}

void initArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d\t", array[i]);
    }
}

int getLine(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    s[i] = '\0';
    return i-1;
}

void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}


int isCharArrayEqual(char firstArray[], char secondArray[]) {
    return strcmp(firstArray, secondArray) == 0;
}

int getCharArraySize(char array[]) {
    int i;
    for (i = 0; array[i] != '\0'; ++i)
        ;
    return i;
}

int isInEnglishAlphabet(char ch) {
    return isalpha(ch);
}

int isDigit(char ch) {
    return isdigit(ch);
}

int getch(void) {
    return (nextFreePositionInBuffer > 0) ? buffer[--nextFreePositionInBuffer] : getchar();
}

void ungetch(int c) {
    if (nextFreePositionInBuffer >= BUFFER_SIZE)
        printf("ungetch: too many characters\n");
    else
        buffer[nextFreePositionInBuffer++] = c;
}

#endif // USEFULFUNCS_H
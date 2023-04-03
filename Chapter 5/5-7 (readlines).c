#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../usefulFuncs.h"

#define MAXLINES 5000 /* max number of lines to be sorted */
#define MAXLEN 1000 /* max length of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */
char lines[MAXLINES][MAXLEN];

int readlines(char *lineptr[], char lines[][MAXLEN], int nlines);
void writelines(char *lineptr[], int nlines);

void quicksort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */

    if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
        quicksort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], char lines[][MAXLEN], int maxlines)
{
    int len, nlines;

    nlines = 0;
    for (int i = 0; (len = getLine(lines[i], MAXLEN)) > 0; ++i) {
        if (nlines >= maxlines)
            return -1;
        else {
            lines[i][len-1] = '\0'; /* delete newline */
            lineptr[nlines++] = lines[i];
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* quicksort: sort v[left]...v[right] into increasing order */
void quicksort(char *lineptr[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(lineptr, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, ++last, i);
    swap(lineptr, left, last);
    quicksort(lineptr, left, last-1);
    quicksort(lineptr, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
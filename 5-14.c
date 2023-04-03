#include <stdio.h>
#include <string.h>
#include "stdlib.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void quicksort(void *lineptr[], int left, int right,int (*comp)(void *, void *));

int numcmp(const char *, const char *);

void reversearray(char *lineptr[] ,int nlines);

// gcc 38.pointers-to-functions.c numcmp.c readlines-writelines.c 6.alloc.c
int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;

    for (int i = 1; i < argc; ++i) {
        if(strcmp(argv[i], "-n") == 0)
        {
            numeric = 1;
            printf("Found a numeric\n");
        }
        if(strcmp(argv[i], "-r") == 0)
        {
            printf("Found a reverse\n");
            reverse = 1;
        }
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        quicksort((void **) lineptr, 0, nlines-1,(int (*)(void*, void*))(numeric ? numcmp : strcmp));
        if (reverse){
            if (numeric)
                reversearray(lineptr, nlines - 1);
            else
                printf("you cant reverse an array that is not a number...\n");
        }
        writelines(lineptr, nlines);
        getchar();
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

void quicksort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    quicksort(v, left, last-1, comp);
    quicksort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
#define MAXLEN 1000 /* max length of any input line */
int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

static char allocbuf[MAXLEN];
static char *allocp = allocbuf;

/* alloc: return pointer to n characters */
char *alloc(int n)
{
    if (allocbuf + MAXLEN - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else /* not enough room */
        return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c!= '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int numcmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void reversearray(char *lineptr[], int nlines)
{
    int i;
    char *temp;

    for (i = 0; i < nlines / 2; i++) {
        temp = lineptr[i];
        lineptr[i] = lineptr[nlines - i - 1];
        lineptr[nlines - i - 1] = temp;
    }
}
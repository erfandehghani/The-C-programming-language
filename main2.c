#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "math.h"
#include "usefulFuncs.h"

#define MAX_OPERATION_SIZE 100   /* Max size of the operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define BUFFER_SIZE 100
#define MAX_DEPTH_OF_STACK 100

int getch(void);
void ungetch(int);
int nextFreeStackPosition = 0;
double stack[MAX_DEPTH_OF_STACK];
char buffer[BUFFER_SIZE];
int nextFreePositionInBuffer = 0;
int getop(char []);
void push(double);
double pop(void);

//  4-3, 4-4, 4-5, 4-6 (Reverse Polish Calculator)


int main()
{
    int type;
    double op2;
    char string[MAX_OPERATION_SIZE];

    while ((type = getop(string)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(string));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: divided by zero");
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':

                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: divided by zero");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("unknown command %s\n", string);
                break;
        }
    }
    return 0;
}

void push(double d)
{
    if (nextFreeStackPosition <= MAX_DEPTH_OF_STACK)
        stack[nextFreeStackPosition++] = d;
    else
        printf("Stack is full... cant push any more%g\n", d);
}

double pop()
{
    if(nextFreeStackPosition > 0)
        return stack[--nextFreeStackPosition];
    else
    {
        printf("Error: stack empty");
        return 0.0;
    }
}

int getop(char string[])
{
    int i, c;
    while ((string[0] = c = getch()) == ' ' || c == '\t')
        ;

    string[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    i = 0;

    if (c == '-'){
        if(isdigit(c = getch()) || c == '.')
            string[++i] = c;
        else
        {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
    if (isdigit(c))
        while (isdigit(string[++i] = c = getch()))
            ;

    if (c == '.')
        while (isdigit(string[++i] = c = getch()))
            ;

    string[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

int getch(void)
{
    return (nextFreePositionInBuffer >= BUFFER_SIZE) ? buffer[--nextFreeStackPosition] : getchar();
}

void ungetch(int c)
{
    if (nextFreeStackPosition >= BUFFER_SIZE)
        printf("ungetch: too many characters\n");
    else
        buffer[nextFreePositionInBuffer++] = c;
}
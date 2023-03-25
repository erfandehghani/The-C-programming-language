#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "math.h"
#include "string.h"

#define MAX_OPERATION_SIZE 100   /* Max size of the operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define BUFFER_SIZE 100
#define MAX_DEPTH_OF_STACK 100
#define COMPLEX_MATH 'e'

int getch(void);
void ungetch(int);
int nextFreeStackPosition = 0;
double stack[MAX_DEPTH_OF_STACK];
char buffer[BUFFER_SIZE];
int nextFreePositionInBuffer = 0;
int getop(char []);
void push(double);
double pop(void);
void clearStack();
void reverseLastToItemsInStack();
double complexMath(char []);

//  4-3, 4-4, 4-5, 4-6 (Reverse Polish Calculator)


int main()
{
    int type;
    double op2, op1;
    char string[MAX_OPERATION_SIZE];

    while ((type = getop(string)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(string));
                break;
            case COMPLEX_MATH:
                push(complexMath(string));
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
            case '?':
                op1 = pop();
                push(op1);
                printf("last element of the stack: %f\n",op1);
                break;
            case 'c':
                clearStack();
                break;
            case 'd':
                op1 = pop();
                push(op1);
                push(op1);
                break;
            case 's':
                reverseLastToItemsInStack();
                break;
            case 'r':
                printf("result is: %.8g\n", pop());
                break;
            case '\n':
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
        printf("Stack is empty\n");
        return 0.0;
    }
}

int getop(char string[])
{
    int i, c;
    while ((string[0] = c = getch()) == ' ' || c == '\t')
        ;


    i = 1;

    if (!isdigit(c) && c != '.' && c != '-')
    {
        while (isalpha(string[i++] = c = getch()))
            ;

        string[--i] = '\0';
        c = string[i - 1];

        if (strlen(string) == 3)
            return COMPLEX_MATH;
        else if(strlen(string) == 1)
            return c;
        else
            printf("Unknown Command: %s\n", string);
    }

    string[1] = '\0';

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
    return (nextFreePositionInBuffer >= BUFFER_SIZE) ? buffer[--nextFreePositionInBuffer] : getchar();
}

void ungetch(int c)
{
    if (nextFreeStackPosition >= BUFFER_SIZE)
        printf("ungetch: too many characters\n");
    else
        buffer[nextFreePositionInBuffer++] = c;
}

void reverseLastToItemsInStack()
{
    double first = pop();
    double second = pop();
    push(first);
    push(second);
}

void clearStack()
{
    while (pop() != 0.0)
        ;
}

double complexMath(char string[])
{
    double op1 = pop();

    if (strcmp(string, "sin") == 0)
        return sin(op1);
    else if (strcmp(string, "cos") == 0)
        return cos(op1);
    else if (strcmp(string, "tan") == 0)
        return tan(op1);
    else if (strcmp(string, "cot") == 0)
        return 1/tan(op1);
    else if (strcmp(string, "exp") == 0)
        return exp(op1);
    else if (strcmp(string, "pow") == 0)
    {
        double op2 = pop();
        return pow(op2,op1);
    }
    else
        printf("Unknown command: %s\n",string);

    return 0.0;
}
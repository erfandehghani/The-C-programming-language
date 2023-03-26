#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "math.h"
#include "string.h"

#define MAX_OPERATION_SIZE 100          /* Max size of the operand or operator */
#define BUFFER_SIZE 100
#define MAX_DEPTH_OF_STACK 100
#define COMPLEX_COMMAND_LENGTH 3
#define NUMBER_OF_ENGLISH_ALPHABET 26
#define DEFAULT_VAR_ARRAY_NUMBER 2.48675

enum {
    SINGLE_LETTER,                      /* When input is a single letter */
    NUMBER,                             /* When the operation is a number */
    COMPLEX_MATH,                       /* When we have a complex math operation */
    CLEAR_STACK,
    DUPLICATE_LAST_STACK_ITEM,
    RESULT,
    REVERSE_LAST_TWO_STACK_ITEMS,
    STACK_TOP_ITEM,
    VARIABLE,
    CLEAR_VAR_STACK
};

int nextFreePositionInBuffer = 0;
int nextFreeStackPosition = 0;
int nextFreeVariableStackPosition = 0;

double stack[MAX_DEPTH_OF_STACK];
char buffer[BUFFER_SIZE];
char variableStack[MAX_DEPTH_OF_STACK];
double userDefinedVariables[NUMBER_OF_ENGLISH_ALPHABET];

double lastPrintedValue = 0.0;


int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
void clearStack();
void reverseLastToItemsInStack();
double complexMath(char []);
char popVar(void);
void pushVar(char);
void clearVariableStack();

//  4-3, 4-4, 4-5, 4-6 (Reverse Polish Calculator)


int main()
{
    int type;
    double op2, op1;
    char var1;
    char string[MAX_OPERATION_SIZE];

    for (int i = 0; i < NUMBER_OF_ENGLISH_ALPHABET; ++i)
        userDefinedVariables[i] = DEFAULT_VAR_ARRAY_NUMBER;

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
            case STACK_TOP_ITEM:
                op1 = pop();
                lastPrintedValue = op1;
                push(op1);
                printf("last element of the stack: %f\n",lastPrintedValue);
                break;
            case CLEAR_STACK:
                clearStack();
                break;
            case DUPLICATE_LAST_STACK_ITEM:
                op1 = pop();
                push(op1);
                push(op1);
                break;
            case REVERSE_LAST_TWO_STACK_ITEMS:
                reverseLastToItemsInStack();
                break;
            case RESULT:
                lastPrintedValue = pop();
                printf("result is: %fg\n", lastPrintedValue);
                break;
            case VARIABLE:
                var1 = popVar();
                pushVar(var1);
                printf("last variable in the stack: %c\n",var1);
                break;
            case SINGLE_LETTER:
                if (userDefinedVariables[string[0] - 'a'] != DEFAULT_VAR_ARRAY_NUMBER)
                    push( userDefinedVariables[string[0] - 'a']);
                else
                    pushVar(string[0]);
                break;
            case '=':
                userDefinedVariables[popVar() - 'a'] = pop();
                break;
            case CLEAR_VAR_STACK:
                clearVariableStack();
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

void pushVar(char c) {
    if (nextFreeVariableStackPosition <= MAX_DEPTH_OF_STACK - 1)
        variableStack[++nextFreeVariableStackPosition] = c;
    else
        printf("Stack is full... cant push any more: %c\n", c);

}

char popVar() {
    if (nextFreeVariableStackPosition > 0)
        return variableStack[nextFreeVariableStackPosition--];
    else
    {
        printf("Error: Stack underflow\n");
        return '*';
    }
}

int getop(char string[]) {
    int index, current_char;

    // Skip whitespace
    while ((string[0] = current_char = getch()) == ' ' || current_char == '\t')
        ;

    index = 1;

    // Check for non-numeric input
    if (!isdigit(current_char) && current_char != '.' && current_char != '-') {
        while (isalpha(string[index++] = current_char = getch()))
            ;

        string[--index] = '\0';
        current_char = string[index - 1];

        // Check for known commands
        if (strlen(string) == COMPLEX_COMMAND_LENGTH && strcmp(string, "top") != 0)
            return COMPLEX_MATH;

        else if (strlen(string) > 2){
            if (strcmp(string, "top") == 0) {
                return STACK_TOP_ITEM;
            } else if (strcmp(string, "clear") == 0) {
                return CLEAR_STACK;
            } else if (strcmp(string, "duplicate") == 0) {
                return DUPLICATE_LAST_STACK_ITEM;
            } else if (strcmp(string, "reverse") == 0) {
                return REVERSE_LAST_TWO_STACK_ITEMS;
            } else if (strcmp(string, "result") == 0) {
                return RESULT;
            } else if (strcmp(string, "variable") == 0) {
                return VARIABLE;
            } else if (strcmp(string, "clearvariables") == 0) {
                return CLEAR_VAR_STACK;
            } else
                printf("Unknown Command: %s\n", string);


        } else if(strlen(string) == 1 && isalpha(string[0])) {
            return SINGLE_LETTER;

        } else
            return current_char;
    }

    // Handle negative numbers
    string[1] = '\0';
    index = 0;

    if (current_char == '-') {
        if (isdigit(current_char = getch()) || current_char == '.')
            string[++index] = current_char;
        else {
            if (current_char != EOF)
                ungetch(current_char);
            return '-';
        }
    }

    // Handle numeric input
    if (isdigit(current_char))
        while (isdigit(string[++index] = current_char = getch()))
            ;
    if (current_char == '.')
        while (isdigit(string[++index] = current_char = getch()))
            ;
    string[index] = '\0';

    // Return the appropriate value
    if (current_char != EOF)
        ungetch(current_char);

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

void clearVariableStack()
{
    while (popVar() != '*')
        ;
}
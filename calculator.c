#include "usefulFuncs.h"
#include "stdlib.h"
#include "stdio.h"

#define MAX_INPUT_CHARACTER_COUNT 200

int recrusiveCalc(char *string, int startIndex, int endIndex);
int replaceResult(char *string, int operatorIndex);
int evaluate(char *string, int startIndex);
char *remove_spaces(char *str);

int main()
{
    int inputLineLength;
    char inputString[MAX_INPUT_CHARACTER_COUNT];

    printf("Please enter something to evaluate: ");

    while((inputLineLength = getLine(inputString, MAX_INPUT_CHARACTER_COUNT)) != 0)
    {
        int res = recrusiveCalc(remove_spaces(inputString), 0, inputLineLength);
        printf("\n");
        printf("Result is: %d\n", res);
    }
}

int recrusiveCalc(char *string, int startIndex, int endIndex)
{
    int SI = startIndex;
    int i, result = 0;

    if (*string == EOF || *string == '\n')
    {
        printf("End of file or line!");
        return 0;
    }

    while (isdigit(string[SI++]))
        ;


    if(string[SI] == '(')
    {
        while (string[SI] != ')')
            SI++;
        for (i = SI; string[i] != '('; --i)
            return evaluate(string, i);
    }

    for (int operator = 0; operator <= endIndex; ++operator)
        if(string[operator] == '*')
            result += replaceResult(string, operator);

    for (int operator = 0; operator <= endIndex; ++operator)
        if(string[operator] == '/')
            result += replaceResult(string, operator);

    for (int operator = 0; operator <= endIndex; ++operator)
        if(string[operator] == '+')
            result += replaceResult(string, operator);

    for (int operator = 0; operator <= endIndex; ++operator)
        if(string[operator] == '-')
            result += replaceResult(string, operator);

    return result;
}


int replaceResult(char *string, int operatorIndex)
{
    int result;
    int temp;
    int remainder, stringLastIndex;

    for (int i = 0; string[i] != ')' && string[i] != '\0'; i++)
        stringLastIndex = i;

    stringLastIndex++;

    result = temp = evaluate(string, operatorIndex);
    for (; 0 <= stringLastIndex; stringLastIndex--)
    {
        if(temp != 0)
        {
            remainder = temp % 10;
            temp /= 10;
            string[stringLastIndex] = 48 + remainder;
        }
        else
            string[stringLastIndex] = ' ';
    }
    return result;
}

int evaluate(char *string, int Index)
{
    int SI = Index;
    int tempIndex = SI;
    int op1, op2;

    while (isdigit(string[--tempIndex]))
        ;

    if(string[tempIndex] == '-')
        op1 = -1 * atoi((string + ++tempIndex));
    else
        op1 = atoi((string + ++tempIndex));

    tempIndex = SI;
    if(string[++tempIndex] == '-')
        op2 = -1 * atoi((string + ++tempIndex));
    else
        op2 = atoi((string + tempIndex));


    switch (string[SI]) {
        case '*':
            return op1 * op2;

        case '/':
            if (op2 != '/')
                return op1/op2;
            else
            {
                printf("Division by zero!");
                return 0;
            }

        case '+':
            return op1 + op2;

        case '-':
            return op1 - op2;
    }

}

char *remove_spaces(char *str)
{
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    return str;
}
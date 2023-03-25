#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_BUFFER_SIZE 100
#define MAX_OPERATION_SIZE 100

#define NUMBER '0'
#define COMMAND '1'
#define MATH_FUNCTION '2'

double stack[MAX_STACK_SIZE];
int stack_top = 0;

char buffer[MAX_BUFFER_SIZE];
int buffer_top = 0;

int getop(char s[]);
void push(double value);
double pop(void);
void clear_stack(void);
void duplicate_top(void);
void swap_top_two(void);
void handle_math_function(char s[]);

int main(void)
{
    int type;
    double op2;
    char s[MAX_OPERATION_SIZE];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case COMMAND:
                switch (s[0]) {
                    case 'c':
                        clear_stack();
                        break;
                    case 'd':
                        duplicate_top();
                        break;
                    case 's':
                        swap_top_two();
                        break;
                    case 'q':
                        exit(0);
                        break;
                    default:
                        printf("Unknown command: %s\n", s);
                        break;
                }
                break;
            case MATH_FUNCTION:
                handle_math_function(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: division by zero\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("Error: division by zero\n");
                break;
            case '\n':
                printf("Result: %.8g\n", pop());
                break;
            default:
                printf("Unknown operator: %s\n", s);
                break;
        }
    }

    return 0;
}

int getop(char s[])
{
    int i, c;

    while ((c = buffer_top > 0 ? buffer[--buffer_top] : getchar()) == ' ' || c == '\t')
        ;

    if (c == '\n')
        return c;

    if (c == '-' && !isdigit(buffer[buffer_top])) {
        buffer[buffer_top++] = c;
        return '-';
    }

    if (!isdigit(c) && c != '.') {
        buffer[buffer_top++] = c;
        return COMMAND;
    }

    i = 0;
    if (isdigit(c))
        s[i++] = c;

    while (isdigit(c = buffer_top > 0 ? buffer[--buffer_top] : getchar()))
        s[i++] = c;

    if (c == '.')
        while (isdigit(c = buffer_top > 0 ? buffer[--buffer_top] : getchar()))
            s[i++] = c;

    s[i] = '\0';

    if (c != EOF)
        buffer[buffer_top++] = c;

    if (strlen(s) == 1 && !isdigit(s[0]))
        return s[0];

    if (strcmp(s, "sin") == 0 || strcmp(s, "cos") == 0 || strcmp(s, "tan") == 0 || strcmp(s, "exp") == 0 || strcmp(s, "pow") == 0) {
        return MATH_FUNCTION;
    }

    return NUMBER;
}

void push(double value)
{
    if (stack_top < MAX_STACK_SIZE)
        stack[stack_top++] = value;
    else
        printf("Error: stack full, can't push %g\n", value);
}

double pop(void)
{
    if (stack_top > 0)
        return stack[--stack_top];
    else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

void clear_stack(void)
{
    stack_top = 0;
}

void duplicate_top(void)
{
    double top = pop();
    push(top);
    push(top);
}

void swap_top_two(void)
{
    double top1 = pop();
    double top2 = pop();
    push(top1);
    push(top2);
}

void handle_math_function(char s[])
{
    double op;
    if (strcmp(s, "sin") == 0) {
        push(sin(pop()));
    } else if (strcmp(s, "cos") == 0) {
        push(cos(pop()));
    } else if (strcmp(s, "tan") == 0) {
        push(tan(pop()));
    } else if (strcmp(s,"cot") == 0) {
        op = pop();
        push(1.0 / tan(op));
    } else if (strcmp(s, "exp") == 0) {
        push(exp(pop()));
    } else if (strcmp(s, "pow") == 0) {
        double op2 = pop();
        op = pop();
        push(pow(op, op2));
    } else {
        printf("Unknown math function: %s\n", s);
    }
}
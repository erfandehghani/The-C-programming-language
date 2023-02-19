#ifndef THE_C_PROGRAMMING_LANGUAGE_USEFULFUNCS_H
#define THE_C_PROGRAMMING_LANGUAGE_USEFULFUNCS_H
#endif //THE_C_PROGRAMMING_LANGUAGE_USEFULFUNCS_H

int getASCIICode(char character);
void initArray(int array[], int size);
void printArray(int array[], int size);

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
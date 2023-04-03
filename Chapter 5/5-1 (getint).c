int getch(void);
void ungetch(int);

int getint(int *pointerToNumber)
{
    int ch, sign, lastCh;

    //  Skippong whitespaces
    while (isspace(ch = getch()))
        ;


    // this will check for characters that may not be a number or a plut or minus sign
    if (!isdigit(ch) && ch != EOF && ch != '+' && ch != '-')
    {
        ungetch(ch);
        return 0;
    }


    // Check if the number is negetive befor skipping the character if its a minus or plus
    sign = (ch == '-') ? -1 : 1;

    // if the character is minus or plus you can skip it now
    if (((lastCh = ch) == '+' || lastCh == '-') && !isdigit((ch = getch())))
    {
        ungetch(lastCh);
        ungetch(ch);
        return lastCh;
    }
    
    // Get the hole number... if there was a number after the sign it will collect the hole number else it will unget the character;
    if (isdigit(ch))
    {
        for (*pointerToNumber = 0; isdigit(ch); ch = getch())
            *pointerToNumber = 10 * *pointerToNumber + (ch - '0');

        // Apply the sign to the number
        *pointerToNumber *= sign;
    }
    else
        ungetch(ch);

    if (ch != EOF)
        ungetch(ch);

    return 1;
    
}
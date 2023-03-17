void expandSigns(char inputLineOfString[], char exportedLineOFString[])
{
    char c;
    int i = 0, j = 0;

    while ((c = inputLineOfString[i++]) != '\0')
    {
        if (inputLineOfString[i] == '-' && inputLineOfString[i+1] > c)
        {
            i++;
            while (c < inputLineOfString[i])
                exportedLineOFString[j++] = c++;
        }
        else
            exportedLineOFString[j++] = c;
    }
    exportedLineOFString[j] = '\0';
}
int strIndex(char string[], char pattern[])
{
    int lengthOfString = getCharArraySize(string) - 1;
    int lengthOfPattern = getCharArraySize(pattern) - 1;
    int i = lengthOfString, j = lengthOfPattern;

    while (0 <= i)
    {
        while (0 <= j && string[i--] == pattern[j])
        {
            if(j == 0)
                return i;
            j--;
        }
        i--;
    }
    return -1;
}
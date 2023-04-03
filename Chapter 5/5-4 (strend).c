int strend(char *s, char *t)
{
    static int sizeOfT = 0;
    while (*s)
        s++;
    while (*t)
    {
        t++;
        sizeOfT++;
    }
    while ((sizeOfT-- > 0))
        if (*t-- != *s--)
            return 0;

    return 1;
}
int escape(char from[],char copy[])
{
    int x = 0;
    for (int i = 0; from[i] != '\0'; ++i && ++x)
        switch (from[i])
        {
            case '\t':
                copy[x] = '\\';
                ++x;
                copy[x] = 't';
                break;
            case '\b':
                copy[x] = '\\';
                ++x;
                copy[x] = 'b';
                break;
            case '\\':
                copy[x] = '\\';
                ++x;
                copy[x] = '\\';
                break;
            case '\n':
                copy[x] = '\\';
                ++x;
                copy[x] = 'n';
                break;
            default:
                copy[x] = from[i];
                break;
        }
    copy[x] = '\0';
}

int reverseEscape(char from[],char copy[])
{
    int x = 0;
    for (int i = 0; from[i] != '\0'; ++i && ++x)
        if (from[i] == '\\')
            switch (from[i + 1])
            {
                case 't':
                    copy[x] = '\t';
                    ++i;
                    break;
                case 'b':
                    copy[x] = '\b';
                    ++i;
                    break;
                case '\\':
                    copy[x] = '\\';
                    ++i;
                    break;
                case 'n':
                    copy[x] = '\n';
                    ++i;
                    break;
                default:
                    break;
            }
        else
            copy[x] = from[i];
    copy[x] = '\0';
}
/* atof: convert string to double */

#include "ctype.h"

double atof(char string[]) {

    double val, power, symbolVal;
    int i, doubleSign, symbolSign, symbolPower;

    for (i = 0; isspace(string[i]); i++)
        ;

    doubleSign = (string[i] == '-') ? -1 : 1;

    if (string[i] == '-' || string[i] == '+')
        i++;

    for(val = 0.0; isdigit(string[i]); i++)
        val = 10.0 * val + (string[i] - '0');

    if (string[i] == '.')
        i++;

    for (power = 1.0; isdigit(string[i]); i++)
    {
        val = 10.0 * val + (string[i] - '0');
        power *= 10;
    }

    if(string[i] == 'e' || string[i] == 'E')
        i++;

    symbolSign = (string[i] == '-') ? -1 : 1;

    if(string[i] == '-' || string[i] == '+')
        i++;

    for (symbolPower = 1; isdigit(string[i]) && symbolPower <= (string[i] - '0'); ++symbolPower)
        if ((string[i] - '0') == symbolPower)
        {
            i++;
            if(isdigit(string[i]))
                symbolPower *= 10;
        }

    printf("%d\n", symbolPower);

    for (symbolVal = 1.0; 0 < symbolPower-- ; symbolVal *= 10)
        ;

    symbolVal = (symbolSign == -1) ? 1/symbolVal : symbolVal;

    printf("%f\n", symbolVal);

    printf("%d\n", symbolSign);

    return doubleSign * val/power * symbolVal;

}
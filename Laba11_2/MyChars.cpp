#include "Laba11_2.h"

char toUpperRus(char c)
{
	char new_c = c;
    if (c >= 'à' && c <= 'ï')
    {
        new_c = 'À' + (c - 'à');
    }
    if (c >= 'ð' && c <= 'ÿ')
    {
        new_c = 'Ð' + (c - 'ð');
    }
    if (c == '¸')
    {
        new_c = '¨';
    }
    return new_c;
}

char toLowerRus(char c)
{
    char new_c = c;
    if (c >= 'À' && c <= 'Ï')
    {
        new_c = 'à' + (c - 'À');
    }
    if (c >= 'Ð' && c <= 'ß')
    {
        new_c = 'ð' + (c - 'Ð');
    }
    if (c == '¨')
    {
        new_c = '¸';
    }
    return new_c;
}

bool isLetter(char c)
{
    if ((c >= 'à' && c <= 'ï') || (c >= 'ð' && c <= 'ÿ') || (c == '¸'))
    {
        return 1;
    }
    if ((c >= 'À' && c <= 'Ï')|| (c >= 'Ð' && c <= 'ß')|| (c == '¨'))
    {
        return 1;
    }
    if ((c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    return 0;
}


bool IsDigit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}
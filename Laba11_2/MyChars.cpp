#include "Laba11_2.h"

char toUpperRus(char c)
{
	char new_c = c;
    if (c >= '�' && c <= '�')
    {
        new_c = '�' + (c - '�');
    }
    if (c >= '�' && c <= '�')
    {
        new_c = '�' + (c - '�');
    }
    if (c == '�')
    {
        new_c = '�';
    }
    return new_c;
}

char toLowerRus(char c)
{
    char new_c = c;
    if (c >= '�' && c <= '�')
    {
        new_c = '�' + (c - '�');
    }
    if (c >= '�' && c <= '�')
    {
        new_c = '�' + (c - '�');
    }
    if (c == '�')
    {
        new_c = '�';
    }
    return new_c;
}

bool isLetter(char c)
{
    if ((c >= '�' && c <= '�') || (c >= '�' && c <= '�') || (c == '�'))
    {
        return 1;
    }
    if ((c >= '�' && c <= '�')|| (c >= '�' && c <= '�')|| (c == '�'))
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
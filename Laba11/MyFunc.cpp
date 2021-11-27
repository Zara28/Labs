#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "MyFunc.h"


bool IsDigit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}


char ToUpper(char c)
{
    char new_c;
    if (c >= 'a' && c <= 'z')
    {
        new_c = 'A' + (c - 'a');
    }
    else if (c >= 'à' && c <= 'ï')
    {
        new_c = 'À' + (c - 'à');
    }
    else if (c >= 'ð' && c <= 'ÿ')
    {
        new_c = 'Ð' + (c - 'ð');
    }
    else if (c == '¸')
    {
        new_c = '¨';
    }
    else
    {
        new_c = c;
    }
    return new_c;
}
int StrLen(char s[1000])
{
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        n++;
    }
    return n-1;
}
int StrCmp(char s1[100], char s2[100])
{
    if (StrLen(s1) > StrLen(s2))
    {
        return 1;
    }
    else if (StrLen(s1) < StrLen(s2))
    {
        return -1;
    }
    else
    {
        for (int i = 0; s1[i] != '\0'; i++)
        {
            if (s1[i] != s2[i])
            {
                if (s1[i] > s2[i])
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
        }
        return 0;
    }
}

char* StrCpy(char*s_copy, char* s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s_copy[i] = s[i];
    }
    return s_copy;
}

char* StrCat(char* s, char* s1)
{
    int i = 0;
   while(s1[i] != '\0')
    {
       i++;
    }
   for (int j = i; s1[j] != '\0'; j++)
   {
       s[i] = s1[j];
   }
   return s;
}


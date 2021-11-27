// Laba11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "MyFunc.h"

void task1(char name[12])
{
    printf("Приветствую тебя, %s\n", name);
}
void task2(char ch)
{
    for (int c = ch; c <= ch + 19; c++)
    {
        printf("'%c' %d\n", c, c);
    }
    printf("\n\n\n");
}
void task3(char ch)
{
    for (int c = ch; c >= ch - 29; c--)
    {
        printf("'%c' %d\n", c, c);
    }
    printf("\n\n\n");
}

void task4(char s[80])
{
    int cnt = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ') cnt++;
    }
    printf("\nВ ней %d пробелов\n", cnt);
}
void task5(char s[80])
{

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ') s[i] = '#';
    }
    printf("Вы получили строку s = \"%s\"", s);
}
void task6(char s[80])
{
    printf("Вы ввели строку s = \"%s\"", s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i])) s[i] = '$';
    }
    printf("Вы получили строку s = \"%s\"", s);
}


void task6_2(char s[80])
{

    printf("Вы ввели строку s = \"%s\"", s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (IsDigit(s[i])) s[i] = '$';
    }
    printf("Вы получили строку s = \"%s\"", s);
}
void task7(char s[100])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = toupper(s[i]);
    }
    printf("Вы получили строку s = \"%s\"", s);
}

void task7_1(char s[100])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = ToUpper(s[i]);
    }
    printf("Вы получили строку s = \"%s\"", s);
}
void task10(char* s, char* s1)
{
    printf("%d\n", StrCmp(s, s1));
    if (StrCmp(s, s1) == strcmp(s, s1))
    {
        printf("Работает верно");
    }
    else
    {
        printf("Работает !верно");
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s[80];
    char s1[100];
    printf("Введите строку/символ: ");
    fgets(s, 79, stdin);

    printf("Вы ввели s = %s", s);

    printf("Введите строку 2: ");
    fgets(s1, 99, stdin);
    printf("Вы ввели s1 = %s", s1);
    
    int x;
    x = 0;
    while (x != -1)
    {
        printf("\n1: task1\n2: task2\n3: task3\n4: task4\n5: task5\n6: task6\n6.1: task6.1\n7: task7\n7.1: task7.1\n9: task9\n11: task11\n12: task12\n");
        scanf("\n%d", &x);
        switch (x)
        {
        case 1:
            task1(s);
            break;
        case 2:
            task2(s[0]);
            break;
        case 3:
            task3(s[0]);
            break;
        case 4:
            task4(s);
            break;
        case 5:
            task5(s);
            break;
        case 6:
            task6(s);
            break;
        case 62:
            task6_2(s);
            break;
        case 7:
            task7(s);
            break;
        case 72:
            task7_1(s);
            break;
        case 9:
            printf("%d", StrLen(s));
            break;
        case 10:
            task10(s, s1);
            break;
        case 11:
            printf("%s\n", StrCpy(s1, s));
            if (StrCpy(s1, s) == strcpy(s1, s))
            {
                printf("Работает верно");
            }
            else
            {
                printf("Работает !верно");
            }
            break;
        case 12:
            printf("%s\n", StrCat(s1, s));
            if (StrCat(s1, s) == strcat(s1, s))
            {
                printf("Работает верно");
            }
            else
            {
                printf("Работает !верно");
            }
            break;
        }
    }
    {
        int x;
        scanf("%d", &x);
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

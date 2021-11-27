// Laba11_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "Laba11_2.h"


#define MAX_LEN 80

void task13()
{
    char ss[24][80] = {
"задача 2",
"Преобразовать файл in2.txt в файл out2.txt",
"Заменив все большие русские буквы на маленькие",
"",
"задача 3",
 "Зашифровать текст записанный латиницей, и находящийся в файле in3.txt",
 "применив шифр Цезаря с ключом 4",
 "Результат сохранить в файл in4.txt",
 "задача 4",
 "Расшифровать текст записанный латиницей,  и находящийся в файле in4.txt",
 "применив шифр Цезаря с ключом 4",
 "Результат сохранить в файл out4.txt",
"",
 "задача 5",
 "Преобразовать текстовый файл in5.txt",
 "в файл out5.txt, в котором каждое слово выводится на отдельной строке",
"",
 "Задача 6*",
 "Игра в слова",
 "В файле in6.txt есть строки со словами",
 "в каждой строке ровно одно слово",
 "С консоли вводится комплект букв",
 "Нужно вывести в консоль те слова из файла in6.txt",
 "Которые можно составить из введенных с консоли букв"
    };
    char fileIn1[] = "in1.txt";
    FILE* fout = fopen(fileIn1, "wt");
    for (int i = 0; i < 24; i++)
    {
        // сохранить строку в выходной файл
        fprintf(fout, "%s\n", ss[i]);
        // контрольный вывод в консоль
        printf(">>%s<<\n", ss[i]);
    }
    fclose(fout);
}


void task14()
{
    char fileIn1[] = "in1.txt";
    char fileOut1[] = "out1.txt";
    FILE* fin = fopen(fileIn1, "rt");
    FILE* fout = fopen(fileOut1, "wt");
    char s[MAX_LEN+1];

    while (!feof(fin)) {
        // загрузить строку
        if (fgets(s, MAX_LEN - 1, fin) != NULL) {
            // обработать загруженную строку
            for (int i = 0; s[i] != '\0'; i++) {
                s[i] = toUpperRus(s[i]); 
            }
            // сохранить строку в выходной файл
            fprintf(fout, "%s", s);
            printf(">>%s<<\n", s);
        }
    }
    fclose(fin);
    fclose(fout);


}


void task15()
{
    char fileIn1[] = "in1.txt";
    char fileOut1[] = "out2.txt";
    FILE* fin = fopen(fileIn1, "rt");
    FILE* fout = fopen(fileOut1, "wt");
    char s[MAX_LEN];

    while (!feof(fin)) {
        // загрузить строку
        if (fgets(s, MAX_LEN - 1, fin) != NULL) {
            // обработать загруженную строку
            for (int i = 0; s[i] != '\0'; i++) {
                s[i] = toLowerRus(s[i]);
            }
            // сохранить строку в выходной файл
            fprintf(fout, "%s", s);
            printf(">>%s<<\n", s);
        }
    }
    fclose(fin);
    fclose(fout);


}

void task16()
{
    char fileIn1[] = "in1.txt";
    char fileOut1[] = "out6.txt";
    FILE* fin = fopen(fileIn1, "rt");
    FILE* fout = fopen(fileOut1, "wt");
    int is_letter = 0;

    char word[MAX_LEN+1];
    int word_len = 0;
    int ch;
    int n = 0;
    while ((ch = getc(fin))!=EOF) {
        char c = ch;
        if (isLetter(c))
        {
            if (!is_letter)
            {
                word_len = 0;
                is_letter = 1;
            }
            word[word_len++] = c;
        }
        else
        {
            if (is_letter)
            {
                word[word_len] = '\0';
                fprintf(fout, "%s\n", word);
                printf("%s\n", word);
            }
            is_letter = 0;
        }
    }
    fclose(fin);
    fclose(fout);


}

void task17()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char fileIn1[] = "in17.txt";
    FILE* fin = fopen(fileIn1, "rt");
    
    int l;
    int n;
    int ch;
    int is_letter = 0;
    char word[80];

    char letter[15];
    scanf("%s", letter);
    //fgets(letter, 14, stdin);
    while (!feof(fin)) {
        // загрузить строку
        if (fgets(word, 79, fin) != NULL) {
            l = strlen(word)-1;
            n = 0;
            // обработать загруженную строку
            for (int j = 0; letter[j] != '\0'; j++) {
                for (int i = 0; word[i] != '\n'; i++)
                {
                    if (word[i] == letter[j])
                    {
                        n += 1;
                        break;
                    }
               }
            }
            if (n >= l)
            {
                printf("%s", word);
            }
        }
    }
    fclose(fin);
}
void taskdz()
{
    char fileIn1[] = "inht_2.txt";
    char fileOut1[] = "outht_2.txt";
    FILE* fin = fopen(fileIn1, "rt");
    FILE* fout = fopen(fileOut1, "wt");
    char s[MAX_LEN];

    while (!feof(fin)) {
        // загрузить строку
        if (fgets(s, MAX_LEN - 1, fin) != NULL) {
            // обработать загруженную строку
            for (int i = 0; s[i] != '\0'; i++) {
                if (IsDigit(s[i]))
                {
                    s[i] = 'X';
                }
            }
            // сохранить строку в выходной файл
            fprintf(fout, "%s", s);
            printf(">>%s<<\n", s);
        }
    }
    fclose(fin);
    fclose(fout);
}
void task_dz2()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char fileIn1[] = "input.txt";
    char fileOut1[] = "output.dat";
    FILE* fin = fopen(fileIn1, "rt");
    FILE* fout = fopen(fileOut1, "wt");
    int l;
    int n;
    int ch;
    int is_letter = 0;
    char stroka[200];
    char word[200];
    while (!feof(fin)) {
        // загрузить строку
        if (fgets(stroka, 199, fin) != NULL) {
            n = 0;
            l = 0;
            // обработать загруженную строку
            for (int i = 0; stroka[i] != '\0'&&stroka[i]!='M';)
            {
                for (int j = i+1; (stroka[j] != ' ')&&(stroka[j]!='M'); j++)
                {
                    if (stroka[j] == stroka[j - 1])
                    {
                        n += 1;
                    }
                    l += 1;
                }
                if (n >= 1)
                {
                    for (int j = i; stroka[j] != ' '; j++)
                    {
                        stroka[j] = toupper(stroka[j]);
                    }
                }
                i += l;
              }
            
            fprintf(fout, "%s", stroka);
            printf("%s\n", stroka);
        }
    }
    fclose(fin);
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x = 0;
    while (x != -1)
    {
        printf("/nВведите номер задания: 13, 14, 15, 16, 17, 18\n");
        scanf_s("%d", &x);
        switch (x) {
        case 13:
            task13();
            break;
        case 14:
            task14();
            break;
        case 15:
            task15();
            break;
        case 16:
            task16();
            break;
        case 17:
            task17();
            break;
        case 18:
            taskdz();
            break;
        }
    }
   
  //  task_dz2();
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

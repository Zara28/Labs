// Laba10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS 
#include "stdio.h"
#include <stdlib.h>
#define WIN32_LEAN_AND_MEAN    
// индексы входа и выхода
struct Position {
	int i, j;
};

// Уровень игры
struct Level {
	int map[10][10]; // карта уровня
// 0 – воздух
// 1 – земля
	int n; // количество строк
	int m; // количество столбцов
	struct Position entry; // вход
	struct Position exit; // выход
};

void printLevel(struct Level* level) {

	for (int i = 0; i < level->n; i++) {
		for (int j = 0; j < level->m; j++) {
			printf("%5d ", level->map[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Entry i = %d; j = %d\n", level->entry.i, level->entry.j);
	printf("Exit i = %d; j = %d\n\n", level->exit.i, level->exit.j);
}


char filename[] = "1.txt";

int loadLevel(struct Level* level) {
	FILE* fin = fopen(filename, "rt");

	if (fin == NULL) {
		printf("File %s is not opened", filename);
		return 0;
	}

	fscanf(fin, "%d", &level->n);
	fscanf(fin, "%d", &level->m);

	for (int i = 0; i < level->n; i++) {
		for (int j = 0; j < level->m; j++) {
			fscanf(fin, "%d", &level->map[i][j]);
		}
	}

	fscanf(fin, "%d", &level->entry.i);
	fscanf(fin, "%d", &level->entry.j);

	fscanf(fin, "%d", &level->exit.i);
	fscanf(fin, "%d", &level->exit.j);

	fclose(fin);
	return 1;
}


int saveLevel(struct Level* level) {
	FILE* fin = fopen(filename, "rt");

	if (fin == NULL) {
		printf("File %s is not opened", filename);
		return 0;
	}

	fprintf(fin, "%d", level->n);
	fprintf(fin, "%d", level->m);

	for (int i = 0; i < level->n; i++) {
		for (int j = 0; j < level->m; j++) {
			fprintf(fin, "%d", level->map[i][j]);
		}
	}

	fprintf(fin, "%d", level->entry.i);
	fprintf(fin, "%d", level->entry.j);

	fprintf(fin, "%d", level->exit.i);
	fprintf(fin, "%d", level->exit.j);

	fclose(fin);
	return 1;
}

void addInColumn(struct Level* level, int indexCol)
{
	for (int i = level->n - 1; i >= 0; i--)
	{
		if (level->map[i][indexCol] == 0)
		{
			level->map[i][indexCol] = 1;
			break;
		}
	}
}

void deleteChoose(struct Level* level, int indexCol)
{
	for (int i = 0; i < level->n; i++)
	{
		if (level->map[i][indexCol] == 1)
		{
			level->map[i][indexCol] = 0;
			break;
		}
	}
}

void deleteMaxColumn(struct Level* level)
{
	
	int kol_z = 0;
	int maxcol = 0;
	int indexmax = 0;
	for (int j = 0; j < level->m; j++)
	{
		for (int i = 0; i < level->n; i++)
		{
			if (level->map[i][j] == 1)
			{
				kol_z += 1;
				if (maxcol < kol_z)
				{
					maxcol = kol_z;
					indexmax = j;
				}
			}
		}
		kol_z = 0;
	}

	for (int i = 0; i < level->n; i++)
	{
		if (level->map[i][indexmax] == 1)
		{
			level->map[i][indexmax] = 0;
		}
	}

}

void addMinColumn(struct Level* level)
{

	int kol_z = 0;
	int mincol = 1000;
	int indexmin = 0;
	for (int j = 0; j < level->m; j++)
	{
		for (int i = 0; i < level->n; i++)
		{
			if (level->map[i][j] == 1)
			{
				kol_z += 1;
			}
		}

		if (mincol > kol_z)
		{
			mincol = kol_z;
			indexmin = j;
		}
		kol_z = 0;
	}

	for (int i = level->n-1; i > 0; i--)
	{
		if (level->map[i][indexmin] == 0)
		{
			level->map[i][indexmin] = 1;
			break;
		}
	}

}

int main()
{
	struct Level g;
	int k = 0;
	int j;
	do
	{
		switch (k) {
		case 0:
			loadLevel(&g);
			break;
		case 1:
			printf("\n Input j >");
			scanf("%d", &j);
			addInColumn(&g, j);
			break;
		case 2:
			printf("\n Input j =");
			scanf("%d", &j);
			deleteChoose(&g, j);
			break;
		case 3:
			deleteMaxColumn(&g);
			break;
		case 4:
			addMinColumn(&g);
			break;
		}
		printLevel(&g);

		printf("\n\n\n");
		printf("Please select action:\n");
		printf("0: Reload file\n");
		printf("1: addInColumn\n");
		printf("2: deleteChoose\n");
		printf("3: deleteMaxColumn\n");
		printf("4: addMinColumn\n");
		printf("-1:  Exit\n");

		scanf("%d", &k);
	} while (k != -1);
	loadLevel(&g);
	printLevel(&g);

	addInColumn(&g, 1);
	printLevel(&g);

	addInColumn(&g, 1);
	printLevel(&g);
	{
		int x;
		scanf("%d", &x);
	}

	saveLevel(&g);
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

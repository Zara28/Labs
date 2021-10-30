#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "stdio.h"
#define WIN32_LEAN_AND_MEAN      
#include "framework.h"

// ‘айлы заголовков среды выполнени€ C
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <clocale>

#include <conio.h>
#include <ctype.h>

#define N 10
#define M 15
int a[N][M] = {
{ 3, 0, 1, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 2,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 2,   0, 0, 0, 0, 0,   0, 2, 0, 0, 0 },
{ 0, 0, 0, 0, 2,   2, 2, 2, 2, 2,   0, 2, 0, 0, 0 },

{ 0, 0, 0, 0, 0,   0, 0, 0, 0, 2,   0, 2, 0, 0, 0 },
{ 0, 0, 1, 0, 0,   4, 0, 0, 0, 2,   0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0,   0, 1, 0, 0, 0,   0, 2, 0, 0, 0 },
{ 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 2, 0, 0, 0 },
{ 0, 0, 1, 0, 1,   0, 0, 0, 0, 0,   4, 2, 0, 0, 0 }
};
void ReadFromFile()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	setlocale(LC_ALL, "rus");
	FILE* fin;
	char k;
	fin = fopen("play.txt", "rt");
		if (fin == NULL) {
			printf("File in1.txt is not found");
			return;
		}
		//fscanf(fin, "%c", &k);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				fscanf(fin, "%5d", &a[i][j]);
			}
		}
	fclose(fin);

}
void WriteInFile()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	setlocale(LC_ALL, "rus");
	FILE* fout;
	fout = fopen("play.txt", "wt");
		if (fout == NULL) {
			printf("File out1.txt cannot be created");
			return;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				fprintf(fout, "%5d", a[i][j]);
			}
		}
	fclose(fout);

}
int steps = 0;
int gold = 0;
void moveToLeft() {
	int i, j;
	i = 0;
	while (i < N) {
		j = 1;
		while (j < M) {
			if (a[i][j] == 3) {
				if (a[i][j - 1] == 0) {
					a[i][j - 1] = 3;
					a[i][j] = 0;
					steps++;
				}
				else if (a[i][j - 1] == 1 || (a[i - 1][j] == 4 && gold >= 5)) {
					a[i][j - 1] = 3;
					a[i][j] = 0;
					steps++;
					gold++;
				}
			}
			j++;
		}
		i++;
	}

}
void moveToRight() {
	int i = 0;
	while (i < N) {
		int j = M - 2;
		while (j >= 0) {
			if (a[i][j] == 3) {
				if (a[i][j + 1] == 0) {
					a[i][j + 1] = 3;
					a[i][j] = 0;
					steps++;
				}
				else if (a[i][j + 1] == 1 || (a[i + 1][j] == 4 && gold >= 5)) {
					a[i][j + 1] = 3;
					a[i][j] = 0;
					steps++;
					gold++;
				}
			}
			j--;
		}
		i++;
	}

}
void moveUp() {
	int i = 1;
	while (i < N) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == 3) {
				if (a[i - 1][j] == 0) {
					a[i - 1][j] = 3;
					a[i][j] = 0;
					steps++;
				}
				else if (a[i - 1][j] == 1 || (a[i - 1][j] == 4 && gold >= 5)) {
					a[i - 1][j] = 3;
					a[i][j] = 0;
					steps++;
					gold++;
				}
			}
			j++;
		}
		i++;
	}

}
void moveDown() {
	int i = N-2;
	while (i >= 0) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == 3) {
				if (a[i + 1][j] == 0) {
					a[i + 1][j] = 3;
					a[i][j] = 0;
					steps++;
				}
				else if (a[i + 1][j] == 1 || (a[i + 1][j] == 4 && gold>=5)) {
					a[i + 1][j] = 3;
					a[i][j] = 0;
					steps++;
					gold++;
				}
			}
			j++;
		}
		i--;
	}

}

void Create_wall_left()
{
	int i, j;
	i = 0;
	while (i < N) {
		j = 1;
		while (j < M) {
			if (a[i][j] == 3) {
				if (a[i][j - 1] == 0) {
					a[i][j - 1] = 2;
				}
			}
			j++;
		}
		i++;
	}
}
void Create_wall_right()
{
	int i, j;
	i = 0;
	while (i < N) {
		j = 0;
		while (j < M) {
			if (a[i][j] == 3) {
				if (a[i][j + 1] == 0) {
					a[i][j + 1] = 2;
				}
			}
			j++;
		}
		i++;
	}
}

void Destroy_wall_right()
{
	int i, j, pi, pj;
	i = 0;
	while (i < N) {
		j = 0;
		while (j < M) {
			if (a[i][j] == 3) {
				pi = i;
				pj = j;
				break;
			}
			j++;
		}
		i++;
	}
	while (pj < M)
	{
		if (a[pi][pj] == 2)
		{
			a[pi][pj] = 0;
		}
		pj+= 1;
	}
}

void Destroy_wall(int ras)
{
	int i, j;
	i = 1;
	while (i < N) {
		j = 1;
		while (j < M) {
			if (a[i][j] == 3) {
				if (a[i][j + ras] == 2) {
					a[i][j + ras] = 0;
				}
				if (a[i][j - ras] == 2) {
					a[i][j - ras] = 0;
				}
				if (a[i+ras][j] == 2) {
					a[i+ras][j] = 0;
				}
				if (a[i-ras][j] == 2) {
					a[i-ras][j] = 0;
				}

			}

			j++;
		}
		i++;
	}
}

void Destroy_wall_D()
{
	int i, j, n;
	j = 0;
	int maxn = 0;
	int mi = 0;
	while (j < M) {
		i = 0;
		n = 0;
		while (i < N) {
			if (a[i][j] == 2) {
				n += 1;
			}
			i++;
		}
		if (n > maxn)
		{
			maxn = n;
			mi = j;
		}

		j++;
	}
	i = 0;
	while (i < N) {
		if (a[i][mi] == 2) {
			a[i][mi] = 0;
			break;
		}
		i++;
	}
}
void  Double() {
	gold *= 2;
}

void Again()
{
	gold = 0;
	steps = 0;
	int i = 0;
	while (i < N) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == 3) {

				a[i][j] = 0;
				a[0][0] = 3;

			}
			j++;
		}
		i++;
	}
}
void to_end()
{
	int i = 0;
	while (i < N) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == 3) {
				
					a[i][j] = 0;
					a[N-1][M-1] = 3;
			}
			j++;
		}
		i++;
	}
}
int sizeX = 36;
int sizeY = 30;

void DrawField(HDC hdc) {

	HBRUSH hBrushEmptyCell; //создаЄм кисть дл€ пустого пол€
	hBrushEmptyCell = CreateSolidBrush(RGB(200, 200, 200)); // серый

	HBRUSH hBrushGold; //создаЄм кисть дл€ пол€ с золотом
	hBrushGold = CreateSolidBrush(RGB(255, 255, 0)); // желтый

	HBRUSH hBrushWall; //создаЄм кисть дл€ стены
	hBrushWall = CreateSolidBrush(RGB(0, 0, 0)); // черный

	HBRUSH hBrushMan; //создаЄм кисть дл€ игрока
	hBrushMan = CreateSolidBrush(RGB(0, 0, 255)); // синий

	HBRUSH hBrushMonster; //создаЄм кисть дл€ игрока
	hBrushMonster = CreateSolidBrush(RGB(255, 0, 0)); // красный
	int i, j;
	i = 0;
	while (i < N) {
		j = 0;
		while (j < M) {
			RECT rect = { j * sizeX, i * sizeY,  (j + 1) * sizeX,(i + 1) * sizeY };
			if (a[i][j] == 0) {
				FillRect(hdc, &rect, hBrushEmptyCell);
			}
			else if (a[i][j] == 1) {
				FillRect(hdc, &rect, hBrushGold);
			}
			else if (a[i][j] == 2) {
				FillRect(hdc, &rect, hBrushWall);
			}
			else if (a[i][j] == 3) {
				FillRect(hdc, &rect, hBrushMan);
			}
			else if (a[i][j] == 4) {
				FillRect(hdc, &rect, hBrushMonster);
			}
			else {
				// тут никогда не должны оказатьс€
			}
			j++;
		}
		i++;
	}
	HFONT hFont;
	hFont = CreateFont(20,
		0, 0, 0, 0, 0, 0, 0,
		DEFAULT_CHARSET,
		0, 0, 0, 0,
		L"Courier New"
	);
	SelectObject(hdc, hFont);
	SetTextColor(hdc, RGB(0, 128, 128));

	TCHAR  string1[] = _T("сделано ходов:");
	TCHAR  string2[] = _T("собрано золота:");
	TextOut(hdc, 10, sizeY * (N + 1), (LPCWSTR)string1, _tcslen(string1));
	TextOut(hdc, 10, sizeY * (N + 1) + 20, (LPCWSTR)string2, _tcslen(string2));
	char sSteps[5];
	TCHAR  tsSteps[5];
	sprintf(sSteps, "%d", steps);
	OemToChar(sSteps, tsSteps);
	TextOut(hdc, 220, sizeY * (N + 1), (LPCWSTR)tsSteps, _tcslen(tsSteps));

	char sGold[5];
	TCHAR  tsGold[5];
	sprintf(sGold, "%d", gold);
	OemToChar(sGold, tsGold);
	TextOut(hdc, 220, sizeY * (N + 1) + 20, (LPCWSTR)tsGold, _tcslen(tsGold));

	DeleteObject(hFont);
	DeleteObject(hBrushEmptyCell);
	DeleteObject(hBrushGold);
	DeleteObject(hBrushWall);
	DeleteObject(hBrushMan);
	DeleteObject(hBrushMonster);

}

void MoveMonsters() {
		int i = 0;
		while (i < N) {
			int j = 0;
			while (j < M) {
				if (a[i][j] == 4) {
					int di = rand() % 3 - 1; // от -1 до +1
					int dj = 0;

					if (di == 0) {
						dj = rand() % 3 - 1; // от -1 до +1
					}

					if (di != 0 || dj != 0) {
						if (i + di >= 0 && i + di < N
							&& j + dj >= 0 && j + dj < M)
						{
							a[i][j] = 0;
							a[i + di][j + dj] = -4;
						}
					}

				}
				j++;
			}
			i++;
		}
		i = 0;
		while (i < N) {
			int j = 0;
			while (j < M) {
				if (a[i][j] == -4) {
					a[i][j] = 4;
				}
				j++;
			}
			i++;
		}

	

}
void randomMove()
{
	int i1, j1;
	i1 = rand() % N;
	j1 = rand() % M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == 3 && a[i1][j1]==0)
			{
				a[i][j] = 0;
				a[i1][j1] = 3;
			}
		}
	}
}
void generateLevel() {
	//  оды €чеек
	// 0 - свободно
	// 1 - золото
	// 2 - стена
	// 3 - игрок
	// 4 - ћќЌ—“–!

	// всЄ заново!
	steps = 0;
	gold = 0;

	// все €чейки делаем свободными
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			a[i][j] = 0;
		}
	}
	// в часть €чеек помещаем много «ќЋќ“ј
	int k;
	for (k = 0; k < (N * M) / 2; k++) {
		i = rand() % N;
		j = rand() % M;
		a[i][j] = 1;
	}

	// в часть €чеек помещаем —“≈Ќџ
	for (k = 0; k < (N * M) / 5; k++) {
		i = rand() % N;
		j = rand() % M;
		a[i][j] = 2;
	}

	// в часть €чеек помещаем ћќЌ—“–ќ¬
	for (k = 0; k < (N * M) / 13; k++) {
		i = rand() % N;
		j = rand() % M;
		a[i][j] = 4;
	}

	// в одну из €чеек помещаем игрока
	i = rand() % N;
	j = rand() % M;
	a[i][j] = 3;

}
void addGold()
{
	int i, j;
	bool hole = false;
	while (!hole)
	{
		i = rand() % N;
		j = rand() % M;
		if (a[i][j] == 0)
		{
			a[i][j] = 1;
			hole = true;
		}
	}

}
bool EndGame()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == 3)
			{
				return false;
			}
		}
	}
	return true;
}
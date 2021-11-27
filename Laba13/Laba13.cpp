#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"stdio.h"
#define NUM = 10

long fuct2(int n) {
	if (n == 0) {
		return 1;
	}

	long res = fuct2(n - 1) * n;
	return res;
}

void f1(int n) {
	printf(" %d", n);
	if (n > 1) {
		f1(n - 2);
	}
}

void f2(int n) {
	if (n > 1) {
		f2(n - 2);
	}
	printf(" %d", n);
}

void f3(int n) {
	printf(" %d", n);
	if (n > 1) {
		f3(n - 2);
	}
	if (n!=1)
		printf(" %d", n);
}

void recEGE1(int n) {
	if (n >= 1) {
		printf(" %d", n);
		recEGE1(n - 1);
		recEGE1(n - 1);
	}
}


void F1(int n)
{
	if (n > 2)
	{
		printf("%d", n);
		F1(n - 3);
		F1(n - 4);
	}
}
void F2(int n)
{
	if (n < 5)
	{
		printf("%d", n);
		F2(n + 1);
		F2(n + 3);
	}
}

void G3(int n);
void F3(int n)
{
	if (n > 0)
	{
		G3(n - 1);
	}
}

void G3(int n)
{
	printf("*");
	if (n > 1)
	{
		F3(n - 3);
	}
}

int array[10] = { 1, 3, 4, 8, 9, 10, 11, 15, 16, 18 };

void printArray()
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n\n");
}

int contains(int v)
{
	int left = 0;
	int right = 10 - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (array[middle] == v)
		{
			return 1;
		}
		if (array[middle] < v)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}
	return 0;
}
int containsR(int left, int right, int v)
{
	if (left > right)
	{
		return 0;
	}
	int middle = (right + left) / 2;
	if (array[middle] == v)
	{
		return 1;
	}
	if (array[middle] < v)
	{
		return containsR(middle + 1, right, v);
	}
	else
	{
		return containsR(left, middle - 1, v);
	}
}

void F1dz(int n) {
	if (n > 0) {
		F1dz(n - 1);
		printf("%d", n);
		F1dz(n / 4);
	}
}

void F2dz(int n)
{
	if (n < 8) {
		F2dz(2 * n);
		printf("%d", n);
		F2dz(n + 3);
	}
}

void F3dz(int n)
{
	if (n > 0)
	{
		printf("*");
		F3dz(n - 1);
		F3dz(n / 3);
	}
}
int main() {
	int k;
	while (k != -1)
	{
		printf("task 1, 2, 4, 5, 6, 9, 10\n");
		scanf_s("%d", &k);
		switch (k)
		{
		case 1:
			int n;
			scanf_s("%d", &n);
			long f = fuct2(n);

			printf("%d! = %ld", n, f);
			break;
		case 2:
			f1(7);
			printf(" f1 FINISH\n");

			f2(7);
			printf(" f2 FINISH\n");

			f3(7);
			printf(" f3 FINISH\n");
			break;
		case 4:
			recEGE1(3);
			break;
		case 5:
			F1(10);
			break;
		case 6:
			F2(1);
			break;
		case 7:
			F3(11);
			break;
		case 9:
			printArray();
			printf("contains (1) = %d\n", contains(1));
			printf("contains (2) = %d\n", contains(2));
			printf("contains (3) = %d\n", contains(3));
			printf("contains (4) = %d\n", contains(4));
			printf("contains (5) = %d\n", contains(5));
			printf("contains (6) = %d\n", contains(6));
			printf("contains (10) = %d\n", contains(10));
			printf("contains (15) = %d\n", contains(15));
			printf("\n\n");
			printf("containsR (1) = %d\n", containsR(0, 9, 1));
			printf("containsR (2) = %d\n", containsR(0, 9, 2));
			printf("containsR (3) = %d\n", containsR(0, 9, 3));
			printf("containsR (4) = %d\n", containsR(0, 9, 4));
			printf("containsR (5) = %d\n", containsR(0, 9, 5));
			printf("containsR (6) = %d\n", containsR(0, 9, 6));
			printf("containsR (10) = %d\n", containsR(0, 9, 10));
			printf("containsR (15) = %d\n", containsR(0, 9, 15));
			break;
		case 10:
			F1dz(5);
			printf("\n");
			F2dz(1);
			printf("\n");
			F3dz(6);
			break;
		}
	}
	
}

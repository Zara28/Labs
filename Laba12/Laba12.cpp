// Laba12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d) -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}
void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}

int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;

	first = first->next;
	free(delNode);

	return value;
}
int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL)
	{
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}


int sum()
{
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL)
	{
		s += ptr->data;
		ptr = ptr->next;
	}
	return s;
}

int evenCount()
{
		struct Node* ptr = first;
		int s = 0;
		while (ptr != NULL)
		{
			if (ptr->data % 2 == 0)
			{
				s += 1; 
			}

			ptr = ptr->next;
		}
		return s;
}

void oddsX10()
{
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL)
	{
		if (ptr->data % 2 != 0)
		{
			ptr->data *= 10;
		}

		ptr = ptr->next;
	}
}
void elementIx100(int i)
{
	int index = 0;
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL)
	{
		if (index == i)
		{
			ptr->data *= 100;
			return;
		}

		ptr = ptr->next;
		index++;
	}
}

void elementLeftIx10(int i)
{
	int index = 0;
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL)
	{
		if (index < i)
		{
			ptr->data *= 10;
		}

		ptr = ptr->next;
		index++;
	}
}
void elementRightIx10(int i)
{
	int index = 0;
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL)
	{
		if (index > i)
		{
			ptr->data *= 10;
		}

		ptr = ptr->next;
		index++;
	}
}

void deleteElementI(int i)
{
	if (first == NULL)
	{
		return;
	}
	if (i == 0)
	{
		deleteFromHead();
		return;
	}

	struct Node* prev_ptr = first;
	struct Node* ptr = first->next;
	int index = 1;

	while (ptr != NULL)
	{
		if (index == i)
		{
			prev_ptr->next = ptr->next;
			return;
		}
		prev_ptr = ptr;
		ptr = ptr->next;
		index++;
	}
}
void printListInver(struct Node* first)
{
	if (first == NULL)
	{
		return;
	}

	struct Node* prev_ptr = first;
	struct Node* ptr = first->next;
	if (ptr != NULL)
	{
		printListInver(ptr);
		ptr = prev_ptr;
		printf("(%d) -> ", ptr->data);
		//printf("(%d) -> ", prev_ptr->data);
	}
	else
	{
		printf("(%d)", prev_ptr->data);
	}
}

void povtor()
{
	struct Node* prev_ptr = first;
	struct Node* ptr = first->next;
	int n = 0;
	while (ptr != NULL)
	{
		if (ptr->data == prev_ptr->data)
		{
			n += 1;
		}
		prev_ptr = ptr;
		ptr = ptr->next;
	}
	if (n > 0)
	{
		printf("yes");
	}
	else printf("No");
}

void swap(int i)
{
	struct Node* prev_ptr = first;
	struct Node* ptr = first->next;
	int index = 0;

	while (ptr != NULL)
	{
		if (index == i)
		{
			int temp = prev_ptr->data;
			prev_ptr->data = ptr->data;
			ptr->data = temp;
			return;
		}
		prev_ptr = ptr;
		ptr = ptr->next;
		index++;
	}
}

void swap_differ(int i, int j)
{
	struct Node* ptr = first;
	int index = 0;

	int temp1 = 0;
	int temp2 = 0;
	while (ptr != NULL)
	{
		if (index == i)
		{
			temp1 = ptr->data;
		}
		if (index == j)
		{
			temp2 = ptr->data;
			ptr->data = temp1;
		}
		ptr = ptr->next;
		index++;
	}
	ptr = first;
	index = 0;
	while (ptr != NULL)
	{
		if (index == i)
		{
			ptr->data = temp2;
			break;
		}
		ptr = ptr->next;
		index++;
	}
}
int kol()
{
	struct Node* ptr = first; 
	int n = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		n++;
	}
	return n;
}
void sort()
{
	
	int index = 0;

	while (index < kol())
	{
		struct Node* prev_ptr = first;
		struct Node* ptr = first->next;
		while (ptr!=NULL)
		{
			if (prev_ptr->data > ptr->data)
			{
				int temp = prev_ptr->data;
				prev_ptr->data = ptr->data;
				ptr->data =temp;
			}
			prev_ptr = ptr;
			ptr = ptr->next;
		}

		index++;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	addToHead(rand()%10);
	addToHead(rand()% 10);
	addToHead(rand() % 10);
	addToHead(rand() % 10);
	addToHead(rand() % 10);
	printList();
	int n = 0;
	printf("Choose number of task");
	while (n!=-1)
	{
		printf("\n1:addToHead() \n2:deleteFromHead()\n3:contains() \n4:sum()\n5:evenCount()\n6:oddsX10\n7:elementIX100\n8:elementLeftIX10\n9:elementRightIX100\n10:deleteElement\n11:inverse, povtor, swap, swap different, sort\n");
		int k;
		scanf("\n%d", &n);
		switch (n)
		{
		case 1:
			
			printf("Введите значение, которое добавим: ");
			scanf("%d", &k);
			addToHead(k);
			printList();
			break;
		case 2:
			deleteFromHead();
			printList();
			break;
		case 3:
			printf("Введите значение, которое проверим: ");
			scanf("%d", &k);
			printf("\n%d", contains(k));
			break;
		case 4:
			printf("\n%d", sum());
			break;
		case 5:
			printf("%d", evenCount());
			break;
		case 6:
			oddsX10();
			printList();
			break;
		case 7:
			printf("Введите индекс элемента, который увеличим: ");
			scanf("%d", &k);
			elementIx100(k);
			printList();
			break;
		case 8:
			printf("Введите индекс элемента, левее которого увеличим: ");
			scanf("%d", &k);
			elementLeftIx10(k);
			printList();
			break;
		case 9:
			printf("Введите индекс элемента, правее которого увеличим: ");
			scanf("%d", &k);
			elementRightIx10(k);
			printList();
			break;
		case 10:
			printf("Введите индекс элемента, который удалим: ");
			scanf("%d", &k);
			deleteElementI(k);
			printList();
			break;
		case 11:
			printListInver(first);
			printf("/n Есть ли повторяющиеся ");
			povtor();
			printf("\nВведите индекс элемента, который переставим: ");
			scanf("%d", &k);
			if (k < kol()-1) {

				swap(k);
			}
			printList();
			int k2;
			printf("\nВведите индексы элементов, которые переставим: ");
			scanf("%d %d", &k, &k2);
			if (k < kol() && k2 < kol()) {

				swap_differ(k, k2);
			}
			printList();
			sort();
			printList();
		}
	}
	clearList();
	printList();
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

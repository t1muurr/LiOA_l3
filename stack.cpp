#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// ‘ункции добавлени€ элемента, просмотра списка
void spstore(void), review(void), del(void);

char find_el[256];
struct node *find(char *name); // функци€ нахождени€ элемента
struct node *get_struct(void); // функци€ создани€ элемента

struct node *head = NULL, *last = NULL, *f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;
int number;

struct node
{
	char surname[256];  // фамили€ студента
	int scores; // баллы ≈√Ё
	int numb; // дл€ приоритетной очереди
	struct node *next; // ссылка на следующий элемент 
};


struct node *get_struct(void)
{
	struct node *p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выдел€ем пам€ть под новый элемент списка
	{
		printf("ќшибка при распределении пам€ти\n");
		exit(1);
	}

	printf("¬ведите фамилию студента: \n");   // вводим данные
	scanf("%s", &s);
	if (*s == 0)
	{
		printf("«апись не была произведена\n");
		return NULL;
	}
	strcpy(p->surname, s);
	printf("¬ведите сумму баллов:\n");
	scanf("%d", &p->scores);

	p->numb = number;
	printf("Ќомер записи: %d\n", p->numb);
	number += 1;

	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* ѕоследовательное добавление в список элемента (в конец)*/
void spstore(void)
{
	struct node *p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // список уже есть, то вставл€ем в конец
	{
		last->next = p;
		last = p;
	}
	return;
}


/* ѕросмотр содержимого списка. */
void review(void)
{
	struct node *struc = head;
	if (head == NULL)
	{
		printf("—писок пуст\n");
	}
	while (struc)
	{
		printf("‘амили€ - %s, \n", struc->surname);
		printf("—умма баллов - %d, \n", struc->scores);
		printf("Ќомер записи - %d, \n", struc->numb);
		struc = struc->next;
	}
	return;
}


/* ѕоиск элемента по содержимому. */
struct node *find(char *name)
{
	struct node *struc = head;
	if (head == NULL)
	{
		printf("—писок пуст\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->surname) == 0)
		{
			printf("‘амили€ - %s, \n", struc->surname);
			printf("—умма баллов - %d, \n", struc->scores);
			printf("Ќомер записи - %d, \n", struc->numb);
			return struc;
		}
		struc = struc->next;
	}
	printf("Ёлемент не найден\n");
	return NULL;
}

/* ”даление элемента по содержимому. */
void del(void)
{
	struct node *struc = head; // указатель, проход€щий по списку установлен на начало списка
	struct node *prev;// указатель на предшествующий удал€емому элемент
	int flag = 0;      // индикатор отсутстви€ удал€емого элемента в списке

	if (head == NULL) // если голова списка равна NULL, то список пуст
	{
		printf("—писок пуст\n");
		return;
	}

	flag = 1;
	head = struc->next; // установливаем голову на следующий элемент
	free(struc);  // удал€ем первый элемент
	struc = head; // устанавливаем указатель дл€ продолжени€ поиска
	
	

	if (flag == 0)				// если флаг = 0, значит нужный элемент не найден
	{
		printf("Ёлемент не найден\n");
		return;
	}


}

int main () 
{
	setlocale(LC_ALL, "rus");
	int menu = 0;
	char m[256];
	char *name;
	number = 1;

	printf("ƒл€ добавлени€ элемента нажмите: 1\n");
	printf("ƒл€ удалени€ элемента нажмите:   2\n");
	printf("ƒл€ поиска элемента нажмите:     3\n");
	printf("ƒл€ просмотра элемента нажмите:  4\n");
	printf("ƒл€ выхода нажмите:              5\n");

	while (menu != 5)
	{
		scanf("%d", &menu);

		switch (menu) {
		case 1: 
			spstore();
			break;
		case 2: 
			del();
			break;
		case 3: 
			printf("¬ведите фамилию студента дл€ поиска данных: \n");
			scanf("%s", m);
			name = m;
			find(name);
			break;
		case 4: 
			review();
			break;
		}
	}
	return 0;
}
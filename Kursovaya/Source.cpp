#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct older //структурный тип, обозначающий старшее множество
{
	older* next; //указатель на следующий элемент старшего множества
	struct yanger* y_mn_vo; //указатель на младшее множество
};

struct yanger //структурный тип, обозначающий младшее множество
{
	struct yanger* next; //указатель на следующий элемент младшего множества
	int chislo; //данные целого типа
};

// прототипы всех ф-ий

int menu();

int vvod();
int comparison_mn(yanger*, yanger*);

int start_yanger();
yanger* yanger_clear(yanger*);
int clean(void*, int);
yanger* delete_item_yanger(yanger*, int);
yanger* take_item_yanger(yanger*, int*);
int yanger_amount_of_elements(yanger*);
int older_amount_of_elements(older*);
yanger* add_yanger_item(yanger*, int);
int check_yanger_item(yanger*, int);
void print_yanger(yanger*);
int end_work_yanger();

int start_older();
older* older_clear(older*);
older* delete_completle_item_older(older*);
older* take_item_older(older*, yanger**);
older* add_completle_older_item(older*);
int check_older_item(older*);
void print_older(older*);
int end_work_older();
older* older_many_check(older*);


int main()
{
	menu(); // Вызываем основное меню
	return 0;
}

int menu()
{
	int d, h, f = 1, flag = 1, older_start = 0, yanger_start = 0, zap_yanger_chislo;	// Описание переменных, необходимых для работы программы
	older* begin = NULL, * zap = NULL;
	yanger* zap_older_mn;
	while (f)
	{
		if (older_start)	//Условие начала работы со старшим множеством
		{
			system("cls");	// очищение консоли
			printf("Available actions with older set:\n");	 // печать списка доступных действий
			printf("1.Make set empty\n");
			printf("2.Check for emptiness of set\n");
			printf("3.Remove item from set\n");
			printf("4.Take any element of set\n");
			printf("5.Add item to set\n");
			printf("6.Checking for an element to belong to a set\n");
			printf("7.Print set\n");
			printf("8.Finish work\n");
			if (clean(begin, 0))	 // проверка старшего множества на пустоту
				printf("Set are empty!\n");
			else
				print_older(begin);	 // вызов ф-ии печати старшего множества после каждого действия
			printf("Enter action number: ");
			d = vvod();		// вызов ф-ии ввода номера действия
			switch (d)	 // выбор действия в зависимости от введеного номера
			{
			case 1: {
				if (!clean(begin, d))	 // предварительная проверка старшего множества на пустоту
					begin = older_clear(begin);	 // вызов ф-ии очищения старшего множества
				else
					printf("Set are empty!\n");
				break;
			}
			case 2: {clean(begin, d); break; }	// вызов ф-ии проверки старшего множества на пустоту
			case 3: {
				if (clean(begin, d))	// предварительная проверка старшего множества на пустоту
					printf("Many are empty!\n");
				else
				{
					begin = delete_completle_item_older(begin); break;	//вызов ф-ии удаления элемента из старшего множества
				}
				break;
			}
			case 4: {
				if (clean(begin, d))	// предварительная проверка старшего множества на пустоту
					printf("Many are empty!\n");
				else
					begin = take_item_older(begin, &zap_older_mn);	//вызов ф-ии взфтия случайного элемента старшего множества
				break; }
			case 5: {
				printf("1.Add full set\n");
				printf("2.Go to work with junior plural\n");
				printf("Enter action number: ");
				h = vvod();	 // вызов ф-ии ввода номера
				switch (h)	 // выбор действия в зависимости от введеного номера
				{
				case 1: {
					begin = add_completle_older_item(begin);
					if (begin && begin->next == NULL)
						zap = begin;
					break; }
				case 2: {
					zap = begin;
					begin = (older*)malloc(sizeof(older));	// выделение памяти под новый элемент старшего множества
					if (clean(begin, 0))	 // проверка на ошибку выделения памяти
					{
						printf("Memory Allocation Error");
						return 0;
					}
					begin->next = zap;
					begin->y_mn_vo = NULL;
					flag = 1;
					while (flag)	// повторение, пока не будет решено вернутся к старшему множеству
						if (yanger_start)	 // условие начала работы с младшим множеством
						{
							while (yanger_start)	 // меню работы с младшим можеством, пока она начата
							{
								system("cls");	// очищение консоли
								printf("Available actions with yanger set:\n");	 // печать списка доступных действий
								printf("1.Make set empty\n");
								printf("2.Check for emptiness of set\n");
								printf("3.Remove item from set\n");
								printf("4.Take any element of set\n");
								printf("5.Add item to set\n");
								printf("6.Checking for an element to belong to a set\n");
								printf("7.Print set\n");
								printf("8.Finish work (back)\n");
								if (!begin || clean(begin->y_mn_vo, 0))	 // проверка множеств на пустоту
									printf("Set are empty!\n");
								else
								{
									printf("Set: ");
									print_yanger(begin->y_mn_vo);	 // вызов ф-ии печати младшего множества после каждого действия
								}
								printf("Enter action number: ");
								d = vvod();	 // вызов ф-ии ввода номера
								switch (d)	// выбор действия в зависимости от введеного номера
								{
								case 1: {
									if (!begin || clean(begin->y_mn_vo, 0))		// предварительная проверка множеств на пустоту
										printf("Set are empty!\n");
									else
									{
										begin->y_mn_vo = yanger_clear(begin->y_mn_vo);	// вызов ф-ии очищения младшего множества
									}
									break; }
								case 2: {
									if (!clean(begin, begin ? 0 : d))	 // предварительная проверка старшего множества на пустоту
										clean(begin->y_mn_vo, d);	 //вызов ф-ии проверки младшего множества на пустоту
									break; }
								case 3: {
									if (!begin || clean(begin->y_mn_vo, 0))		// предварительная проверка множеств на пустоту
										printf("Set are empty!\n");
									else
										begin->y_mn_vo = delete_item_yanger(begin->y_mn_vo, vvod());	//вызов ф-ии удаления элемента младшего множества
									break; }
								case 4: {
									if (!begin || clean(begin->y_mn_vo, 0))		// предварительная проверка множеств на пустоту
										printf("Set are empty!\n");
									else
										begin->y_mn_vo = take_item_yanger(begin->y_mn_vo, &zap_yanger_chislo);	// вызов ф-ии взятия элемента из младшего мноества
									break; }
								case 5: {
									printf("Enter item: ");
									if (!begin)		// действия на случай добавления первого элемента старшего множества
									{
										begin = (older*)malloc(sizeof(older));	// выделение памяти под первый элемент старшего множества
										if (clean(begin, 0))
										{
											printf("Memory Allocation Error");
											return 0;
										}
										begin->next = NULL;
										begin->y_mn_vo = NULL;
									}
									begin->y_mn_vo = add_yanger_item(begin->y_mn_vo, vvod());	// вызов ф-ии добавления нового элемента младшего множества
									break;
								}
								case 6: {
									if (!begin || clean(begin->y_mn_vo, 0))		// предварительная проверка множеств на пустоту
										printf("Set are empty!\n");
									else
									{
										if (check_yanger_item(begin->y_mn_vo, vvod()))	// вызов ф-ии проверки наличия элемента в младшем множестве
											printf("Such an element exists!\n");
										else
											printf("No such item!\n");
									}
									break;
								}
								case 7: {
									if (!begin || clean(begin->y_mn_vo, 0))		// предварительная проверка множеств на пустоту
										printf("Set are empty!\n");
									else
									{
										printf("Set: ");
										print_yanger(begin->y_mn_vo);	// вызов ф-ии печати младшего множества
									}
									break; }
								case 8: {
									if (begin)	// проверка добавления новго элемента в старшее множество
									{
										begin = older_many_check(begin);	// вызов ф-ии проверки наличия введенного младшего множества в старшем
										if (begin->y_mn_vo == NULL)
											begin = begin->next;
									}
									yanger_start = end_work_yanger();
									flag--;
									break; }
								default: {printf("No action available\n"); }	// отлов введения номера действия не соответствующего доступным действиям
								}
								system("pause");
							}
						}
						else	// действия до начала работы с младшим множеством
						{
							while (!yanger_start && flag)	 // до тех пор, пока не начнется работа или пока не будет решено вернутся к старшему множеству
							{
								printf("Available actions:\n");	 // печать списка доступных действий
								printf("1.Get started\n");
								printf("2.back\n");
								printf("Enter action number :\n");
								d = vvod();		// вызов ф-ии ввода номера
								switch (d)
								{
								case 1: {yanger_start = start_yanger(); break; }	// вызов ф-ии начала работы с младшим множеством
								case 2: {--flag; begin = begin->next; break; }	// возвращение к работе со старшим множеством
								default: {printf("No action available\n"); }	// отлов введения номера действия не соответствующего доступным действиям
								}
							}
						}
					break;
				}
				default: {printf("No action available\n"); }	// отлов введения номера действия не соответствующего доступным действиям
				}
				break; }
			case 6: {
				if (clean(begin, d))	// предварительная проверка старшего множества на пустоту
					printf("Many are empty!\n");
				else
					check_older_item(begin);	//вызов ф-ии проверки наличия элемента в старшем множестве
				break; }
			case 7: {
				if (clean(begin, d))	// предварительная проверка старшего множества на пустоту
					printf("Many are empty!\n");
				else
					print_older(begin);		// вызов ф-ии печати старшего множества
				break; }
			case 8: {older_start = end_work_older(); if (begin)begin = older_clear(begin); break; } // вызов ф-ии очищения старшего множества и окончания работы с ним
			default: {printf("No action available\n"); }	// отлов введения номера действия не соответствующего доступным действиям
			}
			system("pause");
			system("cls");	 // очищение консоли

		}
		else	// действия до начала со старшим множеством
		{
			printf("Available actions:\n");
			printf("1.Get started\n");
			printf("Enter action number: ");
			d = vvod();		// вызов ф-ии ввода номера действия
			if (d == 1)
			{
				older_start = start_older();	// вызов ф-ии начала работы со старшим множеством
			}
			else
				printf("No action available\n");	// отлов введения номера действия не соответствующего доступным действиям
		}
	}
}

int vvod()
{
	char c, s[20];
	int j = 0;
	c = getchar();
	while (isspace(c) && c != '\n')	 // пропуск начальных символов табуляции
		c = getchar();
	while (!isspace(c))		// считывание символов доервой табуляции
	{
		s[j] = c;
		j++;
		c = getchar();
	}
	s[j] = '\0';
	if (s[0] == '0' || atoi(s) != 0 || isspace(s[0])) // проверка на хоть частичное введение числа
		return atoi(s);
	else
	{
		printf("Input Error!\n");
		printf("Repeat input: ");
		return vvod(); // повтор попытки ввода
	}
}

int comparison_mn(yanger* first, yanger* second)
{
	yanger* first_rab = first, * second_rab = second;
	int f = 0;
	while (first_rab != NULL)	 // проход по всем элементам младшего множества
	{
		if (yanger_amount_of_elements(first) == yanger_amount_of_elements(second))	//отлов одинаковых по количеству элементов младших множеств
		{
			if (!check_yanger_item(second, first_rab->chislo))	// проверка очередного элемента младшего множества на принадлежность другому младшему множеству
				return 1;
			first_rab = first_rab->next;
		}
		else
			return 1;	// выход из ф-ии при неравенстве можеств
	}
	return 0;
}

int start_yanger()
{
	return 1;
}

yanger* yanger_clear(yanger* begin)
{
	yanger* rab = NULL, * zap = NULL;
	rab = begin;
	while (rab->next != NULL)	// проход по всем элементам младшего множества
	{
		zap = rab;
		rab = rab->next;
		free(zap);	// освобождение памяти, выделенной под очередной элемент мл. множества
	}
	free(rab);
	return NULL;
}

int clean(void* ptr, int d)
{
	if (!ptr)	// проверка указателя на NULL
	{
		if (d == 2)		// вызвана ф-ия как отделная операция или для работы программы?
			printf("Set are empty!\n");
		return 1;
	}
	else
	{
		if (d == 2)		// вызвана ф-ия как отделная операция или для работы программы?
			printf("Set are not empty!\n");
		return 0;
	}
}

yanger* delete_item_yanger(yanger* begin, int c)
{
	yanger* rab = begin, * zap = begin;
	if (clean(begin, 0))	// предварительная проверка множества на пустоту
		printf("Set are empty!\n");
	else
	{
		if (check_yanger_item(begin, c))	// проверка на принадлежность элемента множеству
		{
			while (rab != NULL)		// проход по всем элементам мл. множества
			{
				if (rab->chislo == c)	// действия при совпадении элемента множества и введенного
				{
					if (rab == begin)	// изменение указателя начала множества, если совпадение на первом элементе
					{
						begin = rab->next;
						free(rab);
						printf("Item deleted!\n");
						return begin;
					}
					else
					{
						zap->next = rab->next;
						free(rab);
						printf("Item deleted!\n");
						return begin;
					}
				}
				zap = rab;
				rab = rab->next;
			}
		}
		else
			printf("No such item\n");
	}
	return begin;
}


yanger* take_item_yanger(yanger* begin, int* chislo)
{
	int number;
	yanger* rab = begin, * zap = begin;
	if (clean(begin, 0))	// предварительная проверка мл. множества на пустоту
		printf("Set are empty!\n");
	else
	{
		srand(time(NULL));
		number = rand() % (yanger_amount_of_elements(begin) + 1);	//генерация случайного номера элемента из существующих
		for (int i = 1; i < number; i++)	//проход по всем элементам мл. множества до нужного
		{
			rab = rab->next;
		}
		*chislo = rab->chislo;	// запись взятого элемента
		printf("Was taken: %d\n", rab->chislo);
		return delete_item_yanger(begin, rab->chislo);	// удаление взятого элемента из множества
	}
}

int yanger_amount_of_elements(yanger* begin)
{
	yanger* rab = begin;
	int k = 1;
	if (clean(begin, 0))	//предварительная проверка мл. множества на пустоту 
		return 0;
	else
	{
		while (rab->next != NULL)	// подсчет количества элементов множества
		{
			rab = rab->next;
			k++;
		}
		return k;
	}
}
int older_amount_of_elements(older* begin)
{
	older* rab = begin;
	int k = 1;
	if (clean(begin, 0))	//предварительная проверка ст. множества на пустоту
		return 0;
	else
	{
		while (rab->next != NULL)	// подсчет количества элементов множества
		{
			rab = rab->next;
			k++;
		}
		return k;
	}
}

yanger* add_yanger_item(yanger* begin, int c)
{
	yanger* zap;
	if (!begin)		// действия при добавлении первого элемента мл. множества
	{
		begin = (yanger*)malloc(sizeof(yanger));
		if (!begin)
		{
			printf("Memory Allocation Error!\n");
			return NULL;
		}
		begin->chislo = c;
		begin->next = NULL;
		return begin;
	}
	else
	{
		if (!check_yanger_item(begin, c))	// проверка на наличие вводимого элемента мл. множеству
		{
			zap = begin;
			begin = (yanger*)malloc(sizeof(yanger));
			if (!begin)		// проверка на ошибку выделения памяти
			{
				printf("Memory Allocation Error!\n");
				return NULL;
			}
			begin->chislo = c;
			begin->next = zap;
			return begin;
		}
		else
			printf("Such an element already exists!\n");
	}
	return begin;
}

int check_yanger_item(yanger* begin, int c)
{
	yanger* rab = begin;
	while (rab != NULL)		// проход по всем элементам множества спроверкой на совпадние с введенным
	{
		if (rab->chislo == c)
			return 1;
		rab = rab->next;
	}
	return 0;
}

void print_yanger(yanger* begin)
{
	yanger* rab;
	rab = begin;
	while (rab != NULL)		// последовательная печать каждого элемента мл. множества
	{
		printf(" %5d", rab->chislo);
		rab = rab->next;
	}
	printf("\n");
}

int end_work_yanger()
{
	return 0;
}

int start_older()
{
	return 1;
}

older* older_clear(older* begin)
{
	older* rab = NULL, * zap = NULL;
	rab = begin;
	while (rab->next != NULL)	// последовательное очищение памяти, выделенной под элементы старшего множества
	{
		zap = rab;
		rab = rab->next;
		yanger_clear(zap->y_mn_vo);
	}
	rab->y_mn_vo = yanger_clear(rab->y_mn_vo);
	return NULL;
}

older* delete_completle_item_older(older* begin)
{
	yanger* new_mn = NULL;
	older* rab = begin, * zap = begin;
	int j = 0;
	char c, s[20];
	printf("Enter a set:");
	c = getchar();
	while (c != '\n')	// считывание чисел вводимого элемента старшего множества
	{
		j = 0;
		while (isspace(c) && c != '\n')		// пропуск всей табуляции кроме '\n'
			c = getchar();
		if (!isspace(c))
		{
			while (!isspace(c))	 // считывание очередного числа
			{
				s[j] = c;
				j++;
				c = getchar();
			}
			s[j] = '\0';
			if (s[0] != 0 && !atoi(s))	// проверка корректности ввода
				printf("Input Error!\n");
			else
				new_mn = add_yanger_item(new_mn, atoi(s));	// заполнение впомогательного мл. множества 
		}
	}
	while (rab != NULL)		// проход по всем элементам ст. множества
	{
		if (!comparison_mn(new_mn, rab->y_mn_vo))	// проверка на наличие вспомогательного мл. множества в старшем множестве
		{
			rab->y_mn_vo = yanger_clear(rab->y_mn_vo);	// удаление мл. множества при совпадении
			printf("Many have been deleted!\n");
			if (rab == begin)
				begin = begin->next;
			else
				zap->next = rab->next;
			free(rab);
			return begin;
		}
		zap = rab;
		rab = rab->next;
	}
	printf("Such a lot is missing!\n");
	return begin;
}

older* take_item_older(older* begin, yanger** zap_mn)
{
	int number;
	older* rab = begin, * zap = begin;
	if (clean(begin, 0))	// предварительна проверка ст. можества на пустоту
		printf("Set are empty!\n");
	else
	{
		srand(time(NULL));
		number = rand() % (older_amount_of_elements(begin) + 1);	// генерация случайного номера элемента ст. множества из существующих
		for (int i = 1; i < number; i++)	// проход до нужного элемента
		{
			rab = rab->next;
		}
		*zap_mn = rab->y_mn_vo;		// запись элемента
		printf("Was taken set:");
		print_yanger(rab->y_mn_vo);		// печать взятого элемента на экран
		if (rab == begin)	// изменение указателя на начало ст. множества при взятии его первого элемента
		{
			begin = rab->next;
			yanger_clear(rab->y_mn_vo);		// удаление взятого элемента
			free(rab);
			return begin;
		}
		else
		{
			zap->next = rab->next;
			yanger_clear(rab->y_mn_vo);		// удаление взятого элемента
			free(rab);
			return begin;
		}
	}
}

older* add_completle_older_item(older* begin)
{
	yanger* new_mn = NULL;
	older* rab = begin;
	int  j = 0;
	char c, s[20];
	printf("Enter a set:");
	c = getchar();
	while (c != '\n')	// считывание чисел вводимого элемента старшего множества
	{
		j = 0;
		while (isspace(c) && c != '\n')		// пропуск всей табуляции кроме '\n'
			c = getchar();
		if (!isspace(c))
		{
			while (!isspace(c))	 // считывание очередного числа
			{
				s[j] = c;
				j++;
				c = getchar();
			}
			s[j] = '\0';
			if ((s[0] != 0 && !atoi(s)) || s[0] == '\n')	// проверка корректности ввода
				printf("Input Error!\n");
			else
				new_mn = add_yanger_item(new_mn, atoi(s));	// заполнение впомогательного мл. множества 
		}
	}
	if (new_mn != NULL)		// введено ли вообще вспомогательное мл. множество
		if (begin != NULL)	// проверка ст. множества на пустоту
		{
			while (rab != NULL)		// проверка на уже наличие введенного множества в ст. множестве
			{
				if (!comparison_mn(new_mn, rab->y_mn_vo))
				{
					printf("There are already set!\n");
					return begin;
				}
				rab = rab->next;
			}
			rab = begin;
			if (!(begin = (older*)malloc(sizeof(older))))	// проверка на ошибку выделения памяти под новый элемент
			{
				printf("Memory Allocation Error!\n");
				return NULL;
			}
			begin->next = rab;
			begin->y_mn_vo = new_mn;
			return begin;
		}
		else
		{
			if (!(begin = (older*)malloc(sizeof(older))))	// проверка на ошибку выделения памяти под новый элемент
			{
				printf("Memory Allocation Error!\n");
				return NULL;
			}
			begin->next = NULL;
			begin->y_mn_vo = new_mn;
			return begin;
		}
	else
		printf("Input Error!\n");
	return begin;
}

int check_older_item(older* begin)
{
	yanger* new_mn = NULL;
	older* rab = begin;
	int j = 0;
	char c, s[20];
	printf("Enter a set:");
	c = getchar();
	while (c != '\n')	// считывание чисел вводимого элемента старшего множества
	{
		j = 0;
		while (isspace(c) && c != '\n')		// пропуск всей табуляции кроме '\n'
			c = getchar();
		if (!isspace(c))
		{
			while (!isspace(c))	 // считывание очередного числа
			{
				s[j] = c;
				j++;
				c = getchar();
			}
			s[j] = '\0';
			if (s[0] != 0 && !atoi(s))	// проверка корректности ввода
				printf("Input Error!\n");
			else
				new_mn = add_yanger_item(new_mn, atoi(s));	// заполнение впомогательного мл. множества 
		}
	}
	while (rab != NULL)		// проверка на наличие введенного множества в старшем множестве
	{
		if (!comparison_mn(new_mn, rab->y_mn_vo))
		{
			printf("Yes, there is such an element!\n");
			return 1;
		}
		rab = rab->next;
	}
	printf("No, there is no such element!\n");
	return 0;
}

void print_older(older* begin)
{
	older* zap = begin;
	printf("==================================================\n");
	while (zap != NULL)		// последовательная печать элементов ст. множества
	{
		printf("--");
		print_yanger(zap->y_mn_vo);
		zap = zap->next;
	}
	printf("==================================================\n");
}

older* older_many_check(older* begin)
{
	older* rab = begin->next, * zap;
	while (rab != NULL)		// проверка на наличие одинаковых элементов в старшем множестве 
	{
		if (!comparison_mn(rab->y_mn_vo, begin->y_mn_vo))
		{
			printf("There are already set!\n");
			zap = begin->next;
			yanger_clear(begin->y_mn_vo);	// удаление одного из одинаковых элементов ст. множества
			free(begin);
			return zap;
		}
		rab = rab->next;
	}
	return begin;
}

int end_work_older()
{
	return 0;
}
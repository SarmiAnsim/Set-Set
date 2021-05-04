#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct older //����������� ���, ������������ ������� ���������
{
	older* next; //��������� �� ��������� ������� �������� ���������
	struct yanger* y_mn_vo; //��������� �� ������� ���������
};

struct yanger //����������� ���, ������������ ������� ���������
{
	struct yanger* next; //��������� �� ��������� ������� �������� ���������
	int chislo; //������ ������ ����
};

// ��������� ���� �-��

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
	menu(); // �������� �������� ����
	return 0;
}

int menu()
{
	int d, h, f = 1, flag = 1, older_start = 0, yanger_start = 0, zap_yanger_chislo;	// �������� ����������, ����������� ��� ������ ���������
	older* begin = NULL, * zap = NULL;
	yanger* zap_older_mn;
	while (f)
	{
		if (older_start)	//������� ������ ������ �� ������� ����������
		{
			system("cls");	// �������� �������
			printf("Available actions with older set:\n");	 // ������ ������ ��������� ��������
			printf("1.Make set empty\n");
			printf("2.Check for emptiness of set\n");
			printf("3.Remove item from set\n");
			printf("4.Take any element of set\n");
			printf("5.Add item to set\n");
			printf("6.Checking for an element to belong to a set\n");
			printf("7.Print set\n");
			printf("8.Finish work\n");
			if (clean(begin, 0))	 // �������� �������� ��������� �� �������
				printf("Set are empty!\n");
			else
				print_older(begin);	 // ����� �-�� ������ �������� ��������� ����� ������� ��������
			printf("Enter action number: ");
			d = vvod();		// ����� �-�� ����� ������ ��������
			switch (d)	 // ����� �������� � ����������� �� ��������� ������
			{
			case 1: {
				if (!clean(begin, d))	 // ��������������� �������� �������� ��������� �� �������
					begin = older_clear(begin);	 // ����� �-�� �������� �������� ���������
				else
					printf("Set are empty!\n");
				break;
			}
			case 2: {clean(begin, d); break; }	// ����� �-�� �������� �������� ��������� �� �������
			case 3: {
				if (clean(begin, d))	// ��������������� �������� �������� ��������� �� �������
					printf("Many are empty!\n");
				else
				{
					begin = delete_completle_item_older(begin); break;	//����� �-�� �������� �������� �� �������� ���������
				}
				break;
			}
			case 4: {
				if (clean(begin, d))	// ��������������� �������� �������� ��������� �� �������
					printf("Many are empty!\n");
				else
					begin = take_item_older(begin, &zap_older_mn);	//����� �-�� ������ ���������� �������� �������� ���������
				break; }
			case 5: {
				printf("1.Add full set\n");
				printf("2.Go to work with junior plural\n");
				printf("Enter action number: ");
				h = vvod();	 // ����� �-�� ����� ������
				switch (h)	 // ����� �������� � ����������� �� ��������� ������
				{
				case 1: {
					begin = add_completle_older_item(begin);
					if (begin && begin->next == NULL)
						zap = begin;
					break; }
				case 2: {
					zap = begin;
					begin = (older*)malloc(sizeof(older));	// ��������� ������ ��� ����� ������� �������� ���������
					if (clean(begin, 0))	 // �������� �� ������ ��������� ������
					{
						printf("Memory Allocation Error");
						return 0;
					}
					begin->next = zap;
					begin->y_mn_vo = NULL;
					flag = 1;
					while (flag)	// ����������, ���� �� ����� ������ �������� � �������� ���������
						if (yanger_start)	 // ������� ������ ������ � ������� ����������
						{
							while (yanger_start)	 // ���� ������ � ������� ���������, ���� ��� ������
							{
								system("cls");	// �������� �������
								printf("Available actions with yanger set:\n");	 // ������ ������ ��������� ��������
								printf("1.Make set empty\n");
								printf("2.Check for emptiness of set\n");
								printf("3.Remove item from set\n");
								printf("4.Take any element of set\n");
								printf("5.Add item to set\n");
								printf("6.Checking for an element to belong to a set\n");
								printf("7.Print set\n");
								printf("8.Finish work (back)\n");
								if (!begin || clean(begin->y_mn_vo, 0))	 // �������� �������� �� �������
									printf("Set are empty!\n");
								else
								{
									printf("Set: ");
									print_yanger(begin->y_mn_vo);	 // ����� �-�� ������ �������� ��������� ����� ������� ��������
								}
								printf("Enter action number: ");
								d = vvod();	 // ����� �-�� ����� ������
								switch (d)	// ����� �������� � ����������� �� ��������� ������
								{
								case 1: {
									if (!begin || clean(begin->y_mn_vo, 0))		// ��������������� �������� �������� �� �������
										printf("Set are empty!\n");
									else
									{
										begin->y_mn_vo = yanger_clear(begin->y_mn_vo);	// ����� �-�� �������� �������� ���������
									}
									break; }
								case 2: {
									if (!clean(begin, begin ? 0 : d))	 // ��������������� �������� �������� ��������� �� �������
										clean(begin->y_mn_vo, d);	 //����� �-�� �������� �������� ��������� �� �������
									break; }
								case 3: {
									if (!begin || clean(begin->y_mn_vo, 0))		// ��������������� �������� �������� �� �������
										printf("Set are empty!\n");
									else
										begin->y_mn_vo = delete_item_yanger(begin->y_mn_vo, vvod());	//����� �-�� �������� �������� �������� ���������
									break; }
								case 4: {
									if (!begin || clean(begin->y_mn_vo, 0))		// ��������������� �������� �������� �� �������
										printf("Set are empty!\n");
									else
										begin->y_mn_vo = take_item_yanger(begin->y_mn_vo, &zap_yanger_chislo);	// ����� �-�� ������ �������� �� �������� ��������
									break; }
								case 5: {
									printf("Enter item: ");
									if (!begin)		// �������� �� ������ ���������� ������� �������� �������� ���������
									{
										begin = (older*)malloc(sizeof(older));	// ��������� ������ ��� ������ ������� �������� ���������
										if (clean(begin, 0))
										{
											printf("Memory Allocation Error");
											return 0;
										}
										begin->next = NULL;
										begin->y_mn_vo = NULL;
									}
									begin->y_mn_vo = add_yanger_item(begin->y_mn_vo, vvod());	// ����� �-�� ���������� ������ �������� �������� ���������
									break;
								}
								case 6: {
									if (!begin || clean(begin->y_mn_vo, 0))		// ��������������� �������� �������� �� �������
										printf("Set are empty!\n");
									else
									{
										if (check_yanger_item(begin->y_mn_vo, vvod()))	// ����� �-�� �������� ������� �������� � ������� ���������
											printf("Such an element exists!\n");
										else
											printf("No such item!\n");
									}
									break;
								}
								case 7: {
									if (!begin || clean(begin->y_mn_vo, 0))		// ��������������� �������� �������� �� �������
										printf("Set are empty!\n");
									else
									{
										printf("Set: ");
										print_yanger(begin->y_mn_vo);	// ����� �-�� ������ �������� ���������
									}
									break; }
								case 8: {
									if (begin)	// �������� ���������� ����� �������� � ������� ���������
									{
										begin = older_many_check(begin);	// ����� �-�� �������� ������� ���������� �������� ��������� � �������
										if (begin->y_mn_vo == NULL)
											begin = begin->next;
									}
									yanger_start = end_work_yanger();
									flag--;
									break; }
								default: {printf("No action available\n"); }	// ����� �������� ������ �������� �� ���������������� ��������� ���������
								}
								system("pause");
							}
						}
						else	// �������� �� ������ ������ � ������� ����������
						{
							while (!yanger_start && flag)	 // �� ��� ���, ���� �� �������� ������ ��� ���� �� ����� ������ �������� � �������� ���������
							{
								printf("Available actions:\n");	 // ������ ������ ��������� ��������
								printf("1.Get started\n");
								printf("2.back\n");
								printf("Enter action number :\n");
								d = vvod();		// ����� �-�� ����� ������
								switch (d)
								{
								case 1: {yanger_start = start_yanger(); break; }	// ����� �-�� ������ ������ � ������� ����������
								case 2: {--flag; begin = begin->next; break; }	// ����������� � ������ �� ������� ����������
								default: {printf("No action available\n"); }	// ����� �������� ������ �������� �� ���������������� ��������� ���������
								}
							}
						}
					break;
				}
				default: {printf("No action available\n"); }	// ����� �������� ������ �������� �� ���������������� ��������� ���������
				}
				break; }
			case 6: {
				if (clean(begin, d))	// ��������������� �������� �������� ��������� �� �������
					printf("Many are empty!\n");
				else
					check_older_item(begin);	//����� �-�� �������� ������� �������� � ������� ���������
				break; }
			case 7: {
				if (clean(begin, d))	// ��������������� �������� �������� ��������� �� �������
					printf("Many are empty!\n");
				else
					print_older(begin);		// ����� �-�� ������ �������� ���������
				break; }
			case 8: {older_start = end_work_older(); if (begin)begin = older_clear(begin); break; } // ����� �-�� �������� �������� ��������� � ��������� ������ � ���
			default: {printf("No action available\n"); }	// ����� �������� ������ �������� �� ���������������� ��������� ���������
			}
			system("pause");
			system("cls");	 // �������� �������

		}
		else	// �������� �� ������ �� ������� ����������
		{
			printf("Available actions:\n");
			printf("1.Get started\n");
			printf("Enter action number: ");
			d = vvod();		// ����� �-�� ����� ������ ��������
			if (d == 1)
			{
				older_start = start_older();	// ����� �-�� ������ ������ �� ������� ����������
			}
			else
				printf("No action available\n");	// ����� �������� ������ �������� �� ���������������� ��������� ���������
		}
	}
}

int vvod()
{
	char c, s[20];
	int j = 0;
	c = getchar();
	while (isspace(c) && c != '\n')	 // ������� ��������� �������� ���������
		c = getchar();
	while (!isspace(c))		// ���������� �������� ������� ���������
	{
		s[j] = c;
		j++;
		c = getchar();
	}
	s[j] = '\0';
	if (s[0] == '0' || atoi(s) != 0 || isspace(s[0])) // �������� �� ���� ��������� �������� �����
		return atoi(s);
	else
	{
		printf("Input Error!\n");
		printf("Repeat input: ");
		return vvod(); // ������ ������� �����
	}
}

int comparison_mn(yanger* first, yanger* second)
{
	yanger* first_rab = first, * second_rab = second;
	int f = 0;
	while (first_rab != NULL)	 // ������ �� ���� ��������� �������� ���������
	{
		if (yanger_amount_of_elements(first) == yanger_amount_of_elements(second))	//����� ���������� �� ���������� ��������� ������� ��������
		{
			if (!check_yanger_item(second, first_rab->chislo))	// �������� ���������� �������� �������� ��������� �� �������������� ������� �������� ���������
				return 1;
			first_rab = first_rab->next;
		}
		else
			return 1;	// ����� �� �-�� ��� ����������� �������
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
	while (rab->next != NULL)	// ������ �� ���� ��������� �������� ���������
	{
		zap = rab;
		rab = rab->next;
		free(zap);	// ������������ ������, ���������� ��� ��������� ������� ��. ���������
	}
	free(rab);
	return NULL;
}

int clean(void* ptr, int d)
{
	if (!ptr)	// �������� ��������� �� NULL
	{
		if (d == 2)		// ������� �-�� ��� �������� �������� ��� ��� ������ ���������?
			printf("Set are empty!\n");
		return 1;
	}
	else
	{
		if (d == 2)		// ������� �-�� ��� �������� �������� ��� ��� ������ ���������?
			printf("Set are not empty!\n");
		return 0;
	}
}

yanger* delete_item_yanger(yanger* begin, int c)
{
	yanger* rab = begin, * zap = begin;
	if (clean(begin, 0))	// ��������������� �������� ��������� �� �������
		printf("Set are empty!\n");
	else
	{
		if (check_yanger_item(begin, c))	// �������� �� �������������� �������� ���������
		{
			while (rab != NULL)		// ������ �� ���� ��������� ��. ���������
			{
				if (rab->chislo == c)	// �������� ��� ���������� �������� ��������� � ����������
				{
					if (rab == begin)	// ��������� ��������� ������ ���������, ���� ���������� �� ������ ��������
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
	if (clean(begin, 0))	// ��������������� �������� ��. ��������� �� �������
		printf("Set are empty!\n");
	else
	{
		srand(time(NULL));
		number = rand() % (yanger_amount_of_elements(begin) + 1);	//��������� ���������� ������ �������� �� ������������
		for (int i = 1; i < number; i++)	//������ �� ���� ��������� ��. ��������� �� �������
		{
			rab = rab->next;
		}
		*chislo = rab->chislo;	// ������ ������� ��������
		printf("Was taken: %d\n", rab->chislo);
		return delete_item_yanger(begin, rab->chislo);	// �������� ������� �������� �� ���������
	}
}

int yanger_amount_of_elements(yanger* begin)
{
	yanger* rab = begin;
	int k = 1;
	if (clean(begin, 0))	//��������������� �������� ��. ��������� �� ������� 
		return 0;
	else
	{
		while (rab->next != NULL)	// ������� ���������� ��������� ���������
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
	if (clean(begin, 0))	//��������������� �������� ��. ��������� �� �������
		return 0;
	else
	{
		while (rab->next != NULL)	// ������� ���������� ��������� ���������
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
	if (!begin)		// �������� ��� ���������� ������� �������� ��. ���������
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
		if (!check_yanger_item(begin, c))	// �������� �� ������� ��������� �������� ��. ���������
		{
			zap = begin;
			begin = (yanger*)malloc(sizeof(yanger));
			if (!begin)		// �������� �� ������ ��������� ������
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
	while (rab != NULL)		// ������ �� ���� ��������� ��������� ���������� �� ��������� � ���������
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
	while (rab != NULL)		// ���������������� ������ ������� �������� ��. ���������
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
	while (rab->next != NULL)	// ���������������� �������� ������, ���������� ��� �������� �������� ���������
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
	while (c != '\n')	// ���������� ����� ��������� �������� �������� ���������
	{
		j = 0;
		while (isspace(c) && c != '\n')		// ������� ���� ��������� ����� '\n'
			c = getchar();
		if (!isspace(c))
		{
			while (!isspace(c))	 // ���������� ���������� �����
			{
				s[j] = c;
				j++;
				c = getchar();
			}
			s[j] = '\0';
			if (s[0] != 0 && !atoi(s))	// �������� ������������ �����
				printf("Input Error!\n");
			else
				new_mn = add_yanger_item(new_mn, atoi(s));	// ���������� ��������������� ��. ��������� 
		}
	}
	while (rab != NULL)		// ������ �� ���� ��������� ��. ���������
	{
		if (!comparison_mn(new_mn, rab->y_mn_vo))	// �������� �� ������� ���������������� ��. ��������� � ������� ���������
		{
			rab->y_mn_vo = yanger_clear(rab->y_mn_vo);	// �������� ��. ��������� ��� ����������
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
	if (clean(begin, 0))	// �������������� �������� ��. �������� �� �������
		printf("Set are empty!\n");
	else
	{
		srand(time(NULL));
		number = rand() % (older_amount_of_elements(begin) + 1);	// ��������� ���������� ������ �������� ��. ��������� �� ������������
		for (int i = 1; i < number; i++)	// ������ �� ������� ��������
		{
			rab = rab->next;
		}
		*zap_mn = rab->y_mn_vo;		// ������ ��������
		printf("Was taken set:");
		print_yanger(rab->y_mn_vo);		// ������ ������� �������� �� �����
		if (rab == begin)	// ��������� ��������� �� ������ ��. ��������� ��� ������ ��� ������� ��������
		{
			begin = rab->next;
			yanger_clear(rab->y_mn_vo);		// �������� ������� ��������
			free(rab);
			return begin;
		}
		else
		{
			zap->next = rab->next;
			yanger_clear(rab->y_mn_vo);		// �������� ������� ��������
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
	while (c != '\n')	// ���������� ����� ��������� �������� �������� ���������
	{
		j = 0;
		while (isspace(c) && c != '\n')		// ������� ���� ��������� ����� '\n'
			c = getchar();
		if (!isspace(c))
		{
			while (!isspace(c))	 // ���������� ���������� �����
			{
				s[j] = c;
				j++;
				c = getchar();
			}
			s[j] = '\0';
			if ((s[0] != 0 && !atoi(s)) || s[0] == '\n')	// �������� ������������ �����
				printf("Input Error!\n");
			else
				new_mn = add_yanger_item(new_mn, atoi(s));	// ���������� ��������������� ��. ��������� 
		}
	}
	if (new_mn != NULL)		// ������� �� ������ ��������������� ��. ���������
		if (begin != NULL)	// �������� ��. ��������� �� �������
		{
			while (rab != NULL)		// �������� �� ��� ������� ���������� ��������� � ��. ���������
			{
				if (!comparison_mn(new_mn, rab->y_mn_vo))
				{
					printf("There are already set!\n");
					return begin;
				}
				rab = rab->next;
			}
			rab = begin;
			if (!(begin = (older*)malloc(sizeof(older))))	// �������� �� ������ ��������� ������ ��� ����� �������
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
			if (!(begin = (older*)malloc(sizeof(older))))	// �������� �� ������ ��������� ������ ��� ����� �������
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
	while (c != '\n')	// ���������� ����� ��������� �������� �������� ���������
	{
		j = 0;
		while (isspace(c) && c != '\n')		// ������� ���� ��������� ����� '\n'
			c = getchar();
		if (!isspace(c))
		{
			while (!isspace(c))	 // ���������� ���������� �����
			{
				s[j] = c;
				j++;
				c = getchar();
			}
			s[j] = '\0';
			if (s[0] != 0 && !atoi(s))	// �������� ������������ �����
				printf("Input Error!\n");
			else
				new_mn = add_yanger_item(new_mn, atoi(s));	// ���������� ��������������� ��. ��������� 
		}
	}
	while (rab != NULL)		// �������� �� ������� ���������� ��������� � ������� ���������
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
	while (zap != NULL)		// ���������������� ������ ��������� ��. ���������
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
	while (rab != NULL)		// �������� �� ������� ���������� ��������� � ������� ��������� 
	{
		if (!comparison_mn(rab->y_mn_vo, begin->y_mn_vo))
		{
			printf("There are already set!\n");
			zap = begin->next;
			yanger_clear(begin->y_mn_vo);	// �������� ������ �� ���������� ��������� ��. ���������
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
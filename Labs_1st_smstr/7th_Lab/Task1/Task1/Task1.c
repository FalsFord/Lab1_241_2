#include <stdio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	char c;
	printf("Введите символы 'a' or 'b': ");
	scanf_s("%c", &c);//считывание с консоли
	switch (c)
	{
		case 'a':
			printf("Введено 'a'.\n");
			break;
		case 'b':
			printf("Введено 'b'.\n");
			break;
		default:
			printf("Неизвестный символ\n");
		}

	getchar();
	printf("Введите любой символ: ");
	scanf_s("%c", &c);//считывание с консоли
	switch (c)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
		printf("Это цифра.\n");
		break;

	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
		printf("Это буква.\n");
		break;

	default:
		printf("Неизвестный символ.\n");
	}




	return 0;
}
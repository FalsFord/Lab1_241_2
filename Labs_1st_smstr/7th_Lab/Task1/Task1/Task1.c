#include <stdio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	char c;
	printf("������� ������� 'a' or 'b': ");
	scanf_s("%c", &c);//���������� � �������
	switch (c)
	{
		case 'a':
			printf("������� 'a'.\n");
			break;
		case 'b':
			printf("������� 'b'.\n");
			break;
		default:
			printf("����������� ������\n");
		}

	getchar();
	printf("������� ����� ������: ");
	scanf_s("%c", &c);//���������� � �������
	switch (c)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
		printf("��� �����.\n");
		break;

	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
		printf("��� �����.\n");
		break;

	default:
		printf("����������� ������.\n");
	}




	return 0;
}
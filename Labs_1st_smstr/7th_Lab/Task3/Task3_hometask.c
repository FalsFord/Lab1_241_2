#include <stdio.h>
#include<math.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int check, rub, kop, var;
	puts("������� ��������� ������� ");
	scanf_s("%d", &check);
	rub = check/100;
	kop = check - rub*100;
	//��������� ��� ������
	switch (rub % 10 ) {
	case 0:
		printf("\n����� ");
		break;
	case 1:
		printf("\n����� %d �����", rub);
		break;
	case 2:;
	case 3:
	case 4:
		printf("\n����� %d �����", rub);
		break;
	default: printf("\n����� %d ������", rub);
	}
	//��������� ��� ������
<<<<<<< HEAD
	switch (kop % 10) {
=======
	switch (kop % 100) {
>>>>>>> 4588d0b062961d92b53be187843b61b6386a89cc
	case 0:
		printf(" 0 ������ ");
		break;
	case 1:
		printf(" %d �������", kop);
		break;
	case 2:
	case 3:
	case 4:
		printf(" %d �������", kop);
		break;
<<<<<<< HEAD
=======
	case 11:
		printf(" %d ������ ", kop);
		break;
>>>>>>> 4588d0b062961d92b53be187843b61b6386a89cc
	default: printf(" %d ������", kop);
	}


}
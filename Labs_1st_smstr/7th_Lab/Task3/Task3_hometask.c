#include <stdio.h>
#include<math.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int check, rub, kop, var;
	puts("Введите стоимость покупки ");
	scanf_s("%d", &check);
	rub = check/100;
	kop = check - rub*100;
	//Окончание для рублей
	switch (rub % 10 ) {
	case 0:
		printf("\nИтого ");
		break;
	case 1:
		printf("\nИтого %d рубль", rub);
		break;
	case 2:;
	case 3:
	case 4:
		printf("\nИтого %d рубля", rub);
		break;
	default: printf("\nИтого %d рублей", rub);
	}
	//Окончание для копеек
	switch (kop % 10) {
	case 0:
		printf(" 0 копеек ");
		break;
	case 1:
		printf(" %d копейка", kop);
		break;
	case 2:
	case 3:
	case 4:
		printf(" %d копейки", kop);
		break;
	default: printf(" %d копеек", kop);
	}


}
#include<stdio.h>
#include<locale.h>
#include<math.h>
#define _USE_MATH_DEFINE
void main() {
	//Вариант 13
	setlocale(LC_ALL, "Rus");
	float one, two, three;
	int counter =0;
	puts("Введите 3 вещественных чилса через пробел ");
	scanf_s("%f %f %f", &one, &two, &three);
	printf("Вы ввели %.2f, %.2f, %.2f", one, two, three);
	
	if((-1< one && one <1) && (-1 < two && two < 1) && (-1 < three && three < 1)){
		printf("\nОтрезку (-1:1) принадлежат числа %.2f, %.2f, %.2f", one, two, three);
	}
	else if ((-1 < one && one < 1) && (-1 < two && two < 1)) {
		printf("\nОтрезку (-1:1) принадлежат числа %.2f, %.2f", one, two);
	}
	else if ((-1 < one && one < 1) && (-1 < three && three < 1)) {
		printf("\nОтрезку (-1:1) принадлежат числа %.2f, %.2f", one, three);
	}
	else if ((-1 < three && three < 1) && (-1 < two && two < 1)) {
		printf("\nОтрезку (-1:1) принадлежат числа %.2f, %.2f", two, three);
	}
	else if (-1 < one && one < 1) {
		printf("\nОтрезку (-1:1) принадлежат число %.2f", one);
	}
	else if (-1 < two && two < 1) {
		printf("\nОтрезку (-1:1) принадлежат число %.2f", two);
	}
	else if (-1 < three && three < 1) {
		printf("\nОтрезку (-1:1) принадлежат число %.2f", three);
	} else printf("\nОтрезку (-1:1) не принадлежит ни одно число");





	/*if (-1 < one && one < 1)counter+=1;
	if (-1 < two && two < 1)counter+=2;
	if (-1 < three && three < 1)counter+=4;

	switch (counter) {
	case 1: printf("\nОтрезку (-1;1) принадлежит число %f", one);
		break;
	case 2: printf("\nОтрезку(-1; 1) принадлежит число % f", two);
		break;
	case 3: printf("\nОтрезку (-1;1) принадлежит числа %f, %f", one, two);
		break;
	case 4: printf("\nОтрезку (-1;1) принадлежит число %f", three);
		break;
	case 5: printf("\nОтрезку (-1;1) принадлежит числа %f, %f", one, three);
		break;
	case 6:	printf("\nОтрезку (-1;1) принадлежит числа %f, %f", two, three);
		break;
	case 7: printf("\nОтрезку (-1;1) принадлежит числа %f, %f, %f", one, two, three);
		break;
	default: printf("\nНе одно из чисел не пренадлежит отрезку (-1;1)");
	}*/

}
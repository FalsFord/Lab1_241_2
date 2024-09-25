#include<stdio.h>
#include<locale.h>
#include<math.h>
#define _USE_MATH_DEFINE
void main() {
	setlocale(LC_ALL, "Rus");
	int years;
	puts("Введите год ");
	scanf_s("%d", &years);
	if ((years % 4 == 0 && years % 100 != 0) || years % 400 == 0 ) printf("Год %d високосный.",years); else printf("Год %d невисокосный.",years);
}	
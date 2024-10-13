#include<stdio.h>
#include<locale.h>
#include<math.h>
void main() {
	setlocale(LC_ALL, "Rus");

	int n;
	float result=0;

	//Запрос у пользователя числа n 
	puts("Введите n ");
	scanf_s("%d", &n);

	//Цикл с заданным n
	for (int i = 1; i <= n; i++) {
		result += 1. / pow((2*i + 1), 2);
	}

	printf("Результат: %f", result);
}
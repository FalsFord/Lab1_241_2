#include<stdio.h>
#include<locale.h>

void main() {

	setlocale(LC_ALL,"RUS");

	int num1;
	int num2;
	puts("Введите 1 число ");
	scanf_s("%d", &num1); 
	puts("Введите 2 число ");
	scanf_s("%d", &num2);
	printf("Введено число %d", num1);
	printf("\nВведено число %d",num2);
	printf("\nCyмма 1 и 2 чисел равна %d", num1+num2);
	printf("\nРазность 1 и 2 чисел равна  %d", num1 - num2);
	printf("\nПроизведение 1 и 2 чисел равно %d", num1*num2);
	printf("\nЧастное 1 и 2 чисел равно %d", num1 / num2);
	printf("\nОстаток равен %d", num1%num2);
	return(0);
}
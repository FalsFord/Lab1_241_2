#include<stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int N;
	puts("Введите трехзначное число ");
	scanf_s("%d", &N);
	printf("\nВаше число %d", N);
	printf("\nПоследняя цифра %d, первая - %d, сумма цифра %d равна %d", N%10,N/100,N,N/100+N%10+ N/10%10);
	int a = N / 100, b = N/10%10, c=N%10;
	printf("\nЧисло %d наоборот выглядит так %d%d%d\n", N,c,b,a);
}
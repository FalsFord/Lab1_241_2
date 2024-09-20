// 7 вариант
#include<locale.h>
#include<stdio.h>
int main() {
	setlocale(LC_ALL, "RUS");
	int n = 2, L = 353;
	float a, b;
	puts("Дано:");
	printf("\n\t%5d", n);
	printf("\n\t%5d", L);
	puts("\n\t________");
	puts("Ответ:");
	a = n;
	b = L;
	printf("\n\t%+08.3f", a/b);
}
// 7 �������
#include<locale.h>
#include<stdio.h>
int main() {
	setlocale(LC_ALL, "RUS");
	int n = 2, L = 353;
	float a, b;
	puts("����:");
	printf("\n\t%5d", n);
	printf("\n\t%5d", L);
	puts("\n\t________");
	puts("�����:");
	a = n;
	b = L;
	printf("\n\t%+08.3f", a/b);
}
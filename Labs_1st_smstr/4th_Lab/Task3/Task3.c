#include<stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int N;
	puts("������� ����������� ����� ");
	scanf_s("%d", &N);
	printf("\n���� ����� %d", N);
	printf("\n��������� ����� %d, ������ - %d, ����� ����� %d ����� %d", N%10,N/100,N,N/100+N%10+ N/10%10);
	int a = N / 100, b = N/10%10, c=N%10;
	printf("\n����� %d �������� �������� ��� %d%d%d\n", N,c,b,a);
}
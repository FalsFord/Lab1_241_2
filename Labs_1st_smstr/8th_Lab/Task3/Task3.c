#include<stdio.h>
#include<locale.h>
#include<math.h>
void main() {
	setlocale(LC_ALL, "Rus");

	int n;
	float result=0;

	//������ � ������������ ����� n 
	puts("������� n ");
	scanf_s("%d", &n);

	//���� � �������� n
	for (int i = 1; i <= n; i++) {
		result += 1. / pow((2*i + 1), 2);
	}

	printf("���������: %f", result);
}
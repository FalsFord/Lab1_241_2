#include<stdio.h>
#include<locale.h>

void main() {

	setlocale(LC_ALL,"RUS");

	int num1;
	int num2;
	puts("������� 1 ����� ");
	scanf_s("%d", &num1); 
	puts("������� 2 ����� ");
	scanf_s("%d", &num2);
	printf("������� ����� %d", num1);
	printf("\n������� ����� %d",num2);
	printf("\nCy��� 1 � 2 ����� ����� %d", num1+num2);
	printf("\n�������� 1 � 2 ����� �����  %d", num1 - num2);
	printf("\n������������ 1 � 2 ����� ����� %d", num1*num2);
	printf("\n������� 1 � 2 ����� ����� %d", num1 / num2);
	printf("\n������� ����� %d", num1%num2);
	return(0);
}
 #include<stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int walk = 4, run = walk * 3;
	float distance, time;

	puts("������� ����������, ���������� ��������� ");
	scanf_s("%f", &distance);

	time = distance / run;

	printf("������� ����� %.2f �", time);
}
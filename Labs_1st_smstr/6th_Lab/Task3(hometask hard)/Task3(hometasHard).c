#include<stdio.h>
#include<locale.h>
#include<math.h>
#define _USE_MATH_DEFINE
void main() {
	//������� 33
	setlocale(LC_ALL, "Rus");
	float x, y;
	puts("������� x � y ����� ������");
	scanf_s("%f %f", &x, &y);
	if (sqrt(pow(x, 2) + pow(y, 2)) <= 3) {
		printf("����� �� ����������� �������������� ������� f");
	}
	else if (x > 0 || y < 0 || x<-5 || y > 5) {
		printf("����� �� ����������� �������������� ������� g ");
	}
	else if (x+y >= 5 && x+y <= 0) {
		printf("����� �� ����������� �������������� ������� r");
	}
	else printf("����� ����������� �������������� �������");
	//y = x + 5 => a = 5, ������ ����� � ������ 5 �� ������ 0!
}
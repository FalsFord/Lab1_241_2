#include<stdio.h>
#include<locale.h>
#include<math.h>
#define _USE_MATH_DEFINE
void main() {
	setlocale(LC_ALL, "Rus");
	float x, f, y, z;
	puts("������� � ");
	scanf_s("%f", &x);
	puts("������� y ");
	scanf_s("%f", &y);
	puts("������� z ");
	scanf_s("%f", &z);
	printf("������� ����� x=%f, y=%f, z=%f ",x,y,z);
	printf("\nresult = %0.5f", pow(y + pow(x - 1, 1. / 3), 0.25)/ (fabs(x - y) * (pow(sin(z), 2) + tan(z))));
}
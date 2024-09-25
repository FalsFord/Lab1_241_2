#include<stdio.h>
#include<locale.h>
#include<math.h>
#define _USE_MATH_DEFINE
#define t 3
void main() {
	setlocale(LC_ALL, "Rus");
	double y,a, b, x = 4.2e-3;
	a = 1. / t + pow(x, 3);
	b = pow(t, 2) * pow(fabs(a + x), 0.5);
	y = pow(log(fabs(b + pow(a, 2))), 5);
	printf("\nx = %f", x);
	printf("\nФункция равна %.2f", y);

	puts("\nВведите x ");
	scanf_s("%f", &x);
	a = 1. / t + pow(x, 3);
	b = pow(t, 2) * pow(fabs(a + x), 0.5);
	y = pow(log(fabs(b + pow(a, 2))), 5);
	printf("\nФункция равна %.2f", y);
}
#include<stdio.h>
#include<locale.h>
#include<math.h>
#define _USE_MATH_DEFINE
void main() {
	setlocale(LC_ALL, "Rus");
	float x;
	puts("¬ведите х");
	scanf_s("%f", &x);
	/*x = x <= 3 ? (pow(x, 3)) / (pow(x, 2) + 8) : -3 * x + 9;*/
	printf("%f", (x <= 3) ? (pow(x, 3)) / (pow(x, 2) + 8) : -3 * x + 9);
}
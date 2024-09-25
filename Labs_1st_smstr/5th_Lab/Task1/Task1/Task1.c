#include<stdio.h>
#include<locale.h>
#include<math.h>
#define _USE_MATH_DEFINE
#define M_PI 3.14159265358979323846
void main() {
	setlocale(LC_ALL, "Rus");
	float gr;
	puts("¬ведите градусы угла ");
	scanf_s("%f", &gr);
	gr = gr * M_PI / 180;
	printf("ќтвет: %.6f", sin(gr));
}
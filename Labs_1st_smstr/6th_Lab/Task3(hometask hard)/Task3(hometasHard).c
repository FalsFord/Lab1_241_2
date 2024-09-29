#include<stdio.h>
#include<locale.h>
#include<math.h>
#define _USE_MATH_DEFINE
void main() {
	//Вариант 33
	setlocale(LC_ALL, "Rus");
	float x, y;
	puts("Введите x и y через пробел");
	scanf_s("%f %f", &x, &y);
	if (sqrt(pow(x, 2) + pow(y, 2)) <= 3) {
		printf("Точка не принадлежит заштрихованной области f");
	}
	else if (x > 0 || y < 0 || x<-5 || y > 5) {
		printf("Точка не принадлежит заштрихованной области g ");
	}
	else if (x+y >= 5 && x+y <= 0) {
		printf("Точка не принадлежит заштрихованной области r");
	}
	else printf("Точка принадлежит заштрихованной области");
	//y = x + 5 => a = 5, значит нужно а меньше 5 но больше 0!
}
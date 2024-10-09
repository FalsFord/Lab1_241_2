#include<stdio.h>
#include<locale.h>
#include<math.h>
void main() {
	setlocale(LC_ALL, "Rus");
	float x, y;
	puts("Задайте шаг х ");
	char word = " ";
	scanf_s("%f", &x);
	/*puts("Введите х ");
	scanf_s("%f", &x);
	y = x - 3 * powf(cosf(1.04 * x), 2);
	printf("\n%f", x - 3 * powf(cosf(1.04 * x),2));*/
	puts("___________________________");
	printf("| %-11s| %-10s |", "x","f(x)");
	for (float i = 0.15; i <= 2.1; i += x) {
		y = i - 3 * powf(cosf(1.04 * i), 2);
		printf("\n| %010.2e | %010.2e |", i, y);
	}
	return 0;
}
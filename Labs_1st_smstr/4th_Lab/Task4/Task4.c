 #include<stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int walk = 4, run = walk * 3;
	float distance, time;

	puts("Введите расстояние, пройденное мальчиком ");
	scanf_s("%f", &distance);

	time = distance / run;

	printf("Мальчик бежал %.2f ч", time);
}
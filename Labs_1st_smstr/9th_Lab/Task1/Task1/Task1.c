#include<stdio.h>
#include<locale.h>
#define ROW 9
#define COL 9
void main() {
	setlocale(LC_ALL, "Rus");
	int row, col;
	printf("\n");
	//Пример из задания
	puts("Пример из задания");
	for (row = 1; row <= ROW; ++row) {
		for (col = 1; col <= COL; col++) {
			printf("%5d", row * col);
			printf("\n");
		}
	}
	//Таблица пифагора
	printf("\nТаблица пифагора\n");
	for (row = 2; row <= ROW+1; ++row) {
		for (col = 2; col <= COL+1; col++) {
			printf("%5d\t", row * col);
		}
		printf("\n");
	}
		
	//Левый нижний угол таблицы пифагора
	printf("\nЛевый нижний угол таблицы пифагора\n");
	for (row = 2; row <= ROW + 1; ++row) {
		for (col = 2; col <= COL + 1; col++) {
			if (col > row) break; else printf("%5d\t", row * col);
		}
		printf("\n");
	}

	//Задание 1.3 Вариант 13
	int first_cycle, second_cycle, var=19;
	printf("\nЗадание 1.3 Вариант 13\n");
	for (first_cycle = 5; first_cycle >= 1; first_cycle--) {
		for (second_cycle = 1; second_cycle <= first_cycle; second_cycle++) {
			printf("\t%d", second_cycle + var);
		}
		var--;

		printf("\n");
	}
	system("pause");
}
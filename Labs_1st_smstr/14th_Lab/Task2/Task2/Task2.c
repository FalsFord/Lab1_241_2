#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<math.h>
#define N 1000
#define const 10
double* full_elements(double* array, int size) {
	float step = (2.1 - 0.15) / size;
	float x = 0.15, y;
	for (int i = 0; i < size; i++) {
		y = x - 3 * powf(cosf(1.04 * i), 2);
		x += step;
		array[i] = y;
	}
	array[size] = '\0';
}

int put_elements(double* array, int size) { for (int i = 0; i < size; i++) printf("array[%d]=%f\n", i, array[i]); }
double* calc_elements(double* array, int size) { for (int i = 0; i < size; i++) array[i] -= const; }

double sum_elements(double* array, int begin, int end) {
	double sum = 0;
	for (int i = begin; i <= end; i++) sum += array[i];
	return sum;
}

int find_element(double* array, int size, double element) {
	int n = 0, l=0;
	for (int i = 0; i < size; i++) {
		array[i] -= 0.0000001;
		printf("%f\n", array[i]);
		if ((int)(100 * element) == (int)(100 * array[i])) {
			l = i;
			n += 1;
		}
	}
	if (n == 1) return l; else return -1;
}
void main()
{
	setlocale(LC_ALL, "Rus");
	double array[N];
	int size;
	printf("Введите размер массив > ");
	scanf_s("%d", &size);
	full_elements(array, size);
	put_elements(array, size);
	printf("Обработка массива через константу\n");

	calc_elements(array, size);
	put_elements(array, size);

	int begin, end;
	printf("Введите диапозон суммы массива\n");
	printf("Начальный индекс: ");
	getchar();
	scanf_s("%d", &begin);
	printf("Конечный индекс: ");
	scanf_s("%d", &end);
	printf("Сумма диапозона: %lf",sum_elements(array, begin, end));

	double element;
	printf("\nВведите число, которое хотите найти(до сотых): ");
	scanf_s("%lf", &element);
	printf("Индекс введенного числа: %d", find_element(array, size, element));
}
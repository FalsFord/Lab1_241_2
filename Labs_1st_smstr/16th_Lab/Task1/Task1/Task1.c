#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define const 10


double* full_elements(double* array, int size) {
	float step = (2.1 - 0.15) / size;
	float x = 0.15, y;
	for (int i = 0; i < size; i++) {
		y = x - 3 * powf(cosf(1.04 * i), 2);
		x += step;
		array[i] = y;
	}
}

double* calc_elements(double* array, int size) { for (int i = 0; i < size; i++) array[i] -= const; }


int printe(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		printf("array[%d] = %f\n", i, ptr_array[i]);
	}
}

int main() {

	setlocale(LC_ALL, "ru");

	double* ptr_array;
	int size;

	printf("¬ведите размер массива: ");
	scanf_s("%d", &size);

	ptr_array = (double*)malloc(size * sizeof(double));

	if (ptr_array == NULL) {
		puts("error");
		return -1;
	}

	full_elements(ptr_array, size);
	calc_elements(ptr_array, size);
	printe(ptr_array, size);

	free(ptr_array);

}
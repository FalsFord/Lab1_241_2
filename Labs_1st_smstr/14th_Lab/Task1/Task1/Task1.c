#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<math.h>
#define N 1000
#define const 10
double* full_elements(double* array, int size) {
		float step = (2.1 - 0.15) / size;
		float x = 0.15,y;
		for (int i = 0; i < size; i++) {
			y = x - 3 * powf(cosf(1.04 * i), 2);
			x += step;
			array[i] = y;
			}
		array[size] = '\0';
}

int put_elements(double* array, int size) { for (int i = 0; i < size; i++) printf("array[%d]=%f\n", i, array[i]); }
double* calc_elements(double* array, int size) { for (int i = 0; i < size; i++) array[i] -= const; }

void main()
{
	setlocale(LC_ALL, "Rus");
	double array[N];
	int size;
	printf("¬ведите размер массив > ");
	scanf("%d", &size);
	full_elements(array, size);
	put_elements(array, size);
	printf("ќбработка массива через константу\n");

	calc_elements(array, size);
	put_elements(array, size);

}
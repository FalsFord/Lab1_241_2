#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define N 100
float function(float* array, int size) {
	float A, B, count=array[0];
	printf("Теперь введите диапазон значений.\n");
	printf("Значение A: ");
	scanf_s("%f", &A);
	printf("Значение B: ");
	scanf_s("%f", &B);
	for (int i = 0; i < size; i++) { if (array[i] >= A && array[i] <= B && array[i]<=count)count = array[i]; }
	return count;
}
void main()
{
	setlocale(LC_ALL, "Rus");
	float array[N];
	int size;
	printf("Введите размер массив > ");
	scanf_s("%d", &size);
	for (int i = 0; i < size; i++) {
		printf("array[%d]=", i);
		scanf_s("%f", &array[i]);
	}

	printf("Наименьшее число в массиве: %f", function(array, size));

}
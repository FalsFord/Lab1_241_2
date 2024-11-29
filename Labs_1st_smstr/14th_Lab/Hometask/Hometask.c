#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define N 100
float function(float* array, int size, float A) {
	float sumAv=0;
	int k;
	
	printf("Введите число k: ");
	scanf_s("%d", &k);
	for (int i = 0; i < size; i+=k) {
		if(i!=0)sumAv += fabs(A -array[i]);
	}
	sumAv = sumAv / (size / k);
	return sumAv;
}
void main()
{
	setlocale(LC_ALL, "Rus");
	float array[N], A;
	int size;
	printf("Введите размер массив > ");
	scanf_s("%d", &size);
	for (int i = 0; i < size; i++) {
		printf("array[%d]=", i);
		scanf_s("%f", &array[i]);
	}
	printf("Задайте число А: ");
	scanf_s("%f", &A);
	
	printf("Среднее отклонение от числа %f = %f", A,function(array, size,A));

}
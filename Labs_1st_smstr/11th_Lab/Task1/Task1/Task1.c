#include<stdio.h>
#include<locale.h>
#define const 5
#define N 10
void main() {
	setlocale(LC_ALL, "Rus");
	float A[N],temp,sum=0;
	
	for (int i = 0; i < 10; i++) {
		printf("a[%d]=", i);
		scanf_s("%f", &temp);
		A[i] = temp;
		sum += A[i]-const;
	}
	printf("| %s | %s | %s |", "индекс", "исходное число", "новое значение");
	for (int i = 0; i < 10; i++) {
		printf("\n| %-6d | %-14.2f | %-14.2f |", i, A[i], A[i] - const);
	}
	printf("\nСреднеарифметическое массива равно %f", sum / N);
	
}
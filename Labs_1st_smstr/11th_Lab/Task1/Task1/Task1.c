#include<stdio.h>
#include<locale.h>
#define const 3.1415926535798932384626
void main() {
	setlocale(LC_ALL, "Rus");
	float A[10],temp;
	for (int i = 0; i < 10; i++) {
		printf("a[%d]= ", i + 1);
		scanf_s("%f", &temp);
		A[i] = temp;
		A[i] -= const;
		printf("%f", A[i]);
	}

}
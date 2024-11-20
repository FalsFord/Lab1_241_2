#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
void main(void)
{
	setlocale(LC_ALL, "Rus");
	int x = 0x12345678;
	int *prt;
	unsigned char *a1, *a2, *a3, *a4;
	unsigned char *a;

	prt = &x;
	a = (unsigned char*)prt;

	a1 = a + 3;
	a2 = a + 2;
	a3 = a + 1;
	a4 = a;	
	printf("%.2x\n%.2x\n%.2x\n%.2x\n", *a1, *a2, *a3, *a4);

	int r = 12345.0;
	double r1 = 12345.0;
	float r2 = 12345.0;

	int* R = &r;
	double* R1 = &r1;
	float* R2 = &r2;
	printf("%p\n", R);
	printf("%p\n", R1);
	printf("%p\n", R2);

}
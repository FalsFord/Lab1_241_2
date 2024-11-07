#include<stdio.h>
#include<locale.h>
void main() {
	setlocale(LC_ALL, "Rus");
	int *pa, x = 5;
	pa = &x;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa++;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa--;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);

	double *pa2, x2= 5;
	pa2 = &x2;
	printf("\n");
	printf("По адресу %p хранится *ptr=%g\n", pa2, *pa2);
	pa2++;
	printf("По адресу %p хранится *ptr=%g\n", pa2, *pa2);
	pa2--;
	printf("По адресу %p хранится *ptr=%g\n", pa2, *pa2);

	fflush(stdin);
	printf("\n");
	char *pa3, x3 = 5;
	pa3 = &x3;
	printf("По адресу %p хранится *ptr=%c\n", pa3, *pa3);
	pa3++;
	printf("По адресу %p хранится *ptr=%c\n", pa3, *pa3);
	pa3--;
	printf("По адресу %p хранится *ptr=%c\n", pa3, *pa3);

	printf("\n");

	long double *pa4, x4 = 5;
	pa4 = &x4;
	printf("\n");
	printf("По адресу %p хранится *ptr=%g\n", pa4, *pa4);
	pa4++;
	printf("По адресу %p хранится *ptr=%g\n", pa4, *pa4);
	pa4--;
	printf("По адресу %p хранится *ptr=%g\n", pa4, *pa4);
	
	printf("\n");

	short unsigned *pa5, x5 = 5;
	pa5 = &x5;
	printf("\n");
	printf("По адресу %p хранится *ptr=%d\n", pa5, *pa5);
	pa5++;
	printf("По адресу %p хранится *ptr=%d\n", pa5, *pa5);
	pa5--;
	printf("По адресу %p хранится *ptr=%d\n", pa5, *pa5);

	printf("\n");

	_Bool *pa6, x6 = 5;
	pa6 = &x6;
	printf("\n");
	printf("По адресу %p хранится *ptr=%d\n", pa6, *pa6);
	pa6++;
	printf("По адресу %p хранится *ptr=%d\n", pa6, *pa6);
	pa6--;
	printf("По адресу %p хранится *ptr=%d\n", pa6, *pa6);
}
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

}
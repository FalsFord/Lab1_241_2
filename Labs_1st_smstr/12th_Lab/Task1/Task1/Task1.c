#include<stdio.h>
#include<locale.h>
void main() {
	setlocale(LC_ALL, "Rus");
	int *pi, i = 5;
	float *pf, f = 2.1f;
	char *pc, c = 'c';
	double *pd, d = 10e-2;
	printf("%lu\n", sizeof(pi));
	printf("%lu\n", sizeof(pf));
	printf("%lu\n", sizeof(pc));
	printf("%lu\n", sizeof(pd));

}
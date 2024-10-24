#include<stdio.h>
#include<locale.h>
#include<math.h>
int funcfact(int f) {
	int factorial = 1;
	for (int j = 1; j <= f; j++) factorial *= j;
	return factorial;
}

double sin_n(double x, int n) {
	double sinx = 0;
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 0)sinx -= pow(x, 2 * i - 1) / funcfact(2 * i - 1); else sinx += pow(x, 2 * i - 1) / funcfact(2 * i - 1);
		}
		return sinx;
}
int main() {
	int x, n;
	setlocale(LC_ALL, "Rus");

	puts("Введите х ");
	scanf_s("%d", &x);

	puts("Введите n ");
	scanf_s("%d", &n);

	printf("Синус си %f", sinf(x));
	printf("\nSinx = %f", sin_n(x,n));


}



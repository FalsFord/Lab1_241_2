#include<stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int a = 11, b = 3;
	int x = a/b;
	float y = a/b;
	double z = a/b;
	printf("%d\n%f\n%e", x, y, z);
	printf("\n%f", (float)a / b);
	printf("\n%e", (double)a / b);

}
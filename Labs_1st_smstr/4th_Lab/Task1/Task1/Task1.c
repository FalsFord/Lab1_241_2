#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
	#include<locale.h>
	

	int main() {
		setlocale(LC_ALL, "Rus");
		puts("1.\n");
		char c = '!';
		int i = 2;
		float f = 3.14f;
		double d = 5e-12;
		printf("char %c, int %d, float %f, double %e", c, i, f, d);
	
		puts("\nchar: ");
		scanf("%c", &c);

		puts("int: ");
		scanf("%d", &i);

		puts("float: ");
		scanf("%f", &f);

		puts("double: ");
		scanf("%le", &d);

		printf("char %c, int %d, float %f, double %e", c, i, f, d);
	
		int cel = f;
		float drob = f - cel;
		printf("\n%d, %f ", cel, drob);
	
		char ch;
		puts("\n1b");
		puts("\nВведите один символ ");
		getchar();
		scanf("%c", &ch);
		printf("\nCH=%c", ch);

		printf("\n%x", ch);
		printf("\n%o",ch);

		printf("\n1v");
		int v;
		puts("\nВведите число");
		scanf_s("\n%d", &v);
		printf("Вывод числа %d в десятичное равно %f ", v, .1 / v);
	}
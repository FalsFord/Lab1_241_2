#include<stdio.h>
#include<locale.h>
void main() {
	setlocale(LC_ALL, "Rus");
	char simbol, a1,a2;
	int changer, counter;
	puts("Введите кол-во символов ");
	scanf_s("%d", &counter);
	getchar();
	puts("Введите символ вначале ");
	scanf_s("%c", &simbol);
	getchar();
	puts("Введите 1 символ ");
	scanf_s("%c", &a1);
	getchar();
	puts("Введите 2 символ ");
	scanf_s("%c", &a2);
		for (int start = 1; start <= counter; start++) {
			if (start == 1) printf("%c",simbol);
			changer =  counter / 2 >= start ? printf("%c",a1) : printf("%c",a2);
			putchar('!');
		}
}
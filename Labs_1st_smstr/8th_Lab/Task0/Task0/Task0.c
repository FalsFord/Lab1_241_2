#include<stdio.h>
#include<locale.h>
void main() {
	setlocale(LC_ALL, "Rus");
	char symbol, a1,a2;
	int changer, counter;
	puts("������� ���-�� �������� ");
	scanf_s("%d", &counter);
	getchar();
	puts("������� ������ ������� ");
	scanf_s("%c", &symbol);
	getchar();
	puts("������� 1 ������ ");
	scanf_s("%c", &a1);
	getchar();
	puts("������� 2 ������ ");
	scanf_s("%c", &a2);
		for (int start = 1; start <= counter; start++) {
			if (start == 1) printf("%c",symbol);
			changer =  counter / 2 >= start ? printf("%c",a1) : printf("%c",a2);
			putchar('!');
		}
}
#include <stdio.h>
#include<math.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");	
	float x, y;
	int a, b;
	char c;
	puts("Введите выражение(проблел между знаокм операции и числом ставить НЕ надо!).");
	scanf_s("%f%c%f", &x, &c,1, &y);
	switch (c) {
	case '+':
		printf("=%f", x+y);
		break;
	case '-':
		printf("=%f", x - y);
		break;
	case '*':
		printf("=%f", x * y);
		break;
	case '/':
		printf("=%f", x / y);
		break;
	case'%':
		a = x;
		b = y;
		printf("=%d", a %  b);
		break;
	case '^':
		printf("=%f", pow(x, y));
		break;
	default:
		puts("Не понял вашу операцию");
	}

}
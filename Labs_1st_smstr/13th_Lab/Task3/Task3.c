#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#define N 100
void main() {
	setlocale(LC_ALL, "Rus");
	char array[N];
	printf("Введите предложение.\n");
	char* a = fgets(array, N, stdin);
	int len = strlen(array) - 1;

	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (isdigit(array[i])) sum += array[i] - '0';
		/*if (isdigit(array[i])) sum += array[i] - 48;*/
	}
	printf("Введено символов: %d\n",len);
	printf("Сумма всех цифр в предложении: %d\n", sum);
	return 0;
}




//int transDigit(char digit) {
//	switch (digit) {
//	case '0':
//		return 0;
//		break;
//	case '1':
//		return 1;
//		break;
//	case '2':
//		return 2;
//		break;
//	case '3':
//		return 3;
//		break;
//	case '4':
//		return 4;
//		break;
//	case '5':
//		return 5;
//		break;
//	case '6':
//		return 6;
//		break;
//	case '7':
//		return 7;
//		break;
//	case '8':
//		return 8;
//		break;
//	case '9':
//		return 9;
//		break;
//	}
//
//}
//void main() {
//	setlocale(LC_ALL, "Rus");
//	char array[N];
//	printf("Введите предложение.\n");
//	char* a = fgets(array, N, stdin);
//	int len = strlen(array) - 1;
//
//	int sum = 0;
//	for (int i = 0; i < len; i++) {
//		if (isdigit(array[i])) sum += transDigit(array[i]);
//	}
//	printf("Введено сиволов: %d \n", len);
//	printf("Сумма всех цифр в предложении: %d\n", sum);
//	return 0;
//}
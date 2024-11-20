#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<Windows.h>
#define N 100


//void main() {
//	setlocale(LC_ALL, "Rus");
//	SetConsoleCP(1251);
//	char Name[N];
//	char Snew[N];
//	
//	puts("Введите ваше имя: ");
//	scanf_s("%s", Name, (unsigned int)sizeof(Name));
//	printf("Здравствуйте, %s! Теперь введите приветсвие: ",Name);
//	getchar();
//	char* snew =  gets(Snew);
//	strcat(Snew,Name);
//	printf("%s!\n", Snew);
//
//	printf("Задание 1.2\n");
//	for (int i = 0; i < strlen(Snew); i++) {
//		Snew[i] = toupper(Snew[i]);
//		
//	}
//	printf("%s", Snew);
//
//	printf("\nЗадание 1.3\n");
//	char At[41];
//	int len = 40 - strlen(Snew);
//	
//	for (int i = 0; i < 40 - strlen(Snew); i++) At[i] = '!';
//	At[40 - strlen(Snew)] = '\0';
//	
//	strcat(Snew, At);
//	printf("%s", Snew);
// 
//	return 0;
//}


void main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	char Name[N];
	char Snew[N];

	puts("Введите ваше имя: ");
	scanf_s("%s", Name, (unsigned int)sizeof(Name));
	printf("Здравствуйте, %s! Теперь введите приветсвие: ", Name);
	getchar();

	char* snew = gets(Snew);
	strcat(Snew, Name);
	printf("%s!\n", Snew);

	printf("Задание 1.2\n");

	for (int i = 0; i < strlen(Snew); i++) Snew[i] = toupper(Snew[i]);
	printf("%s\n", Snew);

	printf("Задание 1.3\n");
	int n;
	puts("Задайте длину строки: ");
	scanf_s("%d", &n);
	char* vosk, len = n - strlen(Snew);
	vosk = malloc((len + 1) * sizeof(char));
	for (int i = 0; i < len; i++) vosk[i] = '!';
	vosk[len] = '\0';

	strcat(Snew, vosk);
	printf("%s\n", Snew);

	free(vosk);

	return 0;
}
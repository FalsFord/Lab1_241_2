#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<Windows.h>
#define N 100
void main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	char Name[N];
	char Snew[N];
	
	puts("Введите ваше имя: ");
	scanf_s("%s", Name, (unsigned int)sizeof(Name));
	printf("Здравствуйте, %s! Теперь введите приветсвие: ",Name);
	getchar();
	char* snew =  gets(Snew);

	char DubSnew[N];

	for (int i = 0; i < strlen(Snew); i++)DubSnew[i] = Snew[i];
	DubSnew[strlen(Snew)] = '\0';

	printf("%s!\n", DubSnew);
	strcat(Snew,Name);

	printf("%s!\n", Snew);

	printf("Номер 7)\n");

	char FirPol[N];
	char SecPol[N];

	for (int i = 0; i < strlen(Name) / 2; i++) FirPol[i] = tolower(Name[i]);
	FirPol[strlen(Name) / 2] = '\0';

	for (int i = 0, n = strlen(Name)/2; i <= strlen(Name)/2; i++,n++) SecPol[i] = toupper(Name[n]);
	SecPol[strlen(Name) / 2+1] = '\0';

	strcat(DubSnew, FirPol);
	strcat(DubSnew, SecPol);

	printf("%s!", DubSnew);
 
	return 0;
}
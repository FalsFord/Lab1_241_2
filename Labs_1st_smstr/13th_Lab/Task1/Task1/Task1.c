#include<stdio.h>
#include<locale.h>
#include<string.h>
#define N 100
void main() {
	setlocale(LC_ALL, "Rus");
	char Name[N];
	const char Snew[N];
	char* name,*snew;

	puts("������� ���� ���: ");
	name = gets(Name);
	printf("������������, %s! ������ ������� ����������.\n ",Name);
	snew = gets(Snew);
	strcat_s(Snew,N,Name);
	printf("%s!", Snew);


}
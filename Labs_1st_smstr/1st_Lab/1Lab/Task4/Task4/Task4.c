#include <locale.h>
#include <stdio.h>

void name() {
	setlocale(LC_ALL, "RUS");
	puts("");
	puts("");
	puts("          * * * * * * * * * * * * * * * * * * * * * *");
	puts("          *                                         *");
	puts("          * ����: ���������� ����������� ���������� *");
	puts("          *                                         *");
	puts("          * ��������: ��������� ����                *");
	puts("          *                                         *");
	puts("          * * * * * * * * * * * * * * * * * * * * * *");
}

void date() {
	puts("              _          _   _     _    _   ");
	puts("             | |  /|    | | |_    | |  |_   ");
	puts("             |_|   | .  |_|  _| . |_|  |_|  ");
}

void main()
{
	name();
	date();
	return(812);
}
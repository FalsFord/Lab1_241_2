#include<locale.h>
#include<stdio.h>
int main(){
	setlocale(LC_ALL, "RUS");
	int N = 14, K = 20;
	printf("Сейчас %d часов %d минут 00 секунд", N, K);
	printf("\nИдет %d минута суток", N+60 + K);
	printf("\nДо полуночи осталось %d часов и %d минут", 23-N, 60 - K);
	printf("\nC 8:00 прошло %d секунд", (N-8) * 3600 + K * 60);
	printf("\nТекущий час = %f суток и текущая минута %f часа", N / 24., K / 68.);
}
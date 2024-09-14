#include<stdio.h>
#include<locale.h>
#define M 1.852;
#define S 1.609;
#define R 1.475;
#define C 7.468;
#define G 7412.6;
void main() {
	setlocale(LC_ALL, "RUS");
	int km;
	float result;
	printf("Введите км для перевода в мили ");
	scanf_s("%d", &km);
	result = km / M;
	printf("\nB морских милях = %f", result);
	result = km / S;
	printf("\nB сухопутных милях = %f", result);
	result = km / R;
	printf("\nB Римских милях = %f", result);
	result = km / C;
	printf("\nВ старорусских милях %f", result); 
	result = km / G;
	printf("\nB rеографических милях = %f", result);
} 
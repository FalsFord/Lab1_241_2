#include<locale.h>
#include<stdio.h>
int main(){
	setlocale(LC_ALL, "RUS");
	int N = 14, K = 20;
	printf("������ %d ����� %d ����� 00 ������", N, K);
	printf("\n���� %d ������ �����", N+60 + K);
	printf("\n�� �������� �������� %d ����� � %d �����", 23-N, 60 - K);
	printf("\nC 8:00 ������ %d ������", (N-8) * 3600 + K * 60);
	printf("\n������� ��� = %f ����� � ������� ������ %f ����", N / 24., K / 68.);
}
#include<stdio.h>
#include<locale.h>
#include<math.h>
void main() {
	setlocale(LC_ALL, "Rus");
	int n, m, sum, s = 0, i = 0,k = 1;
	float grad;

	puts("������� n ");
	scanf_s("%d", &n);
	puts("������� m ");
	scanf_s("%d", &m);
	//1 
	sum = (n + m) * (m - n + 1) / 2;
	printf("����� �� ������� ����. ���������� ����� %d", sum);

	for (int i = m; i >= n; i--) { s += i; printf("\n��������� %d ��� ", k++); }
	printf("\n��������� %d", s);

	//1 a

	for (int i = 1; i <= n; i++) {
		grad = pow(2, i);
		printf("\n2^%d = %4.0f", i, grad);
		if (grad >= m) {
			printf("\n��������� %.1fK", grad / 1024);
			break;
		}
	}

}
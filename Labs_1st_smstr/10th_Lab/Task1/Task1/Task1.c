#include<stdio.h>
#include<locale.h>
#include<math.h>
float func1(float x) {
	float operation;
	if (x <= 3) {
		operation = pow(x, 2) - 3 * x + 9;
	}
	else operation = 1. / (pow(x, 3) + 3);
	return operation;
}
float func2(float x) {
	float operation;
	operation = x * exp(sin(pow(x, 2)));
	return operation;
}
int main() {
	setlocale(LC_ALL, "Rus");
	float x,multipl, quaras,doublesum;
	puts("������� � ");
	scanf_s("%f", &x);

	//��������� �������
	multipl = func1(x) * func2(x);
	printf("\n������������ ������� ����� %f", multipl);
	
	//�������� ���������
	quaras = pow(func1(x),2) - pow(func2(x),2);
	printf("\n�������� ��������� ������� ����� %f", quaras);

	//��������� ����� �������
	doublesum = 2 * (func1(x) + func2(x));
	printf("\n��������� ����� ������� ����� %f", doublesum);
}

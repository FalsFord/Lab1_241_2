#include <stdio.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14
int funcfact(int f) {
    int factorial = 1;
    for (int j = 1; j <= f; j++) factorial *= j;
    return factorial;
}

double sin_n(double x, int n) {
    double sinx = 0;
    for (int i = 0; i < n; i++) {
        int sign = (i % 2 == 0) ? 1 : -1;
        sinx += sign * pow(x, 2 * i + 1) / funcfact(2 * i + 1);
    }
    return sinx;
}
double sin_eps(double x, double eps) {
    double sinx = 0;
    for (int i = 0; i >=0; i++) {
        int sign = (i % 2 == 0) ? 1 : -1;
        sinx += sign * pow(x, 2 * i + 1) / funcfact(2 * i + 1);
        if (fabs(sinx) > eps)break;
    }
    return sinx;
}

int main() {
    double x;
    int n;
    setlocale(LC_ALL, "Rus");

    puts("������� � (� ��������) ");
    scanf_s("%lf", &x);

    puts("������� n ");
    scanf_s("%d", &n);

    // �������������� �� �������� � �������
    x = x * M_PI / 180;

    printf("����� � �������������� ����������: %f\n", sin(x));
    printf("����� � �������������� ���������� � ��� �������: %lf\n", sin_n(x, n));

    return 0;
}


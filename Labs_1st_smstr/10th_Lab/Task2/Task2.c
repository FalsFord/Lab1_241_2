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

    puts("Введите х (в градусах) ");
    scanf_s("%lf", &x);

    puts("Введите n ");
    scanf_s("%d", &n);

    // Преобразование из градусов в радианы
    x = x * M_PI / 180;

    printf("Синус с использованием библиотеки: %f\n", sin(x));
    printf("Синус с использованием разложения в ряд Тейлора: %lf\n", sin_n(x, n));

    return 0;
}


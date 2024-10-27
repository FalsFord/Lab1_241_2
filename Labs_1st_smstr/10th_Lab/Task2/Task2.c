#include <stdio.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.1415926535897932384626
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
     for (int i = 0; fabs(sinx)<eps; i++) {
        int sign = (i % 2 == 0) ? 1 : -1;
        sinx += sign * pow(x, 2 * i + 1) / funcfact(2 * i + 1);
    }
    return sinx;
}

double func_arccos(double x, int n) {
    double arccos = (M_PI / 2) - x, mpl1=1, mpl2=1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            mpl1 *= 2 * j - 1;
            mpl2 *= 2 * j + 1;
       }
       arccos -= mpl1 * pow(x, mpl2) / mpl2;
    }
    return arccos;
}

int main() {
    double x, eps;
    int n;
    setlocale(LC_ALL, "Rus");

    puts("Введите х в радианах(x <= |6,28|)  ");
    scanf_s("%lf", &x);

    puts("Введите n ");
    scanf_s("%d", &n);
    
    getchar();
    puts("Введите точность");
    scanf_s("%lf", &eps);

    if (x > 3.14)x =-1*(x - 3.14);
    // Преобразование из градусов в радианы
    /*x = x * M_PI / 180;*/

    printf("Синус с использованием библиотеки: %f\n", sin(x));
    printf("Синус с использованием разложения в ряд Тейлора: %lf\n", sin_n(x, n));
    printf("Синус c точностью eps, ряд Маклорена: %lf\n", sin_eps(x, eps));

    printf("Аркосинус с использованием разложения в ряд: %lf\n", func_arccos(x, n));
    return 0;
}


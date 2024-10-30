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
       (i % 2 == 0) ? 1 : -1;
        sinx += (i % 2 == 0 ? 1 : -1) * pow(x, 2 * i + 1) / funcfact(2 * i + 1);
    }
    return sinx;
}

double sin_eps(double x, double eps) {
    double ans = 0;
    int i = 0;
    double term=0;
    printf("\n|  N  |    sin_N    |  отклонение |");
        do {
            printf("\n|  %d  |  %+.6f  | %+.5e|", i, term, sin(x) - ans);
            term = (i % 2 == 0 ? 1 : -1) * pow(x, 2 * i + 1) / funcfact(2 * i + 1);
            ans += term;
            i++;
        } while (fabs(term) > eps);
        return ans;
}
//double sin_eps(double x, double eps) {
//    double sinx = 0;
//    double sum = 0;
//     for (int i = 0;fabs(sinx)>eps; i++) {
//        sinx = (i % 2 == 0 ? 1 : -1) * pow(x, 2 * i + 1) / funcfact(2 * i + 1);
//        sum += sinx;
//    }
//    return sum;
//}
//double sin_eps(double x, double eps) {
//
//    double term = x; // первый член ряда (x^1 / 1!)
//    double sum = term; // сумма ряда
//    int n = 1; // счетчик для факториала в знаменателе и степени x
//
//    // Цикл для вычисления членов ряда до достижения заданной точности
//    while (fabs(term) > eps) {
//        n += 2;
//        term *= -x * x / (n * (n - 1)); // вычисление следующего члена ряда
//        sum += term;
//    }
//
//    return sum;
//}

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
    double x, eps, sum_eps;
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


    printf("Синус с использованием библиотеки: %f\n", sin(x));
    printf("Синус с использованием разложения в ряд Тейлора: %lf\n", sin_n(x, n));

    sin_eps(x, eps);

    printf("\nАркосинус с использованием разложения в ряд: %lf\n", func_arccos(x, n));
    return 0;
}


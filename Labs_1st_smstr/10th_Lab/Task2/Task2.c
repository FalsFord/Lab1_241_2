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
        sinx += (i % 2 == 0 ? 1 : -1) * pow(x, 2 * i - 1) / funcfact(2 * i - 1);
    }
    return sinx;
}
double sin_N(double x, int n) {
    double sinx = 0;
    printf("\n|   N   |    sin_N    |  отклонение |");
    for (int i = 1; i < n+1; i++) {\
        printf("\n|   %2d  |  %+.6f  | %+.5e|", i, sinx, sin(x) - sinx);
        sinx += (i % 2 == 0 ? 1 : -1) * pow(x, 2 * i + 1) / funcfact(2 * i + 1);
    }
    return sinx;
}

double sin_eps(double x, double eps) {
    double ans = 0;
    int i = 0;
    double term=0;
    /*printf("\n|  N  |    sin_N    |  отклонение |");*/
        do {
            /*printf("\n|  %d  |  %+.6f  | %+.5e|", i, term, sin(x) - ans);*/
            term = (i % 2 == 0 ? 1 : -1) * pow(x, 2 * i + 1) / funcfact(2 * i + 1);
            ans += term;
            i++;
        } while (fabs(term) > eps);
        return ans;
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


    printf("Синус с использованием библиотеки: %f\n", sin(x));
    printf("Синус с использованием разложения в ряд Тейлора: %lf\n", sin_n(x, n));
    printf("Синус через ряд Маклорена(ввод точности) равен %lf", sin_eps(x, eps));

    sin_N(x, n);

    printf("\nАркосинус с использованием разложения в ряд: %lf\n", func_arccos(x, n));
    return 0;
}


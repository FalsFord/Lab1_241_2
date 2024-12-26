#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

typedef double (*TFun)(double);

double funY(double);
double funV(double);
double funS(double);

int t_rez(TFun, double, double, double);
void create2Dmassive(TFun, double, double, double, int);
double action(TFun, double, double, double, double, double);

void main() {
    setlocale(LC_ALL, "ru");
    double a, b, h;
    printf("Введите начальное значение интервала a=");
    scanf_s("%lf", &a);
    printf("Введите конечное значение интервала b=");
    scanf_s("%lf", &b);
    printf("Введите шаг h=");
    scanf_s("%lf", &h);

    int num = 0, count = 0;
    double xmin = 0, xmax = 0;

    printf("Выберите функцию:\n");
    printf("1. Y(x) \n");
    printf("2. V(x) \n");
    printf("3. S(x) \n");
    printf("4. Выход\n");
    scanf_s("%d", &num);
    switch (num) {
    case 1:
        count = t_rez(funY, a, b, h);
        create2Dmassive(funY, a, b, h, count);
        printf("Введите xmin=");
        scanf_s("%lf", &xmin);
        printf("Введите xmax=");
        scanf_s("%lf", &xmax);
        printf("Максимальная точка функции равна при x=%f\n", action(funY, xmin, xmax, a, b, h));
        break;
    case 2:
        count = t_rez(funV, a, b, h);
        create2Dmassive(funV, a, b, h, count);
        printf("Введите xmin=");
        scanf_s("%lf", &xmin);
        printf("Введите xmax=");
        scanf_s("%lf", &xmax);
        printf("Максимальная точка функции равна при x=%f\n", action(funV, xmin, xmax, a, b, h));
        break;
    case 3:
        count = t_rez(funS, a, b, h);
        create2Dmassive(funS, a, b, h, count);
        printf("Введите xmin=");
        scanf_s("%lf", &xmin);
        printf("Введите xmax=");
        scanf_s("%lf", &xmax);
        printf("Максимальная точка функции равна при x=%f\n", action(funS, xmin, xmax, a, b, h));
        break;
    case 4:
        break;
    }
}

double action(TFun ptrf, double xmin, double xmax, double xn, double xk, double h) {
    double l = -INFINITY;
    double xt = 0;
    for (double x = xn; x <= xk; x += h) {
        if (x >= xmin && x <= xmax) {
            if (ptrf(x) >= l) {
                l = ptrf(x);
                xt = x;
            }
        }   
    }
    return xt;
}

void create2Dmassive(TFun f, double a, double b, double h, int count) {
    double** array = (double**)malloc(count * sizeof(double*));
    if (array == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        array[i] = (double*)malloc(2 * sizeof(double));
        if (array[i] == NULL) {
            fprintf(stderr, "Ошибка выделения памяти\n");
            exit(1);
        }
    }

    double n = a;
    for (int i = 0; i < count; i++) {
        array[i][0] = n;
        array[i][1] = f(n);
        n += h;
    }

    printf("\n");
    printf("Двумерный массив аргументов и значений функций\n");
    for (int i = 0; i < count; i++) {
        printf("%.2f %.2f\n", array[i][0], array[i][1]);
    }

    for (int i = 0; i < count; i++) {
        free(array[i]);
    }
    free(array);
}

double funY(double x) {
    if (x > 0) return (fabs(sqrt(pow(x, 3))));
    return 0; // Возвращаем 0, если условие не выполняется
}

double funV(double x) {
    if (x > 1) return sqrt(tan(x * x - 1));
    else if (x >= 0 && x <= 1) return -2 * x;
    else return exp(cos(x));
}

double funS(double x) {
    double sum = 0;
    for (int i = 1; i <= 7; i += 2) {
        sum += (1.0 / i) * pow((x - 1) / (x + 1), i);
    }
    return sum;
}

int t_rez(TFun f, double xn, double xk, double h) {
    int count = 0;
    for (double x = xn; x <= xk; x += h) {
        printf("x=%5lf, y=%5lf\n", x, f(x));
        count++;
    }
    return count;
}

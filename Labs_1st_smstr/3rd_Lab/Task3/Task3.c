#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    double a, b;
    printf("������� �������� a: ");
    scanf_s("%lf", &a);
    printf("������� �������� b: ");
    scanf_s("%lf", &b);

    double multiplication = a * b;
    double addition = a + b;
    double subtraction = a - b;


    printf("__________________________________________________________________\n");
    printf("| %19s | %19s | %19s |\n", "a * b", "a + b", "a - b");
    printf("__________________________________________________________________\n");
    printf("| %4.2e * %-4.2e | %4.2e + %-4.2e | %4.2e - %-4.2e |\n", a, b, a, b, a, b);
    printf("__________________________________________________________________\n");
    printf("| %19.4e | %19.4e | %19.4e |\n", multiplication, addition, subtraction);
    printf("__________________________________________________________________\n");

    return 0;
}
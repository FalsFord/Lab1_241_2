#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    float lkm, benz, km;
    puts("Затраты бензина на км(в литрах): ");
    scanf_s("%f", &lkm);
    puts("Стоимость бензина за литр(в рублях): ");
    scanf_s("%f", &benz);
    puts("Расстояние(в км): ");
    scanf_s("%f", &km);
    float bet = lkm / km * benz;
    int result = bet;
    if (result % 10 == 1) {
        printf("Итого стоимость поездки равна %d рубль", result);
    }
    else if (result % 10 == 2 || result % 10 == 3 || result % 10 == 4) {
        printf("Итого стоимость поездки равна %d рубля", result);
    }
    else {
        printf("Итого стоимость поездки равна %d рублей", result);
    }
}

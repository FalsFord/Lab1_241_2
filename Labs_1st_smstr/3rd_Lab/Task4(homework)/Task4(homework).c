#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    float lkm, benz, km;
    puts("������� ������� �� ��(� ������): ");
    scanf_s("%f", &lkm);
    puts("��������� ������� �� ����(� ������): ");
    scanf_s("%f", &benz);
    puts("����������(� ��): ");
    scanf_s("%f", &km);
    float bet = lkm / km * benz;
    int result = bet;
    if (result % 10 == 1) {
        printf("����� ��������� ������� ����� %d �����", result);
    }
    else if (result % 10 == 2 || result % 10 == 3 || result % 10 == 4) {
        printf("����� ��������� ������� ����� %d �����", result);
    }
    else {
        printf("����� ��������� ������� ����� %d ������", result);
    }
}

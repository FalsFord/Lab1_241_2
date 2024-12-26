#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include"list.h"
#define NMAX 100
#define TYPE char
#define FTYPE "%3c,"

void main() {
    queue_list Str;
    Str.back = Str.front = NULL;
    char temp[100];
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");
    puts("¬ведите строку");
    fgets(temp, NMAX - 1, stdin);

    for (int i = 0; i < NMAX - 1 && temp[i] != '\n' && temp[i]; i++) {
        enQueue(&Str, temp[i]);
    }
    while (Str.front) {
        printf(FTYPE, deQueue(&Str));
    }
    printf("\n");
}

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<Windows.h>
#include"list.h"
#define NMAX 100
#define TYPE char
#define FTYPE "%c"


void main() {
    stack s1 = { 0, {0} };
    stack s2 = { 0, {0} };
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");
    TYPE word[NMAX];
    puts("¬ведите два слова через *");
    fgets(word, NMAX, stdin);

    size_t len = strlen(word);
    if (len > 0 && word[len - 1] == '\n') {
        word[len - 1] = '\0';
    }

    int count1 = 0, count2 = 0;
    for (int i = 0; word[i] != '*'; i++) {
        count1++;
    }
    for (int i = count1 + 1; word[i] != '\0'; i++) {
        count2++;
    }
    for (int i = 0; i < count1; i++) {
        push(&s1, word[i]);
    }
    for (int i = count1 + 1; i < count1 + 1 + count2; i++) {
        push(&s2, word[i]);
    }

    display(&s1);
    display(&s2);
    printf("\n");
    compare(s1, s2);
}

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#define NMAX 100
#define TYPE char
#define FTYPE "%3c,"
int isempty(stack* s) {
    if (s->top == 0) return 1;
    else return 0;
}

int isfull(stack* s) {
    if (s->top == NMAX - 1) return 1;
    else return 0;
}

int push(stack* s, TYPE a) {
    if (!isfull(s)) {
        s->top += 1;
        s->data[s->top] = a;
        return 1;
    }
    else {
        printf("Невозможно записать элемент - стек полон.\n");
        return 0;
    }
}

TYPE pop(stack* s) {
    if (isempty(s)) {
        printf("Удаление невозможно. Стек пустой.\n");
        return '\0'; // Возвращаем нулевой символ вместо -1
    }
    else {
        TYPE value = s->data[s->top];
        s->top--;
        return value;
    }
}

TYPE top(stack* s) {
    if (isempty(s)) {
        printf("Стек пустой\n");
        return '\0'; // Возвращаем нулевой символ вместо -1
    }
    else {
        return s->data[s->top];
    }
}

void display(stack* s) {
    int i = s->top;
    while (i > 0)
        printf(FTYPE, s->data[i--]);
    printf("\n");
}
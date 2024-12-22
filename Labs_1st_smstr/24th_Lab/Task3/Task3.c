#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<Windows.h>
#define NMAX 100
#define TYPE char
#define FTYPE "%c"

typedef struct Stack {
    int   top;
    TYPE  data[NMAX];
} stack;

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
        return '\0';
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
        return '\0';
    }
    else {
        return s->data[s->top];
    }
}

void display(stack* s) {
    int i = s->top;
    while (i > 0)
        printf(FTYPE, s->data[i--]);
}

int compare(stack s1, stack s2) {
    if (s1.top != s2.top) {
        printf("Строки имеют разную длину и не могут быть обратными.\n");
        return -1;
    }
    else {
        char data1[NMAX];
        char data2[NMAX];

        for (int i = 1; i <= s1.top; i++) {
            data1[i - 1] = tolower(s1.data[i]);
        }
        data1[s1.top] = '\0';

        int n = s2.top;
        for (int i = 0; i < s2.top; i++) {
            data2[i] = tolower(s2.data[n--]);
        }
        data2[s2.top] = '\0';

        printf("\nСтрока 1: %s\n", data1);
        printf("Строка 2 (обратная): %s\n", data2);

        if (strcmp(data1, data2) != 0) {
            printf("Данные строки не являются обратными\n");
            return -1;
        }
        else {
            printf("Данные строки обратны\n");
            return 1;
        }
    }
}

void main() {
    stack s1 = { 0, {0} };
    stack s2 = { 0, {0} };
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");
    TYPE word[NMAX];
    puts("Введите два слова через *");
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

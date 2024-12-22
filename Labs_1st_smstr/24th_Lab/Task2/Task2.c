#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define NMAX 100
#define TYPE char
#define FTYPE "%3c,"

struct Node {
    TYPE data;
    struct Node* next;
};

typedef struct {
    struct Node* front;
    struct Node* back;
} queue_list;

void enQueue(queue_list* que, TYPE element) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = element;
    node->next = NULL;
    if (que->back != NULL) {
        que->back->next = node;
        que->back = node;
    }
    else {
        que->back = node;
        que->front = node;
    }
}

TYPE deQueue(queue_list* que) {
    if (que->front == NULL) {
        printf("Ошибка извлечения\n");
        return '\0';
    }
    else {
        TYPE elem = que->front->data;
        struct Node* temp = que->front;
        que->front = que->front->next;
        if (que->front == NULL) {
            que->back = NULL;
        }
        free(temp);
        return elem;
    }
}

void main() {
    queue_list Str;
    Str.back = Str.front = NULL;
    char temp[100];
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");
    puts("Введите строку");
    fgets(temp, NMAX - 1, stdin);

    for (int i = 0; i < NMAX - 1 && temp[i] != '\n' && temp[i]; i++) {
        enQueue(&Str, temp[i]);
    }
    while (Str.front) {
        printf(FTYPE, deQueue(&Str));
    }
    printf("\n");
}

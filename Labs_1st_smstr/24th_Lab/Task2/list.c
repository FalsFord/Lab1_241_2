#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include"list.h"
#define NMAX 100
#define TYPE char
#define FTYPE "%3c,"

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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <WIndows.h>
#ifndef _LIST_H
#define _LIST_H
struct listitem {
    int number;
    int data[20];
    char time[6];
    char name[80];
    struct listitem* next;
};

typedef struct listitem* List;

void initlist(List* list) {
    *list = NULL;
}


void insertfront_str(List* list, char* str) {
    struct listitem* new_item = (struct listitem*)malloc(sizeof(struct listitem));
    new_item->number = 0;
    strncpy(new_item->name, str, sizeof(new_item->name) - 1);
    new_item->name[sizeof(new_item->name) - 1] = '\0';
    new_item->next = *list;
    *list = new_item;
}

void insertback_str(List* list, char* data, char* time, char* name, int num) {
    struct listitem* newnode = (struct listitem*)malloc(sizeof(struct listitem));
    if (newnode == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return;
    }
    newnode->number = num;
    strncpy(newnode->data, data, sizeof(newnode->data) - 1);
    strncpy(newnode->time, time, sizeof(newnode->time) - 1);
    strncpy(newnode->name, name, sizeof(newnode->name) - 1);
    newnode->data[sizeof(newnode->data) - 1] = '\0';
    newnode->time[sizeof(newnode->time) - 1] = '\0';
    newnode->name[sizeof(newnode->name) - 1] = '\0';
    newnode->next = NULL;

    if (*list == NULL) {
        *list = newnode;
    }
    else {
        struct listitem* current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}


bool isempty(List* list) {
    return *list == NULL;
}

int length(List list) {
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

void destroyItem(List* list, List node) {
    if (*list == NULL || node == NULL) {
        return;
    }

    if (*list == node) {
        *list = node->next;
        free(node);
        return;
    }

    struct listitem* current = *list;
    while (current->next != NULL && current->next != node) {
        current = current->next;
    }

    if (current->next == node) {
        current->next = node->next;
        free(node);
    }
}

struct listitem* getitem_number(List list, int n) {
    while (list != NULL) {
        if (list->number == n) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

#endif




int main() {
    List list;
    initlist(&list);
    struct listitem* nowlist = list;
    int pos = 0, a = 1;
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");
    while (a) {
        char name[80];
        char data[20];
        char time[20];
        int num = 0;
        puts("Выберите действие.");
        puts("1. Добавить посещенные страницы");
        puts("2. Вывести посещенные страницы");
        puts("3. Удалить посещенную страницу");
        puts("4. Завершить работу");
        scanf("%d", &num);

        switch (num) {
        case 1:
            pos++;
            puts("Введите название сайта:");
            getchar(); // Сброс буфера
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // Удаление символа новой строки
            puts("Введите дату посещения:");
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = '\0'; // Удаление символа новой строки
            puts("Введите время посещения:");
            fgets(time, sizeof(time), stdin);
            time[strcspn(time, "\n")] = '\0'; // Удаление символа новой строки
            insertback_str(&list, data, time, name, num);
            break;
        case 2:
            nowlist = list;
            if (!isempty) {
                for (int i = 0; i < length(list); i++) {
                    printf("%d. %s. Последнее посещение %s в %s\n", i + 1, nowlist->name, nowlist->data, nowlist->time);
                    nowlist = nowlist->next;
                }
            }
            else printf("Список пуст\n");
            break;
        case 3:
            num = 0;
            puts("Введите номер страницы для удаления:");
            scanf("%d", &num);
            struct listitem* item = getitem_number(list, num);
            if (item != NULL) {
                destroyItem(&list, item);
                puts("Страница удалена.");
            }
            else {
                puts("Страница не найдена.");
            }
            break;
        }
        if (num == 4) a = 0;
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef _LIST_H
#define _LIST_H
struct listitem {
    int number;
    char name[80];
    struct listitem* next;
};

typedef struct listitem* List;

void initlist(List* list) {
    *list = NULL;
}

void insertfront(List* list, int val) {
    struct listitem* new_item = (struct listitem*)malloc(sizeof(struct listitem));
    new_item->number = val; 
    new_item->next = *list;
    *list = new_item;
}

void insertback(List* list, int val) {
    struct listitem* new_item = (struct listitem*)malloc(sizeof(struct listitem));
    new_item->number = val;
    new_item->next = NULL;

    if (*list == NULL) {
        *list = new_item;
    }
    else {
        struct listitem* current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_item;
    }
}

void insertfront_str(List* list, char* str) {
    struct listitem* new_item = (struct listitem*)malloc(sizeof(struct listitem));
    new_item->number = 0;
    strncpy(new_item->name, str, sizeof(new_item->name) - 1);
    new_item->name[sizeof(new_item->name) - 1] = '\0'; 
    new_item->next = *list;
    *list = new_item;
}

void insertback_str(List* list, char* str) {
    struct listitem* newnode = (struct listitem*)malloc(sizeof(struct listitem));
    newnode->number = 0;

    strncpy(newnode->name, str, sizeof(newnode->name) - 1);
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

struct listitem* getitem_name(List list, char* str) {
    while (list != NULL) {
        if (strcmp(list->name, str) == 0) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

#endif





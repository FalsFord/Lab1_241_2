#ifndef _LIST_H
#define _LIST_H
#include<stdbool.h>
struct listitem {
    int number;
    int data[20];
    char time[6];
    char name[80];
    struct listitem* next;
};
typedef struct listitem* List;
void initlist(List* list);
void insertfront(List* list, int val);
void insertback(List* list, int val);
void insertfront_str(List* list, char* str);
void insertback_str(List* list, const char* data, const char* time, const char* name, int num);
bool isempty(List* list);
int length(List list);
void destroyItem(List* list, List node);
struct listitem* getitem_number(List list, int n);
struct listitem* getitem_name(List list, char* str);
#endif





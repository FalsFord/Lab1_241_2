#ifndef _LIST_H
#define NMAX 100
#define TYPE char
#define FTYPE "%3c,"

typedef struct Stack {
    int   top;
    TYPE  data[NMAX];
} stack;
int isempty(stack* s);
int isfull(stack* s);
int push(stack* s, TYPE a);
TYPE pop(stack* s);
TYPE top(stack* s);
void display(stack* s);
#endif // !_LIST_H

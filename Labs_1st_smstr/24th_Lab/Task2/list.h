#ifndef _LIST_H
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
void enQueue(queue_list* que, TYPE element);
TYPE deQueue(queue_list* que);
#endif // !_LIST_H

#ifndef _LIST_H
#define _LIST_H
typedef struct Train {
    int rideNumber;
    char arrivalTime[6];
    char departureTime[6];
    char direction[21];
    float distance;
    float averageSpeed;
} train_t;

typedef struct Node {
    train_t data;
    struct Node* next;
} Node;

Node* addToList(Node* head, train_t data);
Node* searchRide(Node* head, int rideNumber);
Node* split(Node* head);
Node* merge(Node* left, Node* right);
Node* mergeSort(Node* head);
#endif

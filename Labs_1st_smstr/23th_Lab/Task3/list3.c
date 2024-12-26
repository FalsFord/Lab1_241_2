#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include"list3.h"

Node* addToList(Node* head, train_t data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* searchRide(Node* head, int rideNumber) {
    Node* current = head;
    while (current != NULL) {
        if (current->data.rideNumber == rideNumber) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


Node* split(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

Node* merge(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Node* result = NULL;
    if (strcmp(left->data.direction, right->data.direction) <= 0) {
        result = left;
        result->next = merge(left->next, right);
    }
    else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}


Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head, second);
}

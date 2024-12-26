#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include"list3.h"
#define SIZE 10


void printList(Node* head) {
    printf("| ����� ����� | ����� �������� | ����� ����������� | �����������          | ���������� | ������� �������� |\n");
    Node* current = head;
    while (current != NULL) {
        printf("| %-11d | %-14s | %-17s | %-20s | %-10.2f | %-16.2f |\n",
            current->data.rideNumber, current->data.arrivalTime, current->data.departureTime, current->data.direction,
            current->data.distance, current->data.averageSpeed);
        current = current->next;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    train_t trains[SIZE] = {
        {1, "10:00", "12:00", "������", 500.0, 80.0},
        {2, "11:00", "13:00", "�����-���������", 600.0, 90.0},
        {3, "12:00", "14:00", "������", 700.0, 100.0},
        {4, "12:00", "14:00", "����", 1111.0, 1030.0},
        {5, "06:00", "14:00", "������", 30.0, 70.0},
        {6, "10:00", "12:00", "�����������", 500.0, 80.0},
        {7, "11:00", "13:00", "��������", 600.0, 90.0},
        {8, "12:00", "14:00", "�������", 700.0, 100.0},
        {9, "12:00", "14:00", "�����", 1111.0, 1030.0},
        {10, "06:00", "14:00", "������", 30.0, 70.0}
    };

    Node* head = NULL;
    for (int i = 0; i < SIZE; i++) {
        head = addToList(head, trains[i]);
    }

    printf("�������� ������:\n");
    printList(head);

    head = mergeSort(head);

    printf("\n��������������� ������:\n");
    printList(head);

    int searchRideNumber = 3;
    Node* found = searchRide(head, searchRideNumber);
    if (found != NULL) {
        printf("\n������ ����� � ������� ����� %d:\n", searchRideNumber);
        printf("| ����� ����� | ����� �������� | ����� ����������� | �����������         | ���������� | ������� �������� |\n");
        printf("| %-11d | %-14s | %-17s | %-20s | %-10.2f | %-16.2f |\n",
            found->data.rideNumber, found->data.arrivalTime, found->data.departureTime, found->data.direction,
            found->data.distance, found->data.averageSpeed);
    }
    else {
        printf("\n����� � ������� ����� %d �� ������.\n", searchRideNumber);
    }

    return 0;
}

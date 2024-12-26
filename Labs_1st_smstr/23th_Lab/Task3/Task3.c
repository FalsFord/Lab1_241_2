#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include"list3.h"
#define SIZE 10


void printList(Node* head) {
    printf("| Номер рейса | Время прибытия | Время отправления | Направление          | Расстояние | Средняя скорость |\n");
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
        {1, "10:00", "12:00", "Москва", 500.0, 80.0},
        {2, "11:00", "13:00", "Санкт-Петербург", 600.0, 90.0},
        {3, "12:00", "14:00", "Казань", 700.0, 100.0},
        {4, "12:00", "14:00", "Ялта", 1111.0, 1030.0},
        {5, "06:00", "14:00", "Аазань", 30.0, 70.0},
        {6, "10:00", "12:00", "Владивосток", 500.0, 80.0},
        {7, "11:00", "13:00", "Мурманск", 600.0, 90.0},
        {8, "12:00", "14:00", "Сахалин", 700.0, 100.0},
        {9, "12:00", "14:00", "Алжир", 1111.0, 1030.0},
        {10, "06:00", "14:00", "Рязань", 30.0, 70.0}
    };

    Node* head = NULL;
    for (int i = 0; i < SIZE; i++) {
        head = addToList(head, trains[i]);
    }

    printf("Исходный список:\n");
    printList(head);

    head = mergeSort(head);

    printf("\nОтсортированный список:\n");
    printList(head);

    int searchRideNumber = 3;
    Node* found = searchRide(head, searchRideNumber);
    if (found != NULL) {
        printf("\nНайден поезд с номером рейса %d:\n", searchRideNumber);
        printf("| Номер рейса | Время прибытия | Время отправления | Направление         | Расстояние | Средняя скорость |\n");
        printf("| %-11d | %-14s | %-17s | %-20s | %-10.2f | %-16.2f |\n",
            found->data.rideNumber, found->data.arrivalTime, found->data.departureTime, found->data.direction,
            found->data.distance, found->data.averageSpeed);
    }
    else {
        printf("\nПоезд с номером рейса %d не найден.\n", searchRideNumber);
    }

    return 0;
}

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3

typedef struct Train {
    int rideNumber;
    char arrivalTime[6];
    char departureTime[6];
    char direction[10];
    float distance;
    float averageSpeed;
} train_t;

int definitionTime(char* time) {
    int hours, minutes;
    sscanf(time, "%d:%d", &hours, &minutes);
    int retime = hours * 3600 + minutes * 60;
    return retime;
}

void fill_array(train_t* trains, int size) {
    for (int i = 0; i < size; i++) {
        printf("Введите номер поезда: ");
        scanf("%d", &trains[i].rideNumber);
        getchar();

        printf("Введите время прибытия: ");
        scanf("%s", trains[i].arrivalTime);
        getchar();

        printf("Введите время отбытия: ");
        scanf("%s", trains[i].departureTime);

        printf("Введите направление: ");
        scanf("%s", trains[i].direction);

        printf("Введите расстояние(в км): ");
        scanf("%f", &trains[i].distance);

        float distance = trains[i].distance * 1000;
        int arrivalTime = definitionTime(trains[i].arrivalTime);
        int departureTime = definitionTime(trains[i].departureTime);
        int timeTrail = arrivalTime - departureTime;
        if (timeTrail > 0)
            trains[i].averageSpeed = distance / timeTrail;
    }
}

void print_array(train_t* trains, int size) {
    for (int i = 0; i < size; i++) {
        printf("Номер поезда: %d\n", trains[i].rideNumber);
        printf("Время прибытия %s\n", trains[i].arrivalTime);
        printf("Время отбытия %s\n", trains[i].departureTime);
        printf("Направление движения поезда: %s\n", trains[i].direction);
        printf("Расстояние до пункта назначения %f км\n", trains[i].distance);
        printf("Средняя скорость поезда %f м/с.\n", trains[i].averageSpeed);
    }
}

void print_train(train_t train) {
    printf("| %2d || %15s || %15s || %11s || %10.2f || %8.2f |\n", train.rideNumber, train.arrivalTime, train.departureTime, train.direction, train.distance, train.averageSpeed);
}

int search_rideNumber(train_t* trains, int size, char* direction) {
    for (int i = 0; i < size; i++) {
        if (strcmp(trains[i].direction, direction) == 0)
            return trains[i].rideNumber;
    }
    return -1; // Return -1 if not found
}

int compare(const void* a, const void* b) {
    train_t* trainA = (train_t*)a;
    train_t* trainB = (train_t*)b;
    int comA = definitionTime(trainA->departureTime) - definitionTime(trainA->arrivalTime);
    int comB = definitionTime(trainB->departureTime) - definitionTime(trainB->arrivalTime);

    return (comA > comB) - (comA < comB);
}

void write_to_file(train_t* trains, int size) {
    FILE* file = fopen("trains.txt", "w");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d %s %s %s %f %f\n", trains[i].rideNumber, trains[i].arrivalTime, trains[i].departureTime, trains[i].direction, trains[i].distance, trains[i].averageSpeed);
    }
    fclose(file);
}

void read_from_file(train_t* trains, int size) {
    FILE* file = fopen("trains.txt", "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d %s %s %s %f %f", &trains[i].rideNumber, trains[i].arrivalTime, trains[i].departureTime, trains[i].direction, &trains[i].distance, &trains[i].averageSpeed);
    }
    fclose(file);
}

int main() {
    setlocale(LC_ALL, "Rus");
    train_t trains[SIZE] = {
        {1, "15:00", "14:00", "Moscow", 5.0f, 300.0f},
        {2, "06:30", "06:00", "Voronezh", 8.0f, 500.0f},
        {9, "07:34", "02:55", "Kazan", 300.0f, 133.0f}
    };
    train_t trains2[SIZE];

    write_to_file(trains, SIZE);

    // Чтение данных из файла
    read_from_file(trains2, SIZE);

    print_array(trains2, SIZE);

    printf("\n");
    printf("| %2s || %15s || %15s || %11s || %10s || %8s |\n", "#", "Время прибытия", "Время отбытия", "Направление", "Расстояние", "Скорость");
    for (int i = 0; i < SIZE; i++) {
        print_train(trains2[i]);
    }
    return 0;
}

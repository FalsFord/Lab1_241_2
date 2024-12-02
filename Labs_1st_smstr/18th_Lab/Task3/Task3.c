#include<stdio.h>
#include<locale.h>
#include<string.h>]
#define quantity 3
struct Train {
	int rideNumber;
	char arrivalTime[6];
	char departureTime[6];
	char direction[10];
	float distance;
	float averageSpeed;
};
int definitionTime(char* time) {
	int hours, minutes;
	sscanf(time,"%d:%d", &hours, &minutes);
	int retime = hours * 60 + minutes;
	return retime;
}

void recordRide(struct Train* train) {

	printf("Введите номер поезда: ");
	scanf_s("%d", &train->rideNumber);
	getchar();

	printf("Введите время прибытия: ");
	scanf("%s", train->arrivalTime);
	getchar();
	printf("Введите время отбытия: ");
	scanf("%s", train->departureTime);

	printf("Введите направление: ");
	scanf("%s", train->direction);

	printf("Введите расстояние(в км): ");
	scanf_s("%f", &train->distance);

	float distance = train->distance * 1000;
	int arrivalTime = definitionTime(train->arrivalTime);
	printf("%d\n", arrivalTime);
	int departureTime = definitionTime(train->departureTime);
	printf("%d\n", departureTime);
	int timeTrail = arrivalTime - departureTime;
	if (timeTrail > 0)train->averageSpeed = distance / timeTrail;
}

void printTrain(struct Train* train) {
	printf("Номер поезда: %d", train->rideNumber);
	printf("Время прибытия: %s", train->arrivalTime);
	printf("Время отбытия: %s", train->departureTime);
	printf("Направление движения: %s", train->direction);
	printf("Расстояние: %f", train->distance);
}
void main() {
	setlocale(LC_ALL, "Rus");
	struct Train train[quantity];

	for (int i = 0; i < quantity; i++) {
		printf("Заполните информацию о поезде %d.\n", i+1);
		recordRide(&train[i]);
		float speed = train[i].averageSpeed;
		printf("Средняя скорость поезда %d равно %f м/с.\n", i + 1, speed);
	}
}

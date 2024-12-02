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

	printf("������� ����� ������: ");
	scanf_s("%d", &train->rideNumber);
	getchar();

	printf("������� ����� ��������: ");
	scanf("%s", train->arrivalTime);
	getchar();
	printf("������� ����� �������: ");
	scanf("%s", train->departureTime);

	printf("������� �����������: ");
	scanf("%s", train->direction);

	printf("������� ����������(� ��): ");
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
	printf("����� ������: %d", train->rideNumber);
	printf("����� ��������: %s", train->arrivalTime);
	printf("����� �������: %s", train->departureTime);
	printf("����������� ��������: %s", train->direction);
	printf("����������: %f", train->distance);
}
void main() {
	setlocale(LC_ALL, "Rus");
	struct Train train[quantity];

	for (int i = 0; i < quantity; i++) {
		printf("��������� ���������� � ������ %d.\n", i+1);
		recordRide(&train[i]);
		float speed = train[i].averageSpeed;
		printf("������� �������� ������ %d ����� %f �/�.\n", i + 1, speed);
	}
}

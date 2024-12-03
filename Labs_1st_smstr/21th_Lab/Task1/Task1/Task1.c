#include<stdio.h>
#include<locale.h>
#include<string.h>
#define SIZE 2
typedef struct Train {
	int rideNumber;
	char arrivalTime[6];
	char departureTime[6];
	char direction[10];
	float distance;
	float averageSpeed;
}train_t;
int definitionTime(char* time) {
	int hours, minutes;
	sscanf(time, "%d:%d", &hours, &minutes);
	int retime = hours * 3600 + minutes*60;
	return retime;
}
void fill_array(train_t* trains, int size) {
	for (int i = 0; i < size; i++) {
		printf("������� ����� ������: ");
		scanf_s("%d", &trains[i].rideNumber);
		getchar();

		printf("������� ����� ��������: ");
		scanf("%s", trains[i].arrivalTime);
		getchar();
		printf("������� ����� �������: ");
		scanf("%s", trains[i].departureTime);

		printf("������� �����������: ");
		scanf("%s", trains[i].direction);

		printf("������� ����������(� ��): ");
		scanf_s("%f", &trains[i].distance);

		float distance = trains[i].distance * 1000;
		int arrivalTime = definitionTime(trains[i].arrivalTime);
		int departureTime = definitionTime(trains[i].departureTime);
		int timeTrail = arrivalTime - departureTime;
		if (timeTrail > 0)printf("������� �������� %f �/�.\n",trains[i].averageSpeed = distance / timeTrail);
	}
}
void print_array(train_t* trains, int size) {
	for (int i = 0; i < size; i++) {
		printf("����� ������: %d\n", trains[i].rideNumber);
		printf("����� �������� %s\n", trains[i].arrivalTime);
		printf("����� ������� %s\n", trains[i].departureTime);
		printf("����������� �������� ������: %s\n", trains[i].direction);
		printf("���������� �� ������ ���������� %f ��\n", trains[i].distance);
		printf("������� �������� ������ %f �/�.\n", trains[i].averageSpeed);
	}
}
void print_train(train_t train) {
	printf("| %2d || %15s || %15s || %11s || %10d || %8.2f |\n", train.rideNumber, train.arrivalTime, train.departureTime, train.direction, train.distance, train.averageSpeed);
}
void main() {
	setlocale(LC_ALL, "Rus");
	train_t trains[SIZE]={
	{1,"15:00","14:00","Moscow", 5},
	{ 2,"6:30","6:00","Voronezh",8 }
	};
	fill_array(trains, SIZE);
	print_array(trains, SIZE);

	printf("\n");	
	printf("| %2s || %15s || %15s || %1s || %10s || %8s |\n","#", "����� ��������","����� �������","�����������","����������","��������");
	for (int i = 0; i < SIZE; i++) {
		print_train(trains[i]);
	}	
}
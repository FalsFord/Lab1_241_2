#include<stdio.h>
#include<locale.h>
#include<math.h>
#define _USE_MATH_DEFINE
void main() {
	//������� 13
	setlocale(LC_ALL, "Rus");
	float one, two, three;
	int counter =0;
	puts("������� 3 ������������ ����� ����� ������ ");
	scanf_s("%f %f %f", &one, &two, &three);
	printf("�� ����� %.2f, %.2f, %.2f", one, two, three);
	
	if((-1< one && one <1) && (-1 < two && two < 1) && (-1 < three && three < 1)){
		printf("\n������� (-1:1) ����������� ����� %.2f, %.2f, %.2f", one, two, three);
	}
	else if ((-1 < one && one < 1) && (-1 < two && two < 1)) {
		printf("\n������� (-1:1) ����������� ����� %.2f, %.2f", one, two);
	}
	else if ((-1 < one && one < 1) && (-1 < three && three < 1)) {
		printf("\n������� (-1:1) ����������� ����� %.2f, %.2f", one, three);
	}
	else if ((-1 < three && three < 1) && (-1 < two && two < 1)) {
		printf("\n������� (-1:1) ����������� ����� %.2f, %.2f", two, three);
	}
	else if (-1 < one && one < 1) {
		printf("\n������� (-1:1) ����������� ����� %.2f", one);
	}
	else if (-1 < two && two < 1) {
		printf("\n������� (-1:1) ����������� ����� %.2f", two);
	}
	else if (-1 < three && three < 1) {
		printf("\n������� (-1:1) ����������� ����� %.2f", three);
	} else printf("\n������� (-1:1) �� ����������� �� ���� �����");





	/*if (-1 < one && one < 1)counter+=1;
	if (-1 < two && two < 1)counter+=2;
	if (-1 < three && three < 1)counter+=4;

	switch (counter) {
	case 1: printf("\n������� (-1;1) ����������� ����� %f", one);
		break;
	case 2: printf("\n�������(-1; 1) ����������� ����� % f", two);
		break;
	case 3: printf("\n������� (-1;1) ����������� ����� %f, %f", one, two);
		break;
	case 4: printf("\n������� (-1;1) ����������� ����� %f", three);
		break;
	case 5: printf("\n������� (-1;1) ����������� ����� %f, %f", one, three);
		break;
	case 6:	printf("\n������� (-1;1) ����������� ����� %f, %f", two, three);
		break;
	case 7: printf("\n������� (-1;1) ����������� ����� %f, %f, %f", one, two, three);
		break;
	default: printf("\n�� ���� �� ����� �� ����������� ������� (-1;1)");
	}*/

}
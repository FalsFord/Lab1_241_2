#include<stdio.h>
#include<locale.h>
#include<math.h>
#define ROW 9
#define COL 9
void main() {
	setlocale(LC_ALL, "Rus");


	while (1) {
		char a;

		int number, lengthOfNumber = 1;
		puts("\n������� ����� ����� ");
		scanf_s("%d", &number);

		//���������� ����� �����
		for (int i = 10; i > 0; i *= 10) {
			if (number >= i)lengthOfNumber++; else break;
		}
		printf("����� ���� ����� %d", lengthOfNumber);

		//����������
		int grad, VarNum = number, AddVar;
		int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, counter7 = 1, counter8 = 1, counter9 = 0, counter10 = 0, counter11 = 0, counter12 = 0;
		int var = number % 10, var10 = 0, var11 = 0, var12 = 0;

		//����
		for (int i = 0; i < lengthOfNumber; i++) {
			grad = pow(10, i);

			// �������� ����� �����
			if (VarNum > 10) {
				VarNum = (number / grad);
				AddVar = VarNum % 10;
			}
			else AddVar = number % 10;

			//����� 1)
			if (AddVar == 3)counter1++;

			//����� 2)
			if (AddVar == var)counter2++;

			//����� 3)
			if (AddVar % 2 == 0)counter3++;

			//����� 4)
			if ((AddVar > 5)) counter4++;

			//����� 5)
			if (AddVar % 2 != 0)counter5 += AddVar;

			//����� 6)
			if ((AddVar >= 7)) counter6 += AddVar;

			//����� 7)
			if ((AddVar > 0)) counter7 *= AddVar;

			//����� 8)
			if ((i == 1 || i == lengthOfNumber - 2)) counter8 *= AddVar;

			//����� 9)
			if (AddVar % 2 == 0 && i > 0)counter9 += AddVar;

			//����� 10)
			if (AddVar == var10)counter10 = AddVar;
			var10 = AddVar;

			//����� 11)
			if (i >= lengthOfNumber / 2)counter11 += AddVar; else var11 += AddVar;

			//����� 12)
			if (AddVar % 2 == 0)counter12 += AddVar; else var12 += AddVar;
		}

		//����� �������
		printf("\n1) ���������� ���� 3 � ����� ����� %d", counter1);
		printf("\n2) ����� ���������� ��������� ����� ����� %d", counter2);
		printf("\n3) ����� ������ ����� ����� %d", counter3);
		printf("\n4) ���������� ���� ������ 5 ����� %d", counter4);
		printf("\n5) ����� �������� ���� ����� %d", counter5);
		printf("\n6) ����� ���� ������� ��� ������ 7 ����� %d", counter6);
		printf("\n7) ������������ ���� ���� ����� %d", counter7);
		printf("\n8) ������������ ������ � ������������� ���� ����� %d", counter8);
		printf("\n9) ����� ������ ����, �������� ���������, ����� %d", counter9);
		if (counter10 != 0)printf("\n10) ����� ������������� �����: %d � %d ", counter10, counter10); else printf("\n10) ����� ������������� ���");
		if (counter11 == var11)printf("\n11) ����� ������ � ������ �������� ����� "); else printf("\n11) ����� ������ � ������ �������� �� �����");
		printf("\n12) ������������ ���� ����, ������ � �������� �������� ����� %d", counter12 * var12);

		getchar();
		printf("\n\n���������� ? (�� - y, ��� - n)");
		if((a=getchar())=='n')break;


	}

}
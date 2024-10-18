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
		puts("\nВведите целое число ");
		scanf_s("%d", &number);

		//Нахождение длины числа
		for (int i = 10; i > 0; i *= 10) {
			if (number >= i)lengthOfNumber++; else break;
		}
		printf("Число цифр равно %d", lengthOfNumber);

		//переменные
		int grad, VarNum = number, AddVar;
		int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, counter7 = 1, counter8 = 1, counter9 = 0, counter10 = 0, counter11 = 0, counter12 = 0;
		int var = number % 10, var10 = 0, var11 = 0, var12 = 0;

		//цикл
		for (int i = 0; i < lengthOfNumber; i++) {
			grad = pow(10, i);

			// Основной рачет цифры
			if (VarNum > 10) {
				VarNum = (number / grad);
				AddVar = VarNum % 10;
			}
			else AddVar = number % 10;

			//номер 1)
			if (AddVar == 3)counter1++;

			//номер 2)
			if (AddVar == var)counter2++;

			//номер 3)
			if (AddVar % 2 == 0)counter3++;

			//номер 4)
			if ((AddVar > 5)) counter4++;

			//номер 5)
			if (AddVar % 2 != 0)counter5 += AddVar;

			//номер 6)
			if ((AddVar >= 7)) counter6 += AddVar;

			//номер 7)
			if ((AddVar > 0)) counter7 *= AddVar;

			//номер 8)
			if ((i == 1 || i == lengthOfNumber - 2)) counter8 *= AddVar;

			//номер 9)
			if (AddVar % 2 == 0 && i > 0)counter9 += AddVar;

			//номер 10)
			if (AddVar == var10)counter10 = AddVar;
			var10 = AddVar;

			//номер 11)
			if (i >= lengthOfNumber / 2)counter11 += AddVar; else var11 += AddVar;

			//номер 12)
			if (AddVar % 2 == 0)counter12 += AddVar; else var12 += AddVar;
		}

		//Вывод ответов
		printf("\n1) Количество цифр 3 в числе равно %d", counter1);
		printf("\n2) Число повторений последней цифры равно %d", counter2);
		printf("\n3) Число четных чисел равно %d", counter3);
		printf("\n4) Количество цифр больше 5 равно %d", counter4);
		printf("\n5) Сумма нечетных цифр равна %d", counter5);
		printf("\n6) Сумма цифр больших или равных 7 равна %d", counter6);
		printf("\n7) Произведение всех цифр равно %d", counter7);
		printf("\n8) Произведение второй и предпоследней цифр равно %d", counter8);
		printf("\n9) Сумма четных цифр, исключая последнюю, равно %d", counter9);
		if (counter10 != 0)printf("\n10) Рядом расположенные цифры: %d и %d ", counter10, counter10); else printf("\n10) Рядом располоденные нет");
		if (counter11 == var11)printf("\n11) Сумма первой и второй половины равны "); else printf("\n11) Сумма первой и второй половины не равны");
		printf("\n12) Произведение сумм цифр, четных и нечетных разрядов равно %d", counter12 * var12);

		getchar();
		printf("\n\nПродолжить ? (Да - y, нет - n)");
		if((a=getchar())=='n')break;


	}

}
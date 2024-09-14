#include <stdio.h>
#include<locale.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	printf("123\n");
	printf("1\n2\n3\n");
	printf("1\n\t2\n\t\t3\n");
	printf("\n%5d \n%10d \n%15d \n%20d \n", 1, 2, 3, 4);
	printf("%10.5f\n", 12.234657);
	printf("Деление %d на %d равен %d\n", 7, 5, 7 / 5);
	printf("Умножение %d на %d равен %d\n", 2000, 4, 2000*4);
	printf("%g разделить %e равно %f\n", 5., 2., 5. / 2); 
	printf("%d разделить %d равно %d\n",5.,2.,5./2); //ошибка
	printf("%f разделить %f равно %f\n", 5., 2., 5. / 2); 
	printf("%g разделить %g равно %g\n ", 5., 2., 5. / 2);
	printf("%e разделить %e равно %e\n", 5., 2., 5. / 2);
}
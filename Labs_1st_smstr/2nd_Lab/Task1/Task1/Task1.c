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
	printf("������� %d �� %d ����� %d\n", 7, 5, 7 / 5);
	printf("��������� %d �� %d ����� %d\n", 2000, 4, 2000*4);
	printf("%g ��������� %e ����� %f\n", 5., 2., 5. / 2); 
	printf("%d ��������� %d ����� %d\n",5.,2.,5./2); //������
	printf("%f ��������� %f ����� %f\n", 5., 2., 5. / 2); 
	printf("%g ��������� %g ����� %g\n ", 5., 2., 5. / 2);
	printf("%e ��������� %e ����� %e\n", 5., 2., 5. / 2);
}
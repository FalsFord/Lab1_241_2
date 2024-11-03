#include<stdio.h>
#include<locale.h>
#define N 10
void main()
{
	setlocale(LC_ALL, "Rus");
	int a[N],count=0,temp;
	for (int i = 0; i < N; i++)
	{
		printf("\n¬ведите a[%d]=", i);
		scanf_s("%d", &temp);
		a[i] = temp;
	}
	int var = a[0];
	for (int i = 0; i < N; i++) 
	{
		if (a[i] <= var) 
		{
			var = a[i];
			count = i;
		}
	}
	printf("ћинимальное число в массиве %d", var);
	printf("\nЁлементов массива до него %d", count);

}
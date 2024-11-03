#include<stdio.h>
#include<locale.h>
#include<math.h>

float func(float countInterval)
{
	float y=0,a,b;
	a = 1.04 * countInterval;
	b = cos(a);
	y = countInterval - 3 * pow(b, 2);
	return y;
}
void main() 
{
	setlocale(LC_ALL, "Rus");
	int count=0;
	float mas[100], positiveSum=0, nagativeSum=0, step = (2.1 - 0.15) / 100, countInterval = 0.15;
	for (int i = 0; i < 100; i++)
	{
		mas[i] = func(countInterval);
		countInterval += step;
		printf("\na[%d]=%f", i,mas[i]);
		if (mas[i] > 0)
		{
			positiveSum += mas[i];
			count++;
		}
		else if (mas[i] < 0)nagativeSum += mas[i];
	}
	printf("\nСреднее положительное число: %f", positiveSum / count);

	printf("\nНазвание массива: mas");
	printf("\nСумма положительных чисел массива: %f", positiveSum);
	printf("\nСумма отрицательных чисел массива: %f", nagativeSum);
	printf("\nЧисло положительных чисел: %d", count);
	printf("\nЧисло отрицательных чисел: %d", 100-count);
	printf("\nСреднее значение массива: %f", (positiveSum + nagativeSum) / 100);
}
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

void fille(int* ptr_array, int size) {
	for (int i = 0; i < size; i++)
		ptr_array[i] = rand() % 50;
}

void printe(int* ptr_array, int size) {
	for (int i = 0; i < size; i++)
		printf("array[%d] = %d\n", i, ptr_array[i]);
}

void bubbleSort(int* ptr_array, int count) {
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			int swapNeeded = 0;

			if (ptr_array[j] > ptr_array[j + 1]) {
				swapNeeded = 1;
			}

			if (swapNeeded) {
				int temp = ptr_array[j];
				ptr_array[j] = ptr_array[j + 1];
				ptr_array[j + 1] = temp;
			}
		}
	}
}

void shaker_sort(int* ptr_array, int size)
{
	int left = 0;
	int right = size - 1;
	int temp;
	while (right > left)
	{
		for (int i = left; i < right; i++)
		{
			if (ptr_array[i] > ptr_array[i + 1])
			{
				temp = ptr_array[i];
				ptr_array[i] = ptr_array[i + 1];
				ptr_array[i + 1] = temp;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (ptr_array[i - 1] > ptr_array[i])
			{
				temp = ptr_array[i - 1];
				ptr_array[i - 1] = ptr_array[i];
				ptr_array[i] = temp;
			}
		}
		left++;
	}
}

void select_sort(int* ptr_array, int size)
{
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (ptr_array[j] < ptr_array[min])
			{
				min = j;
			}
		}
		temp = ptr_array[i];
		ptr_array[i] = ptr_array[min];
		ptr_array[min] = temp;
	}
}

void insert_sort(int* ptr_array, int size)
{
	for (int i = 1; i < size; i++) {
		int key = ptr_array[i];
		int j = i - 1;
		while (j >= 0 && ptr_array[j] > key) {
			ptr_array[j + 1] = ptr_array[j];
			j--;
		}
		ptr_array[j + 1] = key;
	}
}

void main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int size;
	int* ptr_array;

	printf("¬ведите размер массива: ");
	scanf("%d", &size);

	ptr_array = (int*)malloc(size * sizeof(int));

	fille(ptr_array, size);

	clock_t start = clock();

	bubbleSort(ptr_array, size);
	shaker_sort(ptr_array, size);
	select_sort(ptr_array, size);
	insert_sort(ptr_array, size);

	clock_t end = clock();

	printe(ptr_array, size);

	printf("¬рем€ работы: %.8f ms\n", (double)(end - start) * 1000 / CLOCKS_PER_SEC);

	free(ptr_array);
}

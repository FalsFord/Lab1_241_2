#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	float array[10], temp=0;
	float *ptr_a;
	for (int i = 0; i < 10; i++) {
		temp += 1.1;
		array[i] = temp;
	}
	printf("4.1");
	ptr_a = &array[0];
	printf("\n%f", *ptr_a);
	printf("\n%p", ptr_a);
	ptr_a++;
	printf("\n%f", *ptr_a);
	printf("\n%p", ptr_a);
	ptr_a=ptr_a + 4;
	printf("\n%f", *ptr_a);
	printf("\n%p", ptr_a);
	ptr_a=ptr_a - 2;
	printf("\n%f", *ptr_a);
	printf("\n%p", ptr_a);
	printf("\n");
	printf("\n");
	printf("4.2");
	printf("\n%p", array);
	printf("\n%p", &array[0]);
	printf("\n%p", &array);
	printf("\n");
	printf("\n4.3");
	for (int i = 0; i < 10; i+=2) {
		ptr_a = &array[i];
		printf("\n%f", *ptr_a);
		printf("\n%p", ptr_a);
	}
	printf("\n");
	printf("\n4.4");
	for (int i = 9; i >=0; i--) {
		ptr_a = &array[i];
		printf("\n%f", *ptr_a);
		printf("\n%p", ptr_a);
	}
} 
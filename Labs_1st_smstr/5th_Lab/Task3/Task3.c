#include<stdio.h>
#include<locale.h>
#include<math.h>
#define _USE_MATH_DEFINE
#define t 3
#define e 2,71828182845904
void main() {
	setlocale(LC_ALL, "Rus");
	int A, B, C;

	float y, a, b, x = 4.2e-3;
	puts("\nВведите x ");
	scanf_s("%f", &x);
	a = 1. / t + pow(x, 3);
	b = pow(t, 2) * pow(fabs(a + x), 0.5); 
	y = pow(log(fabs(b + pow(a, 2))), 5);
	printf("\nФункция равна %.2f", y);
	
	A = (int)a;
	B = (int)b;
	C = (int)y;
	printf("\na=%f,b=%f, y=%f", a, b, y);
	printf("\nA=%d,B=%d, C=%d", A, B, C);
	printf("\na) %d", A%2+B%2==1);
	printf("\nб) %d", A%3==0 && B%3==0 && C%2==0);
}
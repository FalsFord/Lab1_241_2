#include<stdio.h>
#include<locale.h>
#include<math.h>

void main() {
    setlocale(LC_ALL, "Rus");

    while (1) {
        char a, symbol;
        int h, b, line, var = 1,step=10;
        float angle;

        puts("\nВведите символ контура ");
        fflush(stdin);
        scanf_s("%c", &symbol, 1);

        printf("\nВведённый символ: %c\n", symbol);

        puts("\nВведите длину b ");
        scanf_s("%d", &b);

        puts("\nВведите высоту h ");
        scanf_s("%d", &h);

        puts("\nВведите значение угла angle(кратное 5)");
        scanf_s("%f", &angle);

        for (int g = angle; g >0; g -= 5) {
            step -= 1;
       }

        /*line = h / tan(angle);*/

        for (int i = 1; i <= h; i++) {

            for (int j = 1; j < b; j++) {
                if ((i == 1 && j < b) || (i == h && j < b)) {
                    printf("%c", symbol);
                }
                else if (j == 1) printf("%c", symbol); else printf("%c", symbol);
            }
            for (int count = 1; count <= var; count++) {
                printf("%c", symbol);
            }
            var += step;

            printf("\n");
        }

        getchar();

        printf("\n\nПродолжить ? (Да - y, нет - n)");
        if ((a = getchar()) == 'n') break;

        getchar();
    }
}

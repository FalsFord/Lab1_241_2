#include <stdio.h>
#include <locale.h>
#include <math.h>

void draw_trapeze(char symbol, int h, int b, float angle)
{
    int line, var = 1,step=10;

    for (int g = angle; g > 0; g -= 5) {
        step -= 1;
    }

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
}
float area_trapeze(int h, int b, float angle) {
    float area = (h / tan(angle) * h) + (h * b);
    return area;
}

int main() {
    setlocale(LC_ALL, "Rus");
    char a,symbol;
    int h, b;
    float angle;
    while (1)
    {
        printf("¬ыберите в меню любую операцию(введите цифру):\n1) рассчитать площадь;\n2) вывести опеределение фигуры;\n3) нарисовать фигуру.\n");
        a = getchar();

        switch (a) {
        case '1':
            getchar();
            puts("\n¬ведите длину b ");
            scanf_s("%d", &b);

            puts("\n¬ведите высоту h ");
            scanf_s("%d", &h);

            puts("\n¬ведите значение угла angle ");
            scanf_s("%f", &angle);

            printf("ѕлощадь трапеции равна %f квад. ед.", area_trapeze(h, b, angle));
            break;
        case '2':
            printf("\n“рапеци€ Ч выпуклый четырЄхугольник, у которого две стороны параллельны, а две другие стороны не параллельны.");
            break;
        case '3':
            getchar();
            puts("\n¬ведите символ контура ");
            scanf_s("%c", &symbol, 1);

            getchar();
            puts("\n¬ведите длину b ");
            scanf_s("%d", &b);

            puts("\n¬ведите высоту h ");
            scanf_s("%d", &h);

            puts("\n¬ведите значение угла angle(кратное 5) ");
            scanf_s("%f", &angle);

            draw_trapeze(symbol, h, b, angle);
            break;
        }

        getchar();
        printf("\nѕродолжить?(y - да, n - нет)");
        if (a = getchar() == 'n')break;
        getchar();
    }
}


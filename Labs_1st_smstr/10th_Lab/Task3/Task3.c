#include <stdio.h>
#include <locale.h>
#include <math.h>

void draw_trapeze(char symbol, int h, int b, float angle)
{
    int line, var = 0;
    /*line = h / tan(angle);*/

    for (int i = 1; i <= h; i++) {

        for (int j = 1; j < b; j++) {
            if ((i == 1 && j < b) || (i == h && j < b)) {
                printf("%c", symbol);
            }
            else if (j == 1) printf("%c", symbol); else printf("%c", symbol);
        }
        /*var += h / line;*/
        for (int count = 1; count <= i; count++) {
            printf("%c", symbol);
        }

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
        printf("�������� � ���� ����� ��������(������� �����):\n1) ���������� �������;\n2) ������� ������������ ������;\n3) ���������� ������.\n");
        a = getchar();

        switch (a) {
        case '1':
            getchar();
            puts("\n������� ����� b ");
            scanf_s("%d", &b);

            puts("\n������� ������ h ");
            scanf_s("%d", &h);

            puts("\n������� �������� ���� angle ");
            scanf_s("%f", &angle);

            printf("������� �������� ����� %f ����. ��.", area_trapeze(h, b, angle));
            break;
        case '2':
            printf("\n�������� � �������� ��������������, � �������� ��� ������� �����������, � ��� ������ ������� �� �����������.");
            break;
        case '3':
            getchar();
            puts("\n������� ������ ������� ");
            scanf_s("%c", &symbol, 1);

            getchar();
            puts("\n������� ����� b ");
            scanf_s("%d", &b);

            puts("\n������� ������ h ");
            scanf_s("%d", &h);

            puts("\n������� �������� ���� angle ");
            scanf_s("%f", &angle);

            draw_trapeze(symbol, h, b, angle);
            break;
        }

        getchar();
        printf("\n����������?(y - ��, n - ���)");
        if (a = getchar() == 'n')break;
        getchar();
    }
}


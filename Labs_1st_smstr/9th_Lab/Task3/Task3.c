#include<stdio.h>
#include<locale.h>
#include<math.h>

void main() {
    setlocale(LC_ALL, "Rus");

    while (1) {
        char a, symbol;
        int h, b, down_line, line,var=0;
        float angle;

        puts("\n������� ������ ������� ");
        fflush(stdin); 
        scanf_s("%c", &symbol, 1);

        printf("\n�������� ������: %c\n", symbol);  

        puts("\n������� ����� b ");
        scanf_s("%d", &b);

        puts("\n������� ������ h ");
        scanf_s("%d", &h);

        puts("\n������� �������� ���� angle ");
        scanf_s("%f", &angle);

        line = h / tan(angle);
        down_line = line + b;
        printf("line %d\n", line);

        for (int i = 1; i <= h; i++) {

            for (int j=1; j < b; j++) {
                if ((i == 1 && j<b) || (i==h&&j<b)) { 
                    printf("%c", symbol);
                }
                else if (j == 1) printf("%c", symbol); else printf("%c",symbol);
            }
            var += h/line;
            for (int count = 1; count <= var; count++) {
                /*if (count > var)break;*/
                printf("%c", symbol);
                /*if(i == h)printf("%c", symbol);
                else if (count == i)printf("%c", symbol);
                else printf(" ");*/
            }

            printf("\n");
        }

        getchar(); 

        printf("\n\n���������� ? (�� - y, ��� - n)");
        if ((a = getchar()) == 'n') break;

        getchar(); 
    }
}

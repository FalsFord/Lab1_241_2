#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Notebook {
    char fabricator[10];
    char OS[10];
    int RAM;
    char CPU[20];
    float screenDiagonal;
} notebook_t;

notebook_t* fill_notebooks(notebook_t* notebooks, int size) {
    char* CPU;
    for (int i = 0; i < size; i++) {
        CPU = notebooks[i].CPU;
        printf("������������� ��������: ");
        scanf("%s", notebooks[i].fabricator);
        getchar();

        printf("������������ �������: ");
        scanf("%s", notebooks[i].OS);
        getchar();

        printf("����������� ������(� ��): ");
        scanf("%d", &notebooks[i].RAM);
        getchar();

        printf("������ ����������: ");
        CPU = gets(notebooks[i].CPU);


        printf("��������� ������(� ������): ");
        fflush(stdin);
        scanf("%f", &notebooks[i].screenDiagonal);
        getchar();
        printf("\n");
    }
    return notebooks;
}

void print_notebook(notebook_t* notebook) {
    printf("������������� ��������: %s\n", notebook->fabricator);
    printf("������������ �������: %s\n", notebook->OS);
    printf("����������� ������(� ��): %d\n", notebook->RAM);
    printf("������ ����������: %s\n", notebook->CPU);
    printf("��������� ������(� ������): %f\n", notebook->screenDiagonal);
    printf("\n");
}

int* search_notebook(notebook_t* notebooks, int SIZE, char* CPU, int RAM) {
    int* countOfSeeked = malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++) {
        countOfSeeked[i] = -1;
    };
    if (CPU != '\0' && RAM != -1) {
        for (int i = 0; i < SIZE; i++) {
            if (strcmp(notebooks[i].CPU, CPU) == 0 && notebooks[i].RAM == RAM) countOfSeeked[i] = i;
        }
    }
    else if (CPU != '\0' && RAM == -1) {
        for (int i = 0; i < SIZE; i++) {
            if (strcmp(notebooks[i].CPU, CPU) == 0) countOfSeeked[i] = i;
        }
    }
    else {
        for (int i = 0; i < SIZE; i++) {
            if (notebooks[i].RAM == RAM) countOfSeeked[i] = i;
        }
    }
    return countOfSeeked;
}


void Sort(notebook_t* notebooks, int size, int n) {
    if (n == 3) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (strcmp(notebooks[j].fabricator, notebooks[j + 1].fabricator) > 0) {
                    notebook_t temp = notebooks[j];
                    notebooks[j] = notebooks[j + 1];
                    notebooks[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (strcmp(notebooks[j].OS, notebooks[j + 1].OS) > 0) {
                    notebook_t temp = notebooks[j];
                    notebooks[j] = notebooks[j + 1];
                    notebooks[j + 1] = temp;
                }
            }
        }
    }
    else if (n == 1) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (strcmp(notebooks[j].fabricator, notebooks[j + 1].fabricator) > 0) {
                    notebook_t temp = notebooks[j];
                    notebooks[j] = notebooks[j + 1];
                    notebooks[j + 1] = temp;
                }
            }
        }
    }
    else {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (strcmp(notebooks[j].OS, notebooks[j + 1].OS) > 0) {
                    notebook_t temp = notebooks[j];
                    notebooks[j] = notebooks[j + 1];
                    notebooks[j + 1] = temp;
                }
            }
        }
    }
}

void WriteFile(notebook_t* notebooks, int size) {
    FILE* fp;
    fp = fopen("Coursework.txt", "w");
    for (int i = 0; i < size; i++) {
        fprintf(fp, "������������� ��������: %s\n", notebooks[i].fabricator);
        fprintf(fp, "������������ �������: %s\n", notebooks[i].OS);
        fprintf(fp, "����������� ������(� ��): %d\n", notebooks[i].RAM);
        fprintf(fp, "������ ����������: %s\n", notebooks[i].CPU);
        fprintf(fp, "��������� ������(� ������): %f\n", notebooks[i].screenDiagonal);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void ReadFile(notebook_t* notebooks, int size) {
    FILE* fp = fopen("Coursework.txt", "r");
    if (fp == NULL) {
        printf("�� ������� ������� ����\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        // ���������� � ��������� � �������
        if (fscanf(fp, "������������� ��������: %[^\n]\n", notebooks[i].fabricator) != 1) {
            printf("������ ��� ���������� ������������� �������� ��� ������ %d\n", i);
            break;
        }
        if (fscanf(fp, "������������ �������: %[^\n]\n", notebooks[i].OS) != 1) {
            printf("������ ��� ���������� ������������ ������� ��� ������ %d\n", i);
            break;
        }
        if (fscanf(fp, "����������� ������(� ��): %d\n", &notebooks[i].RAM) != 1) {
            printf("������ ��� ���������� ����������� ������ ��� ������ %d\n", i);
            break;
        }
        if (fscanf(fp, "������ ����������: %[^\n]\n", notebooks[i].CPU) != 1) {
            printf("������ ��� ���������� ���������� ��� ������ %d\n", i);
            break;
        }
        if (fscanf(fp, "��������� ������(� ������): %f\n", &notebooks[i].screenDiagonal) != 1) {
            printf("������ ��� ���������� ��������� ������ ��� ������ %d\n", i);
            break;
        }
        fscanf(fp, "%*[\n]");
    }

    fclose(fp);
}

void add_notebook(notebook_t* notebooks, int num) {
    char* CPU;
    CPU = notebooks[num].CPU;
    printf("������������� ��������: ");
    scanf("%s", notebooks[num].fabricator);
    getchar();

    printf("������������ �������: ");
    scanf("%s", notebooks[num].OS);
    getchar();

    printf("����������� ������(� ��): ");
    scanf("%d", &notebooks[num].RAM);
    getchar();

    printf("������ ����������: ");
    CPU = gets(notebooks[num].CPU);


    printf("��������� ������(� ������): ");
    fflush(stdin);
    scanf("%f", &notebooks[num].screenDiagonal);
    getchar();
    printf("\n");
}

void main() {
    setlocale(LC_ALL, "Rus");
    int SIZE = 0;
    int* countOfSeeked;
    printf("������� ���������� �������: ");
    scanf_s("%d", &SIZE);
    notebook_t* notebooks;
    notebooks =  malloc(SIZE*sizeof(notebook_t));
    int num = 0;
    char* searchProcUk;
    int a = 1;
    while (a) {
        
        printf("**********************************************\n");
        printf("*                     Menu                   *\n");
        printf("**********************************************\n");
        printf("* 1. ������� ������ �����.                   *\n");
        printf("* 2. ��������� ����� �� �����.               *\n");
        printf("* 3. ������ � ������ �����.                  *\n");
        printf("* 4. ����������� ������ �����.               *\n");
        printf("* 5. ��������� ������                        *\n");
        printf("**********************************************\n");
        scanf("%d", &num);

        switch (num) {
        case 1:
            num = 0;
            fill_notebooks(notebooks, SIZE);
            WriteFile(notebooks, SIZE);
            break;
        case 2:
            num = 0;
            ReadFile(notebooks, SIZE);
            char searchProc[20];
            int searchRAM;
            printf("**********************************************\n");
            printf("*                    ����� ��                *\n");
            printf("**********************************************\n");
            printf("* 1. ����������.                             *\n");
            printf("* 2. ����������� ������.                     *\n");
            printf("* 3. ���������� � ����������� ������.        *\n");
            printf("**********************************************\n");
            scanf("%d", &num);
            switch (num) {
            case 1:
                printf("������� �������� ����������: ");
                getchar();
                searchProcUk = gets(searchProc);
                searchRAM = -1;
                break;
            case 2:
                printf("������� ����� ����������� ������: ");
                scanf("%d", &searchRAM);
                searchProc[0] = '\0';
                break;
            case 3:
                getchar();
                printf("������� �������� ����������: ");
                searchProcUk = gets(searchProc);
                printf("������� ����� ����������� ������: ");
                scanf("%d", &searchRAM);
                break;
            }
            countOfSeeked = search_notebook(notebooks, SIZE, searchProc, searchRAM);
            for (int i = 0; i < SIZE; i++) {
                if (countOfSeeked[i] != -1)print_notebook(&notebooks[i]);
            }
            break;
        case 3:
            num = 0;
            printf("**********************************************\n");
            printf("*             ������ � ������ �����          *\n");
            printf("**********************************************\n");
            printf("* 1. �������� ������.                        *\n");
            printf("* 2. �������� ������.                        *\n");
            printf("* 3. ������� ������.                         *\n");
            printf("* 4. ������ �����.                           *\n");
            printf("**********************************************\n");
            scanf("%d", &num);
            switch (num) {
            case 1:
                SIZE += 1;
                notebooks = realloc(notebooks,SIZE * sizeof(notebook_t));
                add_notebook(notebooks, SIZE);
                WriteFile(notebooks, SIZE);
                break;
                // �������� ��������� ������ ������� �����
            }
            break;
        case 4:

            break;
        case 5:
            a = 0;
            break;
        default:
            printf("�������� �����. ���������� �����.\n");
        }
    }
    free(notebooks);
    free(countOfSeeked);
}

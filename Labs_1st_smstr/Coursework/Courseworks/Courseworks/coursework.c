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
        printf("Производитель ноутбука: ");
        scanf("%s", notebooks[i].fabricator);
        getchar();

        printf("Операционная система: ");
        scanf("%s", notebooks[i].OS);
        getchar();

        printf("Оперативная память(в ГБ): ");
        scanf("%d", &notebooks[i].RAM);
        getchar();

        printf("Модель процессора: ");
        CPU = gets(notebooks[i].CPU);


        printf("Диагональ экрана(в дюймах): ");
        fflush(stdin);
        scanf("%f", &notebooks[i].screenDiagonal);
        getchar();
        printf("\n");
    }
    return notebooks;
}

void print_notebook(notebook_t* notebook) {
    printf("Производитель ноутбука: %s\n", notebook->fabricator);
    printf("Операционная система: %s\n", notebook->OS);
    printf("Оперативная память(в ГБ): %d\n", notebook->RAM);
    printf("Модель процессора: %s\n", notebook->CPU);
    printf("Диагональ экрана(в дюймах): %f\n", notebook->screenDiagonal);
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
        fprintf(fp, "Производитель ноутбука: %s\n", notebooks[i].fabricator);
        fprintf(fp, "Операционная система: %s\n", notebooks[i].OS);
        fprintf(fp, "Оперативная память(в ГБ): %d\n", notebooks[i].RAM);
        fprintf(fp, "Модель процессора: %s\n", notebooks[i].CPU);
        fprintf(fp, "Диагональ экрана(в дюймах): %f\n", notebooks[i].screenDiagonal);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void ReadFile(notebook_t* notebooks, int size) {
    FILE* fp = fopen("Coursework.txt", "r");
    if (fp == NULL) {
        printf("Не удалось открыть файл\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        // Считывание с пробелами в строках
        if (fscanf(fp, "Производитель ноутбука: %[^\n]\n", notebooks[i].fabricator) != 1) {
            printf("Ошибка при считывании производителя ноутбука для записи %d\n", i);
            break;
        }
        if (fscanf(fp, "Операционная система: %[^\n]\n", notebooks[i].OS) != 1) {
            printf("Ошибка при считывании операционной системы для записи %d\n", i);
            break;
        }
        if (fscanf(fp, "Оперативная память(в ГБ): %d\n", &notebooks[i].RAM) != 1) {
            printf("Ошибка при считывании оперативной памяти для записи %d\n", i);
            break;
        }
        if (fscanf(fp, "Модель процессора: %[^\n]\n", notebooks[i].CPU) != 1) {
            printf("Ошибка при считывании процессора для записи %d\n", i);
            break;
        }
        if (fscanf(fp, "Диагональ экрана(в дюймах): %f\n", &notebooks[i].screenDiagonal) != 1) {
            printf("Ошибка при считывании диагонали экрана для записи %d\n", i);
            break;
        }
        fscanf(fp, "%*[\n]");
    }

    fclose(fp);
}

void add_notebook(notebook_t* notebooks, int num) {
    char* CPU;
    CPU = notebooks[num].CPU;
    printf("Производитель ноутбука: ");
    scanf("%s", notebooks[num].fabricator);
    getchar();

    printf("Операционная система: ");
    scanf("%s", notebooks[num].OS);
    getchar();

    printf("Оперативная память(в ГБ): ");
    scanf("%d", &notebooks[num].RAM);
    getchar();

    printf("Модель процессора: ");
    CPU = gets(notebooks[num].CPU);


    printf("Диагональ экрана(в дюймах): ");
    fflush(stdin);
    scanf("%f", &notebooks[num].screenDiagonal);
    getchar();
    printf("\n");
}

void main() {
    setlocale(LC_ALL, "Rus");
    int SIZE = 0;
    int* countOfSeeked;
    printf("Введити количество записей: ");
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
        printf("* 1. Создать запись файла.                   *\n");
        printf("* 2. Выполнить поиск по файлу.               *\n");
        printf("* 3. Запись и чтение файла.                  *\n");
        printf("* 4. Сортировать данные файла.               *\n");
        printf("* 5. Завершить работу                        *\n");
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
            printf("*                    Поиск по                *\n");
            printf("**********************************************\n");
            printf("* 1. Процессору.                             *\n");
            printf("* 2. Оперативной памяти.                     *\n");
            printf("* 3. Процессору и оперативной памяти.        *\n");
            printf("**********************************************\n");
            scanf("%d", &num);
            switch (num) {
            case 1:
                printf("Введите название процессора: ");
                getchar();
                searchProcUk = gets(searchProc);
                searchRAM = -1;
                break;
            case 2:
                printf("Введите объем оперативной памяти: ");
                scanf("%d", &searchRAM);
                searchProc[0] = '\0';
                break;
            case 3:
                getchar();
                printf("Введите название процессора: ");
                searchProcUk = gets(searchProc);
                printf("Введите объем оперативной памяти: ");
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
            printf("*             Запись и чтение файла          *\n");
            printf("**********************************************\n");
            printf("* 1. Добавить запись.                        *\n");
            printf("* 2. Изменить записи.                        *\n");
            printf("* 3. Удалить записи.                         *\n");
            printf("* 4. Чтение файла.                           *\n");
            printf("**********************************************\n");
            scanf("%d", &num);
            switch (num) {
            case 1:
                SIZE += 1;
                notebooks = realloc(notebooks,SIZE * sizeof(notebook_t));
                add_notebook(notebooks, SIZE);
                WriteFile(notebooks, SIZE);
                break;
                // Добавьте обработку других случаев здесь
            }
            break;
        case 4:

            break;
        case 5:
            a = 0;
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
    free(notebooks);
    free(countOfSeeked);
}

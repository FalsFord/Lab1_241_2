#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Notebook {
    char fabricator[10];
    char OS[10];
    int RAM;
    char CPU[20];
    float screenDiagonal;
} notebook_t;

notebook_t* fill_notebooks(notebook_t* notebooks, int size) {
    for (int i = 0; i < size; i++) {
        printf("Производитель ноутбука: ");
        scanf("%9s", notebooks[i].fabricator);
        getchar();

        printf("Операционная система: ");
        scanf("%9s", notebooks[i].OS);
        getchar();

        printf("Оперативная память(в ГБ): ");
        scanf("%d", &notebooks[i].RAM);
        getchar();

        printf("Модель процессора: ");
        fgets(notebooks[i].CPU, sizeof(notebooks[i].CPU), stdin);
        notebooks[i].CPU[strcspn(notebooks[i].CPU, "\n")] = 0; // Удаляем символ новой строки

        printf("Диагональ экрана(в дюймах): ");
        scanf("%f", &notebooks[i].screenDiagonal);
        getchar();
        printf("\n");
    }
    return notebooks;
}

void print_notebook(notebook_t notebook) {
    printf("Производитель ноутбука: %s\n", notebook.fabricator);
    printf("Операционная система: %s\n", notebook.OS);
    printf("Оперативная память(в ГБ): %d\n", notebook.RAM);
    printf("Модель процессора: %s\n", notebook.CPU);
    printf("Диагональ экрана(в дюймах): %f\n", notebook.screenDiagonal);
    printf("\n");
}

int* search_notebook(notebook_t* notebooks, int SIZE, char* CPU, int RAM) {
    int* countOfSeeked = malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++) {
        countOfSeeked[i] = -1;
    }
    if (CPU[0] != '\0' && RAM != -1) {
        for (int i = 0; i < SIZE; i++) {
            if (strcmp(notebooks[i].CPU, CPU) == 0 && notebooks[i].RAM == RAM) countOfSeeked[i] = i;
        }
    }
    else if (CPU[0] != '\0' && RAM == -1) {
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

int compare_fabricator(const void* a, const void* b) {
    const notebook_t* notebook1 = (const notebook_t*)a;
    const notebook_t* notebook2 = (const notebook_t*)b;
    return strcmp(notebook1->fabricator, notebook2->fabricator);
}

int compare_OS(const void* a, const void* b) {
    const notebook_t* notebook1 = (const notebook_t*)a;
    const notebook_t* notebook2 = (const notebook_t*)b;
    return strcmp(notebook1->OS, notebook2->OS);
}

notebook_t* sort_notebooks(notebook_t* notebooks, int size, int criteria) {
    if (criteria == 1) {
        qsort(notebooks, size, sizeof(notebook_t), compare_fabricator);
    }
    else if (criteria == 2) {
        qsort(notebooks, size, sizeof(notebook_t), compare_OS);
    }
    else if (criteria == 3) {
        qsort(notebooks, size, sizeof(notebook_t), compare_fabricator);
        qsort(notebooks, size, sizeof(notebook_t), compare_OS);
    }
    else {
        printf("Ошибка: Неверный критерий сортировки\n");
    }
    return notebooks;
}

char* WriteFile(notebook_t* notebooks, int size) {
    FILE* fp = fopen("Coursework.txt", "w");
    if (fp == NULL) {
        return "Ошибка открытия файла для записи";
    }
    for (int i = 0; i < size; i++) {
        if (fprintf(fp, "Производитель ноутбука: %s\n", notebooks[i].fabricator) < 0 ||
            fprintf(fp, "Операционная система: %s\n", notebooks[i].OS) < 0 ||
            fprintf(fp, "Оперативная память(в ГБ): %d\n", notebooks[i].RAM) < 0 ||
            fprintf(fp, "Модель процессора: %s\n", notebooks[i].CPU) < 0 ||
            fprintf(fp, "Диагональ экрана(в дюймах): %f\n\n", notebooks[i].screenDiagonal) < 0) {
            fclose(fp);
            return "Ошибка записи данных в файл";
        }
    }
    fclose(fp);
    return NULL;
}

char* ReadFile(notebook_t* notebooks, int size) {
    FILE* fp = fopen("Coursework.txt", "r");
    if (fp == NULL) {
        return "Не удалось открыть файл";
    }
    for (int i = 0; i < size; i++) {
        if (fscanf(fp, "Производитель ноутбука: %9s\n", notebooks[i].fabricator) != 1 ||
            fscanf(fp, "Операционная система: %9s\n", notebooks[i].OS) != 1 ||
            fscanf(fp, "Оперативная память(в ГБ): %d\n", &notebooks[i].RAM) != 1 ||
            fscanf(fp, "Модель процессора: %19[^\n]\n", notebooks[i].CPU) != 1 ||
            fscanf(fp, "Диагональ экрана(в дюймах): %f\n\n", &notebooks[i].screenDiagonal) != 1) {
            fclose(fp);
            return "Ошибка при чтении данных из файла";
        }
    }
    fclose(fp);
    return NULL;
}

notebook_t* AddChangeNotes(notebook_t* notebooks, int num) {
    printf("Производитель ноутбука: ");
    scanf("%9s", notebooks[num].fabricator);
    getchar();

    printf("Операционная система: ");
    scanf("%9s", notebooks[num].OS);
    getchar();

    printf("Оперативная память(в ГБ): ");
    scanf("%d", &notebooks[num].RAM);
    getchar();

    printf("Модель процессора: ");
    fgets(notebooks[num].CPU, sizeof(notebooks[num].CPU), stdin);
    notebooks[num].CPU[strcspn(notebooks[num].CPU, "\n")] = 0;

    printf("Диагональ экрана(в дюймах): ");
    scanf("%f", &notebooks[num].screenDiagonal);
    getchar();
    printf("\n");
    return notebooks;
}

notebook_t* DeleteNotes(notebook_t* notebooks, int num, int SIZE)
{
    int n = num - 1;
    int size = SIZE - 1;
    notebook_t* temp = malloc(size * sizeof(notebook_t));
    if (temp == NULL) {
        printf("Ошибка выделения памяти\n");
        return;
    }
    for (int i = 0; i < SIZE; i++) {
        if (i < n) {
            temp[i] = notebooks[i];
        }
        else if (i > n) {
            temp[i - 1] = notebooks[i];
        }
    }
    notebooks = realloc(notebooks, size * sizeof(notebook_t));
    for (int i = 0; i < size; i++) {
        notebooks[i] = temp[i];
    }
    return notebooks;
}

void main() {
    setlocale(LC_ALL, "Rus");
    int SIZE = 0;

    printf("Введити количество записей: ");
    scanf("%d", &SIZE);
    int* countOfSeeked = malloc(SIZE * sizeof(int));
    notebook_t* notebooks = malloc(SIZE * sizeof(notebook_t));
    notebook_t* temp;
    int num = 0;
    char searchProc[20];
    char* error = NULL;
    int a = 1;
    while (a) {
        ReadFile(notebooks, SIZE);

        printf("**********************************************\n");
        printf("*                     Menu                   *\n");
        printf("**********************************************\n");
        printf("* 1. Создать запись файла.                   *\n");
        printf("* 2. Выполнить поиск по файлу.               *\n");
        printf("* 3. Запись и чтение файла.                  *\n");
        printf("* 4. Сортировать данные файла.               *\n");
        printf("* 5. Завершить работу                        *\n");
        printf("**********************************************\n");
        getchar();
        scanf("%d", &num);
        switch (num) {
        case 1:
            num = 0;
            fill_notebooks(notebooks, SIZE);
            error = WriteFile(notebooks, SIZE);
            if (error) {
                printf("Ошибка: %s\n", error);
            }
            else {
                printf("Файл успешно записан\n");
            }
            break;
        case 2:
            num = 0;
            int searchRAM;
            printf("**********************************************\n");
            printf("*                    Поиск по                *\n");
            printf("**********************************************\n");
            printf("* 1. Процессору.                             *\n");
            printf("* 2. Оперативной памяти.                     *\n");
            printf("* 3. Процессору и оперативной памяти.        *\n");
            printf("* 4. Вернуться в меню.                       *\n");
            printf("**********************************************\n");
            scanf("%d", &num);
            switch (num) {
            case 1:
                printf("Введите название процессора: ");
                getchar();
                fgets(searchProc, sizeof(searchProc), stdin);
                searchProc[strcspn(searchProc, "\n")] = 0; // Удаляем символ новой строки
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
                fgets(searchProc, sizeof(searchProc), stdin);
                searchProc[strcspn(searchProc, "\n")] = 0; // Удаляем символ новой строки
                printf("Введите объем оперативной памяти: ");
                scanf("%d", &searchRAM);
                break;
            case 4:
                break;
            }
            countOfSeeked = search_notebook(notebooks, SIZE, searchProc, searchRAM);
            for (int i = 0; i < SIZE; i++) {
                if (countOfSeeked[i] != -1) print_notebook(notebooks[i]);
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
            printf("* 5. Вернуться в меню.                       *\n");
            printf("**********************************************\n");
            scanf("%d", &num);
            switch (num)
            {
            case 1:
                SIZE += 1;
                temp = realloc(notebooks, SIZE * sizeof(notebook_t));
                if (temp == NULL) 
                {
                    printf("Ошибка выделения памяти\n");
                    continue;

                }
                notebooks = temp;
                AddChangeNotes(notebooks, SIZE - 1);
                error = WriteFile(notebooks, SIZE);
                if (error)
                {
                    printf("Ошибка: %s\n", error);
                }
                else 
                {
                    printf("Запись добавлена и файл обновлён\n");
                }
                break;
            case 2:
                num = 0;
                printf("Введите номер записи(%d) для её изменения:", SIZE);
                scanf("%d", &num);
                AddChangeNotes(notebooks, num - 1);
                error = WriteFile(notebooks, SIZE);
                if (error)
                {
                    printf("Ошибка: %s\n", error);
                }
                else
                {
                    printf("Запись обновлена и файл обновлён\n");
                }
                break;
            case 3:
                num = 0;
                printf("Введите номер записи(%d) для её удаления:", SIZE);
                scanf("%d", &num);
                DeleteNotes(notebooks, num, SIZE);
                SIZE -= 1;
                error = WriteFile(notebooks, SIZE);
                if (error) {
                    printf("Ошибка: %s\n", error);
                }
                else {
                    printf("Запись удалена и файл обновлён\n");
                }
                break;
            case 4:
                error = ReadFile(notebooks, SIZE);
                if (error)
                {
                    printf("Ошибка: %s\n", error);
                }
                else 
                {
                    printf("Файл успешно прочитан\n");
                    printf("\n");

                }
                for (int i = 0; i < SIZE; i++) print_notebook(notebooks[i]);
                break;
            case 5:
                break;
            }
            break;
        case 4:
            num = 0;
            printf("**********************************************\n");
            printf("*             Сортировать по                 *\n");
            printf("**********************************************\n");
            printf("* 1. Производителю.                          *\n");
            printf("* 2. Операционной системе.                   *\n");
            printf("* 3. Производителю и операционной системе.   *\n");
            printf("* 4. Вернуться в меню.                       *\n");
            printf("**********************************************\n");
            scanf("%d", &num);
            ReadFile(notebooks, SIZE);
            switch (num) {
            case 1:
                sort_notebooks(notebooks, SIZE, num);
                WriteFile(notebooks, SIZE);
                break;
            case 2:
                sort_notebooks(notebooks, SIZE, num);
                WriteFile(notebooks, SIZE);
                break;
            case 3:
                sort_notebooks(notebooks, SIZE, num);
                WriteFile(notebooks, SIZE);
                break;
            case 4:
                break;
            }

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

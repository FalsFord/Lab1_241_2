#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>
#include<ctype.h>


int main() {
    List list;
    initlist(&list);
    struct listitem* nowlist = list;
    int pos = 0, a = 1;
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");
    while (a) {
        char name[80];
        char data[20];
        char time[20];
        int num = 0;
        puts("Выберите действие.");
        puts("1. Добавить посещенные страницы");
        puts("2. Вывести посещенные страницы");
        puts("3. Удалить посещенную страницу");
        puts("4. Завершить работу");
        scanf("%d", &num);

        switch (num) {
        case 1:
            pos++;
            puts("Введите название сайта:");
            getchar(); // Сброс буфера
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // Удаление символа новой строки
            puts("Введите дату посещения:");
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = '\0'; // Удаление символа новой строки
            puts("Введите время посещения:");
            fgets(time, sizeof(time), stdin);
            time[strcspn(time, "\n")] = '\0'; // Удаление символа новой строки
            insertback_str(&list, data, time, name, num);
            break;
        case 2:
            nowlist = list;
            if (isempty) {
                for (int i = 0; i < length(list); i++) {
                    printf("%d. %s. Последнее посещение %s в %s\n", i + 1, nowlist->name, nowlist->data, nowlist->time);
                    nowlist = nowlist->next;
                }
            }
            else printf("Список пуст\n");
            break;
        case 3:
            num = 0;
            puts("Введите номер страницы для удаления:");
            scanf("%d", &num);
            struct listitem* item = getitem_number(list, num);
            if (item != NULL) {
                destroyItem(&list, item);
                puts("Страница удалена.");
            }
            else {
                puts("Страница не найдена.");
            }
            break;
        }
        if (num == 4) a = 0;
    }
    return 0;
}
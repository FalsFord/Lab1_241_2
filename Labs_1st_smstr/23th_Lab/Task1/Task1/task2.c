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
        puts("�������� ��������.");
        puts("1. �������� ���������� ��������");
        puts("2. ������� ���������� ��������");
        puts("3. ������� ���������� ��������");
        puts("4. ��������� ������");
        scanf("%d", &num);

        switch (num) {
        case 1:
            pos++;
            puts("������� �������� �����:");
            getchar(); // ����� ������
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // �������� ������� ����� ������
            puts("������� ���� ���������:");
            fgets(data, sizeof(data), stdin);
            data[strcspn(data, "\n")] = '\0'; // �������� ������� ����� ������
            puts("������� ����� ���������:");
            fgets(time, sizeof(time), stdin);
            time[strcspn(time, "\n")] = '\0'; // �������� ������� ����� ������
            insertback_str(&list, data, time, name, num);
            break;
        case 2:
            nowlist = list;
            if (isempty) {
                for (int i = 0; i < length(list); i++) {
                    printf("%d. %s. ��������� ��������� %s � %s\n", i + 1, nowlist->name, nowlist->data, nowlist->time);
                    nowlist = nowlist->next;
                }
            }
            else printf("������ ����\n");
            break;
        case 3:
            num = 0;
            puts("������� ����� �������� ��� ��������:");
            scanf("%d", &num);
            struct listitem* item = getitem_number(list, num);
            if (item != NULL) {
                destroyItem(&list, item);
                puts("�������� �������.");
            }
            else {
                puts("�������� �� �������.");
            }
            break;
        }
        if (num == 4) a = 0;
    }
    return 0;
}
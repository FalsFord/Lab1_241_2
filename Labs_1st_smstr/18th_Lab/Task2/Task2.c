#include<stdio.h>
#include<time.h>
#include<locale.h>
#include<string.h>
void main() {
    setlocale(LC_ALL, "Rus");
	time_t t;
    t = time(NULL);
    struct tm* mytime;
    mytime = localtime(&t);
    printf("������� 2.1\n");
    printf("Moscow time: %02d:%02d:%02d \n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
    printf("������� 2.2\n");
    char array[100];
    switch (mytime->tm_wday) {
    case 1:
        printf("���� ������ �����������. ");
        break;
    case 2: 
        printf("���� ������ �������. ");
        break;
    case 3:
        printf("���� ������ �����. ");
        break;
    case 4:
        printf("���� ������ �������. ");
        break;
    case 5:
        printf("���� ������ �������. ");
        break;
    case 6:
        printf("���� ������ �������. ");
        break;
    case 7:
        printf("���� ������ �����������. ");
        break;

    }
    printf("������� %d.%d.%d. ", mytime->tm_mday, mytime->tm_mon+1, mytime->tm_year+1900);
    switch (mytime->tm_mon) {
    case 0: printf("���� %d ����� ������. ",mytime->tm_mday);
        break;
    case 1: printf("���� %d ����� �������. ", mytime->tm_mday);
        break;
    case 2: printf("���� %d ����� ����. ", mytime->tm_mday);
        break;
    case 3: printf("���� %d ����� ������. ", mytime->tm_mday);
        break;
    case 4: printf("���� %d ����� ���. ", mytime->tm_mday);
        break;
    case 5: printf("���� %d ����� ����. ", mytime->tm_mday);
        break;
    case 6: printf("���� %d ����� ����. ", mytime->tm_mday);
        break;
    case 7: printf("���� %d ����� ������. ", mytime->tm_mday);
        break;
    case 8: printf("���� %d ����� ��������. ", mytime->tm_mday);
        break;
    case 9: printf("���� %d ����� �������. ", mytime->tm_mday);
        break;
    case 10: printf("���� %d ����� ������. ", mytime->tm_mday);
        break;
    case 11: printf("���� %d ����� �������. ", mytime->tm_mday);
        break;
    }
    printf("C������ %d-���� %d ����. ", mytime->tm_yday, mytime->tm_year + 1900);
    printf("�� ����������� %d ���� � %d �����. ", 7-mytime->tm_wday, (7-mytime->tm_wday)*24-mytime->tm_hour);
    if(mytime->tm_min>=30)printf("� ������ ���� ������ %d ����� � %d �����. ",mytime->tm_hour-9,mytime->tm_min-30);
    else printf("� ������ ���� ������ %d ����� � %d �����. ", mytime->tm_hour - 9, mytime->tm_min);
    printf("�� ������ ���� �������� %d ������� � %d ����. ", 12 - mytime->tm_mon -1, abs((365 - mytime->tm_yday)-(12-mytime->tm_mon-1)*31));
    printf("�� ����� ���� �������� %d ����� � %d ������. ", 90 - mytime->tm_min, 59 - mytime->tm_sec);
    printf("�� ����� ������ %d ����, �� ����� ���� %d �������. ", 31 - mytime->tm_mday, 11 - mytime->tm_mon);
}
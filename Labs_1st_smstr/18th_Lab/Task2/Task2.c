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
    printf("«адание 2.1\n");
    printf("Moscow time: %02d:%02d:%02d \n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
    printf("«адание 2.2\n");
    char array[100];
    switch (mytime->tm_wday) {
    case 1:
        printf("ƒень недели понедельник. ");
        break;
    case 2: 
        printf("ƒень недели вторник. ");
        break;
    case 3:
        printf("ƒень недели среда. ");
        break;
    case 4:
        printf("ƒень недели четверг. ");
        break;
    case 5:
        printf("ƒень недели п€тница. ");
        break;
    case 6:
        printf("ƒень недели суббота. ");
        break;
    case 7:
        printf("ƒень недели воскресенье. ");
        break;

    }
    printf("—егодн€ %d.%d.%d. ", mytime->tm_mday, mytime->tm_mon+1, mytime->tm_year+1900);
    switch (mytime->tm_mon) {
    case 0: printf("ƒень %d мес€ц €нварь. ",mytime->tm_mday);
        break;
    case 1: printf("ƒень %d мес€ц февраль. ", mytime->tm_mday);
        break;
    case 2: printf("ƒень %d мес€ц март. ", mytime->tm_mday);
        break;
    case 3: printf("ƒень %d мес€ц апрель. ", mytime->tm_mday);
        break;
    case 4: printf("ƒень %d мес€ц май. ", mytime->tm_mday);
        break;
    case 5: printf("ƒень %d мес€ц июнь. ", mytime->tm_mday);
        break;
    case 6: printf("ƒень %d мес€ц июль. ", mytime->tm_mday);
        break;
    case 7: printf("ƒень %d мес€ц август. ", mytime->tm_mday);
        break;
    case 8: printf("ƒень %d мес€ц сент€брь. ", mytime->tm_mday);
        break;
    case 9: printf("ƒень %d мес€ц окт€брь. ", mytime->tm_mday);
        break;
    case 10: printf("ƒень %d мес€ц но€брь. ", mytime->tm_mday);
        break;
    case 11: printf("ƒень %d мес€ц декабрь. ", mytime->tm_mday);
        break;
    }
    printf("Cегодн€ %d-день %d года. ", mytime->tm_yday, mytime->tm_year + 1900);
    printf("ƒо воскресень€ %d дней и %d часов. ", 7-mytime->tm_wday, (7-mytime->tm_wday)*24-mytime->tm_hour);
    if(mytime->tm_min>=30)printf("— первой пары прошло %d часов и %d минут. ",mytime->tm_hour-9,mytime->tm_min-30);
    else printf("— первой пары прошло %d часов и %d минут. ", mytime->tm_hour - 9, mytime->tm_min);
    printf("ƒо Ќового года осталось %d мес€цев и %d дней. ", 12 - mytime->tm_mon -1, abs((365 - mytime->tm_yday)-(12-mytime->tm_mon-1)*31));
    printf("ƒо конца пары осталось %d минут и %d секунд. ", 90 - mytime->tm_min, 59 - mytime->tm_sec);
    printf("ƒо конца мес€ца %d дней, до конца года %d мес€цев. ", 31 - mytime->tm_mday, 11 - mytime->tm_mon);
}
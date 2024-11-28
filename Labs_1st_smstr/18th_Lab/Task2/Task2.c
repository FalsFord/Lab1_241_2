#include<stdio.h>
#include<time.h>
void main() {
	time_t t;
    t = time(NULL);
    struct tm* mytime;
    mytime = localtime(&t);
    printf("Moscow time: %02d:%02d:%02d \b", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
}
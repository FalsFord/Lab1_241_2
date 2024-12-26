#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#define NMAX 100
#define TYPE char
#define FTYPE "%3c,"

void main() {
    stack s = { 0, {0} }; 
    setlocale(LC_ALL, "ru");
    TYPE word[] = "ПРивет";
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        count++;
    }
    for (int i = 0; i < count; i++) {
        push(&s, word[i]);
    }
    display(&s);
}

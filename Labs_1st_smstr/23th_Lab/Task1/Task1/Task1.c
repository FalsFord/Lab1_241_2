#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


#ifndef _LIST_H
#define _LIST_H

typedef struct listitem {
	int number;
	char name[80];
	struct List* next;
	
}List;

void initlist(List* list) {
	list = NULL;
}

bool isempty(List* list) {
	return list == NULL;
}
int length(List* list) {
	int count = 0;
	struct listitem* next= list;
	while (next != NULL) {
		count++;
		next = next->next;
	}
}

void insertfrontint(List* list, int val) {
	List* newnode = (List*)malloc(sizeof(List));
	newnode->number = val;
	newnode->next = list;
	list = newnode;
}

void insertfrontstr(List* list, char* str) {
	List* newnode = (List*)malloc(sizeof(List));
	strcpy(newnode->name, str);
	newnode->next = list;
	list = newnode;
}

void insertbackint(List* head, int val)
{
	List* last;
	if (head == NULL) {
		last = NULL;
	}
	while (head->next) {
		last = head;
		head = head->next;
	}
	List* temp = (List*)malloc(sizeof(List));
	strcpy(temp->number, val);
	temp->next = NULL;
	last->next = temp;
}

void insertbackstr(List* head, char* str)
{
	List* last;
	if (head == NULL) {
		last = NULL;
	}
	while (head->next) {
		last = head;
		head = head->next;
	}
	List* temp = (List*)malloc(sizeof(List));
	strcpy(temp->name, str);
	temp->next = NULL;
	last->next = temp;
}
#endif // !_LIST_H

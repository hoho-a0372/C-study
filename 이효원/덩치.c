#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void init();
void insert();
void Free();

typedef struct size {
	int x;
	int y;
	struct size* next;
	int rank;
}size;

size* head;
size* tail;

int main() {
	int n=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		insert();
	Free();
	return 0;
}

void init() {
	head = (size*)malloc(sizeof(size));
	if (head == NULL) return;
	head->next = NULL;
	tail = head;
	if (tail == NULL) return;

}

void insert() {
	size* newNode = (size*)malloc(sizeof(size));
	if (newNode == NULL)return;
	size* tmp = head;
	scanf("%d %d", &newNode->x, &newNode->y);
	newNode->rank = 1;
	newNode->next = NULL;
	while (tmp != NULL) {
		tmp = tmp->next;
		if ((newNode->x > tmp->x) && (newNode->y > tmp->y))
			tmp->rank += 1;
		else if ((newNode->x < tmp->x) && (newNode->y < tmp->y))
			newNode->rank += 1;
	}

	tail->next = newNode;
	tail = newNode;
}

void Free() {
	while (1) {
		size* tmp = head;
		head = head->next;
		free(tmp);
		tmp = NULL;
	}
	head = NULL;
	tail = NULL;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct member_OldName {
	int old;
	char name[20];
}member;

void printfFunc(int, member*);
void scanfFunc(int, member*);
void ascending_sort(int, member*);

int main() {
	int m, N;
	m = scanf("%d", &N);
	member* mem_p = NULL;
	mem_p = (member*)calloc(N, sizeof(member));
	scanfFunc(N, mem_p);
	ascending_sort(N, mem_p);
	printfFunc(N, mem_p);
	return 0;
}

void ascending_sort(int n, member* mems) {
	int i = 0, j = 0;
	member* tmp = mems;
	for (j = 0; j < (n - 1); j++) {
		for (i = 0; i < (n - j - 1); i++) {
			if ((mems + i)->old > (mems + i + 1)->old) {
				tmp->old = (mems + i)->old;
				strcpy(tmp->name, (mems + i)->name);

				(mems + i)->old = (mems + i + 1)->old;
				strcpy((mems + i)->name, (mems + i+1)->name);

				(mems + i + 1)->old = tmp->old;
				strcpy((mems + i + 1)->name, tmp->name);

			}
		}
	}
}
void scanfFunc(int n, member* mem){
	for (int i = 0; i < n; i++) {
		int m = scanf("%d %s", &(mem+n)->old, (mem+n)->name);
	}
}
void printfFunc(int n, member* mem) {
	for (int i = 0; i < n; i++) {
		int m = printf("%d %s", (mem + n)->old, (mem + n)->name);
	}
}
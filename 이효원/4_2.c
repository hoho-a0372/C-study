#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10
#define L 10
void ascendingSort(char**);
void Get_a_word(char[]);
void words(char**);
int compare_word(const void *, const void *);
int main(){
	char *words_p[N];
	words(words_p);
	ascendingSort(words_p);
//오름차순 출력
	for(int i=0;i<N;i++)
		printf("%s\n", words_p[i]);
//data free
	for(int i=0;i<N;i++)
		free(words_p[i]);
	return 0;
}

//오름차순 정렬
void ascendingSort(char *sortWords[]){
	qsort(sortWords, N, sizeof(char*), compare_word);
}
int compare_word(const void *p, const void *q){
	return strcmp(*(char**)p, *(char**)q);
}

//단어 받아서 그 크기만큼 동적할당
void words(char *words[]){
	for(int n=0;n<N;n++){
		char word[10]={0};
		Get_a_word(word);
		words[n] = (char*)calloc(strlen(word)+1,sizeof(char));
		strcpy(words[n], word);
	}
}

//한 글자씩 받아서 \n 까지 전달
void Get_a_word(char wp[]){
	char Aword;
	int i=0;
	while(i<L){
		Aword = getchar();
		if(Aword == '\n') break;
		wp[i++] = Aword;
	}
}

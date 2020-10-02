//로또 추첨 프로그램

#include <stdio.h>
int count_func(int[], int[]);
int lotto_func(int[], int[], int, int);
void rank(int);

int main(void){
	int set[][6]={{1,2,3,4,5,6}, {10,15,25,35,40,42}, {1,9,11,22,23,25}, {9,28,31,34,35,36}, {1,9,23,28,33,35}};
	int i, j, lotto[6], bonus, count;

	printf("금주의 로또 번호를 입력하세요 -> ");
	for(i=0; i<6; i++)
		scanf("%d", &lotto[i]);

	printf("보너스 번호를 입력하세요 -> ");
	scanf("%d", &bonus);

	printf("\n홍길동님의 로또 당첨 결과는 다음과 같습니다.\n\n");
	for(i=1; i<6; i++){
		printf("%d세트 번호<", i);
		for(j=0; j<6; j++){
			printf("%d", set[i-1][j]);
			if (j<5)
				printf(" ");
			else
				printf("> -> ");
		}
		count = count_func(set[i-1], lotto);
		count = lotto_func(set[i-1], lotto, bonus, count);
		rank(count);
	}
	return 0;
}

int count_func(int set[], int lotto[]){
	int i, j, k=0;
	for(i=0; i<6; i++)
		for(j=0; j<6; j++)
			if(set[i]==lotto[j])
				k++;
	return k;
}

int lotto_func(int set[], int lotto[], int  bonus, int k){
	int i, j;
	for(i=0; i<6; i++){
		for(j=0; j<6; j++){
			if(set[i]==lotto[j]){
				printf("%d ", set[i]);
				break;
			}
			else if(bonus==set[i] && k==5){
				printf("%d ", bonus);
				k += 2;
				break;
			}
			if(j==5)
				printf("X ");
		}
	}
	return k;
}

void rank(int count){
	if(count==6)
		printf("<1등>\n");
	else if(count==7)
		printf("<2등>\n");
	else if(count==5)
		printf("<3등>\n");
	else if(count==4)
		printf("<4등>\n");
	else if(count==3)
		printf("<5등>\n");
	else
		printf("<꽝>\n");
}

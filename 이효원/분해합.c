#include <stdio.h>

int sum_number(int num, int n);
int main() {
	int i = 0, R;
	int N, M = 0, k=1, sum, tem;
	//N: M의 분해합, M: N의 생성자, k: N은 k자리 숫자임, i: N의 자릿수
	//sum: 임시 생성자
	//백준에서 프린트 문같은 쓸데없는 문장 넣지 말기...
	tem = scanf("%d", &N);
	tem = N;
	while (1) {
		tem /= 10;
		i++;
		if (!tem) break;
		k *= 10;
	}
	for (R = N - (9 * i); R < N; R++) {
		sum = sum_number(R, k);
		if (sum == N) {
			M = R;
			break;
		}
	}
	printf("%d\n", M);
	return 0;
}

//각 자리의 숫자를 모두 합하는 함수
int sum_number(int num, int n) {
	int tem = num, k = n;
	for (n = k; n >= 1; n /= 10) {
		num += tem / n;
		tem = tem % n;
	}
	return num;
}
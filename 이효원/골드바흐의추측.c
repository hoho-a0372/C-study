#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int goldbach_partition(int);
int prime_number(int);

int main (){
	int T, n, tmp;
	int *nump;
	scanf("%d", &T);
	nump = (int*)malloc(sizeof(int)*T);
	for(int i=0; i<T; i++){
		scanf("%d", &n);
		*(nump+i) = goldbach_partition(n);
	}
	for (int i=0; i<T; i++){
		tmp = *(nump+i);
		printf("%d %d", tmp, n-tmp);
	}
	free(nump);
	nump = NULL;
	return 0;
}
int prime_number(int num){
	for (int div = 2; div <= sqrt(num); div++){
		if (num % div == 0)
			return 0;
	}
	return 1;
}

int goldbach_partition(int n){
	int gp, i, primeBool;
	for(i=2; i<n/2+1; i++){
		if(prime_number(i)){
			if(prime_number(n-i))
				gp = i;
		}
	}
	return gp;
}

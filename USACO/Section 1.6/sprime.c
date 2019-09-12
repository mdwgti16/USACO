/*
ID: xggc1
LANG : C
PROG : sprime
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE* fout;

int N;
int isPrime(int n) {
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

void genSprime(int n, int num) {
	if (n == 0) {
		if (isPrime(num))
			//printf("%d %d\n", n, num);
			fprintf(fout, "%d\n", num);
		return;
	}
	//printf("%d %d\n", n, num);
	int i = 1;
	if (n == N) {
		genSprime(n - 1, num + 2);
		i = 3;
	}
	if (num == 0 || isPrime(num)) {
		//printf("numnum %d %d\n", num, n);
		num *= 10;
		for (i; i <= 9; i += 2) {
			//printf("num+1 num+1 %d\n", num+i);
			genSprime(n - 1, num + i);
		}
	}

}
void main() {
	FILE* fin = fopen("sprime.in", "r");
	fout = fopen("sprime.out", "w");

	fscanf(fin, "%d", &N);
	
	genSprime(N, 0);

	exit(0);
}
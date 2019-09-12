/*
ID: xggc1
LANG : C
PROG : pprime
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* fout;
int a, b;

void isPrime(int n);
void getPals(int i, int n, int isMid, char* str);


int main() {
	FILE* fin = fopen("pprime.in", "r");
	fout = fopen("pprime.out", "w");
	
	int t;
	int an, bn;
	
	fscanf(fin, "%d %d", &a,&b);

	an = bn = 0;
	t = a;
	while (t)
	{
		t /= 10;
		an += 1;
	}
	t = b;
	while (t)
	{
		t /= 10;
		bn += 1;
	}

	char* str;
	str = (char*)calloc(bn+1, sizeof(char));
	
	for (int i = an; i <= bn; i++) {
		getPals(0, i, 0, str);
	}	

	return 0;
}

void isPrime(int n) {
	for (int d = 3; d*d <= n; d += 2) {
		if (n % d == 0) {
			return;
		}
	}
	if(n>=a && n<=b)
		fprintf(fout, "%d\n", n);
	
}
void getPals(int i, int n, int isMid, char* str) {
	int d = 1;
	int j = 0;
	char c[2];

	if (!isMid) {
		d = 2;
		j = 1;
	}
	
	if (n / 2 == i) {
		if (n % 2 == 1) {
			for (; j <= 9; j += d) {
				sprintf(c, "%d", j);
				str[i] = c[0];
				isPrime(atoi(str));
			}
			return;
		}

		isPrime(atoi(str));
		return;
	}
	
	for (; j <= 9; j += d) {
		sprintf(c, "%c", j);
		sprintf(c, "%d", j);
		str[i] = c[0];
		str[n - 1 - i] = c[0];

		getPals(i + 1, n, 1, str);

	}
}
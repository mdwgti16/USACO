/*
ID: xggc1
LANG : C
PROG : pprime
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int* result;
int j;
void isPrime(int n);
void getPals(int i, int n, int isMid, char* str);

int main() {
	FILE* fin = fopen("pprime.in", "r");
	FILE* fout = fopen("pprime.out", "w");
	
	int a, b, t;
	int an, bn;

	
	fscanf(fin, "%d", &a);
	fscanf(fin, "%d", &b);
	
	result= (int*)calloc(1, sizeof(int));
	
	j = 0;

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

	for (int i = 0; i < j; i++) {
		if (result[i]>=a && result[i]<=b)
			fprintf(fout, "%d\n", result[i]);
	}
	return 0;
}

void isPrime(int n) {
	for (int d = 3; d < n; d += 2) {
		if (n % d == 0) {
			break;
		}
		if (d > sqrt(n)) {
			
			result[j] = n;
			j += 1;
			result = (int*)realloc(result, sizeof(int) * (j + 5));
			break;
		}
	}
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
		/*str[i] = itoa(j, t, 10);
		str[n - 1 - i] = itoa(j, t, 10);*/
		sprintf(c, "%c", j);
		sprintf(c, "%d", j);
		str[i] = c[0];
		str[n - 1 - i] = c[0];

		getPals(i + 1, n, 1, str);

	}
}
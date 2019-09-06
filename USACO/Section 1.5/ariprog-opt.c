/*
"""
ID: xggc1
	LANG : C
	PROG : ariprog
"""
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Result {
	int s;
	int d;
} Result;

int compare_num(const void* value1, const void* value2);

int main(void)
{
	Result* result = NULL;
	FILE* fin = fopen("ariprog.in", "r");
	FILE* fout = fopen("ariprog.out", "w");
	int N, M;
	fscanf(fin, "%d", &N);
	fscanf(fin, "%d", &M);

	int* sList = NULL;
	int size = M * M * 2;
	int rSize = 0;
	int r = 0;

	sList = (int*)malloc(sizeof(int) * size + 1);


	memset(sList, 0, sizeof(int) * (size)+1);

	for (int i = 0; i < M + 1; i++) {
		for (int j = 0; j < M + 1; j++) {
			rSize += 1;
			sList[i * i + j * j] = 1;
		}
	}
	rSize = rSize - (N - 1);
	result = (Result*)calloc(rSize, sizeof(Result));

	//int cnt = 0;
	for (int i = 0; i < M * M * 2 - (N - 1) + 1; i++) {
		if (sList[i])
			for (int j = 1; i+j*(N-1) <= M * M * 2 ; j++) {
				int isAP = 1;
				for (int k = 0; k < N; k++) {
					//cnt += 1;
					if (sList[i + j * k] != 1) {
						isAP = 0;
						break;
					}

				}

				if (isAP) {
					result[r].s = i;
					result[r].d = j;
					r += 1;
				}

			}
	}
	//printf("%d", cnt);
	if (r > 0) {
		qsort(result, r, sizeof(Result), compare_num);

		for (int i = 0; i < r; i++) {
			if (result[i].d) {
				fprintf(fout, "%d %d\n", result[i].s, result[i].d);
			}
			else {
				break;
			}
		}
	}
	else {
		fprintf(fout, "%s\n", "NONE");
	}



}


int compare_num(const void* value1, const void* value2) {
	Result* item1 = (Result*)value1;
	Result* item2 = (Result*)value2;

	if (item1->d != item2->d) {
		if (item1->d > item2->d) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {
		if (item1->s > item2->s) {
			return 1;
		}
		else {
			return -1;
		}
	}
}
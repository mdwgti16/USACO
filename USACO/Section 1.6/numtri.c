/*
ID: xggc1
	LANG : C
	PROG : numtri
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Triangle {
	int* r;
}Triangle;

void getHighest(int i,int j,int s);

Triangle* tri = NULL;
int highest;
int r;
int main() {
	
	FILE* fin = fopen("numtri.in", "r");
	FILE* fout = fopen("numtri.out", "w");
	highest = 0;
	
	fscanf(fin, "%d", &r);

	tri = (Triangle*)malloc(sizeof(Triangle) * r);
	for (int i = 0; i < r; i++) {
		tri[i].r = (int*)calloc(i + 1, sizeof(int));
	}
	
	int t = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < i + 1; j++) {
			fscanf(fin, "%d", &t);
			tri[i].r[j] = t;
		}
	}

	getHighest(0, 0, 0);

	fprintf(fout, "%d\n", highest);

	return 0;
}

void getHighest(int i,int j,int s) {

	if (i < r) {
		getHighest(i + 1, j, s + tri[i].r[j]);
		getHighest(i + 1, j + 1, s + tri[i].r[j]);
	}else if (i == r) {
		
		if (highest < s) {
			highest = s;
		}
	}
}
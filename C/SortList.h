#pragma once
#define MAXSIZE 10

struct SortList {
	int data[MAXSIZE + 1];
	int length;
};
typedef struct SortList *SList;
typedef struct SortList SortList;

void Swap(SList l, int m, int n);
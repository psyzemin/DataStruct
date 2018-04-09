#include "SortList.h"

void Swap(SList l, int m, int n) {
	int temp = l->data[m];
	l->data[m] = l->data[n];
	l->data[n] = temp;
}
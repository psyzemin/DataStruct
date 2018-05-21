#include "HeapSort.h"

void HeapAdjust(SList L, int min, int max) {
	int tmp = L->data[min];
	for (int i = 2*min; i < max; i*=2)
	{
		if (i<max && L->data[i]<L->data[i+1])
		{
			++i;
		}
		if (tmp>=L->data[i])
		{
			break;
		}
		L->data[min] = L->data[i];
		min = i;
	}
	L->data[min] = tmp;
}
void HeapSort(SList L) {
	for (int i = L->length/2; i > 0; i--)
	{
		HeapAdjust(L, i, L->length);
	}
	for (int i = L->length; i > 1; i--)
	{
		Swap(L, 1, i);
		HeapAdjust(L, 1, i - 1);
	}
}
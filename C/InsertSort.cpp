#include "InsertSort.h"

void InsertSort(SList L) {
	for (int i = 2; i < L->length; i++)
	{
		if (L->data[i]<L->data[i-1])
		{
			L->data[0] = L->data[i];
			int j;
			for (j = i-1;L->data[j] > L->data[0] ; j--)
			{
				L->data[j + 1] = L->data[j];
			}
			L->data[j+1] = L->data[0];
		}
	}
}
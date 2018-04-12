#include "SelectSort.h"
#include<stdio.h>
#include<stdlib.h>

void SelectSort(SList L) {
	int min;
	for (int i = 1; i < L->length; i++)
	{
		min = i;
		for (int j = i+1; j < L->length; j++)
		{
			if (L->data[j]<L->data[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			Swap(L, i, min);
		}
	}
}
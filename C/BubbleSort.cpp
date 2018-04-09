#include "BubbleSort.h"
#include<stdio.h>
#include<stdlib.h>

int BubbleSort0(SList L) {
	for (int j = 1; j < L->length; j++)
	{
		for (int i = L->length-1; i > 0; i--)
		{
			if (L->data[i-1]>L->data[i])
			{
				Swap(L, i - 1, i);
			}
		}
	}
	return true;
}

int BubbleSort1(SList L) {
	bool isChanged = true;
	for (int j = 1; j < L->length && isChanged; j++)
	{
		isChanged = false;
		for (int i = L->length - 1; i > 0; i--)
		{
			if (L->data[i - 1]>L->data[i])
			{
				Swap(L, i - 1, i);
				isChanged = true;
			}
		}
	}
	return true;
}

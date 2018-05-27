#include "MergeSort.h"
#include<stdio.h>
#include<stdlib.h>

void MergeSort(SList list) {
	MSort(list->data, list->data, 1, list->length);
}
void MergeSort2(SList list) {
	int *space = (int*)malloc(sizeof(int)*list->length);
	int mark = 1;
	while (mark<list->length)
	{
		MergePass(list->data, space, mark, list->length);
		mark *= 2;
		MergePass(space, list->data, mark, list->length);
		mark *= 2;
	}
}
void MergePass(int SPart[], int LPart[], int small, int large) {
	int i = 1;
	while (i <= large-2*small+1)
	{
		Merge(SPart, LPart, i, i + small - 1, i + 2 * small - 1);
		i = i + 2 * small;
	}
	if (i < large - small + 1) {
		Merge(SPart, LPart, i, i + small - 1, large);
	}
	else
	{
		for (int j = i; j < large; j++)
		{
			LPart[j] = SPart[j];
		}
	}
}
void MSort(int Part[], int result[], int small, int large) {
	int medium;
	int temp[MAXSIZE + 1];
	if (small == large)
	{
		result[small] = Part[small];
	}
	else
	{
		medium = (small + large) / 2;
		MSort(Part, temp, small, medium);
		MSort(Part, temp, medium + 1, large);
		Merge(temp, result, small, medium, large);
	}
}
void Merge(int Part[], int result[], int Psmall, int medium, int large) {
	int left, Plarge;
	for (left = Psmall, Plarge = medium+1; Psmall<=medium && Plarge <=large; left++)
	{
		if (Part[Psmall]<Part[Plarge])
		{
			result[left] = Part[Psmall];
			Psmall++;
		}
		else
		{
			result[left] = Part[Plarge];
			Plarge++;
		}
	}
	if (Psmall<=medium)
	{
		for (int i = 0; i < medium-left; i++)
		{
			result[i + left] = Part[Psmall + i];
		}
	}
	if (Plarge <=large)
	{
		for (int i = 0; i < large-Plarge; i++)
		{
			result[i + left] = Part[Plarge + i];
		}
	}
}
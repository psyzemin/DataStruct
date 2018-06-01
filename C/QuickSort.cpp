#include "QuickSort.h"

void QuickSort(SList list) {
	QSort(list, 1, list->length);
}
void QSort(SList list, int left, int right) {
	if (left < right)
	{
		int key = Partition(list, left, right);
		QSort(list, left, key - 1);
		QSort(list, key + 1, right);
	}
}
int Partition(SList list, int left, int  right) {
	int m = left + (right - left) / 2;
	if (list->data[left] > list->data[right])
		Swap(list, left, right);
	if (list->data[m] > list->data[right])
		Swap(list, m, right);
	if (list->data[left] < list->data[m])
		Swap(list, left, m);
	int key = list->data[left];
	list->data[0] = key;
	while (left<right)
	{
		while (left<right&&list->data[right]>=key)
			right--;
		list->data[left] = list->data[right];
		while (left<right&&list->data[left]<=key)
			left++;
		list->data[right] = list->data[left];
		list->data[left] = list->data[0];
	}
	return left;
}
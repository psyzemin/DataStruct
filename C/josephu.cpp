#include<stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int josephu(int number, int time) {
	int M = 1;
	int N = 5;
	int size = 1;

	List L = CreatNode(1);
	L->next = L;
	position p = L;
	for (int i = 2; i < number + 1; i++)
	{
		List tem = CreatNode(i);
		tem->next = L;
		p->next = tem;
		p = p->next;
		size++;
	}
	p = L;
	position tem;
	while (size > 1)
	{
		int t = 0;
		tem = p;

		if (time > 1)
		{
			while (t < time - 1)
			{
				p = p->next;
				t++;
			}
			tem = p->next;
		}
		else
		{
			while (t < time - 1)
			{
				tem = tem->next;
				t++;
			}
			while (p->next != tem)
			{
				p = p->next;
			}
		}

		printf_s("%d\n", tem->data);
		p->next = tem->next;
		p = p->next;
		free(tem);
		size--;
	}
	printf_s("the winner is %d\n", p->data);
	return 0;
}
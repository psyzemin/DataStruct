#include<stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue CreatQueue(int x) {
	Queue  n = (Queue)malloc(sizeof(struct QueueNode));
	if (n == NULL) {
		perror("Out of space!");
	}
	n->next = NULL;
	n->data = x;
	return n;
}
int Isempty(Queue q) {
	return q->next == NULL;
}
int DeQueue(Queue q) {
	if (Isempty(q))
	{
		perror("Empty Stack!");
	}
	Queue tem = q->next;
	q->next = tem->next;
	int x = tem->data;
	free(tem);
	return x;
}
void EnQueue(Queue q, int x) {
	Queue tem = CreatQueue(x);
	Queue pos = q;
	while (pos->next != NULL)
	{
		pos = pos->next;
	}
	pos->next = tem;
}
void MakeEmpty(Queue q) {
	while (!Isempty(q))
	{
		printf("%d\n", DeQueue(q));
	}
}
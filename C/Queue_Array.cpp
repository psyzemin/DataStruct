#include<stdio.h>
#include<stdlib.h>
#include "Queue_Array.h"

AQueue CreatAQueue(int x) {
	AQueue q = (AQueue)malloc(sizeof(struct QueueArray) + sizeof(int)*x);
	if (q == NULL) {
		perror("Out of space!");
	}
	q->data = (int*)malloc(sizeof(int)*x);
	q->front = 0;
	q->rear = 0;
	q->Qsize = x;
	q->size = 0;
	return q;
}
AQueue Expand(AQueue q) {
	int x = q->Qsize;
	AQueue NewQ = CreatAQueue(x * 2);
	NewQ->Qsize = x * 2;
	NewQ->size = q->size;
	for (int i = 0; i < x - 1; i++)
	{
		NewQ->data[i] = q->data[q->front];
		q->front += 1;
	}
	NewQ->front = 0;
	NewQ->rear = x - 1;
	free(q);
	return NewQ;
}
int Isempty(AQueue q) {
	return q->size == 0;
}
int DeQueue(AQueue q) {
	if (Isempty(q)) {
		perror("Empty Queue!");
	}
	if (q->front == q->Qsize - 1)
	{
		q->front = 0;
	}
	int x = q->data[q->front];
	q->size -= 1;
	q->front += 1;
	return x;
}
int isFull(AQueue q) {
	return q->size == q->Qsize - 1;
}
AQueue EnQueue(AQueue q, int x) {
	if (isFull(q))
	{
		q = Expand(q);
	}
	if (q->rear == q->Qsize-1)
	{
		q->rear = 0;
	}
	q->data[q->rear] = x;
	q->size += 1;
	q->rear += 1;
	return q;
}
void MakeEmpty(AQueue q) {
	while (!Isempty(q))
	{
		printf_s("%d\n", DeQueue(q));
	}
}
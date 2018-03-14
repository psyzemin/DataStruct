#pragma once

struct QueueArray {
	int front;
	int rear;
	int size;
	int Qsize;
	int *data;
};
typedef struct QueueArray *AQueue;

AQueue CreatAQueue(int x);
AQueue Expand(AQueue q);
int Isempty(AQueue q);
int isFull(AQueue q);
int DeQueue(AQueue q);
AQueue EnQueue(AQueue q, int x);
void MakeEmpty(AQueue q);

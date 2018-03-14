#pragma once

struct QueueNode {
	int data;
	struct QueueNode *next;
};

typedef struct QueueNode *Queue;

Queue CreatQueue(int x);
int Isempty(Queue q);
int DeQueue(Queue q);
void EnQueue(Queue q, int x);
void MakeEmpty(Queue q);
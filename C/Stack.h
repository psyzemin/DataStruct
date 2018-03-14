#pragma once


struct StackNode {
	int data;
	struct StackNode *next;
};

typedef struct StackNode *Stack;

Stack CreatStack(int x);
int Isempty(Stack s);
int Pop(Stack s);
void Push(Stack s,int x);
void MakeEmpty(Stack s);

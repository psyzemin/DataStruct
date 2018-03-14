#include<stdio.h>
#include <stdlib.h>
#include "Stack.h"


Stack CreatStack(int x) {
	Stack  n = (Stack)malloc(sizeof(struct StackNode));
	if (n == NULL) {
		perror("Out of space!");
	}
	n->next = NULL;
	n->data = x;
	return n;
}
int Isempty(Stack s) {
	return s->next == NULL;
}
int Pop(Stack s) {
	if (Isempty(s))
	{
		perror("Empty Stack!");
	}
	Stack tem = s->next;
	s->next = tem->next;
	int x = tem->data;
	free(tem);
	return x;
}
void Push(Stack s, int x) {
	Stack n = CreatStack(x);
	n->next = s->next;
	s->next = n;
}
void MakeEmpty(Stack s) {
	while (!Isempty(s))
	{
		printf("%d\n",Pop(s));
	}
}
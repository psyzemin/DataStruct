#include<stdio.h>
#include<stdlib.h>
#include "Stack_Array.h"

AStack CreatAStack(int x) {
	AStack s = (AStack)malloc(sizeof(struct StackArray)+sizeof(int)*x);
	if (s == NULL) {
		perror("Out of space!");
	}
	s->data = (int*)malloc(sizeof(int)*x);
	s->top = -1;
	s->size = x;
	return s;
}
int Isempty(AStack s) {
	return s->top == -1;
}
int Pop(AStack s) {
	if (s->top<0)
	{
		perror("Empty Stack!");
	}
	int n = s->data[s->top];
	s->top--;
	return n;
}
AStack Push(AStack s, int x) {
	if (s->top >= s->size - 1)
	{
		s = Expand(s);
	}	
	s->top += 1;
	s->data[s->top] = x;
	return s;
}
void MakeEmpty(AStack s) {
	while (!Isempty(s))
	{
		printf_s("%d\n", Pop(s));
	}
}
AStack Expand(AStack s) {
	int x = s->size;
	AStack NewS = CreatAStack(x * 2);
	NewS->size = s->size * 2;
	NewS->top = s->top;
	for (int i = 0; i < x; i++)
	{
		NewS->data[i] = s->data[i];
	}
	free(s);
	return NewS;
}
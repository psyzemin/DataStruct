#pragma once

struct StackArray {
	int top;
	int size;
	int *data;
};
typedef struct StackArray *AStack;

AStack CreatAStack(int x);
AStack Expand(AStack s);
int Isempty(AStack s);
int Pop(AStack s);
AStack Push(AStack s, int x);
void MakeEmpty(AStack s);

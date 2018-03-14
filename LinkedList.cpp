#include"LinkedList.h"
#include<stdio.h>
#include <stdlib.h>

List CreatNode(int x) {
	List p = (List)malloc(sizeof(Node));
	if (p == NULL) {
		perror("Out of space!");
	}
	p->data = x;
	p->next = NULL;
	return p;
}

int Isempty(List L) {
	return L->next == NULL;
}
int Islast(position p) {
	return p->next == NULL;
}
position Find(List L, int x) {
	position p = L->next;
	while (p->next != 0 && p->data != x)
	{
		p = p->next;
	}
	return p;
}
position Find_prev(List L, int x) {
	position p = L->next;
	if (p->data != x)
	{
		while (p->next->next != 0 && p->next->data != x)
		{
			p = p->next;
		}
	}
	return p;
}
position Delete(List L,position p) {
	position tem = p;
	p = Find_prev(L,p->data);
	if (!Isempty(L))
	{
		p->next = tem->next;
		tem->next = NULL;
		free(tem);
		return p->next;
	}
	else {
		return p;
	}
}
void Insert(List L, int x) {
	position p = L;
	while (!Islast(p))
	{
		p = p->next;
	}
	position tem = CreatNode(x);
	tem->data = x;
	p->next = tem;
}
void Insert_prev(List L, int x, position p) {
	position tem = CreatNode(x);
	position pre = Find_prev(L, p->data);
	pre->next = tem;
	tem->next = p;
}
void Insert_after(List L, int x, position p) {
	position tem = CreatNode(x);
	if (tem == NULL) {
		perror("Out of space!");
	}
	tem->data = x;
	tem->next = p->next;
	p->next = tem;
}
void Delete_list(List L) {
	if (!Isempty(L))
	{	position p,tem;
		p = L->next;
		L->next = NULL;
		while (p!=NULL)
		{
			tem = p->next;
			free(p);
			p = tem;
		}
	}
}
void PrintList(List L) {
	position p = L->next;
	while (true)
	{
		printf_s("%d\n", p->data);
		if (Islast(p))
		{
			break;
		}
		p = p->next;
	}
}
List Reversal(List L) {
	position pre, tem, aft;
	pre = L;
	tem = pre->next;
	aft = tem->next;

	while (aft != NULL)
	{
		tem->next = pre;
		pre = tem;
		tem = aft;
		aft = aft->next;
	}
	tem->next = pre;
	L->next = NULL;
	return tem;
}

#include"DouLinkedList.h"
#include<stdio.h>
#include <stdlib.h>

List CreatNode() {
	List L = (List)malloc(sizeof(struct DLNode));
	if (L == NULL) {
		perror("Out of space!");
	}
	L->next = NULL;
	L->prev = NULL;
	return L;
}
int Isempty(List L) {
	return L->next == NULL && L->prev == NULL;
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
	while (p->next != 0 && p->data != x)
	{
		p = p->next;
	}
	return p->prev;
}
position Delete(List L, position p) {
	position pre, aft;
	pre = p->prev;
	aft = p->next;
	if (pre!=NULL||aft!=NULL)
	{
		pre->next = aft;
		aft->prev = pre;
		free(p);
		return aft;
	}	
	return p;
}
void Insert(List L, int x) {
	position p = L;
	while (!Islast(p))
	{
		p = p->next;
	}
	position tem = CreatNode();
	tem->data = x;
	tem->prev = p;
	p->next = tem;
}
void Insert_prev(List L, int x, position p) {
	position tem = CreatNode();
	position pre = p->prev;
	tem->data = x;
	pre->next = tem;
	tem->prev = pre;
	tem->next = p;
	p->prev = tem;
}
void Insert_after(List L, int x, position p) {
	position tem = CreatNode();
	position aft = p->next;
	tem->data = x;
	p->next = tem;
	tem->prev = p;
	tem->next = aft;
	aft->prev = tem;
}
void Delete_list(List L) {
	if (!Isempty(L))
	{
		position p, tem;
		p = L->next;
		L->next = NULL;
		p->prev = NULL;
		while (p != NULL)
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
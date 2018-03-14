#pragma once

struct Node {
	int data;
	struct Node *next;
};
typedef struct Node *ToNode;
typedef ToNode List;
typedef ToNode position;

List CreatNode(int x);
int Isempty( List L);
int Islast(position p);
position Find(List L, int x);
position Find_prev(List L, int x);
position Delete(List L, position p);
void Insert(List L, int x);
void Insert_prev(List L, int x, position p);
void Insert_after(List L, int x, position p);
void Delete_list(List L);
void PrintList(List L);
List Reversal(List L);
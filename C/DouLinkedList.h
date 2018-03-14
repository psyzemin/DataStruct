#pragma once

struct DLNode {
	int data;
	struct DLNode *next,*prev;
};
typedef struct DLNode *ToNode;
typedef ToNode List;
typedef ToNode position;

List CreatNode();
int Isempty(List L);
int Islast(position p);
position Find(List L, int x);
position Find_prev(List L, int x);
position Delete(List L, position p);
void Insert(List L, int x);
void Insert_prev(List L, int x, position p);
void Insert_after(List L, int x, position p);
void Delete_list(List L);
void PrintList(List L);
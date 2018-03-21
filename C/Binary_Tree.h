#pragma once
#define element char

struct LTreeNode {
	element data;
	struct LTreeNode *lchild, *rchild;
};
typedef struct LTreeNode *LTree;
typedef struct LTreeNode LTreeNode;

LTree CreatNode(element x);
void CreatTree(LTree *t);
LTree ClearTree(LTree);
int TreeDepth(LTree);
void PreTraverseTree(LTree t, int(*Printelem)(element elem));
int Printelem(element elem);
void PrintTree(LTree t,int space);

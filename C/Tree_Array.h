#pragma once
#define element int

struct ChildNode {
	int n;
	struct ChildNode *next;
}; 
typedef struct ChildNode *childptr;
struct TreeNode {
	element data;
	int parent;
	childptr *firstchild;
};
typedef struct TreeNode *TNode;
struct Tree_Array {
	struct TreeNode *nodes;
	int root, num, size;
};
typedef struct Tree_Array *ATree;

ATree InitTree(int x);
int isEmpty(ATree t);
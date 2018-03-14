#include "Tree_Array.h"
#include<stdio.h>
#include<stdlib.h>

ATree InitTree(int x) {
	ATree t = (ATree)malloc(sizeof(struct Tree_Array) + sizeof(struct TreeNode)*x);
	if (t == NULL) {
		perror("Out of space!");
	}
	t->nodes = (TNode)malloc(sizeof(TNode)*x);
	t->num = 0;
	t->root = 0;
	t->size = x;
	return t;
}
int isEmpty(ATree t) {
	return t->num == 0;
}

#include<stdio.h>
#include<stdlib.h>
#include"Tree_LL.h"

LTree CreatNode(element x) {
	LTree t = (LTree)malloc(sizeof(LTreeNode));
	if (t == NULL) {
		perror("Out of space!");
	}
	t->data = x;
	t->lchild = NULL;
	t->rchild = NULL;
	return t;
}
void CreatTree(LTree *t) {
	element enter;
	printf("please enter the tree: \n");
	enter = getchar();
	if (enter=='#')
	{
		*t = NULL;
	}	
	else
	{
		*t = (LTree)malloc(sizeof(LTreeNode));
		(*t)->data = enter;
		printf("正在输入%c的左子节点...\n", enter);
		CreatTree(&(*t)->lchild);
		printf("正在输入%c的右子节点...\n", enter);
		CreatTree(&(*t)->rchild);
	}
	
}
LTree ClearTree(LTree t) {
	if (t != NULL)
	{
		ClearTree(t->lchild);
		ClearTree(t->rchild);
		free(t);
	}
	return NULL;
}
int TreeDepth(LTree t) {
	if (t == NULL)
	{
		return 0;
	}
	int l = TreeDepth(t->lchild);
	int r = TreeDepth(t->rchild);
	return l > r ? l+1 : r+1;
}
void PreTraverseTree(LTree t,int (*Printelem)(element elem)) {
	if (t == NULL)
	{
		return;
	}
	Printelem(t->data);
	PreTraverseTree(t->lchild,Printelem);
	PreTraverseTree(t->rchild,Printelem);
}
int Printelem(element elem) {
	printf_s("%c\n", elem);
	return 0;
}
void PrintTree(LTree t,int space) {
	if (t == NULL)
	{
		return;
	}
	PrintTree(t->rchild, space + 4);
	for (int i = 1; i < space; i++)
	{
		printf(" ");
	}
	printf("%c\n", t->data);
	PrintTree(t->lchild, space + 4);
}
#include<stdio.h>
#include<stdlib.h>
#include"Binary_Sort_Tree.h"

BSTree CreatNode(int x) {
	BSTree t = (BSTree)malloc(sizeof(BSTreeNode));
	if (t == NULL) {
		perror("Out of space!");
	}
	t->data = x;
	t->lchild = NULL;
	t->rchild = NULL;
	return t;
}
int SearchBST(BSTree tree, int data,BSTree father, BSTree *result) {
	if (tree == NULL)
	{
		*result = father;
		return false;
	}
	else if (data == tree->data)
	{
		*result = tree;
		return true;
	}
	else if (data > tree->data)
	{
		SearchBST(tree->rchild, data,tree, result);
	}
	else
	{
		SearchBST(tree->lchild, data,tree, result);
	}
}
int Insert_BST(BSTree *tree,int data) {
	BSTree newNode = CreatNode(data);
	BSTree mark = NULL;
	if (!SearchBST(*tree, data, NULL, &mark))
	{
		if (!mark)
		{
			*tree = newNode;
		}
		else if (data > mark->data)
		{
			mark->rchild = newNode;
		}
		else
		{
			mark->lchild = newNode;
		}
		return true;
	}
	else
		return false;
}
int Delete_TNode(BSTree *Node) {
	BSTree tmp, next;
	if ((*Node)->lchild == NULL)
	{
		tmp = *Node;
		*Node = (*Node)->rchild;
		free(tmp);
	}
	else if ((*Node)->rchild == NULL)
	{
		tmp = *Node;
		*Node = (*Node)->lchild;
		free(tmp);
	}
	else
	{
		next = *Node;
		tmp = (*Node)->rchild;
		while (tmp->lchild)
		{
			next = tmp;
			tmp = tmp->lchild;
		}
		(*Node)->data = tmp->data;
		if (next!=*Node)
		{
			next->lchild = tmp->rchild;
		}
		else
		{
			next->rchild = tmp->rchild;
		}
		free(tmp);
	}
	return true;
}
int Delete_BST(BSTree *tree, int data) {
	if (!*tree)
	{
		return false;
	}
	else
	{
		if ((*tree)->data == data)
		{
			return Delete_TNode(tree);
		}
		else if (data > (*tree)->data)
		{
			return Delete_BST(&(*tree)->rchild, data);
		}
		else
			return Delete_BST(&(*tree)->lchild, data);
	}
}
void PrintTree(BSTree t, int space) {
	if (t == NULL)
	{
		return;
	}
	PrintTree(t->rchild, space + 4);
	for (int i = 1; i < space; i++)
	{
		printf(" ");
	}
	printf("%d\n", t->data);
	PrintTree(t->lchild, space + 4);
}
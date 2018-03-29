#include "AVL_Tree.h"
#include<stdio.h>
#include<stdlib.h>

#define RH +1
#define EH 0
#define LH -1

int R_rotate(AVLTree *tree) {
	AVLTree root = (*tree)->lchild;
	(*tree)->lchild = root->rchild;
	root->rchild = *tree;
	*tree = root;
	return true;
}
int L_rotate(AVLTree *tree) {
	AVLTree root = (*tree)->rchild;
	(*tree)->rchild = root->lchild;
	root->lchild = *tree;
	*tree = root;
	return true;
}
int LeftBalance(AVLTree *tree) {
	AVLTree root, rr;
	root = (*tree)->lchild;
	switch (root->bf)
	{
	case EH:
		root->bf = RH;
		(*tree)->bf = LH;
		R_rotate(tree);
		break;
	case LH:
		root->bf = (*tree)->bf = EH;
		R_rotate(tree);
		break;
	case RH:
		rr = root->rchild;
		switch (rr->bf)
		{
		case EH:
			root->bf = (*tree)->bf = EH;
			break;
		case LH:
			root->bf = EH;
			(*tree)->bf = RH;
			break;
		case RH:
			root->bf = EH;
			(*tree)->bf = RH;
			break;
		}
		rr->bf = EH;
		L_rotate(&root);
		R_rotate(tree);
		break;
	}
	return true;
}
int RightBalance(AVLTree *tree) {
	AVLTree root, rl;
	root = (*tree)->rchild;
	switch (root->bf)
	{
	case EH:
		root->bf = LH;
		(*tree)->bf = RH;
		L_rotate(tree);
		break;
	case RH:
		root->bf = (*tree)->bf = EH;
		L_rotate(tree);
		break;
	case LH:
		rl = root->lchild;
		switch (rl->bf)
		{
		case EH:
			root->bf = (*tree)->bf = EH;
			break;
		case LH:
			root->bf = RH;
			(*tree)->bf = EH;
			break;
		case RH:
			root->bf = EH;
			(*tree)->bf = LH;
			break;
		}
		rl->bf = EH;
		R_rotate(&root);
		L_rotate(tree);
		break;
	}
	return true;
}
int Insert_AVL(AVLTree *tree, int elem, bool *istaller) {
	if (!*tree)
	{
		*tree = (AVLTree)malloc(sizeof(AVLTreeNode));
		if (*tree == NULL) {
			perror("Out of space!");
		}
		(*tree)->data = elem;
		(*tree)->lchild = (*tree)->rchild = NULL;
		(*tree)->bf = EH;
		*istaller = true;
		return true;
	}
	else
	{
		if ((*tree)->data == elem)
		{
			*istaller = false;
			return false;
		}
		else if (elem < (*tree)->data)
		{
			if (!Insert_AVL(&(*tree)->lchild, elem, istaller))
			{
				return false;
			}
			if (*istaller)
			{
				switch ((*tree)->bf)
				{
				case LH:
					LeftBalance(tree);
					*istaller = false;
					break;
				case RH:
					(*tree)->bf = EH;
					*istaller = false;
					break;
				case EH:
					(*tree)->bf = LH;
					*istaller = true;
					break;
				}
			}
		}
		else
		{
			if (!Insert_AVL(&(*tree)->rchild, elem, istaller))
			{
				return false;
			}
			if (*istaller)
			{
				switch ((*tree)->bf)
				{
				case EH:
					(*tree)->bf = RH;
					*istaller = true;
					break;
				case LH:
					(*tree)->bf = EH;
					*istaller = false;
					break;
				case RH:
					RightBalance(tree);
					*istaller = false;
					break;
				}
			}
		}
	}
	return true;
}
void PrintTree(AVLTree t, int space) {
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
int Delete_AVLNode(AVLTree *tree, int key, bool *reduce)
{
	if (!(*tree))
	{
		*reduce = false;
		return false;
	}
	else {
		if (key<(*tree)->data)
		{
			if (!Delete_AVLNode(&(*tree)->lchild,key,reduce))
			{
				return false;
			}
			if (*reduce)
			{
				switch ((*tree)->bf)
				{
				case EH:
					(*tree)->bf = RH;
					*reduce = true;
					break;
				case LH:
					(*tree)->bf = EH;
					*reduce = false;
					break;
				case RH:
					RightBalance(tree);
					*reduce = false;
					break;
				}
			}
		}
		if (key>(*tree)->data)
		{
			if (!Delete_AVLNode(&(*tree)->rchild, key, reduce))
			{
				return false;
			}
			if (*reduce)
			{
				switch ((*tree)->bf)
				{
				case EH:
					(*tree)->bf = LH;
					*reduce = true;
					break;
				case LH:
					LeftBalance(tree);
					*reduce = false;
					break;
				case RH:
					(*tree)->bf = EH;
					*reduce = false;
					break;
				}
			}
		}
		if (key==(*tree)->data)
		{
			AVLTree pre, aft;
			if ((*tree)->lchild == NULL)
			{
				pre = *tree;
				*tree = (*tree)->rchild;
				free(pre);
				*reduce = true;
			}
			else if ((*tree)->rchild == NULL)
			{
				pre = *tree;
				*tree = (*tree)->lchild;
				free(pre);
				*reduce = true;
			}
			else {
				pre = *tree;
				aft = (*tree)->lchild;
				while (aft->rchild)
				{
					pre = aft;
					aft = aft->rchild;
				}
				(*tree)->data = aft->data;
				if (pre != *tree)
				{
					pre->rchild = aft->lchild;
				}
				else
				{
					pre->lchild = aft->lchild;
				}
				free(aft);
				*reduce = true;
			}
		}
	}
	return true;
}
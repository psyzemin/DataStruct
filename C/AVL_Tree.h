#pragma once

struct AVLTreeNode {
	int data;
	int bf;
	struct AVLTreeNode *lchild, *rchild;
};
typedef struct AVLTreeNode *AVLTree;
typedef struct AVLTreeNode AVLTreeNode;

int R_rotate(AVLTree *tree);
int L_rotate(AVLTree *tree);
int LeftBalance(AVLTree *tree);
int RightBalance(AVLTree *tree);
int Insert_AVL(AVLTree *tree, int elem, bool *istaller);
void PrintTree(AVLTree t, int space);
int Delete_AVLNode(AVLTree *T, int key, bool *lower);
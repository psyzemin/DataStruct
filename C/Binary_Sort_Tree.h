#pragma once

struct BSTreeNode {
	int data;
	struct BSTreeNode *lchild, *rchild;
};
typedef struct BSTreeNode *BSTree;
typedef struct BSTreeNode BSTreeNode;

BSTree CreatNode(int x);
int SearchBST(BSTree tree, int data, BSTree father, BSTree *result);
int Insert_BST(BSTree *tree, int data);
int Delete_TNode(BSTree *Node);
int Delete_BST(BSTree *tree, int data);
void PrintTree(BSTree t, int space);
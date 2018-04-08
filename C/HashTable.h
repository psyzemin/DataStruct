#pragma once

#define HASHSIZE 12

struct HashTable {
	int count;
	int *elem;
};
typedef struct HashTable HashTable;

int InitHashTable(HashTable *h);
int Hash(int key);
int InsertHash(HashTable *h, int key);
int SearchHash(HashTable *h, int key);
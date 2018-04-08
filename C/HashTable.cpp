#include "HashTable.h"
#include<stdio.h>
#include<stdlib.h>

int InitHashTable(HashTable *h) {
	h->count = HASHSIZE;
	h->elem = (int*)malloc(sizeof(int)*HASHSIZE);
	for (int i = 0; i < HASHSIZE; i++)
	{
		h->elem[i] = NULL;
	}
	return true;
}
int Hash(int key) {
	return key % HASHSIZE;
}
int InsertHash(HashTable *h, int key) {
	int address = Hash(key);
	while (h->elem[address] != NULL)
	{
		address = Hash(address + 1);
	}
	h->elem[address] = key;
	return true;
}
int SearchHash(HashTable *h, int key) {
	int result = Hash(key);
	while (h->elem[result] != key)
	{
		result = Hash(result + 1);
		if (h->elem[result] == NULL || result == Hash(key))
		{
			return false;
		}
	}
	return result;
}

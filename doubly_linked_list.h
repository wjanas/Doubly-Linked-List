#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST

#include <stdlib.h>
#include <stdio.h>

typedef int (*dll_node_compare)(void*, void*);
typedef void (*dll_show_node)(void*);

struct Node {
	struct Node *prev;
	struct Node *next;
	void *data;
};

struct DoublyLinkedList{
	struct Node *head;
	struct Node *tail;
	unsigned int elements_cnt;

	dll_node_compare dll_node_compare_func;
	dll_show_node dll_show_node_func;
};

void DLL_Create(struct DoublyLinkedList* dll, dll_node_compare dll_cmp, dll_show_node dll_show);
void DLL_PushBack(struct DoublyLinkedList* dll, void* data);
void DLL_PushFront(struct DoublyLinkedList* dll, void* data);
void DLL_InsertBefore(struct DoublyLinkedList* dll, struct Node* next_node, void* data);
void DLL_InsertAfter(struct DoublyLinkedList* dll, struct Node* prev_node, void* data);
void DLL_Remove(struct DoublyLinkedList* dll, struct Node* ptr);
void DLL_RemoveBefore(struct DoublyLinkedList* dll, struct Node* prev_node);//TODO
void DLL_RemoveAfter(struct DoublyLinkedList* dll, struct Node* next_node);//TODO
void DLL_RemoveNth(struct DoublyLinkedList* dll, unsigned int idx);
struct Node* DLL_Find(struct DoublyLinkedList* dll, void* val);
void DLL_ShowList(struct DoublyLinkedList* dll); //TODO
#endif // !DOUBLY_LINKED_LIST_H


#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST

#include <stdlib.h>
#include <stdio.h>

struct Node {
	struct Node *prev;
	struct Node *next;
	int data;
};

struct DoublyLinkedList{
	struct Node *head;
	struct Node *tail;
	int elements_cnt;
};

void DLL_Create(struct DoublyLinkedList* dll);
void DLL_PushBack(struct DoublyLinkedList* dll, int data);
void DLL_PushFront(struct DoublyLinkedList* dll, int data);
void DLL_InsertBefore(struct DoublyLinkedList* dll, struct Node* prev_node, int data);
void DLL_InsertAfter(struct DoublyLinkedList* dll, struct Node* next_node, int data);
void DLL_Remove(struct DoublyLinkedList* dll, struct Node* ptr);
void DLL_RemoveBefore(struct DoublyLinkedList* dll, struct Node* prev_node, int data);//TODO
void DLL_RemoveAfter(struct DoublyLinkedList* dll, struct Node* next_node, int data);//TODO
void DLL_RemoveNth(struct DoublyLinkedList* dll, unsigned int idx);
struct Node* DLL_Find(struct DoublyLinkedList* dll, int val);
void DLL_ShowList(struct DoublyLinkedList* dll); //TODO
#endif // !DOUBLY_LINKED_LIST_H


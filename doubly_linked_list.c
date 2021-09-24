#include "doubly_linked_list.h"

void DLL_Create(struct DoublyLinkedList *dll) {
	dll->head = NULL;
	dll->tail = NULL;
	dll->elements_cnt = 0;
}

void DLL_PushBack(struct DoublyLinkedList* dll, int data) {
	
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	
	if (temp != NULL) {
		temp->prev = NULL;
		temp->next = NULL;

		if (dll->head == NULL) {
			dll->head = temp;
			dll->tail = temp;

			temp->prev = NULL;
			temp->next = NULL;
			temp->data = data;
		}
		else {
			temp->prev = dll->tail;
			dll->tail->next = temp;
			dll->tail = temp;
			temp->data = data;
		}
	}
	dll->elements_cnt += 1;
}

void DLL_PushFront(struct DoublyLinkedList* dll, int data) {

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	if (temp != NULL) {
		temp->prev = NULL;
		temp->next = NULL;

		if (dll->head == NULL) {
			dll->head = temp;
			dll->tail = temp;

			temp->prev = NULL;
			temp->next = NULL;
			temp->data = data;
		}
		else {
			temp->next = dll->head;
			dll->head->prev = temp;
			dll->head = temp;
			temp->data = data;
		}
	}
	dll->elements_cnt += 1;
}

void DLL_InsertBefore(struct DoublyLinkedList* dll, struct Node* next_node, int data) {

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	
	if (temp != NULL) {
		temp->next = next_node;
		temp->prev = next_node->prev;
		temp->data = data;

		temp->prev->next = temp;
		next_node->prev = temp;
	}
	dll->elements_cnt += 1;
}

void DLL_InsertAfter(struct DoublyLinkedList* dll, struct Node* prev_node, int data) {

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	if (temp != NULL) {
		temp->prev = prev_node;
		temp->next = prev_node->next;
		temp->data = data;

		temp->next->prev = temp;
		prev_node->next = temp;
	}
	dll->elements_cnt += 1;
}

void DLL_Remove(struct DoublyLinkedList* dll, struct Node* ptr) {

	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	
	free(ptr);
	dll->elements_cnt -= 1;
}

void DLL_RemoveNth(struct DoublyLinkedList* dll, unsigned int idx) {

	struct Node* ptr = dll->head;
	
	if (idx >= dll->elements_cnt) {
		printf("Index out of range\n");
		return;
	}

	for (int i = 0; i < idx && ptr != NULL; i++) {
		ptr = ptr->next;
	}

	if (ptr != NULL) {
		
		if (ptr->prev != NULL) {
			ptr->prev->next = ptr->next;
		}
		else {
			dll->head = ptr->next;
		}
		
		if(ptr->next != NULL){
			ptr->next->prev = ptr->prev;
		}
		free(ptr); 
	}
	dll->elements_cnt -= 1;
}

struct Node* DLL_Find(struct DoublyLinkedList* dll, int val) {

	struct Node* ptr = dll->head;

	while (ptr != NULL) {
		if (ptr->data == val)
			break;
		ptr = ptr->next;
	}
	return ptr;
}

void DLL_ShowList(struct DoublyLinkedList* dll) {

	struct Node* ptr = dll->head;

	while (ptr != NULL) {
		printf("Address: %d\n"
			"Data: %d\n"
			"Previous Address: %d\n"
			"Next Address: %d\n\n",
			(int)ptr, ptr->data, (int)ptr->prev, (int)ptr->next);
		ptr = ptr->next;
	}

}
#include <stdio.h>
#include "doubly_linked_list.h"

int main() {

	struct DoublyLinkedList dll;
	DLL_Create(&dll);
	DLL_PushBack(&dll, 1);
	DLL_PushBack(&dll, 2);
	DLL_PushBack(&dll, 3);
	DLL_PushBack(&dll, 4);
	DLL_PushBack(&dll, 5);
	DLL_PushFront(&dll, 0);

	printf("Num elements: %d\n", dll.elements_cnt);

	struct Node* ptr = dll.head;

	for (int i = 0; i < 4; i++) {
		ptr = ptr->next;
	}
	
	DLL_ShowList(&dll);

}


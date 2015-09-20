#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	list_t* prev = head; 
	list_t* current = head->next;

	if(new_element->index <= head->index){
		new_element->next = head;
		head = new_element;
	} else{
		while(prev != NULL){
			
			if(current == NULL){
				prev->next = new_element;
				break;
			}
			else if(new_element->index < current->index){
				new_element->next = current;
				prev->next = new_element;
				break;
			}
			prev = current;
			current = current->next;
		}
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* prev = NULL; 
	list_t* current = head;
	list_t* next;

	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return prev;
}

/*
Nathaniel Steeby
nsteeby
14303784
EECS 373 Homework #2
*/

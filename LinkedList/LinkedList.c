/* 
 * Produced by kasper1019
 * Source is availible at https://github.com/kasper1019/C-DataStructures
 * See LICESNSE.md for liscencing information
 */

#include "LinkedList.h"


struct LinkedList* createLinkedList(){

	struct LinkedList* toReturn;
	toReturn = malloc(sizeof(struct LinkedList));
	if(!toReturn){ // Error
		// Write error handler?
		printf("Error allocating memory for linked list.");
		return NULL;
	}
	
	toReturn->head = NULL;
	toReturn->tail = NULL;
	toReturn->size = 0;
	
	return toReturn;
}


void addNode(struct LinkedList* linkedList, void* key, int position){

	if(position > linkedList->size){ // Error
		printf("Position is too large to be valid.");
		return;
	}

	if(position < 0){ // Error
		printf("Position is too small to be valid.");
		return;
	}

	if(!linkedList){ // Error
		printf("Provide a valid linked list structure");
		return;
	}

	if(!key){ // Error
		printf("Provide a valid key structure");
		return;
	}

	struct LinkedListNode* newNode;
	newNode = malloc(sizeof(struct LinkedListNode));
	if(!newNode) { // Error
		printf("Error allocating memory for linked list node.");
		return;
	}

	newNode->key = key;
	
	if(linkedList->size == 0) {
		linkedList->head=newNode;
		linkedList->tail=newNode;
		linkedList->size = 1;
		newNode->prev = NULL;
		newNode->next = NULL;
		return;
	}

	if(position == 0) {
		linkedList->head->prev = newNode;
		newNode->prev = NULL;
		newNode->next = linkedList->head;
		linkedList->head = newNode;
		linkedList->size +=1;
		return;
	}

	if(position == linkedList->size) {
		linkedList->tail->next = newNode;
		newNode->prev = linkedList->tail;
		newNode->next = NULL;
		linkedList->tail = newNode;
		linkedList->size +=1;
		return;
	}

	struct LinkedListNode *nextNode;
	nextNode = getNode(linkedList,position);
	newNode->next = nextNode;
	newNode->prev = nextNode->prev;
	nextNode->prev->next = newNode;
	nextNode->prev = newNode;
	linkedList->size +=1;
}


struct LinkedListNode* getNode(struct LinkedList* linkedList, int position){
	if(position > linkedList->size){ // Error
		printf("Position is too large to be valid.");
		return NULL;
	}

	if(position < 0){ // Error
		printf("Position is too small to be valid.");
		return NULL;
	}

	if(!linkedList){ // Error
		printf("Provide a valid linked list structure");
		return NULL;
	}
	
	if(linkedList->size == 0){ // Error
		printf("Linked List is Empty");
		return NULL;
	}

	int i = 0;
	struct LinkedListNode *currNode;
	currNode = linkedList->head;
	while(i++ < position) {
		currNode = currNode->next;
	}
	return currNode;
}


void removeNode(struct LinkedList* linkedList, void (*freeKey)(void*), int position){
	if(position >= linkedList->size){ // Error
		printf("Position is too large to be valid.\n");
		return;
	}

	if(position < 0){ // Error
		printf("Position is too small to be valid.\n");
	}

	if(!linkedList){ // Error
		printf("Provide a valid linked list structure.\n");
		return;
	}

	if(linkedList->size == 0){ // Error
		printf("Linked List is Empty.\n");
		return;
	}
	
	struct LinkedListNode *toDel;
	toDel = getNode(linkedList, position);

	if(toDel->prev == NULL) {
		if(toDel->next == NULL) {} else {
			toDel->next->prev = NULL;
		}
	} else {
		if(toDel->next == NULL) {} else {
			toDel->next->prev = toDel->prev;
		}
	}

	if(toDel->next == NULL) {
		if(toDel->prev == NULL) {} else {
			toDel->prev->next = NULL;
		}
	} else {
		if(toDel->prev == NULL) {} else {
			toDel->prev->next = toDel->next;
		}
	}

	if(linkedList->head == toDel){
		if(toDel->next == NULL) {
			linkedList->head = NULL;
		} else {
			linkedList->head = toDel->next;
		}
	}

	if(linkedList->tail == toDel){
		if(toDel->prev == NULL) {
			linkedList->tail = NULL;
		} else {
			linkedList->tail = toDel->prev;
		}
	}

	linkedList->size -= 1;
	freeLinkedListNode(toDel, freeKey);
}


void freeLinkedList(struct LinkedList* linkedList, void (*freeKey)(void*)){
	while(linkedList->size > 0){
		removeNode(linkedList,freeKey,0);
	}
	free(linkedList);
}


void freeLinkedListNode(struct LinkedListNode* node, void (*freeKey)(void*)){
	freeKey(node->key);
	free(node);
}

/* 
 * Produced by kasper1019
 * Source is availible at https://github.com/kasper1019/C-DataStructures
 * See LICESNSE.md for liscencing information
 */

#include "LinkedList.h"


LinkedList* createLinkedList(){

	LinkedList* toReturn;
	toReturn = malloc(sizeof(LinkedList));
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


void addNode(LinkedList* linkedList, void* key, int position){

	if(position > linkedList->size){ // Error
		printf("Position is too large to be valid.");
		return;
	}

	if(position < 0){ // Error
		printf("Position is too small to be valid.");
	}

	if(!linkedList){ // Error
		printf("Provide a valid linked list structure");
		return;
	}

	if(!key){ // Error
		printf("Provide a valid key structure");

	LinkedListNode* newNode;
	newNode = malloc(sizeof(LinkedListNode));
	if(!newNode) { // Error
		printf("Error allocating memory for linked list node.");
		return;
	}

	newNode->key = key;
	
	if(size == 0) {
		linkedList->head=newNode;
		linkedList->tail=newNode;
		size = 1;
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

	LinkedListNode *nextNode;
	nextNode = getNode(linkedList,position);
	newNode->next = nextNode;
	newNode->prev = nextNode->prev;
	nextNode->prev->next = newNode;
	nextNode->prev = newNode;
	linkedList->size +=1;
	return;
}


likedListNode* getNode(LinkedList* linkedList, int position){
	if(position > linkedList->size){ // Error
		printf("Position is too large to be valid.");
		return;
	}

	if(position < 0){ // Error
		printf("Position is too small to be valid.");
	}

	if(!linkedList){ // Error
		printf("Provide a valid linked list structure");
		return;
	}
	
	if(linkedList->size == 0){ // Error
		printf("Linked List is Empty");
		return;
	}

	int i = 0;
	LinkedListNode *currNode;
	currNode = linkedList->head;
	while(i++ < position) {
		currNode = currNode->next;
	}
	return currNode;
}


void removeNode(LinkedList* linkedList, void (*freeKey)(void*), int position){
	if(position >= linkedList->size){ // Error
		printf("Position is too large to be valid.");
		return;
	}

	if(position < 0){ // Error
		printf("Position is too small to be valid.");
	}

	if(!linkedList){ // Error
		printf("Provide a valid linked list structure");
		return;
	}

	if(linkedList->size == 0){ // Error
		printf("Linked List is Empty");
		return;
	}
	
	LinkedListNode *toDel;
	toDel = getNode(linkedList, position);
	if(toDel->prev == NULL) {
		toDel->next->prev = NULL;
	}else{
		toDel->next->prev = toDel->prev;
	}
	if(toDel->next == NULL) {
		toDel->prev->next = NULL;
	}else{
		toDel->prev->next = toDel->next;
	}

	linkedList->size -= 1;
	freeLinkedListNode(toDel, freeKey);
	return;
}


void freeLinkedList(LinkedList* linkedList, void (*freeKey)(void*)){
	while(linkedList->size > 0){
		removeNode(linkedList,freeKey,0);
	}
	free(linkedList);
	return;
}


void freeLinkedListNode(linkedListNode* node, void (*freeKey)(void*)){
	freeKey(node->key);
	free(node);
	return;
}


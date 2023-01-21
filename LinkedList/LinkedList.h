/* 
 * Produced by kasper1019
 * Source is availible at https://github.com/kasper1019/C-DataStructures
 * See LICESNSE.md for liscencing information
 */

#ifndef LINKED_LIST
#define LINKED_LIST

struct LinkedListNode {
	void* key;
	linkedListNode* prev;
	linkedListNode* next;
};

struct LinkedList {
	linkedListNode* head;
	linkedListNode* tail;
	int size;
}

/* Used to create a new Linked List Structure.
 * Returns - A pointer to the created Linked List.
 */
LinkedList* createLinkedList();

/*
 * Create a new node and add that node to the Linked List.
 * Parameters:
 *   linkedList - the Linked List a new node will be added to.
 *   key - a pointer to a variable that will be stored in the list.
 *   position - the position in the list to store the new node at.
 */
void addNode(LinkedList* linkedList, void* key, int position);

/*
 * Get the node at the postion from the Linked List.
 * Parameters:
 *   linkedList - The Linked List to get the node from.
 *   postion - the postion of the node to get.
 */
likedListNode* getNode(LinkedList* linkedList, int position);

/*
 * Remove a node from the Linked List using the freeKey function.
 * Parameters:
 *   linkedList - The Linked List to remove the node from
 *   freeKey - Funtion used to free the memory allocated to the key of the node. Accepts key pointer.
 *   position - position of the node to remove.
 */
void removeNode(linkedList* linkedList, void (*freeKey)(void*), int position);


void freeLinkedList(LinkedList* linkedList, void (*freeKey)(void*));


void freeLinkedListNode(linkedListNode* node, void (*freeKey)(void*));

#endif

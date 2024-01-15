/* 
 * Produced by kasper1019
 * Source is availible at https://github.com/kasper1019/C-DataStructures
 * See LICESNSE.md for liscencing information
 */

#ifndef LINKED_LIST
#define LINKED_LIST

struct LinkedListNode {
	void* key;
	struct LinkedListNode* prev;
	struct LinkedListNode* next;
};

struct LinkedList {
	struct LinkedListNode* head;
	struct LinkedListNode* tail;
	int size;
};

/* Used to create a new Linked List Structure.
 * Returns - A pointer to the created Linked List.
 */
struct LinkedList* createLinkedList();

/*
 * Create a new node and add that node to the Linked List.
 * Parameters:
 *   linkedList - the Linked List a new node will be added to.
 *   key - a pointer to a variable that will be stored in the list.
 *   position - the position in the list to store the new node at.
 */
void addNode(struct LinkedList* linkedList, void* key, int position);

/*
 * Get the node at the postion from the Linked List.
 * Parameters:
 *   linkedList - The Linked List to get the node from.
 *   postion - the postion of the node to get.
 */
struct LinkedListNode* getNode(struct LinkedList* linkedList, int position);

/*
 * Remove a node from the Linked List using the freeKey function.
 * Parameters:
 *   linkedList - The Linked List to remove the node from
 *   freeKey - Funtion used to free the memory allocated to the key of the node. Accepts key pointer.
 *   position - position of the node to remove.
 */
void removeNode(struct LinkedList* linkedList, void (*freeKey)(void*), int position);


void freeLinkedList(struct LinkedList* linkedList, void (*freeKey)(void*));


void freeLinkedListNode(struct LinkedListNode* node, void (*freeKey)(void*));

#endif

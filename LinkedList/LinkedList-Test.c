#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.c"

void main() {
	struct LinkedList* ll;
	ll = createLinkedList();

	//int a=0,b=1,c=2,d=3,e=4;
	int *ptr_a, *ptr_b, *ptr_c,*ptr_d,*ptr_e;
	
	ptr_a = (int*) malloc(sizeof(int));
	ptr_b = (int*) malloc(sizeof(int));
	ptr_c = (int*) malloc(sizeof(int));
	ptr_d = (int*) malloc(sizeof(int));
	ptr_e = (int*) malloc(sizeof(int));
	
	*ptr_a = 0;
	*ptr_b = 1;
	*ptr_c = 2;
	*ptr_d = 3;
	*ptr_e = 4;

	addNode(ll,ptr_b,0);
	addNode(ll,ptr_d,1);
	addNode(ll,ptr_c,1);
	addNode(ll,ptr_e,3);
	addNode(ll,ptr_a,0);

	//  Expected output:
	// Index: 0	Value: 0
	// Index: 1	Value: 1
	// Index: 2	Value: 2
	// Index: 3	Value: 3
	// Index: 4	Value: 4

	for(int i=0;i<ll->size;++i) {
		printf("Index: %d\tValue: %d\n", i, *((int*)getNode(ll,i)->key));
	}

	removeNode(ll,free,4);
	removeNode(ll,free,0);
	removeNode(ll,free,1);


	//  Expected output:
	// Index: 0	Value: 1
	// Index: 1	Value: 3

	printf("\n");
	for(int i=0;i<ll->size;++i) {
		printf("Index: %d\tValue: %d\n", i, *((int*)getNode(ll,i)->key));
	}
	
	freeLinkedList(ll,free);
}

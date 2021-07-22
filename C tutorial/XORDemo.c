#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *ptr;
}Node;

Node* XOR(Node* a, Node* b){
	return (Node*)((uintptr_t)(a)^(uintptr_t)(b));
}

int main(void){
	Node* first = (Node*)malloc(sizeof(Node));
	Node* second = (Node*)malloc(sizeof(Node));
	Node* third = (Node*)malloc(sizeof(Node));
	//initialize
	first->data = 1;
	first->ptr = XOR(NULL, second);
	second->data = 2;
	second->ptr = XOR(first, third);
	third->data = 3;
	third->ptr = XOR(second, NULL);
	//print all data
	Node* current = first;
	Node* prev = NULL;
	Node* next;
	while(current != NULL){
		printf("%d\n", current->data);
		next = XOR(prev, current->ptr);
		//update
		prev = current;
		current = next;
	}

}
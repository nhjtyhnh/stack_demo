#include<stdio.h>
#include<stdlib.h>
#include "stack_list.h"

void push1(SN1** head, int val) {
	SN1* new_node = (SN1*)malloc(sizeof(SN1));
	new_node->data = val;
	new_node->next = *head;
	*head = new_node;
}

void pop1(SN1** head) {
	if (*head == NULL) {
		printf("Õ»¿ÕÁË!\n");
		return;
	}
	SN1* p = *head;
	*head = p->next;
	free(p);
}

void print_stack1(SN1* head) {
	SN1* p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

void free_stack1(SN1** head) {
	SN1* p = *head;
	while (p != NULL) {
		SN1* temp = p;
		p = p->next;
		free(temp);
	}
	*head = NULL;
}
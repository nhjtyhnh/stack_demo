#pragma once

typedef struct Stack1_Node {
	int data;
	struct Stack1_Node* next;
}SN1;

void push1(SN1** head, int val);
void pop1(SN1** head);
void print_stack1(SN1* head);
void free_stack1(SN1** head);
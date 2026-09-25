#include<stdio.h>
#include "stack_list.h"
#include "queue_list.h"

int main() {
	printf("========’ª========\n");
	SN1* head = NULL;
	push1(&head, 10);
	push1(&head, 20);
	push1(&head, 30);
	pop1(&head);
	pop1(&head);
	pop1(&head);
	pop1(&head);
	print_stack1(head);
	free_stack1(&head);
	printf("\n========∂”¡–========\n");
	QN1* front = NULL;
	QN1* rear = NULL;
	inqueue(&front, &rear, 10);
	inqueue(&front, &rear, 20);
	inqueue(&front, &rear, 30);
	inqueue(&front, &rear, 40);
	save_queue(front, "queue.dat");
	free_queue(&front);
	rear = NULL;
	load_queue(&front, &rear, "queue.dat");
	print_queue(front);
	free_queue(&front);
	rear = NULL;
	return 0;
}
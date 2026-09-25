#pragma once

typedef struct Queue1_Node {
	int data;
	struct Queue1_Node* next;
}QN1;

void inqueue(QN1** front, QN1** rear, int val);
void dequeue(QN1** front,QN1 **rear);
void print_queue(QN1* front);
void free_queue(QN1** front);
void save_queue(QN1* front, const char* filename);
void load_queue(QN1** front, QN1** rear, const char* filename);
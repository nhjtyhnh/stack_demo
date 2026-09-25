#include<stdio.h>
#include<stdlib.h>
#include "queue_list.h"

void inqueue(QN1** front, QN1** rear,int val) {
	QN1* new_node = (QN1*)malloc(sizeof(QN1));
	new_node->data = val;
	new_node->next = NULL;
	if (*front == NULL) {
		*front = new_node;
		*rear = new_node;
		return;
	}
	(*rear)->next = new_node;
	*rear = new_node;
}

void dequeue(QN1** front,QN1 **rear) {
	if (*front == NULL) {
		printf("队空了!\n");
		return;
	}
	QN1* temp = *front;
	int val = temp->data;
	*front = temp->next;
	if (*front == NULL) {
		*rear = NULL;
	}
	free(temp);
}

void print_queue(QN1* front) {
	QN1* p = front;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

void free_queue(QN1** front) {
	QN1* p = *front;
	while (p != NULL) {
		QN1* temp = p;
		p = p->next;
		free(temp);
	}
	*front = NULL;
}

void save_queue(QN1* front, const char* filename) {
	FILE* fp = fopen(filename, "wb");
	if (fp == NULL) {
		printf("打不开文件\n");
		return;
	}
	QN1* p = front;
	while (p != NULL) {
		fwrite(&p->data, sizeof(int), 1, fp);
		p = p->next;
	}
	fclose(fp);
}

void load_queue(QN1** front, QN1** rear, const char* filename) {
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("文件不存在\n");
		return;
	}
	int val;
	while (fread(&val, sizeof(int), 1, fp) == 1) {
		inqueue(front, rear, val);
	}
	fclose(fp);
}
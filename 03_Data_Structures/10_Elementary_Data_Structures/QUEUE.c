#include <stdio.h>
#include <stdlib.h>

typedef struct _QUEUE{
	int m_head;
	int m_tail;
	int m_capacity;
	int* m_data;
} QUEUE;

QUEUE* QUEUE_CREATE(int capacity){
	QUEUE* new_queue = (QUEUE*)malloc(sizeof(QUEUE));
	new_queue->m_head = 0;
	new_queue->m_tail = 0;
	new_queue->m_capacity = capacity+1;

	new_queue->m_data = (int*)malloc(sizeof(int)*(capacity+1));

	return new_queue;
}

void QUEUE_DELETE(QUEUE* q){
	free(q->m_data);
	free(q);
	return;
}

void ENQUEUE(QUEUE* q, int x){
	q->m_data[q->m_tail] = x;
	q->m_tail = (q->m_tail+1) % (q->m_capacity-1);
}

int DEQUEUE(QUEUE* q){
	int x = q->m_data[q->m_head];
	q->m_head = (q->m_head+1) % (q->m_capacity-1);
	return x;
}

int main(){
	QUEUE* q = QUEUE_CREATE(12);
	int arr[14] = { 0, 0, 0, 0, 0, 0, 15, 6, 9, 8, 4, 17, 3, 5 };
	
	for(int i = 0; i < 6; i ++){
		ENQUEUE(q, arr[i]);
	}
	for(int i = 0; i < 6; i ++){
		DEQUEUE(q);
	}

	for(int i = 6; i < 14; i ++){
		ENQUEUE(q, arr[i]);
	}
	printf("data : %d, ", DEQUEUE(q)); 
	printf("head : %d, ", q->m_head);
	printf("tail : %d\n", q->m_tail);
	QUEUE_DELETE(q);
	return 0;
}

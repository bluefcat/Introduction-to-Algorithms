#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _PRIORITY_QUEUE{
	int* m_data;
	int m_size;
}PRIORITY_QUEUE;

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
	return ;
}

int PARENT(int i){
	return (i-1)/2;
}

int LEFT(int i){
	return 2*i+1;
}

int RIGHT(int i){
	return 2*i+2;
}

void MAX_HEAPIFY(PRIORITY_QUEUE* a, int i){
	int l = LEFT(i);
	int r = RIGHT(i);

	int largest = i;
	if(l < a->m_size && a->m_data[i] < a->m_data[l]) largest = l;
	if(r < a->m_size && a->m_data[largest] < a->m_data[r]) largest = r;

	if(i != largest){
		swap(a->m_data+i, a->m_data+largest);
		MAX_HEAPIFY(a, largest);
	}
	return ;
}

void BUILD_MAX_HEAP(PRIORITY_QUEUE* a){
	for(int i = a->m_size/2; i >= 0; i--){
		MAX_HEAPIFY(a, i);
	}
	return ;
}

int HEAP_MAXIMUM(PRIORITY_QUEUE* a){
	return a->m_data[0];
}

int HEAP_EXTRACT_MAX(PRIORITY_QUEUE* a){
	if(a->m_size < 1) return -1;

	int max = a->m_data[0];
	a->m_data[0] = a->m_data[a->m_size-1];
	a->m_size --;
	MAX_HEAPIFY(a, 0);
	
	return max;
}

void HEAP_INCREASE_KEY(PRIORITY_QUEUE* a, int i, int key){
	if(key < a->m_data[i]) return;

	a->m_data[i] = key;
	while(i >= 0 && a->m_data[PARENT(i)] < a->m_data[i]){
		swap(a->m_data + i, a->m_data + PARENT(i));
		i = PARENT(i);
	}
	return;
}

void MAX_HEAP_INSERT(PRIORITY_QUEUE* a, int key){
	a->m_size ++;
	a->m_data = (int *)realloc(a->m_data, sizeof(int)*a->m_size);
	a->m_data[a->m_size - 1] = INT_MIN;
	HEAP_INCREASE_KEY(a, a->m_size - 1, key);
}

void INIT_PRIORITY_QUEUE(PRIORITY_QUEUE* a, int* arr, int n){
	a->m_data = (int *)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i ++){
		a->m_data[i] = arr[i];
	}
	a->m_size = n;
	BUILD_MAX_HEAP(a);
	return;
}

void FREE_PRIORITY_QUEUE(PRIORITY_QUEUE* a){
	free(a->m_data);
	return;
}

void PRINT_PRIORITY_QUEUE(PRIORITY_QUEUE* a){
	for(int i = 0; i < a->m_size; i ++){
		printf("%d ", a->m_data[i]);
	}
}

int main(){
	PRIORITY_QUEUE pq;
	int arr[10] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };

	INIT_PRIORITY_QUEUE(&pq, arr, 10);
	printf("priority queue\n");
	PRINT_PRIORITY_QUEUE(&pq);
	printf("\n");	
	
	HEAP_INCREASE_KEY(&pq, 8, 15);
	printf("after HEAP INCREASE KEY\n");
	PRINT_PRIORITY_QUEUE(&pq);
	printf("\n");
	
	HEAP_EXTRACT_MAX(&pq);
	printf("after HEAP EXTRACT MAX\n");
	PRINT_PRIORITY_QUEUE(&pq);
	printf("\n");

	MAX_HEAP_INSERT(&pq, 20);
	printf("after MAX HEAP INSERT\n");
	PRINT_PRIORITY_QUEUE(&pq);
	printf("\n");

	FREE_PRIORITY_QUEUE(&pq);
	return 0;
}

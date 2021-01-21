#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
	return ;
}

int PARENT(int i){
	return i/2;
}

int LEFT(int i){
	return 2 * i + 1;
}

int RIGHT(int i){
	return 2 * i + 2;
}

//n is heap-size, i is index.
void MAX_HEAPIFY(int* arr, int n, int i){
	int l = LEFT(i);
	int r = RIGHT(i);

	int largest = i;

	if(l < n && arr[l] > arr[i]) largest = l;
	
	if(r < n && arr[r] > arr[largest]) largest = r;

	if(largest != i){
		swap(arr + i, arr + largest);
		MAX_HEAPIFY(arr, n, largest);
	}
	return;
}

void BUILD_MAX_HEAP(int* arr, int n){
	for(int i = n/2; i >= 0; i--){
		MAX_HEAPIFY(arr, n, i);
	}
	return;
}

int main(){
	int arr[10] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };

	for(int i = 0; i < 10; i ++) printf("%d ", arr[i]);
	printf("\n");
	
	BUILD_MAX_HEAP(arr, 10);

	printf("After BUILD_MAX_HEAP\n");
	for(int i = 0; i < 10; i ++) printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

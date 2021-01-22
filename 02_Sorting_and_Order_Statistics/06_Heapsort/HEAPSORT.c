#include <stdio.h>

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
	return;	
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

void MAX_HEAPIFY(int* arr, int n, int i){
	int l = LEFT(i);
	int r = RIGHT(i);

	int largest = i;
	if(l < n && arr[i] < arr[l]) largest = l;
	if(r < n && arr[largest] < arr[r]) largest = r;

	if(largest != i){
		swap(arr+i, arr+largest);
		MAX_HEAPIFY(arr, n, largest);
	}	

	return ;
}

void BUILD_MAX_HEAP(int* arr, int n){
	for(int i = n/2; i >= 0; i --){
		MAX_HEAPIFY(arr, n, i);
	}
	return ;
}

void HEAPSORT(int* arr, int n){
	BUILD_MAX_HEAP(arr, n);
	
	for(int i = n-1; i > 0; i--){
		swap(arr, arr+i);
		n --;
		MAX_HEAPIFY(arr, n, 0);
	}

	return ; 
}

int main(){
	int arr[10] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
	for(int i = 0; i < 10; i ++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	HEAPSORT(arr, 10);

	printf("sorted array\n");
	for(int i = 0; i < 10; i ++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

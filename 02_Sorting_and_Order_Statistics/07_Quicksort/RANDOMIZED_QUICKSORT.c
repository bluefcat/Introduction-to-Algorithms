#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
	return ;
}

int PARTITION(int* arr, int p, int r){
	int x = arr[r-1];
	int i = p-1;
	
	for(int n = p; n < r-1; n++){
		if(arr[n] <= x){
			i ++;
			swap(arr+n, arr+i);
		}
	}
	swap(arr+i+1, arr+r-1);
	return i+1;
}

int RANDOMIZED_PARTITION(int* arr, int p, int r){
	int i = rand()%(r-p)+p;
	swap(arr+i, arr+r-1);
	return PARTITION(arr, p, r);
}

void RANDOMIZED_QUICKSORT(int* arr, int p, int r){
	if(p < r){
		int q = RANDOMIZED_PARTITION(arr, p, r);
		RANDOMIZED_QUICKSORT(arr, p, q);
		RANDOMIZED_QUICKSORT(arr, q+1, r);
	}
	return;
}

int main(){
	srand(time(NULL));
	int arr[8] = {2, 8, 7, 1, 3, 5, 6, 4};
	for(int i = 0; i < 8; i ++){
		printf("%d ", arr[i]);	
	}
	printf("\n");

	RANDOMIZED_QUICKSORT(arr, 0, 8);
	printf("sorted array\n");
	
	for(int i = 0; i < 8; i ++){
		printf("%d ", arr[i]);	
	}
	printf("\n");
	return 0;
}

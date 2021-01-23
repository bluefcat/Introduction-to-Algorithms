#include <stdio.h>
void swap(int* x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int PARTITION(int* arr, int p, int r){
	int x = arr[r-1];
	int i = p-1;
	
	for(int n = p; n < r-1; n++){
		if(arr[n] <= x){
			i ++;
			swap(arr+i, arr+n);
		}
	}
	swap(arr+i+1, arr+r-1);
	return i+1;
}

void QUICKSORT(int* arr, int p, int r){
	if(p < r){
		int q = PARTITION(arr, p, r);
		QUICKSORT(arr, p, q);
		QUICKSORT(arr, q+1, r);	
	}
	return ;
}

int main(){
	int arr[8] = {2, 8, 7, 1, 3, 5, 6, 4};
	for(int i = 0; i < 8; i ++){
		printf("%d ", arr[i]);	
	}
	printf("\n");

	QUICKSORT(arr, 0, 8);
	printf("sorted array\n");
	
	for(int i = 0; i < 8; i ++){
		printf("%d ", arr[i]);	
	}
	printf("\n");

	return 0;
}

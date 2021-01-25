#include <stdio.h>

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
	return ;
}

int HOARE_PARTITION(int* arr, int p, int r){
	int x = arr[p];
	int i = p;
	int j = r;
	while(1){
		do{
			if(i >= r-1) break;
			i ++;
		} while(arr[i] <= x);

		do{
			j --;
		} while(arr[j] > x);

		if(i < j){
			swap(arr+i, arr+j);
		}
		else{
			swap(arr+j, arr+p);
			return j;
		}
	}
}

void HOARE_QUICKSORT(int* arr, int p, int r){
	if(p+1 < r){
		int q = HOARE_PARTITION(arr, p, r);
		HOARE_QUICKSORT(arr, p, q);
		HOARE_QUICKSORT(arr, q+1, r);
	}
	return ;
}

int main(){
	int arr[12] = { 13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21 };
	for(int i = 0; i < 12; i ++){
		printf("%d ", arr[i]);	
	}
	printf("\n");

	HOARE_QUICKSORT(arr, 0, 12);
	printf("sorted array\n");
	
	for(int i = 0; i < 12; i ++){
		printf("%d ", arr[i]);	
	}
	printf("\n");
	return 0;
}

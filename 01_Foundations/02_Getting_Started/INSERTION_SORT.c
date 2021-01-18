#include <stdio.h>

void insertion_sort(int* arr, int n){
	for(int j = 1; j < n; j ++){
		int key = arr[j];
		int i = j - 1;
		while(i >= 0 && arr[i] > key){
			arr[i + 1] = arr[i];
			i = i - 1;	
		}
		arr[i + 1] = key;
	}
	return ;
}

int main(){
	int arr[6] = { 5, 2, 4, 6, 1, 3 };
	
	for(int i = 0; i < 6; i ++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	insertion_sort(arr, 6);
	
	printf("sorted array\n");
	for(int i = 0; i < 6; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");


	return 0;
}

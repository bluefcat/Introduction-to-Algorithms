#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *arr, int p, int q, int r){
	int n_1 = q - p;
	int n_2 = r - q;

	int* L = (int*)malloc(sizeof(int)*(n_1 + 1));
	int* R = (int*)malloc(sizeof(int)*(n_2 + 1));

	for(int i = 0; i < n_1; i ++){
		L[i] = arr[p + i];
	}
	for(int i = 0; i < n_2; i ++){
		R[i] = arr[q + i];
	}

	L[n_1] = INT_MAX;
	R[n_2] = INT_MAX;

	int i = 0;
	int j = 0;

	for(int k = p; k < r; k ++){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i ++;
		}
		else{
			arr[k] = R[j];
			j ++;
		}
	}
	free(L);
	free(R);
	return;
}

void merge_sort(int* arr, int p, int r){
	if(p + 1 < r){
		int q = (p + r)/2;
		merge_sort(arr, p, q);
		merge_sort(arr, q, r);
		merge(arr, p, q, r);
	}
	return ;
}

int main(){
	int arr[9] = { 9, 5, 2, 4, 7, 1, 3, 2, 6 };
	for(int i = 0; i < 9; i ++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	merge_sort(arr, 0, 9);
	
	printf("sorted array\n");
	for(int i = 0; i < 9; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}

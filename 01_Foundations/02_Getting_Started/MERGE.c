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

int main(){
	int arr[9] = { 2, 4, 5, 7, 1, 2, 3, 6, 9 };
	for(int i = 0; i < 9; i ++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	merge(arr, 0, 9/2, 9);
	
	printf("merged array\n");
	for(int i = 0; i < 9; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}

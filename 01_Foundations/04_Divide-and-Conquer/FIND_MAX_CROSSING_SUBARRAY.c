#include <stdio.h>
#include <limits.h>

int FIND_MAX_CROSSING_SUBARRAY(int* arr, int low, int mid, int high, int* max_left, int* max_right){
	int sum = 0;
	
	int left_sum = INT_MIN;
	sum = 0;
	for(int i = mid-1; i >= low; i--){
		sum += arr[i];
		if(sum > left_sum){
			left_sum = sum;
			*max_left = i;
		}
	}

	int right_sum = INT_MIN;
	sum = 0;
	for(int i = mid; i < high; i++){
		sum += arr[i];
		if(sum > right_sum){
			right_sum = sum;
			*max_right = i;
		}
	}

	return left_sum + right_sum;
}

int main(){
	int arr[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	for(int i = 0; i < 16; i ++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	int max_left = 0;
	int max_right = 0;	
	int max_sum = 0;

	max_sum = FIND_MAX_CROSSING_SUBARRAY(arr, 0, 16/2, 16, &max_left, &max_right);
	
	printf("max_left : %d\n", max_left);
	printf("max_right : %d\n", max_right);
	printf("max_sum : %d\n", max_sum);

	return 0;
}

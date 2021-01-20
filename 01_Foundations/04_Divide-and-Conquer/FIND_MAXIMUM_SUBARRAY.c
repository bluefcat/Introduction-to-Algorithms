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

int FIND_MAXIMUM_SUBARRAY(int* arr, int low, int high, int* max_low, int* max_high){
	if(low+1 == high){
		//base case : only one element
		return arr[low];
	}
	int mid = (low+high)/2;
	
	int left_low = 0, left_high = 0;
	int left_sum = FIND_MAXIMUM_SUBARRAY(arr, low, mid, &left_low, &left_high);

	int right_low = 0, right_high = 0;
	int right_sum = FIND_MAXIMUM_SUBARRAY(arr, mid, high, &right_low, &right_high);

	int cross_low = 0, cross_high = 0;
	int cross_sum = FIND_MAX_CROSSING_SUBARRAY(arr, low, mid, high, &cross_low, &cross_high);

	if(left_sum >= right_sum && left_sum >= cross_sum){
		*max_low = left_low;
		*max_high = left_high;
		return left_sum;
	}
	else if(right_sum >= left_sum && right_sum >= cross_sum){
		*max_low = right_low;
		*max_high = right_high;
		return right_sum;
	}
	else{
		*max_low = cross_low;
		*max_high = cross_high;
		return cross_sum;
	}
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

	max_sum = FIND_MAXIMUM_SUBARRAY(arr, 0, 16, &max_left, &max_right);
	
	printf("max_left : %d\n", max_left);
	printf("max_right : %d\n", max_right);
	printf("max_sum : %d\n", max_sum);

	return 0;
}

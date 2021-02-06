#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int x, int y){
	return (x > y)? x: y;
}

int MEMOIZED_CUT_ROD_AUX(int* p, int n, int* r){
	if(r[n] >= 0) return r[n];
	
	int q = 0;
	if(n == 0){
		q = 0;
	}
	else{
		q = INT_MIN;
		for(int i = 1; i <= n; i ++){
			q = max(q, p[i] + MEMOIZED_CUT_ROD_AUX(p, n-i, r));
		}
	}
	r[n] = q;

	return q;
}

int MEMOIZED_CUT_ROD(int* p, int n){
	int* r = (int*)malloc(sizeof(int)*(n+1));
	for(int i = 0; i <= n; i ++){
		r[i] = INT_MIN;
	}
	 
	int q = MEMOIZED_CUT_ROD_AUX(p, n, r);
	free(r);
	return q;
}

int main(){
	int rod_length = 4;
	int price[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };

	printf("%d-inch rod has maximum revenue %d\n", rod_length, MEMOIZED_CUT_ROD(price, rod_length)); 

	return 0;
}

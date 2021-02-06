#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int x, int y){
	return (x > y)? x: y;
}

int BOTTOM_UP_CUT_ROD(int* p, int n){
	int* r = (int*)malloc(sizeof(int)*(n+1));
	r[0] = 0;

	for(int j = 0; j <= n; j ++){
		int q = INT_MIN;
		for(int i = 0; i <= j; i ++){
			q = max(q, p[i] + r[j-i]);
		}
		r[j] = q;
	}

	return r[n];
}

int main(){
	int rod_length = 4;
	int price[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

	printf("%d-inch rod has maximum revenue %d\n", rod_length, BOTTOM_UP_CUT_ROD(price, rod_length));

	return 0;
}

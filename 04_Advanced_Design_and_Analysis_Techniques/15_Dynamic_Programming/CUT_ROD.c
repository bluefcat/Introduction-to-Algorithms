#include <stdio.h>
#include <limits.h>

int max(int x, int y){
	return (x > y)? x: y;
}

int CUT_ROD(int* p, int n){
	if(n == 0) return 0;
	int q = INT_MIN;

	for(int i = 1; i <= n; i ++){
		q = max(q, p[i] + CUT_ROD(p, n-i));
	}
	return q;
}

int main(){
	int rod_length = 4;
	int price[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

	printf("%d-inch rod has maximum revenue %d\n", rod_length, CUT_ROD(price, rod_length));

	return 0;
}

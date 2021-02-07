#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* COMPUTE_PREFIX_FUNCTION(const char* P){
	int m = strlen(P);
	int* pi = (int*)malloc(sizeof(int)*m);
	memset(pi, 0, sizeof(int)*m);

	int k = 0;
	for(int q = 1; q < m; q ++){
		while(k > 0 && P[k] != P[q]) k = pi[k-1];
		if(P[k] == P[q]) k ++;
		
		pi[q] = k;
	}

	return pi;
}

int KMP_MATCHER(const char* T, const char* P){
	int result = -1;
	
	int n = strlen(T);
	int m = strlen(P);
	int* pi = COMPUTE_PREFIX_FUNCTION(P);

	int q = 0;
	for(int i = 0; i < n; i ++){
		while(q > 0 && P[q] != T[i]) q = pi[q];
		if(P[q] == T[i]) q ++;
		
		if(q == m){
		   	result = i-m+1;
			q = pi[q];
		}
	}
	free(pi);
	return result;
}

int main(){
	const char* T = "abcdefg";
	const char* P = "cde";

	printf("\"%s\" matched \"%s\" to %d\n", T, P, KMP_MATCHER(T, P));

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y){
	if(x > y) return y;
	return x;
}

int is_suffix(const char* T, const char* P){
	int n = strlen(T);
	int m = strlen(P);

	if(n < m) return 0;

	for(int i = 0; i < m; i ++){
		if(T[i+(n-m)] != P[i]) return 0;
	}
	
	return 1;
}


int** COMPUTE_TRANSITION_FUNCTION(const char* P, const char* s){
	int m = strlen(P);
	int n = strlen(s);

	int** d = (int **)malloc(sizeof(int*)*(m+1)); 
	d[0] = (int*)malloc(sizeof(int)*(m+1)*n);

	memset(d[0], 0, sizeof(int)*(m+1)*n);

	for(int i = 1; i < m+1; i ++){
		d[i] = d[i-1]+n;
	}

	for(int q = 0; q < m+1; q ++){
		const char* a = s;
		while(*a){
			int k = min(m, q+1);
			char* pk = (char*)malloc(sizeof(char)*k+1);
			strncpy(pk, P, k);

			char* pa = (char*)malloc(sizeof(char)*q+2);
			strncpy(pa, P, q);
			strncat(pa, a, 1);

			for(; !is_suffix(pa, pk) && k > 0; k--){
				pk = realloc(pk, sizeof(char)*k+1);
				memset(pk, 0, sizeof(char)*k+1);
				strncpy(pk, P, k-1);
			}

			d[q][(*a)%n] = k;
			a ++;
		}
	}

	return d;
}

int FINITE_AUTOMATON_MATCHER(const char* T, const char* s, int** d, int m){
	int result = -1;

	int n = strlen(T);
	int r = strlen(s);
	int q = 0;

	for(int i = 0; i < n; i ++){
		q = d[q][T[i]%r];
		if(q == m){
			result = i-m+1;
			break;
		}
	}
	return result;
}

int main(){
	const char* s = "abcdefg";
	const char* P = "cde";

	const char* T = "abcdefg";

	int** d = COMPUTE_TRANSITION_FUNCTION(P, s);

	printf("\"%s\" matched \"%s\" to %d\n", "abcdefg", "cde", FINITE_AUTOMATON_MATCHER(T, s, d, strlen(P)));

	free(d[0]);
	free(d);

	return 0;
}

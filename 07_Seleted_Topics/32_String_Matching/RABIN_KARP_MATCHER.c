#include <stdio.h>
#include <stdlib.h>

int power_mod(int base, int exp, int div){
	int result = 1;
	while(0 < exp--){
		result *= base;
		result %= div;
	}

	return result;
}

int my_strlen(const char* str){
	int result = 0;
	
	while(*(str++)){
		result ++;
	}

	return result;
}

int RABIN_KARP_MATCHER(const char* T, const char* P, int d, int q){
	int result = -1;
	int n = my_strlen(T);
	int m = my_strlen(P);
	int h = power_mod(d, m-1, q);
	int p = 0;
	int* t = (int*)malloc(sizeof(int)*(n-m+1));
	
	for(int i = 0; i < m; i ++){
		p = (d*p+P[i]) % q;
		t[0] = (d*t[0]+T[i]) % q;
	}

	for(int s = 0; s <= n-m; s ++){
		if(p == t[s]){
			int match_flag = 0;
			for(int i = 0; i < m; i ++){
				if(P[i] != T[i+s]) break;
				if(i == m-1) match_flag = 1;
			}
			if(match_flag) {
				result = s;
				break;
			}
		}

		if(s < n-m){
			t[s+1] = (d*(t[s]-T[s]*h)+T[s+m]) % q;
		}
	}

	free(t);
	return result;
}

int main(){
	printf("\"%s\" matched \"%s\" to %d\n", "abcdefg", "cde", RABIN_KARP_MATCHER("abcdefg", "cde", 26, 13));
	return 0;
}

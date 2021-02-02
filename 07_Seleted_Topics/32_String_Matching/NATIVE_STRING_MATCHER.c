#include <stdio.h>

int my_strlen(const char* str){
	int result = 0;
	while(*(str++)){
		result ++;
	}
	return result;
}

int NATIVE_STRING_MATCHER(const char* T, const char* P){
	int result = -1;

	int n = my_strlen(T);
	int m = my_strlen(P);
	
	for(int i = 0; i <= n-m; i ++){
		int match_flag = 0;
		
		for(int j = 0; j < m; j ++){
			if(P[j] != T[j+i]) break;
			if(j == m-1) match_flag = 1;
		}
		if(match_flag){
			result = i;
			break;
		}
	}

	return result;
}

int main(){
	int result = NATIVE_STRING_MATCHER("acaabc", "aab");
	
	printf("\"%s\" matched \"%s\" to %d\n", "acaabc", "aab", result);
	
	return 0;
}

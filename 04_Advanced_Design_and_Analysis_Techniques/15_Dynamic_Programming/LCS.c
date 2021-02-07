#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int*** LCS_LENGTH(const char* X, const char* Y){
	int m = strlen(X);
	int n = strlen(Y);

	//b[0] points to the entry corresponding
	//0 is no point
	//1 is North West Arrow
	//2 is Up Arrow
	//3 is Left Arrow
	
	//b[1] is the length of an LCS of X and Y
	int*** b = (int***)malloc(sizeof(int**)*2);
	b[0] = (int**)malloc(sizeof(int*)*2*(m+1));
	b[0][0] = (int*) malloc(sizeof(int)*2*(m+1)*(n+1));

	for(int i = 1; i < 2; i ++){
		b[i] = b[i-1]+(m+1);
	}

	for(int i = 1; i < 2*(m+1); i ++){
		b[0][i] = b[0][i-1]+(n+1);
	}

	memset(**b, 0, sizeof(int)*2*(m+1)*(n+1));

	int** a_table = b[0];
	int** l_table = b[1];

	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= n; j ++){
			if(X[i-1] == Y[j-1]){
				l_table[i][j] = l_table[i-1][j-1] + 1;
				a_table[i][j] = 1;
			}
			else if(l_table[i-1][j] >= l_table[i][j-1]){
				l_table[i][j] = l_table[i-1][j];
				a_table[i][j] = 2;
			}
			else {
				l_table[i][j] = l_table[i][j-1];
				a_table[i][j] = 3;
			}
		}
	}

	return b;
}

void PRINT_LCS(int*** b, const char* X, int i, int j){
	if(i == 0 || j == 0) return;

	int** a_table = b[0];

	if(a_table[i][j] == 1){
		PRINT_LCS(b, X, i-1, j-1);
		printf("%c", X[i-1]);
	}
	else if(a_table[i][j] == 2){
		PRINT_LCS(b, X, i-1, j);
	}
	else{
		PRINT_LCS(b, X, i, j-1);
	}
	return;
}

int main(){
	const char* X = "ABCBDAB";
	const char* Y = "BDCABA";

	int*** b = LCS_LENGTH(X, Y);

	int m = strlen(X); int n = strlen(Y);

	printf("\"%s\" and \"%s\" has LCS \"", X, Y);
	PRINT_LCS(b, X, m, n);
	printf("\"\n");

	free(b[0][0]);
	free(b[0]);
	free(b);

	return 0;
}

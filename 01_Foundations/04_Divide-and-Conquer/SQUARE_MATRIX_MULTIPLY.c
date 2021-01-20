#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** SQUARE_MATRIX_MULTIPLY(int** a, int row_a, int col_a, int** b, int row_b, int col_b){
	if(col_a != row_b) return NULL;

	int** c = (int**)malloc(sizeof(int*)*row_a);
	c[0] = (int*)malloc(sizeof(int)*row_a*col_b);

	for(int i = 1; i < row_a; i ++){
		c[i] = c[i - 1] + col_b;
	}

	for(int i = 0; i < row_a; i++){
		for(int j = 0; j < col_b; j++){
			c[i][j] = 0;
			for(int k = 0; k < col_a; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return c;
}

int main(){
	//init matrix a
	int row_a = 2, col_a = 2;
	int** a = (int**)malloc(sizeof(int*)*row_a);
	a[0] = (int*)malloc(sizeof(int)*row_a*col_a);
	for(int i = 1; i < row_a; i ++){
		a[i] = a[i - 1] + col_a;
	}

	for(int i = 0; i < row_a * col_a; i++){
		a[0][i] = i + 1;
	}
	
	printf("matrix a:\n");
	for(int i = 0; i < row_a; i ++){
		for(int j = 0; j < col_a; j ++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	//init matrix b
	int row_b = 2, col_b = 2;
	int** b = (int**)malloc(sizeof(int*)*row_b);
	b[0] = (int*)malloc(sizeof(int)*row_b*col_b);
	for(int i = 1; i < row_b; i ++){
		b[i] = b[i - 1] + col_b;
	}

	for(int i = 0; i < row_b * col_b; i++){
		b[0][i] = i + 1;
	}

	printf("matrix b:\n");
	for(int i = 0; i < row_b; i ++){
		for(int j = 0; j < col_b; j ++){
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}

	int** c = SQUARE_MATRIX_MULTIPLY(a, row_a, col_a, b, row_b, col_b);

	printf("matrix a*b:\n");
	for(int i = 0; i < row_a; i ++){
		for(int j = 0; j < col_b; j ++){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	free(a[0]);
	free(a);
	free(b[0]);
	free(b);
	free(c[0]);
	free(c);

	return 0;
}

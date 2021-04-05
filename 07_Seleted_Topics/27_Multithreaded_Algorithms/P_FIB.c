#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* P_FIB(void* n){
	int m = *(int*)n;
	if(m <= 1) return n;
	
	int* a = (int*)malloc(sizeof(int));
	int* b = (int*)malloc(sizeof(int));
	*a = m-1; *b = m-2;
	
	void* x;
	void* y;

	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, P_FIB, (void*)a);
	pthread_join(thread1, &x);
	
	pthread_create(&thread2, NULL, P_FIB, (void*)b);
	pthread_join(thread2, &y);
	free(b); free(a);

	void* r = malloc(sizeof(int));
	*(int*)(r+0) = *(int*)x + *(int*)y;
	
	return r;
}

int main(){
	int n = 16;
	void* result = P_FIB((void*)&n);

	printf("F(%d) = %d\n", n, *(int*)result);
	
	free(result);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct _STACK{
	int m_top;	
	int m_capacity;
	int* m_data;
} STACK;

STACK* STACK_CREATE(int capacity){
	STACK* new_stack = (STACK*)malloc(sizeof(STACK));
	new_stack->m_top = 0;
	new_stack->m_capacity = capacity + 1;
	new_stack->m_data = (int*)malloc(sizeof(int)*(capacity + 1));
	
	return new_stack;
}

void STACK_DELETE(STACK* s){
	free(s->m_data);
	free(s);
	return;
}

int STACK_EMPTY(STACK* s){
	if(s->m_top == 0) return 1;
	return 0;
}

int PUSH(STACK* s, int x){
	if(s->m_top == s->m_capacity) return 0;
	s->m_data[s->m_top ++] = x;
	return 1;
}

int POP(STACK* s){
	if(STACK_EMPTY(s)) return -1;
	s->m_top --;
	return s->m_data[s->m_top];
}

int main(){
	STACK* s = STACK_CREATE(6);
	int arr[6] = {15, 6, 2, 9, 17, 3};
	for(int i = 0; i < 6; i ++){
		PUSH(s, arr[i]);
	}
	printf("%d\n", POP(s));
	printf("%d\n", POP(s));

	STACK_DELETE(s);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE{
	int data;
	struct _NODE* prev;
	struct _NODE* next;
} NODE;

NODE* LIST_CREATE(int x){
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = x;
	new_node->prev = NULL;
	new_node->next = NULL;

	return new_node;
}

NODE* LIST_INSERT(NODE* l, int x){
	NODE* new_node = LIST_CREATE(x);

	new_node->next = l;
	if(l != NULL){
		l->prev = new_node;
	}
	return new_node;
}

NODE* LIST_SEARCH(NODE* l, int k){
	NODE* result = l;
	while(result != NULL && result->data != k){
		result = result->next;
	}
	return result;
}

void LIST_DELETE(NODE* l, int x){
	NODE* target = LIST_SEARCH(l, x);
	if(target->prev != NULL){
		target->prev->next = target->next;
	}
	else{
		l = target->next;
	}

	if(target->next != NULL){
		target->next->prev = target->prev;
	}
	return ;
}

void LIST_PRINT(NODE* l){
	NODE* t = l;
	while(t != NULL){
		printf("%d -> ", t->data);
		t = t->next;
	}
	printf("\n");
	return ;
}

void LIST_FREE(NODE* l){
	while(l != NULL){
		NODE* t = l;
		l = l->next;
		free(t);
	}
	return ;
}

int main(){
	NODE* l = NULL;
	int arr[4] = { 1, 4, 16, 9 };

	for(int i = 0; i < 4; i ++){
		l = LIST_INSERT(l, arr[i]);
	}
	LIST_PRINT(l);
	
	l = LIST_INSERT(l, 25);
	LIST_PRINT(l);

	LIST_DELETE(l, 4);
	LIST_PRINT(l);

	LIST_FREE(l);
	return 0;
}

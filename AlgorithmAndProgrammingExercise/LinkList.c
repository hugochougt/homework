#include<stdio.h>
#include<malloc.h>

typedef int itemType;
typedef struct node* link;
struct node{ itemType item; link next; };
typedef link Node;

const int N = 100;

int main(){
	int i;
	link head, x, t;
	srand(47);
	head = malloc(sizeof(*head));
	head->next = NULL;
	for(x = head, i = 0; i < N; i++){
		x->next = malloc(sizeof(*x));
		x = x->next;
		x->item = rand() % 100 + 1;
		x->next = NULL;
	}
	for(x = head; x->next != NULL; x = x->next)
		printf("%d ", x->item);
	printf("\n");
	for(x = head; x->next != NULL; ){
		t = x->next;
		x->next = t->next;
		free(t);
	}
}

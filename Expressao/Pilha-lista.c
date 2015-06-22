#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    char info;
    struct lista *prox;
}Lista;

typedef struct pilha{
    Lista* prim;
}Pilha;

Pilha* pilha_cria(){
    Pilha *p=(Pilha*)malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}
void pilha_push(Pilha *p,char x){
    Lista *n=(Lista*)malloc(sizeof(Lista));
    n->info = x;
    n->prox = p->prim;
    p->prim = n;
}
char pilha_vazia(Pilha* f){
    if(f->prim==NULL)
        return 1;
    else
        return 0;
}
char pilha_pop(Pilha *p){
    Lista *t;
    char x;
    if (pilha_vazia(p)){
    	printf("Pilha vazia.\n");
    	exit (1);
	}
	t = p->prim;
	x = t->info;
	p->prim = t->prox;
	free(t);
	return x;
}

void pilha_libera(Pilha *p){
	Lista *q = p->prim;
	while(q!=NULL){
		Lista *t=q->prox;
		free(q);
		q=t;
	}
	free(p);
}
int main(){
	Pilha* p;
	p = pilha_cria();
	pilha_push(p, 20);
	pilha_pop(p);
	pilha_libera(p);
	system("pause");
	return 0;
}

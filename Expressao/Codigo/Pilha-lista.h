#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    char op;
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
void pilha_push(Pilha *p,int x){
    Lista *n=(Lista*)malloc(sizeof(Lista));
    n->info = x;
    n->prox = p->prim;
    p->prim = n;
}
void pilha_pushOP(Pilha *p,char x){
    Lista *n=(Lista*)malloc(sizeof(Lista));
    n->op = x;
    n->prox = p->prim;
    p->prim = n;
}
int pilha_vazia(Pilha* f){
    if(f->prim==NULL)
        return 1;
    else
        return 0;
}
int pilha_pop(Pilha *p){
    Lista *t;
    int x;
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
char pilha_popOP(Pilha *p){
    Lista *t;
    char x;
    if (pilha_vazia(p)){
    	printf("Pilha vazia.\n");
    	exit (1);
	}
	t = p->prim;
	x = t->op;
	p->prim = t->prox;
	free(t);
	return x;
}
void pilha_imprime(Pilha *p1){
      Lista *p;
      for(p=p1->prim;p!=NULL;p=p->prox)
           printf("\tinfo: %d\n",p->info);
}
void pilha_imprimeOP(Pilha *p1){
      Lista *p;
      for(p=p1->prim;p!=NULL;p=p->prox)
           printf("\tinfo: %c\n",p->op);
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

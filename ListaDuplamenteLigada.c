#include <stdlib.h>
#include <stdio.h>
#include "Booleano.h"

typedef struct Celula{
	int item;
	struct Celula *anterior;
	struct Celula *sucessor;
} Celula;

typedef struct{
	int tamanho;
	Celula *inicio;
	Celula *fim;
} Lista;

Lista criarLista();
void inserirLista(Lista*, int);
void mostrarListaED(Lista *A);
void mostrarListaDE(Lista *A);
void removerInicio(Lista *A);
void removerFim(Lista *A);
void removerMeio(Lista *A, int y);

int main(){
	
	Lista D = criarLista();
	
	inserirLista(&D, 4);
	inserirLista(&D, 2);
	inserirLista(&D, 1);
	inserirLista(&D, 3);
	inserirLista(&D, 7);
	inserirLista(&D, 8);
	inserirLista(&D, 6);
	inserirLista(&D, 9);
	
	mostrarListaED(&D);
	printf("\n");
	//mostrarListaDE(&D);
	
	//removerInicio(&D);
	
	printf("\n");
	//mostrarListaDE(&D);
	
	//removerFim(&D);
	
	printf("\n");
	//mostrarListaED(&D);
	
	removerMeio(&D, 3);
	printf("\n");
	mostrarListaED(&D);
	
	return 0;
}

Lista criarLista(){
	Lista A;
	
	A.inicio = NULL;
	A.fim = NULL;
	A.tamanho = 0;
	
	return A;
}

void inserirLista(Lista *A, int y){
	Celula *novo, *apontador;
	novo = malloc(sizeof(Celula));
	novo->item = y;
	
	if(A->inicio == NULL){
		novo->anterior = NULL;
		novo->sucessor = NULL;
		A->inicio = novo;
		A->fim = novo;
		A->tamanho += 1;	
	}
	
	else{
		//inserindo no inicio
		apontador = A->inicio;
		apontador->anterior = novo;
		
		novo->anterior = NULL;
		novo->sucessor = apontador;
	
		A->inicio = novo;
		A->tamanho += 1;
		
	}
}

void mostrarListaED(Lista *A){
	Celula *apontador;
	
	if(A->inicio != NULL){
		apontador = A->inicio;
		
		do{
			printf(" %d ", apontador->item);
			apontador = apontador->sucessor;
		}while(apontador != NULL);
	}
}

void mostrarListaDE(Lista *A){
	Celula *apontador;
	
	if(A->inicio != NULL){
		apontador = A->fim;
		
		do{
			printf(" %d ", apontador->item);
			apontador = apontador->anterior;
		}while(apontador != NULL);
	}
}

void removerInicio(Lista *A){
	Celula *apontador, *proximo;
	apontador = A->inicio;
	
	if(apontador->sucessor == NULL){
		free(apontador);
		A->inicio = NULL;
		A->fim = NULL;
	}
	else{
		proximo = apontador->sucessor;
		proximo->anterior = NULL;
		
		A->inicio = proximo;
		free(apontador);
	}
	
}

void removerFim(Lista *A){
	Celula *apontador, *anterior;
	apontador = A->fim;
	
	if(apontador->anterior == NULL){
		free(apontador);
		A->inicio = NULL;
		A->fim = NULL;
	}
	else{
		anterior = apontador->anterior;
		anterior->sucessor = NULL;
		
		A->fim = anterior;
		free(apontador);
	}	
}

void removerMeio(Lista *A, int y){
	Celula *apontador, *anterior, *proximo;
	apontador = A->inicio;
	
	if(apontador->sucessor == NULL){
		free(apontador);
		A->inicio = NULL;
		A->fim = NULL;
	}
	else{
		
		do{
			apontador = apontador->sucessor;	
		}while((apontador->sucessor != NULL) && (apontador->item != y));
		
		if(apontador->item == y){
			proximo = apontador->sucessor;
			anterior = apontador->anterior;
			
			proximo->anterior = anterior;
			anterior->sucessor = proximo;
			
			free(apontador);
		}
	}
}

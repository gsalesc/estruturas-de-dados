#include <stdlib.h>
#include <stdio.h>
#include "Booleano.h"

//LISTA COM CABEÇA
//FIFO
typedef struct Celula{
	unsigned char item;
	struct Celula *next;
} Celula;

typedef struct {
	Celula *inicio;
	Celula *fim;
} Fila;

Fila criarFila();
bool filaVazia(Fila *A);
unsigned char acessarFila(Fila *A);
void mostrarFila(Fila *A);
void pushFila(Fila *A, unsigned char y);
void popFila(Fila *A);

int main(){
	
	Fila F = criarFila();
	
	pushFila(&F, 6);
	pushFila(&F, 7);
	pushFila(&F, 1);
	pushFila(&F, 2);
	pushFila(&F, 9);
	pushFila(&F, 8);
	pushFila(&F, 5);
	
	printf("\n---\n");
	
	mostrarFila(&F);
	
	popFila(&F);
	popFila(&F);
	
	printf("\n---\n");
	
	mostrarFila(&F);
	
	unsigned char ch = acessarFila(&F);
	
	printf("\n\n %d \n", ch);
	
	return 0;
}

Fila criarFila(){
	Fila A;
	
	A.inicio = NULL;
	A.fim = NULL;
	
	return A;
}

bool filaVazia(Fila *A){
	bool vazia = FALSE;
	
	if(A->inicio == NULL)
		vazia = TRUE;
		
	return vazia;
}

unsigned char acessarFila(Fila *A){
	unsigned char ch;
	Celula *apontador;
	
	if(A->inicio != NULL){
		apontador = A->inicio;
		ch = apontador->item;
	}
	
	return ch;
}

void mostrarFila(Fila *A){
	Celula *apontador;
	
	if(A->inicio != NULL){
		apontador = A->inicio;
		
		do{
			printf(" %d ", apontador->item);
			apontador = apontador->next;
		}while(apontador != NULL);
	}
	else
		printf("\nVazia\n");	
}

void pushFila(Fila *A, unsigned char y){
	Celula *novo, *apontador;
	novo = malloc(sizeof(Celula));
	novo->item = y;
	
	if(A->inicio == NULL){
		A->inicio = novo;
		A->fim = novo;
	}
	else{
		apontador = A->fim;
		novo->next = NULL;
		apontador->next = novo; //muda o proximo do antigo fim
		A->fim = novo; //muda o fim
	}
}

void popFila(Fila *A){
	Celula *apontador, *proximo;
	
	if(A->inicio != NULL){
		apontador = A->inicio;
		proximo = apontador->next;
		
		free(apontador);
		A->inicio = proximo;
	}
}

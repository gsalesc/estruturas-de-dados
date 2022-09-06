#include <stdlib.h>
#include <stdio.h>
#include "Booleano.h"

//LISTA SEM CABEÇA
//FILO
typedef struct Celula{
	unsigned char item;
	struct Celula *next;
} Celula;

typedef Celula *Pilha; //é um pointer de Celula

Pilha criarPilha();
bool pilhaVazia(Pilha A);
unsigned char acessarPilha(Pilha A);
void mostrarPilha(Pilha A);
Pilha pushPilha(Pilha A, unsigned char y);
Pilha popPilha(Pilha A);

int main(){
	
	Pilha P = criarPilha();
	
	//topo da pilha é o inicio
	P = pushPilha(P, 5);
	P = pushPilha(P, 7);
	P = pushPilha(P, 8);
	P = pushPilha(P, 4);
	P = pushPilha(P, 2);
		
	mostrarPilha(P);
	
	printf("\n---\n");
	
	P = popPilha(P);
	P = popPilha(P);
	
	printf("\n---\n");
	
	mostrarPilha(P);
	
	printf("\n---\n");
	
	unsigned char ch = acessarPilha(P);
	
	printf("\n %d ", ch);
	return 0;
}

Pilha criarPilha(){
	Pilha A;
	
	A = NULL;
	return A;
}

bool pilhaVazia(Pilha A){
	bool vazia = FALSE;
	
	if(A == NULL)
		vazia = TRUE;
	
	return vazia;
}

//o topo é o inicio
unsigned char acessarPilha(Pilha A){
	unsigned char ch;
	Pilha apontador;
	
	if(A != NULL){
		
		apontador = A;
		ch = apontador->item;	
	}
	
	return ch;
}

void mostrarPilha(Pilha A){
	Pilha apontador;
	
	if(A != NULL){
		apontador = A;
		
		do{
			printf("\n %d \n", apontador->item);
			apontador = apontador->next;
		}while(apontador != NULL);
	}
	else
		printf("\nVazia\n");
}

Pilha pushPilha(Pilha A, unsigned char y){
	Celula *novo;
	novo = malloc(sizeof(Celula));
	novo->item = y;
	
	if(A == NULL){
		novo->next = NULL;
		A = novo;
	}
	
	else{
		novo->next = A; //o proximo do novo é o primeiro
		A = novo; //novo comeco da pilha
	}
	
	return A;
}

Pilha popPilha(Pilha A){
	Celula *apontador, *proximo;
	
	if(A != NULL){
		apontador = A; //aponta para o primeiro
		proximo = apontador->next; //aponta para o next do primeiro
		
		free(apontador); //limpa o primeiro
		A = proximo; //o novo inicio é o proximo
	}
	else{
		free(apontador);
		A = NULL;
	}
}


/*  Produção da biblioteca do tipo Pilha  */
/* Arquivo: Pilha.h
   Autor: GABRIEL SALES COSTA
   Date: 29/04/22 09:18
   Descrição: implementação das operações de uma pilha
   
*/

/*Pilha.h
	- Os elementos da pilha são guardados a partir da posição 0
	- O campo topo indica o local onde está o último item colocado na pilha
	- Os elementos da pilha não são números inteiros não negativos	{1, 2, 3, 4, ...}
*/

#include <stdio.h>
#include <stdlib.h> //malloc, NULL
#include "Booleano.h"
#define Max 9
#define sinal -1 //identifica a pilha vazia
#define fantasma 0 //não tem relação com o array

typedef struct{
	int topo; //local do último item
	unsigned char vetor[Max];
} Pilha;	
	
//Interfaces
Pilha criarPilha();
bool pilhaVazia(Pilha);
void mostrarPilha(Pilha);
bool pilhaCheia(Pilha);
Pilha pushPilha(Pilha, unsigned char);
Pilha popPilha(Pilha);
unsigned char acessarPilha(Pilha);
Pilha esvaziarPilha(Pilha);

int main(){
	
	Pilha S;
	bool vazia, cheia;
	
	S = criarPilha();
	mostrarPilha(S);
	vazia = pilhaVazia(S);
	cheia = pilhaCheia(S);
	
	if(vazia == TRUE)
		printf("\n\n  Pilha vazia");
	
	if(cheia == FALSE)
		printf("\n\nPilha nao esta cheia");
		
		
	S = pushPilha(S, 'a');
    S =	pushPilha(S, 'b');
	S = pushPilha(S, 'c');
	
	mostrarPilha(S);
	
	S = popPilha(S);
	
	mostrarPilha(S);
	
	return 0;
}

//Implementação
Pilha criarPilha(){
	Pilha A;
	A.topo = sinal;
	
	return A;
}

bool pilhaVazia(Pilha A){
	bool vazia = FALSE;
	
	if(A.topo == sinal)
		vazia = TRUE;
		
	return vazia;
}

void mostrarPilha(Pilha A){
	int tam = A.topo;
	int i = tam;
	if(tam == sinal) //verifica se está vazia 
		printf("\nPilha vazia");
		
	else{
		for(i; i >= 0; i--){
			unsigned char ch = A.vetor[i];
			printf("\n %c", ch);
		}
	}
}

bool pilhaCheia(Pilha A){
	bool cheia = FALSE;
	int tam = A.topo;
	
	if(tam == Max-1) //Max-1 pois a pilha começa da posição 0
		cheia = TRUE;
		
	return cheia;
}

Pilha pushPilha(Pilha A, unsigned char ch){
	int p = A.topo+1;
	
	if(p < Max){
		A.vetor[p] = ch;
		A.topo = p;
	}
		
	return A;
}

Pilha popPilha(Pilha A){
	int p = A.topo-1;
	A.topo = p;
	
	return A;
}

unsigned char acessarPilha(Pilha A){
	int p = A.topo;
	char ch = A.vetor[p];
	
	return ch;
}

Pilha esvaziarPilha(Pilha A){
	A.topo = sinal;
	
	return A;
}

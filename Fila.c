/*                */
/* Arquivo: 
   Autor: 
   Date: 
   Descrição: 
   
*/


#include "Booleano.h"
#define Max 9
#define sinal -1 //identifica a pilha vazia
#define fantasma 99 //não tem relação com o array

typedef struct {
	int inicio;
	int fim;
	unsigned char vetor[Max];
} Fila;


	Fila criarFila();
	bool filaVazia(Fila);
	unsigned char acessarPrimeiro(Fila);
	Fila pushFila(Fila, unsigned char);
	Fila popFila(Fila);
	Fila esvaziarFila(Fila);
	
//interface
/*




*/


int main(){
	
	
	
	return 0;
}

//implementação
Fila criarFila(){
	Fila A;
	A.fim = sinal;
	A.inicio = sinal;
	
	return A;
}

bool filaVazia(Fila A){
	bool vazia = FALSE;
	
	if(A.inicio != sinal || A.fim != sinal)
		vazia = TRUE;
		
	return vazia;
}

unsigned char acessarPrimeiro(Fila A){
	int p = A.inicio;
	unsigned char ch;
	
	if(p != sinal)
		ch = A.vetor[p];
		
	return ch;
}

Fila pushFila(Fila A , unsigned char ch){
	int p = (A.fim+1) % Max;
	
	if(p != A.inicio){
		if( A.inicio == sinal ) 
			A.inicio = p;  
		A.fim = p;
	}
	
	return A;
}

Fila popFila(Fila A){
	int p = A.inicio;
	int seg;
	
	if(p != sinal){
		if(p == A.fim){ //reseta a fila
			A.inicio = sinal;
			A.fim = sinal;
		}
		else{
			seg = (A.inicio + 1) % Max;
			A.inicio = seg;
		}
	}
}

Fila esvaziarFila(Fila A){
	A.inicio = sinal;
	A.fim = sinal;
	
	return A;
}

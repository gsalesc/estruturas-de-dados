#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int elemento;
	struct No *esq;
	struct No *dir;
} No;

typedef No *Arvore;

Arvore criarArvoreVazia();
void mostrarArvore_eRd(Arvore);
Arvore construirArvore(int, Arvore, Arvore);
void mostrarArvore_edR(Arvore);
void mostrarArvore_Red(Arvore);
void mostrarPrimeiro(Arvore);
void mostrarPrimeiro_edR(Arvore arv);
void mostrarUltimo(Arvore);

int main(){
	
	Arvore a, b, c, d, e, f, g;
	/*a = criarArvoreVazia();
	b = criarArvoreVazia();
	c = construirArvore(5, a, b);
	d = construirArvore(3, a, b);
	e = construirArvore(2, c, d);

	//mostrarArvore_edR(e);*/
	
	
	///////////////////////
	
	a = construirArvore(5, NULL, NULL);
	b = construirArvore(1, NULL, a);
	c = construirArvore(6, NULL, NULL);
	d = construirArvore(3, b, c);
	
	e = construirArvore(7, NULL, NULL);
	f = construirArvore(4, e, NULL);
	 
	g = construirArvore(2, d, f);
		
	mostrarPrimeiro(g);
	printf("\n eRd: \n");
	mostrarArvore_eRd(g);
	
	mostrarPrimeiro_edR(g);
	printf("\n edR: \n");
	mostrarArvore_edR(g);
	
	printf("\n Red: \n");
	mostrarArvore_Red(g);
	
	//mostrarUltimo(g);
	
	int h = obterAltura(g);
	
	printf("\nAltura: %d", h);
	
	return 0;
}

Arvore criarArvoreVazia(){
	Arvore arv;
	arv = NULL;
	
	return arv;
}

void mostrarArvore_eRd(Arvore arv){
	if(arv == NULL){
		printf("");
	}
	else{
		
		mostrarArvore_eRd(arv->esq);
		printf("%d,", arv->elemento);
		mostrarArvore_eRd(arv->dir);
	}
}

void mostrarArvore_edR(Arvore arv){
	if(arv == NULL){
		printf("");
	}
	else{
		mostrarArvore_edR(arv->esq);	
		mostrarArvore_edR(arv->dir);	
		printf("%d,", arv->elemento);
	}
}

void mostrarArvore_Red(Arvore arv){
	if(arv == NULL){
		printf("");
	}
	else{
		printf("%d,", arv->elemento);
		mostrarArvore_Red(arv->esq);	
		mostrarArvore_Red(arv->dir);	
		
	}
}

Arvore construirArvore(int y, Arvore esq, Arvore dir){
	Arvore arv;
	arv = malloc(sizeof(No));
	arv->elemento = y;
	arv->esq = esq;
	arv->dir = dir;
	
	return arv;
}	

void mostrarPrimeiro(Arvore arv){
	No *p;
	if(arv == NULL){
		printf(" VAZIA! ");
	}
	else{
		p = arv;
		while (p->esq != NULL){
			p = p->esq;
		}
		
		printf("\n Primeiro eRd: %d", p->elemento);
	}
}

void mostrarPrimeiro_edR(Arvore arv){
	No *p;
	if(arv == NULL){
		printf(" VAZIA! ");
	}
	else{
		p = arv;
		while (p->esq != NULL){
			p = p->esq;
		}
		
		while(p->dir != NULL){
		 	p = p->dir;
		}
		
		printf("\n Primeiro edR: %d", p->elemento);
	}
}

void mostrarUltimo(Arvore arv){
	No *p;
	if(arv == NULL){
		printf(" VAZIA!");
	}
	else{
		p = arv;
		while(p->dir != NULL){
			p = p->dir;
		}
		
		printf("\n Ultimo eRd: %d", p->elemento);
	}
}

int obterAltura(Arvore arv){
	int h, he, hd;
	
	if(arv == NULL){
		h = -1;
	}
	else{
		he = obterAltura(arv->esq);
		hd = obterAltura(arv->dir);
		if(he > hd)
			h = he+1;
		else
			h = hd+1;
	}
	
	return h;
}

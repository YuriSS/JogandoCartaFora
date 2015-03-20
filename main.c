#include <stdio.h>
#include <stdlib.h>

/* [INI] Estrutura Pilha */
	typedef struct No{
		int carta;
		struct No *prox;
	}No;
	typedef struct Pilha{
		No *topo, *base;
		int quant;
	}Pilha;

	No* novoNo(int carta) {
		No* novo = (No *)malloc(sizeof(No));
		novo->carta = carta;
		novo->prox = NULL;
		return novo;
	}

	Pilha* novaPilha() {
		Pilha* nova = (Pilha *)malloc(sizeof(Pilha));
		nova->topo = nova->base = NULL;
		nova->quant = 0;
		return nova;
	}

	typedef struct NoPilha {
		Pilha *pil;
		struct NoPilha *prox;
	}NoPilha;
	
	typedef struct PilhaPilha {
		NoPilha *topo;
	}PilhaPilha;

	NoPilha* novoNoPilha(Pilha *pil) {
		NoPilha *novo = (NoPilha *)malloc(sizeof(NoPilha));
		novo->pil = pil;
		novo->prox = NULL;
		return novo;
	}

	PilhaPilha* novaPilhaPilha() {
		PilhaPilha* nova = (PilhaPilha *)malloc(sizeof(PilhaPilha));
		nova->topo = NULL;
		return nova;
	}
/* [FIM] Estrutura Pilha */


/* [INI] Busca */
	No* busca(Pilha *p, int carta) {
		if(p->topo != NULL) {
			if(p->topo->carta == carta) {
				return p->topo;
			} else {
				No *aux = p->topo;
				while(aux != NULL) {
					if(aux->carta == carta) {
						return aux;
					}
					aux = aux->prox;
				}
			}
		}
		return NULL;
	}
/* [FIM] Busca */


/* [INI] Insercao */
	void push(Pilha *p, int carta) {
		if(p->topo == NULL) {
			p->topo = p->base = novoNo(carta);
		} else {
			No *aux = p->topo;
			while(aux->prox != NULL) {
				aux = aux->prox;
			}
			aux->prox = novoNo(carta);
			if(p->base == aux) p->base = aux->prox;
		}
		p->quant++;
	}

	void pushPilha(Pilha *p, Pilha *c) {
		if(p->topo == NULL) {
			p->topo = novoNoPilha(c);
		} else {
			NoPilha *aux = p->topo;
			while(aux->prox != NULL) {
				aux = aux->prox;
			}
			aux->prox = novoNoPilha(c);
		}
	}

	void pushBottom(Pilha *p) {
		p->base->prox = p->topo;
		p->base = p->base->prox;
		p->topo = p->base->prox;
		p->base->prox = NULL;
	}
/* [FIM] Insercao */


/* [INI] Remoção */
	void rmv(Pilha *p) {
		if(p->topo != NULL) {
			No *tmp = p->topo;
			p->topo = p->topo->prox;
			free(tmp);
		}
	}

	void clear(Pilha *p) {
		No *aux = p->topo;
		int flag = 1;
		while(flag) {
			if(aux == p->base) flag = 0;
			else aux = aux->prox;
			rmv(p);
		}
	}
/* [FIM] Remoção */


/* [INI] Impressao */
	void impressao(Pilha *p) {
		No* aux = p->topo;
		while(aux != NULL) {
			printf("carta: %d\n", aux->carta);
			aux = aux->prox;
		}
	}
/* [FIM] Impressao */

int main() {

	Pilha *baralho = *tmp = novaPilha();
	Pilha *restante = *cova = novaPilha();
	PilhaPilha *cemiterio = novaPilhaPilha();
	int play = 1;
	// Recolhe baralhos
	while(play != 0) {
		printf("Baralho composto por: ");
		scanf("%d", &play);
		if(play <= 50 && play > 0) {
			push(baralho, play);
		}
	}
	// Prepara String
	No *aux = baralho->topo;
	int i;
	while(aux != NULL) {
		if(aux->prox != NULL) {
			clear(tmp);
			for(i=1; i<aux->carta; i++) {
				push(tmp, i);
			}
			while(tmp->prox != NULL) {
				push(cova, aux->carta);
				rmv(tmp);
				pushBottom(tmp);
			}
			push(restante, tmp->carta);
			pushPilha(cemiterio, cova);
		}
	}

	printf("Restantes:\n");
	impressao(restante);

	return 0;

}

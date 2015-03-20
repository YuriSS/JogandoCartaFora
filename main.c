#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main() {

	Baralho* baralho = novoBaralho();

	pushBaralho(baralho, 3);
	pushBaralho(baralho, 5);
	pushBaralho(baralho, 2);
	pushBaralho(baralho, 8);

	rmvBaralho(baralho);
	pushBaralhoBottom(baralho);

	imprimiBaralho(baralho);

	/*Fila fila;
	novaFila(&fila);

	int play = 1;
	int i;
	while(play != 0) {
		printf("Digite quantidade o baralho: ");
		scanf("%d", &play);
		if(play > 0 && play <= 50) {
			Baralho* baralho = novoBaralho();
			for(i=play; i>0; i--) {
				pushBaralho(baralho, i);
			}
			pushFila(&fila, baralho);
		}
	}

	imprimiFila(&fila);*/

	/*Baralho baralho;
	Baralho baralho2;
	novoBaralho(&baralho);
	novoBaralho(&baralho2);

	Fila fila;
	novaFila(&fila);

	pushBaralho(&baralho, 3);
	pushBaralho(&baralho, 5);
	pushBaralho(&baralho, 2);
	pushBaralho(&baralho, 8);

	pushBaralho(&baralho2, 3);
	pushBaralho(&baralho2, 5);
	pushBaralho(&baralho2, 2);
	pushBaralho(&baralho2, 8);

	pushFila(&fila, &baralho);
	pushFila(&fila, &baralho2);

	imprimiFila(&fila);*/

	return 0;
}


/* [INI] Estrutura de Baralho */
	typedef struct Carta{
		int num;
		struct Carta *prox, *ant;
	}Carta;

	typedef struct Baralho{
		Carta *topo, *base;
	}Baralho;


	/* [INI] Inicialização no Baralho */
		Carta* novaCarta(int num) {
			Carta* nova = (Carta *)malloc(sizeof(Carta));
			nova->prox = nova->ant = NULL;
			nova->num = num;
			return nova;
		}

		Baralho* novoBaralho() {
			Baralho* novo = (Baralho *)malloc(sizeof(Baralho));
			novo->topo = novo->base = NULL;
			return novo;
		}
	/* [FIM] Inicialização no Baralho */


	/* [INI] Insercao no Baralho */
		void pushBaralho(Baralho* b, int num) {
			Carta* nova = novaCarta(num);
			nova->ant = b->topo;
			if(b->topo == NULL)
				b->base = nova;
			else
				b->topo->prox = nova;
			b->topo = nova;
		}

		void pushBaralhoBottom(Baralho* b) {
			b->base->ant = b->topo;
			b->topo->prox = b->base;
			b->base = b->topo;
			b->topo = b->topo->ant;
			b->topo->prox = NULL;
			b->base->ant = NULL; 
		}
	/* [FIM] Insercao no Baralho */


	/* [INI] Remocao no Baralho */
		void rmvBaralho(Baralho* b) {
			if(b->topo != NULL) {
				Carta* tmp = b->topo;
				b->topo = b->topo->ant;
				free(tmp);
			}
		}
	/* [FIM] Remocao no Baralho */
	

	/* [INI] Impressao */
		void imprimiBaralho(Baralho *b) {
			Carta* aux = b->base;
			while(aux != NULL) {
				printf(" %d", aux->num);
				if(aux->prox != NULL) printf(",");
				aux = aux->prox;
			}
		}
	/* [FIM] Impressao */
/* [FIM] Estrutura de Baralho */

/* [INI] Estrutura de uma Fila de Baralho */
	typedef struct Node{
		Baralho *baralho;
		struct Node *prox, *ant;
	}Node;

	typedef struct Fila{
		Node *inicio, *fim;
	}Fila;


	/* [INI] Inicialização da Fila */
		Node* novoNode(Baralho *b) {
			Node* novo = (Node *)malloc(sizeof(Node));
			novo->prox = novo->ant = NULL;
			novo->baralho = b;
			return novo;
		}

		void novaFila(Fila *f) {
			f->inicio = f->fim = NULL;
		}
	/* [FIM] Inicialização da Fila */


	/* [INI] Insercao */
		void pushFila(Fila *f, Baralho *b) {
			Node* novo = novoNode(b);
			novo->prox = f->fim;
			if(f->inicio == NULL)
				f->inicio = novo;
			else
				f->fim->ant = novo;
			f->fim = novo;
		}
	/* [FIM] Insercao */


	/* [INI] Impressao */
		void imprimiFila(Fila *f, Fila *c) {
			Node* aux = f->inicio;
			Node* cem = c->inicio;
			while(aux != NULL) {
				printf("Discarded cards:");
				imprimiBaralho(cem->baralho);
				printf("\n");
				printf("Remaining card:");
				imprimiBaralho(aux->baralho);
				printf("\n");
				aux = aux->ant;
				cem = cem->ant;
			}
		}
	/* [FIM] Impressao */
/* [FIM] Estrutura de uma Fila de Baralho */

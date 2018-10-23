/*Exercício- Algoritmos e Estruturas de Dados I: Filas Duplamente Encadeadas
Alunos: Alan Deivison, Bruno Terra, Illyana Avelar, Luan Ferreira, Yan Victor
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct TipoCelula *TipoApontador;

typedef int TipoChave;

typedef struct TipoItem {
     TipoChave Chave;
} TipoItem;

typedef struct TipoCelula {
     TipoItem Item;
     TipoApontador Ante;
     TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila {
     TipoApontador Frente, Tras;
} TipoFila;

void Clear();
void FFVazia(TipoFila *Fila);
int Vazia(TipoFila Fila);
void Enfileira(TipoItem x, TipoFila *Fila);
void Desenfileira(TipoFila *Fila, TipoItem *Item);
void AumentaPrioridade(TipoFila *Fila, TipoChave Chave);
void Imprime(TipoFila Fila, int direcao);

int main(int argc, char *argv[]) {
     TipoFila fila;
     TipoItem item;
     TipoChave chave;
     int opcao = 0, aux;

     FFVazia(&fila);
     while(opcao != 6){
          printf("1-Lista Vazia \n2-Enfileira \n3-Desenfileira \n4-Aumentar Prioridade \n5-Imprimir \n6-Sair\n");

          scanf("%d", &opcao);

          switch(opcao){

               case 1:
               Clear();
               FFVazia(&fila);
               break;

               case 2:
               Clear();
               printf("%s", "Senha: ");
               scanf("%d", &aux);
               item.Chave = aux;
               Enfileira(item, &fila);
               break;

               case 3:
               Clear();
               Desenfileira(&fila, &item);
               break;

               case 4:
               Clear();
               printf("%s", "Senha Prioritaria: ");
               scanf("%d", &aux);
               chave = aux;
               AumentaPrioridade(&fila, chave);
               break;

               case 5:
               Clear();
               printf("%s\n", "Imprimir [1]Normal ou [2]Invertido?");
               scanf("%d", &aux);
               Imprime(fila, aux);
               break;

          }
     }
     return 0;
}

void Clear(){
     for(int i = 0 ; i < 100 ; i++){
          printf("\n");
     }
}

void FFVazia(TipoFila *Fila) {
     Fila -> Frente = (TipoApontador) malloc(sizeof(TipoCelula));
     Fila -> Tras = Fila -> Frente;
     Fila -> Frente -> Prox = NULL;
     Fila -> Frente -> Ante = NULL;
}

int Vazia(TipoFila Fila) {
     return (Fila.Frente == Fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *Fila) {
     TipoApontador Aux;
     Aux = Fila -> Tras;
     Fila -> Tras -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
     Fila -> Tras = Fila -> Tras -> Prox;
     Fila -> Tras -> Item = x;
     Fila -> Tras -> Prox = NULL;
     Fila -> Tras -> Ante = Aux;
}

void Desenfileira(TipoFila *Fila, TipoItem *Item) {
     TipoApontador q;
     if(Vazia(*Fila)){
          printf("Erro, fila esta vazia\n");
          return;
     }
     q = Fila -> Frente;
     Fila -> Frente = Fila -> Frente -> Prox;
     Fila -> Frente -> Ante = NULL;
     *Item = Fila -> Frente -> Item;
     free(q);
}

void Imprime(TipoFila Fila, int direcao) {
     TipoApontador Aux;

     printf("\nProcessos na fila:\n");
     switch(direcao) {
          case 1:
          Aux = Fila.Frente;
          while(Aux != NULL) {
               printf("%d\n", Aux -> Item.Chave);
               Aux = Aux -> Prox;
          }
          break;

          case 2:
          Aux = Fila.Tras;
          while(Aux != NULL) {
               printf("%d\n", Aux -> Item.Chave);
               Aux = Aux -> Ante;
          }
          break;
     }
}

void AumentaPrioridade(TipoFila *Fila, TipoChave Chave) {
     TipoApontador q, retorno, Aux;
     TipoItem Item;
     Aux = Fila -> Frente;

     //Localiza Ponteiro
  	if(Vazia(*Fila)){
  		printf("Não foi possivel localizar essa Chave na Fila.\n");
    		return;
	}
	q = Fila -> Frente -> Prox;
	if(q -> Item.Chave == Chave){
		retorno = Fila -> Frente;
	}
	else{
		do{
			retorno = q;
			q = q -> Prox;
		}
		while(q -> Item.Chave != Chave);
	}

     //Tira da Fila
     if(Vazia(*Fila) || retorno == NULL || retorno -> Prox == NULL){
		printf("Não foi possivel retirar esse item da lista.\n");
		return;
	}
	q = retorno -> Prox;
	Item = q -> Item;
	retorno -> Prox = q -> Prox;
	if(retorno -> Prox == NULL){
		Fila -> Tras = retorno;
	}
	free(q);

     //Coloca no começo
     if(Vazia(*Fila)){
          printf("Erro fila esta vazia\n");
          return;
     }
     Fila -> Frente -> Ante = (TipoApontador) malloc(sizeof(TipoCelula));
     Fila -> Frente = Fila -> Frente -> Ante;
     Fila -> Frente -> Item = Item;
     Fila -> Frente -> Ante = NULL;
     Fila -> Frente -> Prox = Aux;
}

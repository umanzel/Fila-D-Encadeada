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

void FFVazia(TipoFila *Fila);
int Vazia(TipoFila Fila);
void Enfileira(TipoItem x, TipoFila *Fila);
void Desenfileira(TipoFila *Fila, TipoItem *Item);
void AumentaPrioridade(TipoFila *Fila, TipoItem *Item, TipoChave Chave);
void Imprime(TipoFila Fila);

int main(int argc, char *argv[]) {
     TipoFila fila;
     TipoItem item;
     TipoChave chave;
     int opcao = 0, aux;

     FFVazia(&fila);
     while(opcao != 6){

          printf("1-Lista Vazia 2-Enfileira 3-Desenfileira 4-Aumentar Prioridade 5-Imprimir 6-Sair\n");

          scanf("%d", &opcao);

          switch(opcao){

               case 1: FFVazia(&fila);
               break;

               case 2: scanf("%d", &aux);
               item.Chave = aux;
               Enfileira(item, &fila);
               break;

               case 3: Desenfileira(&fila, &item);
               break;

               case 4: scanf("%d", &aux);
               chave = aux;
               AumentaPrioridade(&fila, &item, chave);
               break;

               case 5: Imprime(fila);
               break;

          }
     }
     return 0;
}

void FFVazia(TipoFila *Fila) {
     Fila -> Frente = (TipoApontador) malloc(sizeof(TipoCelula));
     Fila -> Tras = Fila -> Frente;
     Fila -> Frente -> Prox = NULL;
     Fila -> Tras -> Ante = NULL;
}

int Vazia(TipoFila Fila) {
     int vazia = 0;
     if((Fila.Frente -> Prox = NULL) && (Fila.Tras -> Ante = NULL)){
          vazia = 1;
     }
     return (vazia);
}

void Enfileira(TipoItem x, TipoFila *Fila) {
     Fila -> Tras -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
     Fila -> Tras = Fila -> Tras -> Prox;
     Fila -> Tras -> Item = x;
     Fila -> Tras -> Prox = NULL;
}

void Desenfileira(TipoFila *Fila, TipoItem *Item) {
     TipoApontador q;
     if(Vazia(*Fila)){
          printf("Erro fila esta vazia\n");
          return;
     }
     q = Fila -> Frente;
     Fila -> Frente = Fila -> Frente -> Prox;
     *Item = Fila -> Frente -> Item;
     free(q);
}

void Imprime(TipoFila Fila, int direcao) {
     TipoApontador Aux;

     printf("\nProcessos na fila:\n");
     switch(direcao) {
          case 1:
          Aux = Fila.Frente -> Prox;
          while(Aux != NULL) {
               printf("%d\n", Aux -> Item.Chave);
               Aux = Aux -> Prox;
          }
          break;

          case 2:
          Aux = Fila.Tras -> Ante;
          while(Aux != NULL) {
               printf("%d\n", Aux -> Item.Chave);
               Aux = Aux -> Ante;
          }
          break;
     }
}

void AumentaPrioridade(TipoFila *Fila, TipoItem *Item, TipoChave Chave) {
     if(Vazia(*Fila)){
          printf("Erro fila esta vazia\n");
          return;
     }

}

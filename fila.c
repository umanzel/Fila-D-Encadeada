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

void FFVazia(TipoFila *Fila) {
     Fila -> Frente = (TipoApontador) malloc(sizeof(TipoCelula));
     Fila -> Tras = Fila -> Frente;
     Fila -> Frente -> Prox = NULL;
     Fila -> Tras -> Ante = NULL;
}

int Vazia(TipoFila Fila) {
     int vazia;
     if((Fila.Frente -> Prox = NULL) && (Fila.Tras -> Ante = NULL)){
          vazia = 1;
     }
     else{
          vazia = 0;
     }
     return (vazia);
}

void Enfileira(TipoItem x, TipoFila *Fila) {
     Fila -> Tras -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
     Fila -> Tras = Fila -> Tras -> Prox;
     // Fila -> Tras -> Ante = Fila -> Tras;
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

void Imprime(TipoFila Fila) {
     TipoApontador Aux;
     Aux = Fila.Frente -> Prox;
     printf("\nProcessos na fila:\n");
     while(Aux != NULL) {
          printf("%d\n", Aux -> Item.Chave);
          Aux = Aux -> Prox;
     }
}

int main(int argc, char *argv[]) {
     TipoFila fila;
     TipoItem item;

     FFVazia(&fila);

     return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct arv Arv;
struct arv {
  char info;
  struct arv* esq; 
  struct arv* dir; 
};

// Cria uma árvore vazia
Arv* arv_criavazia(void){
  return NULL;
}

// Cria uma árvore com o item do nó raiz e subárvores
Arv* arv_cria(char c, Arv* e, Arv* d){
  Arv* a = (Arv*)malloc(sizeof(Arv));
  a->info = c;
  a->esq = e;
  a->dir = d;
  return a;
}

// Verifica se a árvore está vazia (1) ou não (0)
int arv_vazia(Arv* a){
  return (a == NULL);
}

// Libera o espaço de memória ocupado pela árvore
Arv* arv_libera(Arv* a);

// Indica a ocorrência (1) ou não (0) do item "caracter c"
int arv_pertence(Arv* a, char c);

// Imprime as informações de um nó da árvore
void imprime(Arv* a){
  if(!arv_vazia(a)){
    printf("%c", a->info);
  }
}

// Imprime as informações dos nós da árvore
// void arv_imprime(Arv* a);

void arv_preordem (Arv* a);
void arv_inordem (Arv* a);
void arv_posordem (Arv* a);
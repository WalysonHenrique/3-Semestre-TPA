#include<stdio.h>
#include<stdlib.h>

typedef struct celula Celula;
struct celula{
    Arv* item;
    Celula* prox;
};

typedef struct lista Lista;
struct lista{
    Celula* head;
};

typedef struct arv Arv;
struct arv{
    Arv* esquerda;
    Arv* direita;
    int num;
};

Arv* arv_criavazia(void){
  return NULL;
}

Arv* arv_cria(int num, Arv* e, Arv* d){
  Arv* a = (Arv*)malloc(sizeof(Arv));
  a->num = num;
  a->esquerda = e;
  a->direita = d;
  return a;
}
Lista* iniciaLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    return lista;
}

void buscarItem(Arv* a, int item, Lista* lista){
    

    Arv* atual = a;

   
   while (atual != item)
   {
        Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
        if (lista->head == NULL)
        {
            lista->head = novaCelula;
            novaCelula->item = atual;
            novaCelula->prox = NULL;
        }

        novaCelula->item = atual; 




   }
   
   
}





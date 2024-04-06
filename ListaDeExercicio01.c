#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//criando struct do tipo aluno
//      nome struct / tipo da struct
typedef struct aluno Aluno;
struct aluno{
    int numeros;
};

typedef struct celula Celula;
struct celula{
    Celula* prox;
    Celula* ant;
    Aluno* item;
};

typedef struct lista Lista;
struct lista{
    Celula* prim;
    Celula* ult;
};



//Questão 6 ############################################################
/*
int ordenada(Lista* lista)
{
   
    if(lista->prim = NULL){
        return 0;
    }

    Celula* maior = lista->prim;
    Celula* atual = lista->prim->prox;
    
    while (atual != NULL)
    {
        if(atual->item->numeros < maior->item->numeros)
        {
            return 0;
        }
    atual = atual->prox;
    maior = maior->prox;
    }
    return 1;
}
*/

//Questão 7 ############################################################
/*
Lista* inverter(Lista* lista){
    Celula* atual = lista->prim;
    Lista* lista2;
    if(lista->prim = NULL){
        return 1;
    }
    while (atual != NULL)
    {
        Celula* novaCelula = (Lista*)malloc(sizeof(Lista));
        novaCelula->item = atual->item;
        novaCelula->prox = NULL;

        if(lista2->prim == NULL){
            lista2->prim = novaCelula;
            lista2->ult = novaCelula;
        }else{
            novaCelula->prox = lista2->prim;
            lista2->prim = novaCelula;
        }
        atual = atual->prox;
    }
    return lista2;
}
*/
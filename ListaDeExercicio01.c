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


typedef struct fila Fila;
struct fila{
    Celula* prim;
    Celula* ult;
};



//Questão 6 ############################################################
/*
int ordenada(Lista* lista)
{
   
    if(lista->prim = NULL){
        return 1;
    }

    Celula* maior = lista->prim;
    Celula* atual = lista->prim->prox;
    
    while (atual != NULL)
    {
        if(atual->item->numeros < maior->item->numeros)
        {
            return 1;
        }
    atual = atual->prox;
    maior = maior->prox;
    }
    return 0;
}
*/

//Questão 7 ############################################################
/*
Lista* inverter(Lista* lista){
    Celula* atual = lista->prim;
    Lista* lista2 = (Lista*)malloc(sizeof(Lista));
    if(lista->prim = NULL){
        return 1;
    }
    while (atual != NULL)
    {
        Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
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


//Questão 8 ############################################################

Fila* intercala(Fila* f1, Fila* f2) {
    // Verifica se uma das filas esta vazia
    if (f1->prim == NULL || f2->prim == NULL) {
        printf("\nUma das filas está vazia\n");
        return 1;
    }

    // Inicializa a fila F3
    Fila* f3 = (Fila*)malloc(sizeof(Fila));
    if (f3 == NULL) {
        return 1;
    }
    f3->prim = f3->ult = NULL;

    Celula* auxF1 = f1->prim;
    Celula* auxF2 = f2->prim;

    // Intercala os elementos de F1 e F2 para F3
    while (auxF1 != NULL && auxF2 != NULL) {
        // Adiciona o elemento de F1 a F3
        Celula* novaCelula1 = (Celula*)malloc(sizeof(Celula));
        if (novaCelula1 == NULL) {
            return 1;
        }
        novaCelula1->item = auxF1->item;
        novaCelula1->prox = NULL;
        if (f3->ult == NULL) {
            f3->prim = novaCelula1;
            f3->ult = novaCelula1;
        } else {
            f3->ult->prox = novaCelula1;
            f3->ult = novaCelula1;
        }

        // Adiciona o elemento de F2 a F3
        Celula* novaCelula2 = (Celula*)malloc(sizeof(Celula));
        if (novaCelula2 == NULL) {
            return 1;
        }
        novaCelula2->item = auxF2->item;
        novaCelula2->prox = NULL;
        f3->ult->prox = novaCelula2;
        f3->ult = novaCelula2;

        // Avança para a proxima celula em F1 e F2
        auxF1 = auxF1->prox;
        auxF2 = auxF2->prox;
    }

    // Adiciona os elementos restantes de F1 a F3
    while (auxF1 != NULL) {
        Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
        if (novaCelula == NULL) {
            return 1;
        }
        novaCelula->item = auxF1->item;
        novaCelula->prox = NULL;
        f3->ult->prox = novaCelula;
        f3->ult = novaCelula;
        auxF1 = auxF1->prox;
    }

    // Adiciona os elementos restantes de F2 a F3
    while (auxF2 != NULL) {
        Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
        if (novaCelula == NULL) {
            return 1;
        }
        novaCelula->item = auxF2->item;
        novaCelula->prox = NULL;
        f3->ult->prox = novaCelula;
        f3->ult = novaCelula;
        auxF2 = auxF2->prox;
    }

    return f3;
}



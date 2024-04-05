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



int ordenada(Lista* lista)
{
    int verificador = 1;
    
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
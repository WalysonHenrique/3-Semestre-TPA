#include <stdio.h>
#include <stdlib.h>


typedef struct aluno Aluno;
struct aluno
{
    int matricula
};

typedef struct celula Celula;
struct celula{
    Celula* prox;
    Aluno* item;
};

typedef struct pilha Pilha;
struct pilha
{
    Celula* topo;
    Celula* fundo;
};

Pilha* iniciaLista(){
    Pilha* novaPilha = (Pilha*)malloc(sizeof(Pilha));
    novaPilha-> topo = NULL;
    novaPilha-> fundo = NULL;
    return novaPilha;
}



Aluno* criaAluno(int matricula){
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    novoAluno -> matricula = matricula;

    return novoAluno;
}


Pilha* insereAluno(Pilha* pilha, Aluno* novoAluno){
    //cria uma nova celula
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
    novaCelula->item = novoAluno;
    novaCelula->prox = NULL;
    //verifica se a lista esta vazia
    if(pilha->fundo == NULL){
        pilha->topo = novaCelula;
        pilha->fundo = novaCelula;
        return pilha;
    }
    else{
        //aponta o ponteiro prox para a celula existente
        novaCelula->prox = pilha->topo;
        //aponta o ponteiro topo para a nova celula
        pilha->topo = novaCelula;
        return pilha;
    }
}


Aluno* pop(Pilha* pilha){
    Celula* itemSalvo;
    Celula* celulaAtual = pilha->topo;
    itemSalvo = celulaAtual->item;

    pilha->topo = pilha->topo->prox;

    free(celulaAtual);

    return itemSalvo;

}







#include <stdio.h>
#include <stdlib.h>

typedef struct aluno Aluno;
struct aluno
{
    int matricula;
};

typedef struct celula Celula;
struct celula{
    Celula* prox;
    Aluno* item;
};


typedef struct fila Fila;
struct fila{
    Celula* prim;
    Celula* ult;
};


Aluno* criaAluno(int mat){
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));

    novoAluno->matricula = mat;

    return novoAluno;
}



Fila* iniciaFila(){
    Fila* novaFila = (Fila*)malloc(sizeof(Fila));
    novaFila->prim = NULL;
    novaFila->ult = NULL;
    return novaFila;
}


Fila* insereAluno(Aluno* aluno, Fila* fila){
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
    novaCelula->item = aluno;
    novaCelula->prox = NULL;

    if(fila->ult == NULL){
        fila->prim = novaCelula;
        fila->ult = novaCelula;
        //printf("{{%d}}", fila->prim->item->matricula);
        return fila;
    }

    fila->ult->prox = novaCelula;
    fila->ult = novaCelula;

    //printf("[[%d]]", fila->prim->item->matricula);
    return fila;
}


Aluno* pop(Fila* fila){
    Aluno* sentinela;
    Celula* atual;
    atual = fila->prim;

    if(fila->ult == NULL){
        printf("Nenhum dado");
        return NULL;
    }

    sentinela = fila->prim->item;

    fila->prim = fila->prim->prox;
    free(atual);
    return sentinela;
}



int main(void){
    Fila* fila = iniciaFila();
    
    int matricula = 10; 
    
    insereAluno(criaAluno(matricula), fila);
    
    Aluno* alunoRetirado = pop(fila);
    printf("\n(%d)\n", alunoRetirado->matricula);
    
    return 0;


}
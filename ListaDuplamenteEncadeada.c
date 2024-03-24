#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//criando struct do tipo aluno
//      nome struct / tipo da struct
typedef struct aluno Aluno;
struct aluno{
    char* nome;
    int matricula;
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
Aluno* criaAluno(char* nome, int matricula){
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    novoAluno -> matricula = matricula;
    novoAluno -> nome = strdup(nome);
    return novoAluno;
}

char* recuperarNome(Aluno* item){
    char* nome = item->nome;
    return nome;
}


void imprimir(Aluno* item){
    printf("Nome : %sMatricula: %i\n", recuperarNome(item), item->matricula);
}

void exclui(Aluno* aluno){
    free(aluno);
}



//função que inicializa a lista vazia
Lista* iniciaLista(){
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista-> prim = NULL;
    novaLista-> ult = NULL;
    return novaLista;
}

//inserir um novo aluno na ultima posicao da lista
Lista* insereAlunoUlt(Lista* lista, Aluno* novoAluno){
    //cria uma nova celula
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
    novaCelula->item = novoAluno;
    novaCelula->prox = NULL;
    novaCelula->ant = NULL;
    //verifica se a lista esta vazia
    if(lista->ult == NULL){
        //aponta o primeiro ponteiro para a nova celula
        lista->prim = novaCelula;
        //aponta o ultimo ponteiro para a nova celula
        lista->ult = novaCelula;
        return lista;
    }
    else{
        //aponta o ponteiro prox da ultima celula para a nova celula, antes ele apontava para null
        lista->ult->prox = novaCelula;
        //aponta o ponteiro ant para a ultima celula
        novaCelula->ant = lista->ult;
        //aponta o ponteiro ultimo para essa nova celula
        lista->ult = novaCelula;
        
        return lista;
    }
}

// insere um aluno na primeira posiçao da lista
Lista* insereAlunoPri(Lista* lista, Aluno* novoAluno){
    //cria uma nova celula
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
    novaCelula->item = novoAluno;
    novaCelula->prox = NULL;
    novaCelula->ant = NULL;
    //verifica se a lista esta vazia
    if(lista->ult == NULL){
        //aponta o primeiro ponteiro para a nova celula
        lista->prim = novaCelula;
        //aponta o ultimo ponteiro para a nova celula
        lista->ult = novaCelula;
        return lista;
    }
    else{
        //aponta o ponteiro ant da celula existente para a nova celula;
        lista->prim->ant = novaCelula;
        //aponta o ponteiro prox para a primeira celula que ja existia
        novaCelula->prox = lista->prim;
        //aponta o ponteiro ultimo para essa nova celula
        lista->prim = novaCelula;
        return lista;
    }
}


//retira aluno por nome
int retiraAluno(Lista* lista, char* nomePassado){
    Celula* atual = lista->prim;
    Celula* celulaAnterior = NULL;

    //verifica se a lista esta vazia
    if(atual == NULL)
    {
        return 1;
    }

    //verifica se o aluno buscado e o primeiro da lista
    if(strcmp(atual->item->nome, nomePassado)==0){

        //aponta o pont prim para a prox celula, que se torna a nova primeira celula
        lista->prim = lista->prim->prox;

        //verifica se a celula era unica na lista
        if(lista->ult == atual){
            lista->ult = NULL;
        }
        free(atual->item);
        free(atual);
        return 0;
    }


    //caso ele nao seja o primeiro :

    while (atual != NULL && strcmp(atual->item->nome, nomePassado)!=0)
    {
        celulaAnterior = atual;
        atual = atual->prox;
    }
    

    //se o aluno nao foi encontrado
    if(atual == NULL)
    {
        return 1; 
    }

    //caso ele esteja no meio da lista
    if(atual->prox != NULL){

    //aponta o prox do anterior para o proximo pulando a celula atual
    atual->ant->prox = atual->prox;

    //aponta o ponteiro ant do proximo para o anterior pulando o atual
    atual->prox->ant = atual->ant;

    //libera os itens
    free(atual->item);
    free(atual);
    return 0;
    }

    //caso ele seja o ultimo da lista
    if(atual->prox == NULL)
    {
        lista->ult = atual->ant;
        atual->ant->prox = NULL;
        free(atual->item);
        free(atual);
    }


    
}

//imprime a lista
void imprimeLista(Lista* lista){
    Celula* atual = lista->prim;
    while (atual != NULL)
    {
        // printf("Nome : (%s)\nMatricula : %d\n", atual->item->nome, atual->item->matricula);
        imprimir(atual->item);
        printf("=================================\n");
        atual = atual->prox;
    }
    
    
}

void liberaLista(Lista* lista){
    free(lista);
}

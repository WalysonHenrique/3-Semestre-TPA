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

Aluno* criaAluno(char* nomePassado, int matricula){
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    novoAluno -> matricula = matricula;
        novoAluno->nome = strdup(nomePassado);

    return novoAluno;
}

char* recuperarNome(Aluno* item){
    char* nome = item->nome;
    return nome;
}


void imprimir(Aluno* item){
    printf("Nome : %sMatricula: %i\n", recuperarNome(item), item->matricula);
}

void exclui(Aluno* item){
    free(item);
}

typedef struct celula Celula;
struct celula{
    Celula* prox;
    Aluno* item;
};

typedef struct lista Lista;
struct lista{
    Celula* prim;
    Celula* ult;
};

//função que inicializa a lista vazia
Lista* iniciaLista(){
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista-> prim = NULL;
    novaLista-> ult = NULL;
    return novaLista;
}

//inserir um novo aluno na ultima posicao da lista
Lista* insereAluno(Lista* lista, Aluno* novoAluno){
    //cria uma nova celula
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
    novaCelula->item = novoAluno;
    novaCelula->prox = NULL;
    //verifica se a lista esta vazia
    if(lista->ult == NULL){
        lista->prim = novaCelula;
        lista->ult = novaCelula;
        return lista;
    }
    else{
        lista->ult->prox = novaCelula;
        lista->ult = novaCelula;
        return lista;
    }
}


//retira aluno por nome;
int retiraAluno(Lista* lista, char* nomePassado) {
    Celula* atual = lista->prim;
    Celula* anterior = NULL;

    // Verifica se a lista está vazia
    if (atual == NULL) {
        return 1; // Lista vazia, nada a fazer
    }

    // Verifica se o primeiro aluno da lista é o procurado
    if (strcmp(atual->item->nome, nomePassado) == 0) {
        lista->prim = atual->prox; // Atualiza o ponteiro do primeiro aluno
        if (lista->ult == atual) {
            lista->ult = NULL; // Se a lista tinha apenas um aluno
        }
        exclui(atual->item); // Libera a memória do aluno
        free(atual); // Libera a memória da célula
        return 0; // Aluno removido com sucesso
    }

    // Percorre a lista em busca do aluno
    while (atual != NULL && strcmp(atual->item->nome, nomePassado) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se o aluno não foi encontrado
    if (atual == NULL) {
        return 1; // Aluno não encontrado
    }

    // Remove o aluno da lista
    anterior->prox = atual->prox;
    if (atual == lista->ult) {
        lista->ult = anterior;
    }
    exclui(atual->item); // Libera a memória do aluno
    free(atual); // Libera a memória da célula
    return 0; // Aluno removido com sucesso
}


//imprime a lista
void imprimeLista(Lista* lista){
    Celula* atual = lista->prim;
    while (atual != NULL)
    {
        //printf("Nome : (%s)\nMatricula : %d\n", atual->item->nome, atual->item->matricula);
        imprimir(atual->item);
        printf("=================================\n");
        atual = atual->prox;
    }
}

void liberaLista(Lista* lista){
    free(lista);
}
/*

int main(){
    Lista* minhaLista;
    char* nome;
    int matricula;

    minhaLista = iniciaLista();

    printf("Digite primeiro o nome do aluno\n");
    fgets(nome, 20, stdin);
    printf("Digite agora a matricula\n");
    scanf("%d", &matricula);

    //criaAluno retorna o aluno criado que serve de parametro para a fun inserirAluno
    //que insere esse aluno na lista
    inserirAluno(minhaLista, criaAluno(nome, matricula));

    imprimeLista(minhaLista);

    return 0;
}*/
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
    novoAluno -> nome = nome;
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
Lista* inserirAluno(Lista* lista, Aluno* novoAluno){
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


//retira aluno por nome
int retiraAluno(Lista* lista, char* nomePassado){
    Celula* atual = lista->prim;

    while (atual != NULL)
    {
        //compara o nome que esta dentro da lista com o
        //nome fornecido por parametro
        if (strcmp(atual->item->nome, nomePassado)==0)
        {
            exclui(atual->item);
            free(atual);
        }
        
        atual = atual->prox;
    }
    
}

//imprime a lista
void imprimeLista(Lista* lista){
    Celula* atual = lista->prim;
    do
    {
        imprimir(atual->item);
        atual = atual->prox;
    } while (atual != lista->prim);
    
}

void libera(Lista* lista){
    free(lista);
}


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
}
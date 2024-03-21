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


//retira aluno por nome;
int retiraAluno(Lista* lista, char* nomePassado){
    Celula* atual = lista->prim;

    //verifica se o nome passado é igual ao nome apontado por atual;
    //se o nome buscado for o primeiro;
    if(strcmp(atual->item->nome, nomePassado)==0){
            //se for, ele exclui os itens;
            exclui(atual->item);
            //aponta o prim para prox;
            lista->prim = lista->prim->prox;
            //se o prim for null;
            //aponta o ultimo para null tambem;
            if(lista->prim == NULL){
                lista->ult = NULL;
            }
            //libera a celula atual;
            free(atual);
            //e retorna 0, finalizando a função;
            return 0;
        }


    //caso o nome buscado nao seja o primeiro;
    while (atual != NULL)
    {
        //compara o nome que esta dentro da lista com o;
        //nome fornecido por parametro;
        

        //verifica se o item da proxima celula apontada por atual é o nome buscado;
        if (strcmp(atual->prox->item->nome, nomePassado)==0)
        {
            //exclui os itens;
            exclui(atual->prox->item);
            //cria um ponteiro para celula auxiliar que armazena a posição do proximo;
            Celula* aux = atual->prox;
            //aponta a celula do proximo para o proximo cel1-> cel2-> cel3-> ;
            //                                          cel1-> -----> cel3->;
            atual->prox = atual->prox->prox;
            //libera a celula atual;
            free(aux);
            //verifica se o ponteiro prox da celula atual esta apontando para null;
            //se estiver ele aponta o ponteiro ult para atual;
            if(atual->prox == NULL) lista->ult = atual;
            //retorna 0 para finalizar a fun;
            return 0;
        }
        
        atual = atual->prox;
    }
    return 1;
    
}

//imprime a lista
void imprimeLista(Lista* lista){
    Celula* atual = lista->prim;
    while (atual != NULL)
    {
        imprimir(atual->item);
        atual = atual->prox;
    }
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
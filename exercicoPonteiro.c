#include <stdio.h>
#include <stdlib.h>

//cria o conjunto de dados em si
typedef struct Numero {
    int num;
} Numero;

//encapsula o conjunto de dados anterior
typedef struct Celula {
    struct Celula* prox;
    Numero* item;
} Celula;

//cria o meu head, para navegar entre as celulas
typedef struct Lista {
    Celula* primeiro;
    Celula* ultimo;
} Lista;

//inicia uma lista vazia
Lista* iniciaLista() {
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista->primeiro = NULL;
    novaLista->ultimo = NULL;
    return novaLista;
}

void inserirNum(Lista* lista, int numero) {
    Numero* novoNum = (Numero*)malloc(sizeof(Numero));
    novoNum->num = numero;
    
    //aloca memoria para uma celula
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
    novaCelula->item = novoNum;
    novaCelula->prox = NULL;

    if (lista->primeiro == NULL) {
        lista->primeiro = novaCelula;
        lista->ultimo = novaCelula;
    } else {
        lista->ultimo->prox = novaCelula;
        lista->ultimo = novaCelula;
    }
}

void imprimeLista(Lista* lista) {
    Celula* atual = lista->primeiro;

    while (atual != NULL) {
        printf("%d\n", atual->item->num);
        atual = atual->prox;
    }
}

int main(void) {
    int choose;
    int numero;
    Lista* lista = iniciaLista();

    while (1) {
        printf("Escolha 1 para inserir, ou 2 para listar, ou qualquer outro numero para sair: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                inserirNum(lista, numero);
                break;

            case 2:
                imprimeLista(lista);
                break;

            default:
            
                free(lista);
                return 0;
        }
    }

    return 0;
}

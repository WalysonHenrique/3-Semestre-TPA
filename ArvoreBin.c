#include <stdio.h>
#include <stdlib.h>

typedef struct arv Arv;
struct arv
{
  int numero;
  struct arv *esq;
  struct arv *dir;
};

// Cria uma árvore vazia
Arv *arv_criavazia(void)
{
  Arv *arv = (Arv *)malloc(sizeof(Arv));
  return arv;
}

// Cria uma árvore com o item do nó raiz e subárvores
Arv *arv_cria(int numero)
{
  Arv* novoNo = (Arv*)malloc(sizeof(Arv));
  novoNo->numero = numero;
  novoNo->dir = NULL;
  novoNo->esq = NULL;
  return novoNo;
}



//insere um no na estrutura da arvore
Arv* insere(Arv* arv, Arv* novoNo) {
    if (arv == NULL) {
        // Se a árvore está vazia, o novo nó se torna a raiz.
        return novoNo;
    }

    Arv* aux = arv;
    Arv* pai = NULL;

    // Encontra o local apropriado para o novo nó.
    while (aux != NULL) {
        pai = aux;
        if (novoNo->numero < aux->numero) {
            aux = aux->esq;
        } else {
            aux = aux->dir;
        }
    }

    // Insere o novo nó à esquerda ou à direita do nó pai.
    if (novoNo->numero < pai->numero) {
        pai->esq = novoNo;
    } else {
        pai->dir = novoNo;
    }

    return arv;
}

// Verifica se a árvore está vazia (1) ou não (0)
int arv_vazia(Arv *a)
{
  return (a == NULL);
}


Arv *arv_libera(Arv *a)
{
  if (a != NULL)
  {
    arv_libera(a->esq);
    arv_libera(a->dir);
    free(a);
  }
  return NULL;
}


void imprime(Arv *a)
{
  if (!arv_vazia(a))
  {
    printf("%c", a->numero);
  }
}

// aqui o programa imprime a raiz primeiro depois a esquerda e por fim a direita
void arv_preordem(Arv *a)
{

  if (a != NULL)
  {
    printf("%d ", a->numero);
    arv_preordem(a->esq);
    arv_preordem(a->dir);
  }
}
// aqui o programa imprime primeiro a esquerda depois a raiz e por fim a direita
void arv_inordem(Arv *a)
{
  if (a != NULL)
  {
    arv_inordem(a->esq);
    printf("%d ", a->numero);
    arv_inordem(a->dir);
  }
}
// aqui o programa imprime primeiro a esquerda depois a direita e por ultimo a raiz
void arv_posordem(Arv *a)
{
  if (a != NULL)
  {
    arv_posordem(a->esq);
    arv_posordem(a->dir);
    printf("%c ", a->numero);
  }
}

Arv* removeNo(Arv* arv, int numero) {

    if (arv == NULL) {
        return NULL; 
    }


    //caso o num a ser removido seja menor q o no atual, ele vai pra sub arv esquerda
    if (numero < arv->numero) {
        arv->esq = removeNo(arv->esq, numero);
    }
    //caso o num a ser removido seja maior q o no atual, vai para sub arv direita
    else if (numero > arv->numero) {
        arv->dir = removeNo(arv->dir, numero);
    }

    else {
        //caso ele seja uma folha
        if (arv->esq == NULL && arv->dir == NULL) {
            free(arv);
            return NULL;
        }

        //caso tenha um filho
        else if (arv->esq == NULL) {
            Arv* temp = arv->dir;
            free(arv);
            return temp;
        }
        else if (arv->dir == NULL) {
            Arv* temp = arv->esq;
            free(arv);
            return temp;
        }

        //caso tenha 2 filhos
        else {
            
            Arv* temp = arv->dir;
            while (temp->esq != NULL) {
                temp = temp->esq;
            }

            
            arv->numero = temp->numero;

            
            arv->dir = removeNo(arv->dir, temp->numero);
        }
    }

    return arv;
}

void buscar(int numBuscado, Arv* raiz) {
    Arv* aux = raiz;
    while (aux != NULL) {
        if (aux->numero == numBuscado) {
            printf("numero %d encontrado!\n", aux->numero);
            return;  //sai da fun apos achar o num
        } else if (numBuscado > aux->numero) {
            aux = aux->dir;
        } else {
            aux = aux->esq;
        }
    }
    //caso n encontre o num
    printf("numero nao encontrado \n");
}



int main() {
    Arv* raiz = NULL;

    raiz = insere(raiz, arv_cria(50));
    raiz = insere(raiz, arv_cria(30));
    raiz = insere(raiz, arv_cria(70));
    raiz = insere(raiz, arv_cria(20));
    raiz = insere(raiz, arv_cria(40));
    raiz = insere(raiz, arv_cria(60));
    raiz = insere(raiz, arv_cria(80));

  
    printf("arvore em ordem antes da remocao: ");
    arv_inordem(raiz);
    printf("\n");
    
    raiz = removeNo(raiz, 20);
    raiz = removeNo(raiz, 30);
    raiz = removeNo(raiz, 50);

    printf("arvore em ordem apos a remocao: ");
    arv_inordem(raiz);
    printf("\n");

    buscar(40, raiz);

    return 0;
}

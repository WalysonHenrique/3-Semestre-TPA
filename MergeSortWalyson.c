#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define chave(a) (a)

#define menor(a, b) (chave(a) < chave(b))

#define troca(a, b) {Item t;t = a;a = b;b = t;};

#define comp_troca(a , b) if (menor(b , a)) troca(a , b)

void InsertionSort(Item *a, int inicio, int fim)
{

    // imprime a lista antes de ordenada
    for (int i = 0; i < fim; i++)
    {
    }
    // inicio um for externo onde o inteiro i recebe o valor inicial, no caso 0, que dura ate o fim - 1,
    // pois como o i vai ser a variavel que esta na posição anterior a j,
    // ele nao pode percorrer ate o ultimo, pois j recebe i + 1
    for (int i = inicio; i < fim - 1; i++)
    {

        // inicio um for interno com j valendo i + 1, para depois poder
        // comparar j-1 com j, e enquanto j > inicio, ele percorre a array
        // comparando j-1 com j, e realizando a troca se j for menor que j-1
        for (int j = i + 1; j > inicio; j--)
        {
            // utilizo de callbacks implementados no iniciodo algoritmo
            // para comparar e trocar os valores do vetor [a]
            comp_troca(a[j - 1], a[j]);
        }
    }
}

void merge(Item *a, Item *aux, int inicio, int meio, int fim)
{
    for (int k = inicio; k <= fim; k++) // Faz copia do array
        aux[k] = a[k];

    int i = inicio, j = meio + 1;
    for (int k = inicio; k <= fim; k++)
    {
        // Faz o merge
        if (i > meio)
            a[k] = aux[j++];

        else if (j > fim)
            a[k] = aux[i++];

        else if (menor(aux[j], aux[i]))
            a[k] = aux[j++];

        else
            a[k] = aux[i++];
    }
}

void merge_sort(Item *a, Item *aux, int inicio, int fim, int cutoff)
{
    // verifica se a lista foi cortada até conter um elemento e retorna ela
    if (fim <= inicio) return;

    if (cutoff == 1 && fim < 10)
    {
        // ordeno o vetor caso ele tenha menos que 11 numeros
        // função cutoff
        InsertionSort(a, inicio, fim);
    }

    // armazena a posiçao do meio do vetor
    int meio = inicio + (fim - inicio) / 2;

    // divide a promeira parte do vetor ao meio, de forma recursiva
    merge_sort(a, aux, inicio, meio, cutoff);

    // divide a segunda parte do vetor ao meio de forma recursiva
    merge_sort(a, aux, meio + 1, fim, cutoff);

    // realiza o merge das pequenas partes dos vetores
    merge(a, aux, inicio, meio, fim);
}

//função principal
void sort(Item *a, int inicio, int fim, int cutoff) {
    int n = (fim - inicio) + 1;
    Item *aux = malloc(n * sizeof(Item));
    merge_sort(a, aux, inicio, fim, cutoff);
    free(aux);
}

/*
Walyson Henrique Ozorio Sobrinho
20231stads005



##########################################################


Abaixo casos com 100 milhoes de numeros


##########################################################



Sem cutoff 100 milhoes de numeros :
16.9237


Com cutoff com fim < 10 utilizando 100 milhoes de numeros :
16.9951

Um cutoff com fim < 20 :
16.9041

Um cutoff com fim < 30 :
Tempo de execução: 16.9055 segundos



Um cutoff com fim <= 50 :

16.9320 segundos


Um cutoff com fim <= 70 : 
Tempo de execução: 16.9208 segundos

######################################################


Abaixo casos com 500 milhoes de numeros


######################################################



Um cutoff com fim <= 70 : 
500 milhoes de numeros

Tempo de execução: 115.1179 segundos

Um cutoff com fim < 10 : 
10 milhoes

Tempo de execução: 1.5555 segundos

1 milhao
Tempo de execução: 0.1391 segundos

100 mil
Tempo de execução: 0.0126 segundos



Sem cutoff : 
10 milhoes 
Tempo de execução: 1.5498 segundos

1 milhao
Tempo de execução: 0.1397 segundos




100 mil 
Tempo de execução: 0.0126 segundos


#################################################
#################################################


Apesar do cutoff na teoria ser bem eficiente, ao lidar com quantidades enormes de numeros é viavel analisar
a melhor forma de implementar-lo, utilizando por exemplo uma condiçao maior, no caso fim < {numeros maiores}
*/
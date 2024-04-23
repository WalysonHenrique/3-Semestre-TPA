#include <time.h>
typedef int Item;

#define chave(a) (a)

#define menor(a,b) (chave(a) < chave(b))

#define troca(a,b) {Item t; t = a; a = b; b = t;}


void merge(Item* a,  Item* aux, int inicio, int meio, int fim){
 

}



void merge_sort(Item* a, Item* aux, int inicio, int fim){
    //verifica se a lista foi cortada até conter um elemento e retorna ela
    if(fim <= inicio) return;

    if(fim < 10){
        //implementar a funçao cutoff com insertionSort
    }

    //armazena a posiçao do meio do vetor
    int meio = inicio + (fim - inicio)/2;

    //divide a promeira parte do vetor ao meio, de forma recursiva
    merge_sort(a, aux, inicio, meio);

    //divide a segunda parte do vetor ao meio de forma recursiva
    merge_sort(a, aux, meio+1, fim);

    //realiza o merge das pequenas partes dos vetores
    merge(a, aux, inicio, meio, fim);


}
















void sort(Item* a, int inicio, int fim, int cutoff){

}
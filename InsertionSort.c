#include <stdio.h>
// estou criando um tipo de variavel Item,
// que sera interpertado como inteiro pelo compilador
typedef int Item;

// retorno o valor de a
#define chave(a) (a)

// defino um macro para comparar se o valor retornado por chave(a)
// eh menor que o valor retornado por chave(b)
#define menor(a , b) (chave(a) < chave(b))

//defino um macro que troca os valores de {a} e {b} 
//utilizando uma variavel {t} do tipo Item 
#define troca(a , b) {Item t = a; a = b; b = t;}

// defino uma macro que realiza a troca dos valores de forma condicional
// utilizando outras macros previamente definidas
#define comp_troca(a , b) if (menor(b , a)) troca(a , b)

// crio uma fun do tipo void que recebe um ponteiro para Item, 
// um valor inteiro que eh o valor inicial que indica nesse caso, a primeira casa do vetor
// e um valor final que indica a quantidade de elementos no vetor
void sort(Item* a, int inicio, int fim){

    // imprime a lista antes de ordenada
    for(int i = 0; i < fim; i++){
        printf("Antes [%d]\n", a[i]);
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
            comp_troca(a[j-1], a[j])
        }
        
    }
    // melhorando a visualização
    printf("\n\n");

    // printando a lista depois de ordenada
    for(int i = 0; i < fim; i++){
        printf("Depois [%d]\n", a[i]);
    }


}

// testando a fun implementada
int main(void){

    //  exemplo teste
    int vetor[7] = {32,1,8,2,11,5,4};

    sort(vetor, 0, 7);
    return 0;
}

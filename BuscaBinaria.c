#include <stdio.h>

int binarySearch()
{
    int lista[] = {1,2,3,4,5,6,7,8,9,11};
    int size = 10;
    int key = 7;

    //cria uma variavel do tamanho -1 para abrangir desde a posição 0 ate a posição 99

    int e = -1, d = size;

    //enquanto 
    while (e < d - 1)
    {
        //e = -1 ↓            m↓        key↓              10 ↓d
        //        {1} {2} {3} {4} {5} {6} {7} {8} {9} {11}

        


        int m = ((e + d )/ 2);
        //(-1 + 10)/2 = 4 

        //verifica se 4 eh menor que o num buscado


        if (lista[m] < key)
        //se for e recebe 4 e itera novaemete pelo while



            e = m;
        else
        {
            //caso nao, ele atribui o 4 a d e itera novamente
            d = m;
        }
        
    }
    
    return d;
}




/*
int binarySearch(int lista[], int size, int key) {
    int e = 0, d = size - 1; // Corrigindo a inicialização de 'e' e 'd'

    while (e <= d) {
        int m = e + (d - e) / 2;

        if (lista[m] == key)
            return m;
        else if (lista[m] < key)
            e = m + 1;
        else
            d = m - 1;
    }

    return -1; // Retorna -1 se a chave não for encontrada
}

*/

int main(void){

    
    int lista[10] = {1,2,3,4,5,6,7,8,9,11};

    int key = 7;

    printf("\n[%d]\n", binarySearch());


    return 0;
}


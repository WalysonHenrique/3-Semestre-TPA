#include <stdio.h>

int binarySearch(int list[], int size, int key){
    int e = -1, d = size;
    while (e < d - 1){
        int m = (e + d) / 2;
        if (list[m] < key){
            e = m;
        }
        else{
            d = m;
        }
    }
    if (list[d] == key){
        return list[d];
    }
    return -1;
}

int main(void){
    int lista[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    int key = 7;
    printf("\n[%d]\n", binarySearch(lista, 10, 13));
    return 0;
}
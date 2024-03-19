#include <stdio.h>
#include <stdlib.h>


#define RET 0
#define TRI 1
#define CIR 2


typedef struct retangulo Retangulo;
struct retangulo{
    float base, altura;
};

typedef struct triangulo Triangulo;
struct triangulo{
    float base, altura;
};

typedef struct circulo Circulo;
struct circulo{
    float raio;
};




typedef struct celula Celula;
struct celula{
    Celula* prox;
    Celula* ant;
    int tipo;
    void* item;
};

typedef struct lista Lista;
struct lista{
    Celula* prim;
    Celula* ult;
};


Celula* criar_cel_ret (float b, float h){
    Retangulo* novoRet = (Retangulo*)malloc(sizeof(Retangulo));
    novoRet->base = b;
    novoRet->altura = h;

    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
    
    novaCelula->item = (Retangulo*)novoRet;
    novaCelula->tipo = RET;
    novaCelula->prox = NULL;
    novaCelula->ant = NULL;

    return novaCelula;
}

Celula* criar_cel_tri(float b, float h){
    Triangulo* novoTri = (Triangulo*)malloc(sizeof(Triangulo));
    novoTri->base = b;
    novoTri->altura = h;

    Celula* novaCelula = (Triangulo*)malloc(sizeof(Triangulo));

    novaCelula->item = (Triangulo*)novoTri;
    novaCelula->tipo = TRI;
    novaCelula->prox = NULL;
    novaCelula->ant = NULL;
    
    return novaCelula;
}


Celula* criar_cel_cir(float r){
    Circulo* novoCir = (Circulo*)malloc(sizeof(Circulo));
    novoCir->raio = r;

    Celula* novaCelula = (Circulo*)malloc(sizeof(Circulo));
    
    novaCelula->item = novoCir;
    novaCelula->tipo = CIR;
    novaCelula->prox = NULL;
    novaCelula->ant = NULL;

    return novaCelula;
}



int main(void){

    return 0;
}
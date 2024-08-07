#include<stdio.h>
/*

#########################################
#########################################
2. Sobre laços e vetores, responda:
a) Para que serve um vetor na linguagem C? Exemplifique criando um vetor de 5 inteiros que
armazene os valores de 1 a 5. Depois, mostre como se pode alterar o primeiro elemento para
o número 9.


int main(void){
int vetor[5] = {1,2,3,4,5};
printf("Antes %i\n", vetor[0]);
vetor[0] = 9;
printf("Depois %i\n", vetor[0]);
return 0;
}

#########################################
#########################################


b) Crie uma função que receba um vetor de floats, seu tamanho, e retorne a média simples
dos valores presentes nele. Ela deve ter o seguinde cabeçalho:
float media(float valores[], int tam);



float media(float valores[], int tam){
float soma = 0;
float resultado = 0;
	for(int i = 0; i < tam; i++){
		soma = soma + valores[i];
	}

	resultado = soma/tam;
	return resultado;
}


int main(){
float vetor[5] = {1,2,3,4,5};
printf("%.2f", media(vetor, 5));
return 0;
}

#########################################
#########################################

c) Crie uma função que receba um vetor de floats, seu tamanho, e retorne o menor valor
presente nele. Ela deve ter o seguinde cabeçalho:
float menor(float valores[], int tam);



float menor(float valores[], int tam){
float menorNum = 100;
	for(int i = 0; i < tam; i++){
	if(menorNum > valores[i]){
		menorNum = valores[i];
		}
	}
return menorNum;
}


int main(){
float vetor[5] = {1,2,3,-3,5};
printf("%.2f", menor(vetor, 5));
return 0;
}


#########################################
#########################################


d) Crie uma função que receba um vetor de floats, seu tamanho, e retorne o índice do maior
valor presente nele. Ela deve ter o seguinde cabeçalho:
int maior(float valores[], int tam);





int maior(float valores[], int tam){

int maiorNum = 0;
	for(int i = 0; i < tam; i++){
	if(maiorNum < valores[i]){
		maiorNum = valores[i];
		}
	}
return maiorNum;

}




int main(){
float vetor[5] = {1,2,3,-3,5};
printf("%i", maior(vetor, 5));
return 0;
}



#########################################
#########################################


e) Crie uma função que receba um vetor de floats, seu tamanho e um float x, e retorne
quantos valores do vetor são maiores que x. Ela deve ter o seguinde cabeçalho:
int maiores(float valores[], int tam, float x);




int maiores(float valores[], int tam, float x){
int contador = 0;
for(int i = 0; i < tam; i++){
	if(valores[i] > x){
		contador++;
		}
	}
return contador;
}


int main(){

float vetor[5] = {1,2,3,4,5};
printf("%i", maiores(vetor, 5, 1));
//o retorno no momento deve ser 4, pois existem 4 numeros maiores que um no vetor
return 0;
}

#########################################
#########################################


f) Crie um programa (main) que leia e armazene as temperaturas (float) de todos os dias da
semana em um vetor.




int main(){
float temperaturaSemana[7];

printf("Digite a temperatura dos dias da semana comecando por domingo :\n");

for(int i = 0; i < 7; i++){
	scanf("%f", &temperaturaSemana[i]);
}

printf("A temperatura dos dias da semana sao : ");

for(int i = 0; i < 7; i++){
	printf("\n%.2f\n", temperaturaSemana[i]);
}

return 0;
}

#########################################
#########################################



*/












































































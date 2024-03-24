#include <stdio.h>
#include "ListaDuplamenteEncadeada.c" // use o nome do arquivo que você implementou

int main(){
    int op = 0, matricula;
    char nome[100];

    Lista* lista = iniciaLista();
    Aluno* aluno;


    printf("1. Cadastrar um aluno\n2. Retirar um aluno por nome\n");
    printf("3. Imprimir todos os alunos\n4. Finalizar o programa");
    printf("\n\nDigite a operação desejada: ");
    scanf(" %d", &op);

    while(op!=4){
        switch (op){
        
        case 1:
            system("clear");
            getchar();
            printf("Digite o nome do aluno: ");
            fgets(nome, 100, stdin);
            //scanf(" %99[^\n]", nome);
            printf("Digite a matrícula do aluno: ");
            scanf(" %d", &matricula);

            //aluno = criaAluno(nome, matricula);
            lista = insereAlunoPri(lista, criaAluno(nome, matricula));
            
            break;
        
        case 2:
            system("clear");
            getchar();
            printf("Digite o nome do aluno a ser retirado da lista: ");
            fgets(nome, 100, stdin);

            if(retiraAluno(lista, nome) == 0) printf("Aluno %s retirado com sucesso\n", nome);
            else printf("O aluno %s não existe\n", nome);
            
            break;
        
        case 3: 
            printf("-------------------- Lista de alunos --------------------\n");
            imprimeLista(lista);

            break;
        
        default:
            printf("Operação inválida, tente novamente\n");
            break;
        }

        printf("\n\n1. Cadastrar um aluno\n2. Retirar um aluno por nome\n");
        printf("3. Imprimir todos os alunos\n4. Finalizar o programa");
        printf("\n\nDigite a operação desejada: ");
        scanf(" %d", &op);

    }
    
    liberaLista(lista);
    return 0;
}
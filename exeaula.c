/*Crie uma struct para representar os alunos de Algoritmos e Programação II no segundo semestre de 2024. 
Escreva um programa que mantém um conjunto de alunos (no máximo 50) e forneça para o usuário as seguintes opções:
cadastrar um novo aluno - criar funcao
remover um aluno através do RGA - criar funcao
atualizar notas de um aluno através do RGA - criar funcao
exibir o nome, as três notas e a MA de todos os alunos aprovados na disciplina, ordenados por nome. (criar uma funcao para imprimir e outra para ordenar)
exibir o nome, as três notas e a MA de todos os alunos reprovados na disciplina, ordenados decrescentemente pela MA obtida. 
Caso existam dois ou mais alunos com a mesma MA, esses alunos devem ser exibidos em ordem alfabética.
exibir as seguintes médias:
MA dos alunos aprovados
MA dos alunos reprovados
MA de todos os alunos */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct regaluno 
{
    char nome[25];
    int rga;
    float nota1;
    float nota2;
    float nota3;
    float media; 
    
};
typedef struct regaluno aluno; 

calcula_media(aluno alunos[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
    }
}

cadastra_aluno(aluno alunos[], int n)
{
    int i; 
    for(i = 0; i < n; i++)
    {
        printf("Digite o nome do aluno: ");
        scanf("%s", alunos[i].nome);
        printf("Digite o RGA do aluno: "); 
        scanf("%d", &alunos[i].rga); 
        printf("Digite a nota 1: "); 
        scanf("%f", &alunos[i].nota1);
        printf("Digite a nota 2: "); 
        scanf("%f", &alunos[i].nota2); 
        printf("Digite a nota 3: "); 
        scanf("%f", &alunos[i].nota3); 
    }
    calcula_media(alunos, n);
}

lista_alunos_aprovados(aluno alunos[], int n)
{
    int i; 
    if(alunos[i].media >= 6)
    {
        for(i = 0; i < n; i++)
        {
            printf("Nome: %s\n", alunos[i].nome);
            printf("RGA: %d\n", alunos[i].rga);
            printf("Nota 1: %2.f\n", alunos[i].nota1);
            printf("Nota 2: %2.f\n", alunos[i].nota2);
            printf("Nota 3: %2.f\n", alunos[i].nota3);
            printf("Media: %2.f\n", alunos[i].media);

        }
    }
}

lista_alunos_reprovados(aluno alunos[], int n)
{
    int i; 
    if(alunos[i].media < 6)
    {
        for(i = 0; i < n; i++)
        {
            printf("Nome: %s\n", alunos[i].nome);
            printf("RGA: %d\n", alunos[i].rga);
            printf("Nota 1: %2.f\n", alunos[i].nota1);
            printf("Nota 2: %2.f\n", alunos[i].nota2);
            printf("Nota 3: %2.f\n", alunos[i].nota3);
            printf("Media: %2.f\n", alunos[i].media);

        }
    }
}

lista_alunos(aluno alunos[], int n)
{
    int i; 
    for(i = 0; i < n; i++)
    {
        printf("Nome: %s\n", alunos[i].nome);
        printf("RGA: %d\n", alunos[i].rga);
        printf("Nota 1: %2.f\n", alunos[i].nota1);
        printf("Nota 2: %2.f\n", alunos[i].nota2);
        printf("Nota 3: %2.f\n", alunos[i].nota3);
        printf("Media: %2.f\n", alunos[i].media);

    }
}
remove_aluno(aluno alunos[], int *n, int rga)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        if(alunos[i].rga == rga)
        {
            printf("encontrou esse caralho");
            /*for (j = i; j < *n - 1; j++) {
                alunos[j] = alunos[j + 1]; 
            }
            *n--;*/
        }
    }
}

int main(void)
{
    int n, op, rga;
    aluno alunos[50];

    printf("Selecione uma opção: \n");
    printf("1 - Cadastrar alunos\n");
    printf("2 - Listar alunos\n");
    printf("3 - Listar alunos aprovados\n");
    printf("4 - Listar alunos reprovados\n");
    printf("5 - Remover aluno\n");

    switch(op){
        case 1:
            printf("Quantos alunos serão cadastrados?\n");
            scanf("%d\n", &n);
            cadastra_aluno(alunos, n);
        break;
        case 2: 
            lista_alunos(alunos, n);
        break;
        case 3: 
            lista_alunos_aprovados(alunos, n); 
        break;
        case 4: 
            lista_alunos_reprovados(alunos, n);
        break;
        case 5: 
            printf("Qual o RGA do aluno que deseja remover?");
            scanf("%d", &rga);
            remove_aluno(alunos, &n, rga);
        break;
    }


    
    

    return 0; 
}
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

/*verificar RGA existente para cadastrar e remoção do aluno*/
/*se Caso n = 0 então posição é igual -1*/
/*se Caso n = 1 então if(v[n-1] == x (x no caso seria o RGA) então posição é n-1 
senão posição == -1 )*/
/* Caso > 1 BuscaRec(V[n-1, x]) */

#define MAX_ALUNOS 50

struct regaluno {
    char nome[25];
    int rga;
    float nota1;
    float nota2;
    float nota3;
    float media; 
};
typedef struct regaluno aluno;

/*RECURSIVA*/
void busca_aluno(aluno aluno[], int rga, int n)
{
    if(n > 0)
    {
        return -1;
    }
    if(n == 1)
    {
        if(aluno[n-1].rga == rga)
        {
            return n - 1;
        }
    }
    if(n > 1)
    {
        return busca_aluno(aluno, n-1, rga);
    }
}
    

void calcula_media(aluno aluno[], int *n) {
    int i;
    for(i = 0; i < n; i++) {
        aluno[i].media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3) / 3;
    }
}

void cadastra_aluno(aluno aluno[], int pos) {

    int i;
    for(i = 0; i < pos; i++)
    {
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]", aluno[i].nome);
        printf("Digite o RGA do aluno: "); 
        scanf("%d", &aluno[i].rga); 
        printf("Digite a nota 1: "); 
        scanf("%f", &aluno[i].nota1);
        printf("Digite a nota 2: "); 
        scanf("%f", &aluno[i].nota2); 
        printf("Digite a nota 3: "); 
        scanf("%f", &aluno[i].nota3); 
    }
}

void remove_aluno(aluno alunos[], int *n, int rga) {
    int i, j;
    for(i = 0; i < *n; i++) {
        if(alunos[i].rga == rga) {
            for(j = i; j < *n - 1; j++) {
                alunos[j] = alunos[j + 1]; 
            }
            (*n)--;
            printf("Aluno removido com sucesso.\n");
            return;
        }
    }
    printf("Aluno com RGA %d não encontrado.\n", rga);
}

void lista_alunos(aluno alunos[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Nome: %s\n", alunos[i].nome);
        printf("RGA: %d\n", alunos[i].rga);
        printf("Nota 1: %.2f\n", alunos[i].nota1);
        printf("Nota 2: %.2f\n", alunos[i].nota2);
        printf("Nota 3: %.2f\n", alunos[i].nota3);
        printf("Media: %.2f\n", alunos[i].media);
        printf("\n");
    }
}

void lista_alunos_aprovados(aluno alunos[], int n) {
    aluno aprovados[MAX_ALUNOS];
    int i, count = 0;
    
    for(i = 0; i < n; i++) {
        if(alunos[i].media >= 6) {
            aprovados[count++] = alunos[i];
        }
    }
    
    for(i = 0; i < count; i++) {
        printf("Nome: %s\n", aprovados[i].nome);
        printf("RGA: %d\n", aprovados[i].rga);
        printf("Nota 1: %.2f\n", aprovados[i].nota1);
        printf("Nota 2: %.2f\n", aprovados[i].nota2);
        printf("Nota 3: %.2f\n", aprovados[i].nota3);
        printf("Media: %.2f\n", aprovados[i].media);
        printf("\n");
    }
}

void lista_alunos_reprovados(aluno alunos[], int n) {
    aluno reprovados[MAX_ALUNOS];
    int i, count = 0;
    
    for(i = 0; i < n; i++) {
        if(alunos[i].media < 6) {
            reprovados[count++] = alunos[i];
        }
    }
    
    for(i = 0; i < count; i++) {
        printf("Nome: %s\n", reprovados[i].nome);
        printf("RGA: %d\n", reprovados[i].rga);
        printf("Nota 1: %.2f\n", reprovados[i].nota1);
        printf("Nota 2: %.2f\n", reprovados[i].nota2);
        printf("Nota 3: %.2f\n", reprovados[i].nota3);
        printf("Media: %.2f\n", reprovados[i].media);
        printf("\n");
    }
}


int main(void) {
    aluno aluno[MAX_ALUNOS];
    int n = 0;
    int op, rga, pos;

    
    while (1) {
        printf("Selecione uma opção: \n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Listar alunos aprovados\n");
        printf("4 - Listar alunos reprovados\n");
        printf("5 - Remover aluno\n");
        printf("6 - Buscar aluno \n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Quantos alunos você deseja cadastrar?\n");
                scanf("%d", &pos);
                cadastra_aluno(aluno, pos);
                break;
            case 2:
                lista_alunos(aluno, n);
                break;
            case 3:
                lista_alunos_aprovados(aluno, n);
                break;
            case 4:
                lista_alunos_reprovados(aluno, n);
                break;
            case 5:
                printf("Qual o RGA do aluno que deseja remover? ");
                scanf("%d", &rga);
                remove_aluno(aluno, &n, rga);
                break;
            case 6:
                printf("Qual o RGA do aluno que deseja buscar? ");
                scanf("%d", &rga);
                busca_aluno(aluno, &n, rga);
            case 0:
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 50

/*Estrutura para armazenar informações de um aluno*/
struct regaluno {
    char nome[25];
    int rga;
    float nota1;
    float nota2;
    float nota3;
    float media;
};
typedef struct regaluno aluno;

/*Função recursiva para buscar aluno pelo RGA*/
int busca_aluno(aluno alunos[], int rga, int n) {
    /*Caso base: se não há mais elementos a verificar, o aluno não foi encontrado*/
    if (n == 0) {
        return -1;/*Aluno não encontrado*/
    }
    
    /*Caso base: se o aluno na posição atual tem o RGA desejado*/
    if (alunos[n-1].rga == rga) {
        return n-1;  /*Aluno encontrado na posição n-1*/
    }
    
    /*Caso geral: busca recursiva no restante do vetor (n-1 elementos)*/
    return busca_aluno(alunos, rga, n-1);
}


/*Função para calcular a média de cada aluno*/
void calcula_media(aluno alunos[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3.0;
    }
}

/*Função para cadastrar um novo aluno*/
void cadastra_aluno(aluno alunos[], int *n, int pos) {
    int i;
    for (i = 0; i < pos; i++) {
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]", alunos[*n].nome);
        printf("Digite o RGA do aluno: "); 
        scanf("%d", &alunos[*n].rga); 
        printf("Digite a nota 1: "); 
        scanf("%f", &alunos[*n].nota1);
        printf("Digite a nota 2: "); 
        scanf("%f", &alunos[*n].nota2); 
        printf("Digite a nota 3: "); 
        scanf("%f", &alunos[*n].nota3);

        /*Calcula a média do aluno*/
        calcula_media(alunos, *n + 1);
        (*n)++;
    }
}
/* pq usar o parenteses?
sem parenteses eu altero o ponteiro n e não o valor q ele ta apontando 
*/

/*Função para remover um aluno pelo RGA*/
void remove_aluno(aluno alunos[], int *n, int rga) {
    int i, j;
    for (i = 0; i < *n; i++) {
        if (alunos[i].rga == rga) {
            for (j = i; j < *n - 1; j++) {
                alunos[j] = alunos[j + 1]; /*Move os alunos para a esquerda*/
            }
            (*n)--;
            printf("Aluno removido com sucesso.\n");
            return;
        }
    }
    printf("Aluno com RGA %d não encontrado.\n", rga);
}

/*Função para listar todos os alunos*/
void lista_alunos(aluno alunos[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Nome: %s\n", alunos[i].nome);
        printf("RGA: %d\n", alunos[i].rga);
        printf("Nota 1: %.2f\n", alunos[i].nota1);
        printf("Nota 2: %.2f\n", alunos[i].nota2);
        printf("Nota 3: %.2f\n", alunos[i].nota3);
        printf("Media: %.2f\n", alunos[i].media);
        printf("\n");
    }
}

/*Função para listar alunos aprovados, ordenados por nome*/
void lista_alunos_aprovados(aluno alunos[], int n) {
    aluno aprovados[MAX_ALUNOS];
    int count = 0, i, j;

    /*Seleciona alunos aprovados*/
    for (i = 0; i < n; i++) {
        if (alunos[i].media >= 6) {
            aprovados[count++] = alunos[i];
        }
    }

    /*Ordena alunos aprovados por nome*/
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(aprovados[i].nome, aprovados[j].nome) > 0) {
                aluno temp = aprovados[i];
                aprovados[i] = aprovados[j];
                aprovados[j] = temp;
            }
        }
    }

    /*Lista alunos aprovados*/
    for (i = 0; i < count; i++) {
        printf("Nome: %s\n", aprovados[i].nome);
        printf("RGA: %d\n", aprovados[i].rga);
        printf("Nota 1: %.2f\n", aprovados[i].nota1);
        printf("Nota 2: %.2f\n", aprovados[i].nota2);
        printf("Nota 3: %.2f\n", aprovados[i].nota3);
        printf("Media: %.2f\n", aprovados[i].media);
        printf("\n");
    }
}

/*Função para listar alunos reprovados, ordenados por média (decrescente) e nome*/
void lista_alunos_reprovados(aluno alunos[], int n) {
    aluno reprovados[MAX_ALUNOS];
    int count = 0, i, j;

    /*Seleciona alunos reprovados*/
    for (i = 0; i < n; i++) {
        if (alunos[i].media < 6) {
            reprovados[count++] = alunos[i];
        }
    }

    /*Ordena alunos reprovados por média (decrescente) e nome*/
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (reprovados[i].media < reprovados[j].media ||
                (reprovados[i].media == reprovados[j].media && strcmp(reprovados[i].nome, reprovados[j].nome) > 0)) {
                aluno temp = reprovados[i];
                reprovados[i] = reprovados[j];
                reprovados[j] = temp;
            }
        }
    }

    /*Lista alunos reprovados*/
    for (i = 0; i < count; i++) {
        printf("Nome: %s\n", reprovados[i].nome);
        printf("RGA: %d\n", reprovados[i].rga);
        printf("Nota 1: %.2f\n", reprovados[i].nota1);
        printf("Nota 2: %.2f\n", reprovados[i].nota2);
        printf("Nota 3: %.2f\n", reprovados[i].nota3);
        printf("Media: %.2f\n", reprovados[i].media);
        printf("\n");
    }
}

/*Função recursiva para calcular a soma das médias*/
float soma_mas(aluno alunos[], int n) {
    /*Caso base: se não há mais elementos, a soma é 0*/
    if (n == 0) {
        return 0;
    }
    
    /*Caso geral: adiciona a média do aluno atual à soma das médias dos alunos restantes*/
    return alunos[n-1].media + soma_mas(alunos, n-1);
}


/*Função para calcular e exibir médias*/
void calcula_medias(aluno alunos[], int n) {
    int aprovados = 0, reprovados = 0, i;
    float soma_aprovados = 0, soma_reprovados = 0;

    for (i = 0; i < n; i++) {
        if (alunos[i].media >= 6) {
            soma_aprovados += alunos[i].media;
            aprovados++;
        } else {
            soma_reprovados += alunos[i].media;
            reprovados++;
        }
    }

    printf("MA dos alunos aprovados: %.2f\n", aprovados > 0 ? soma_aprovados / aprovados : 0);
    printf("MA dos alunos reprovados: %.2f\n", reprovados > 0 ? soma_reprovados / reprovados : 0);
    printf("MA de todos os alunos: %.2f\n", soma_mas(alunos, n) / n);
}

int main(void) {
    aluno alunos[MAX_ALUNOS];
    int n = 0;
    int op, rga, pos, resultado, continuar = 1;

    while (continuar) {
        printf("Selecione uma opção: \n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Listar alunos aprovados\n");
        printf("4 - Listar alunos reprovados\n");
        printf("5 - Remover aluno\n");
        printf("6 - Buscar aluno\n");
        printf("7 - Calcular médias\n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Quantos alunos você deseja cadastrar?\n");
                scanf("%d", &pos);
                cadastra_aluno(alunos, &n, pos);
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
                printf("Qual o RGA do aluno que deseja remover? ");
                scanf("%d", &rga);
                remove_aluno(alunos, &n, rga);
                break;
            case 6:
                printf("Qual o RGA do aluno que deseja buscar? ");
                scanf("%d", &rga);
                resultado = busca_aluno(alunos, rga, n);
                if (resultado != -1) {
                    printf("Aluno encontrado na posição %d\n", resultado);
                } else {
                    printf("Aluno não encontrado.\n");
                }
                break;
            case 7:
                calcula_medias(alunos, n);
                break;
            case 0:
                printf("Saindo...\n");
                continuar = 0;
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

#include <stdio.h>

struct regproduto 
{
    int codigo;
    char descricao[50];
    int est_minimo;
    int est_atual;
    float preco;
};

typedef struct regproduto produto; 

void le_produto(produto produtos[], int n) {
    int i;
    for(i = 0; i < n; i++) { 
        printf("Digite o codigo, descricao, est_minimo, est_atual e preco do produto %d:\n", i + 1);
        scanf("%d %s %d %d %f", &produtos[i].codigo, produtos[i].descricao, &produtos[i].est_minimo, &produtos[i].est_atual, &produtos[i].preco);
    }
}

void mostra_produto(produto produtos[], int n) {
    int i;
    for(i = 0; i < n; i++) { 
        if(produtos[i].est_minimo >= produtos[i].est_atual) {
            printf("Codigo: %d\n", produtos[i].codigo);
            printf("Descricao: %s\n", produtos[i].descricao);
            printf("Estoque Minimo: %d\n", produtos[i].est_minimo);
            printf("Estoque Atual: %d\n", produtos[i].est_atual);
            printf("Preco: %.2f\n", produtos[i].preco);
            printf("\n");
        }
    }
}

int main (void)
{
    produto produtos[50];
    int n; 

    printf("Qual a quantidade de produtos a serem registrado?\n"); 
    scanf("%d", &n); 

    le_produto(produtos, n);

    printf("Esses são os produtos que possuem estoque atual menor que estoque mínimo: \n"); 
    mostra_produto(produtos, n);

    return 0; 
}
/*Escreva um programa que leia os dados de dois produtos (descrição, quantidade
em estoque, valor de venda) e depois mostre a descrição e o valor de venda dos
produtos em ordem decrescente da quantidade em estoque.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct regproduto 
{
    char desc[50];
    int qtd_estoque;
    float valor_venda;
};
typedef struct regproduto produto; 

void le_produto(produto produtos[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Qual a descrição do produto?");
        scanf("%s\n", &produtos[i].desc);
        printf("Qual a quantidade em estoque?");
        scanf("%d", &produtos[i].qtd_estoque);
        printf("Qual o valor de venda?");
        scanf("%f", &produtos[i].valor_venda);
    }
}

int main(void){
    produto produtos[10];
    int n;

    printf("Quantos produtos você deseja adicionar?"); 
    scanf("%d", &n);
    le_produto(produtos, n);


    return 0; 
}
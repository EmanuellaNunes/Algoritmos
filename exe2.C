#include <stdio.h>

struct regproduto
{
    int codigo;
    char descricao[50];
    float preco;
}; 
typedef struct regproduto produto;

void mostra_produto(produto p)
{
    printf("%d %s %f\n", p.codigo, p.descricao, p.preco);
}

void le_produto(produto *p)
{
    scanf("%d %s %f", &p->codigo, p->descricao, &p->preco);
}

void troca(produto *a, produto *b)
{
    produto aux; 
    aux = *a; 
    *a = *b;
    *b = aux;
}

int main(void)
{
    produto p1, p2, p3; 

    printf("Digite o codigo, descricao e preco do produto 1:\n");
    le_produto(&p1);
    printf("Digite o codigo, descricao e preco do produto 2:\n");
    le_produto(&p2);
    printf("Digite o codigo, descricao e preco do produto 3:\n");
    le_produto(&p3);

    if (p1.codigo > p2.codigo)
    {
        troca(&p1, &p2); 
    }
    if (p2.codigo > p3.codigo)
    {
        troca(&p2, &p3);
    }
    if (p1.codigo > p2.codigo)
    {
        troca(&p1, &p2);
    }
    
    printf("ORDENADOS POR CODIGO:\n");
    mostra_produto(p1);
    mostra_produto(p2);
    mostra_produto(p3);

    return 0;
}


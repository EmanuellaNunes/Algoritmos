/*Escreva uma função recursiva para encontrar o n-ésimo termo da sequência definida
por:
a0 = 1, a1 = 2, e an = an−1 × an−2, para n = 2, 3, 4, . . . */

/*TESTANDO SÓ ESSA MERDA*/

#include <stdio.h>

nesimo(int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return 2;
    }
    else {
        return nesimo(n - 1) * nesimo(n - 2);
    }
}

int main(void)
{
    int n; 

    scanf("%d", &n);
    nesimo(n);
    printf("%d", nesimo(n));
    return 0;
}
#include <stdio.h> 

acker(int m, int n)
{
    if(m == 0)
    {
        return n+1;
    }
    if(m > 0 && n == 0)
    {
        return acker(m-1, 1);
    }
    if(m > 0 && n > 0)
    {
        return acker(m -1, acker(m, n-1));
    }
}

int main (void)
{
    int m, n, resultado;
    scanf("%d %d", &m, &n);
    acker(m, n);
    resultado = acker(m, n);
    printf("%d", resultado);

    return 0;
}
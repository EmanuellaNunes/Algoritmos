#include <stdio.h>


int div(int x, int y){


    if(x < y)
    {
        return 0;
    }
    if(x == y)
    {
        return 1;
    }
    if(x > y)
    {
        return 1 + div(x - y, y);
    }
    else {
        return -1;
    }
}

int main (void)
{
    int x, y, resultado;

    scanf("%d %d", &x, &y);
    if(x < 0)
    {
        x = x * (-1);
    }
    if(y < 0)
    {
        y = y * (-1);
    }
    div(x, y);
    resultado = div(x, y);
    printf("%d", resultado);

    return 0;
}
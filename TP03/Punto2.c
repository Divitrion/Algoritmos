#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sumaIterativa(int numero);
int sumaRecursiva(int numero);

void main()
{
    int numero;
    printf("Ingrese un numero para sumar sus digitos\n");
    scanf("%d",&numero);
    printf("Suma iterativa: \n");
    sumaIterativa(numero);
    printf("Suma Recursiva: \n");
    numero = sumaRecursiva(numero);
    printf("La suma de sus cifras es: %d \n", numero);
}

void sumaIterativa(int numero)
{
    int suma = 0;
    while(numero > 0)
    {
        suma += numero % 10;
        numero = numero / 10;
    }
    printf("La suma de sus cifras es: %d \n", suma);
}

int sumaRecursiva(int numero)
{
    int suma=0;
    if(numero > 0)
    {
        suma = numero % 10 + sumaRecursiva(numero/10);
        return suma;
    }else
    {
        return 0;
    }
}
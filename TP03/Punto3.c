#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int numeroDeVocales(char *cadena);

int main()
{
    char *cadena = malloc(strlen("sedjadjoiqwdoicaosdqw")*sizeof(char));
    strcpy(cadena,"sedjadjoiqwdoicaosdqw");
    numeroDeVocales(cadena);
    return 0;
}

int numeroDeVocales(char *cadena)
{
    int contador = 0;
    if (cadena != '\0')
    {
        if (strcmp(cadena,"a") == 0 || strcmp(cadena,"e") == 0 || strcmp(cadena,"i") == 0 || strcmp(cadena,"o") == 0 || strcmp(cadena,"u") == 0)
        {
            cadena++;
            contador+= 1 + numeroDeVocales(cadena);
            return contador;
        }else
        {
            cadena++;
            return numeroDeVocales(cadena);
        }
    }else
    {
        return 0;
    }
}
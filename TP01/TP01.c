#include <stdlib.h>
#include <stdbool.h>

int typedef item;

struct nodo
{
    item dato;
    struct nodo* siguiente;
};

typedef struct nodo* Nodo;
typedef struct nodo* Lista;

Lista crearLista();
bool esListaVacia(Lista lista);
Lista insertar(Lista lista, item dato);
bool pertenece(Lista lista, item dato);
item primerElemento(Lista lista);
void mostrar(Lista lista);
Lista borrar(Lista lista);
int longitud(Lista lista);
Lista borrarUltimo(Lista lista);
bool iguales(Lista lista1, Lista lista2);

int main()
{
    int dato;
    Lista lista = crearLista();
    Lista lista2 = crearLista();
    printf("Ingrese 5 valores");
    for (size_t i = 0; i < 5; i++)
    {
        scanf("%d", &dato);
        lista = insertar(lista,dato);
    }
    printf("El primer elemento de la lista es: %d\n", primerElemento(lista));
    printf("la longitud de la lista es: %d\n", longitud(lista));
    printf("pertenece 5 a la lista?\n");
    if (pertenece(lista,5))
    {
        printf("Si pertenece \n");
    }else
    {
         printf("No pertenece \n");
    }
    
    printf("Muestro la lista entera\n");
    mostrar(lista);
    lista = borrar(lista);
    printf("---------------------------\n");
    printf("Muestro la lista despues de borrar el primer elemento\n");
    mostrar(lista);
    lista = borrarUltimo(lista);
    printf("---------------------------\n");
    printf("Muestro la lista despues de borrar el ultimo elemento\n");
    mostrar(lista);
    lista2=lista;
    printf("Ahora comparo estas 2 listas\n");
    printf("LISTA 1\n");
    mostrar(lista);
    lista2->dato = lista->dato + 1; 
    printf("---------------------------\n");
    printf("LISTA 2\n");
    mostrar(lista2);
    printf("Son estas 2 listas iguales?\n");
    if (iguales(lista,lista2))
    {
        printf("Son iguales\n");
    }else
    {
         printf("No son iguales\n");
    }
    
    return 0;
}

Lista crearLista()
{
    return NULL;
}

bool esListaVacia(Lista lista)
{
    return lista == NULL;
}

Lista insertar(Lista lista, item dato)
{
    Nodo nuevoNodo = malloc(1*sizeof(Nodo));
    nuevoNodo->dato = dato;
    if (esListaVacia(lista))
    {
        lista = nuevoNodo;
        nuevoNodo->siguiente = NULL;
    }else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

bool pertenece(Lista lista, item dato)
{
    while (!esListaVacia(lista))
    {
        if (dato == lista->dato)
        {
            return true;
        }
        lista = lista->siguiente;
    }
    return false;
}

item primerElemento(Lista lista)
{
    if (!esListaVacia(lista))
    {
        return lista->dato;
    }
}

void mostrar(Lista lista)
{
    int contador = 1;
    while (!esListaVacia(lista))
    {
        printf("Elemento de la lista nro %d: %d\n", contador, lista->dato);
        lista = lista->siguiente;
        contador++;
    }
    
}

Lista borrar(Lista lista)
{
    if (!esListaVacia(lista))
    {
        Nodo aux = lista;
        lista = aux->siguiente;
        free(aux);
        return lista;
    }
    
}

int longitud(Lista lista)
{
    int contador = 0;
    while (!esListaVacia(lista))
    {
        contador++;
        lista = lista->siguiente;
    }
    return contador;
}

Lista borrarUltimo(Lista lista)
{
    Nodo inicio = lista;
    Nodo nodoAnterior;
    while (lista->siguiente != NULL)
    {
        nodoAnterior = lista;
        lista = lista->siguiente;
    }
    nodoAnterior->siguiente = NULL;
    free(lista);
    lista = inicio;
    return lista;
}

bool iguales(Lista lista1, Lista lista2)
{
    int control=0;
    while (lista1)
    {
        if(pertenece(lista2, primerElemento(lista1)))
        {
            control=1;
        }else{
            control=0;
            return control==1;
        };
        lista1=borrar(lista1);
    }
    return control==1;
}
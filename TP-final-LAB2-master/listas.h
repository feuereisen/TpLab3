#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

const int x=50;

typedef struct
{
    char plato[x];
    int precio;
    struct nodoC*sig;
}nodoC;


nodoC*inicLista();
nodoC*CrearNodo(X);//elegir parametro
nodoC*agregarPrincipio(nodo*lista,nodo*nuevoN);
nodoC*buscarNodo(X,nodo*lista);//PASAR PARAMETRO DEL DATO A BUSCAR Y MODIF FUNCION me tiene que retornar la posicion de memoria del elemento que busco.
nodoC*borrarNodo(char nombre[20], nodo*lista);//adaptarla
nodoC*AgregarDeFormaOrdenada(nodo*lista,nodo*NuevoNodo);//MODIFICAR FUNCION Y ADAPTARLA
nodoC*borrarTodaLaLista(nodo*lista);
void mostrarListas(nodo*lista);//ADAPTARLA
nodoC*buscarUltimo(nodo*lista);//retorna la dirección de memoria del último nodo de la lista.
nodoC*agregarAlFinal(nodo*Lista,nodo*NuevoVodo);
nodoC*eliminaUltimoNodo(nodo*lista);
nodoC*eliminaPrimerNodo(nodo*lista)


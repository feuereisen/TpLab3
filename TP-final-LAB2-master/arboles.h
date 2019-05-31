#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int mesa;
    struct nodoArbolM*izq;
    struct nodoArbolM*der;
} nodoArbolM;

nodoArbol*inicArbol();
nodoArbol*crearNodoArbol(empleado personita);
nodoArbol*insertar(nodoArbol *arbol,nodoArbol *nuevo)//con nodo
nodoArbol*Insertar(nodoArbol*arbol, empleado datos);
void preorden (nodoArbol*arbol);
void inorden(nodoArbol*arbol);
void postorden(nodoArbol*arbol);
nodoArbol*buscarNodoArbol(nodoArbol*arbol, int dato);
int esHoja(nodoArbol*arbol);
nodoArbol*nodoMasDer(nodoArbol*arbol);//paso la izq
nodoArbol*nodoMasIzq(nodoArbol*arbol);
nodoArbol*EliminarUnNodoDeArbol(nodoArbol*arbol,venta dato);
nodo*arbolToLista(nodoArbol*arbol,nodo*lista);
int cantidadNodos(nodoArbol*arbol);






#endif // ARBOLES_H_INCLUDED

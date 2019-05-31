#include "arboles.h"

nodoArbol*inicArbol()
{
    return NULL;
}

nodoArbol*crearNodoArbol(empleado personita)
{
    nodoArbol*aux=(nodoArbol*)malloc(sizeof(nodoArbol));
    aux->persona=personita;
    aux->izq=NULL;
    aux->der=NULL;
    return aux;
}

nodoArbol*insertar(nodoArbol *arbol,nodoArbol *nuevo)//con nodo
{
    if(arbol==NULL)
    {
        arbol=nuevo;
    }
    else
    {
        if(nuevo->dato > arbol->dato)
        {
            arbol->der=insertar(arbol->der,nuevo);
        }
        else
        {
            arbol->izq=insertar(arbol->izq,nuevo);
        }
    }
    return arbol;
}

nodoArbol*Insertar(nodoArbol*arbol, empleado datos)// por dato
{
    if(arbol==NULL)
    {
        arbol=crearNodoArbol(datos);
    }
    else
    {
        if(arbol->persona.nombre < datos.legajo)
        {
            arbol->der=Insertar(arbol->der,datos);
        }
        else
        {
            arbol->izq=Insertar(arbol->izq,datos);
        }
    }
    return arbol;
}

void preorden (nodoArbol*arbol)
{
    if(arbol!=NULL)
    {
        mostrarEmpleado(arbol->persona);
        preorden(arbol->izq);
        preorden(arbol->der);
    }
}

void inorden(nodoArbol*arbol)
{
    if(arbol!=NULL)
    {
        inorden(arbol->izq);
        mostrarEmpleado(arbol->persona);
        inorden(arbol->der);
    }
}

void postorden(nodoArbol*arbol)
{
    if(arbol!=NULL)
    {
        postorden(arbol->izq);
        postorden(arbol->der);
        mostrarEmpleado(arbol->persona);
    }
}

nodoArbol*buscarNodoArbol(nodoArbol*arbol, int dato)
{
    nodoArbol*rta=inicArbol();
    if(arbol!=NULL)
    {
        if(arbol->persona.legajo  ==  dato)
        {
            rta=arbol;
        }
        else
        {
            if(arbol->persona.legajo < dato)
            {
                rta=buscarNodoArbol(arbol->der,dato);
            }
            else
            {
                rta=buscarNodoArbol(arbol->izq,dato);
            }
        }
    }
    return rta;
}
int esHoja(nodoArbol*arbol)//paso arbol
{
    int i=-1;
    if(arbol->der == NULL && arbol->izq == NULL)
    {
        i=0
    }
    return i;
}

nodoArbol*nodoMasDer(nodoArbol*arbol)//paso la izq
{
    nodoArbol*aux;
    if(arbol->der==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasDerecha(arbol->der);
    }
    return aux;
}


nodoArbol*nodoMasIzq(nodoArbol*arbol)
{
    nodoArbol*aux;
    if(arbol->izq==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasIzquierda(arbol->izq);
    }
    return aux;
}

nodoArbol*EliminarUnNodoDeArbol(nodoArbol*arbol,venta dato)
{
 /*-Si es null
   -Si es raiz.
   -si es nodo intermedio
   -si es hoja.
   Siempre vamos a borrar un nodo hoja.
   corta cuando es hoja y cuando encuentra el dato*/

    nodoArbol*maxIzq;
    nodoArbol*minDer;

    if(arbol!=NULL)
    {
        if(arbol->compra.precio == dato)
        {
            if(arbol->izq!=NULL)
            {
                max=nodoMasDer(arbol->izq);//busco uno apto para intecambiar
                arbol->compra=max->compra;//asigno el encontrado en el arbol
                arbol->izq=EliminarUnNodoDeArbol(arbol->izq,max->compra);//borro el nodo que intercambie.
            }
            else if(arbol->der!=NULL)
            {
                min=nodoMasIzq(arbol->der);
                arbol->compra=min->compra;
                arbol->der=EliminarUnNodoDeArbol(arbol->der,min->compra);
            }
            else
            {
                free(arbol);
                arbol=NULL;
            }
        }
        else if(arbol->compra.precio < dato)
        {
            arbol->der=EliminarUnNodoDeArbol(arbol->der,dato);
        }
        else
        {
            arbol->izq=EliminarUnNodoDeArbol(arbol->izq,dato);
        }
    }
    return arbol;
}

nodo*arbolToLista(nodoArbol*arbol,nodo*lista)
{
    if(arbol!=NULL)
    {
        lista=agregarOrden(lista,crearNodoLista(arbol->legajo,arbol->nombre));
        arbolToLista(arbol->izq,lista);
        arbolToLista(arbol->der,lista);
    }
    return lista;
}

int cantidadNodos(nodoArbol*arbol)
{
    int cant=0;
    if(arbol!=NULL)
    {
        cant=1;
        cant=cant+cantidadNodos(arbol->izq);
        cant=cant+cantidadNodos(arbol->der);
    }
    return cant;
}

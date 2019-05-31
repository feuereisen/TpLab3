#include "listas.h"





nodo*inicLista()
{
    return NULL;
}

nodo*CrearNodo(X)//elegir parametro
{
    nodo*aux=(nodo*)malloc(sizeof(nodo));
    aux->Tema=datos;
    aux->siguiente=NULL;
    return aux;
}

nodo*agregarPrincipio(nodo*lista,nodo*nuevoN)
{
    if(lista==NULL)//aqui entra cuando no hay ningun nodo con info.
    {
        lista=nuevoN;//es mi nueva lista.
    }
    else// en caso de que ya haya otros nodos
    {
        nuevoN->siguiente=lista; //enganchamos el nuevo nodo al puntero sigiente pata que apunte a la nueva lista.
        lista=nuevoN;
    }
    return lista;// es el retorno por que es el nuevo comienzo, ademas por que la variable cambio de valor, por eso lo refrezcamos.
}


nodo*buscarNodo(X,nodo*lista)//PASAR PARAMETRO DEL DATO A BUSCAR Y MODIF FUNCION me tiene que retornar la posicion de memoria del elemento que busco.
{
    nodo*seguidora;//esta apunta a la lista que va a ser leida.
    seguidora=lista;//vinculo la lista a leer.
    while((seguidora!=NULL) && strcmpi(song,seguidora->Tema.cancion)!=0 )// el bucle se repita hasta que, o sea igual a null o que sea igual a cero.
    {
        seguidora=seguidora->siguiente;
    }
    return seguidora;
}

nodo*borrarNodo(char nombre[20], nodo * lista)//adaptarla
{
    nodo*seguidora;
    nodo*anterior;//apunta al nodo anterior que seg.

    if((lista!= NULL) && (strcmp(nombre, lista->nombre)==0 ))
    {
        nodo*aux = lista;
        lista=lista->siguiente; //salteo el primer nodo.
        free(aux); //elimino el primer nodo.
    }
    else
    {
        seguidora=lista;
        while((seguidora!=NULL) && (strcmp(nombre, seguidora->nombre)!=0 ))
        {
            ante=seguidora;//adelanto una posicion la var ante.
            seguidora=seguidora->siguiente;//avanzo al siguiente nodo.
        }
        if(seguidora!=NULL)
        {
            ante->siguiente = seguidora->siguiente;//salteo el nodo que quiero eliminar.
            free(seguidora);//elimino el nodo.
        }
    }
    return lista;
}

nodo*AgregarDeFormaOrdenada(nodo*lista,nodo*NuevoNodo)//MODIFICAR FUNCION Y ADAPTARLA
{
    if(lista==NULL)
    {
        lista=NuevoNodo;
    }
    else
    {
        if(lista->Tema.ID > NuevoNodo->Tema.ID)
        {
            lista=agregarPrincipio(lista,NuevoNodo);
        }
        else
        {
            nodo*anterior=lista;//puntero a la lista que va a a ser la anterior
            nodo*seguidora=lista->siguiente;//puntero al siguiente nodo.
            while( seguidora!=NULL  &&  NuevoNodo->Tema.ID >= seguidora->Tema.ID )//usamos while por que no sabemos las cantidades y ademas no tenemos indices.
            {
                anterior=seguidora;//en caso de entrar, guardo la direccion de memoria de seguidora.
                seguidora=seguidora->siguiente;// a seguidora le asigno al puntero del proximo nodo para seguir evaluando.
            }
            NuevoNodo->siguiente=seguidora;//apunto desdee el nuevo nodo a seguidora para no perderlo.
            anterior->siguiente=NuevoNodo;//apunto desde el nodo anterior a nuevo nodo. asi se inserta el nuevo nodo entre el anterior y seguidora.
        }
    }
    return lista;
}

nodo*borrarTodaLaLista(nodo*lista)
{
    nodo*proximo;
    nodo*seguidora;
    seg=lista;
    while(seguidora!=NULL)
    {
        proximo=seguidora->siguiente;//tomo la dir del siguiente.
        free(seguidora);//borro el actual.
        seguidora=proximo;//actualizo el actual con la dir del siguiente, para avanzar
    }
    return seguidora;
}

void mostrarListas(nodo*lista)//ADAPTARLA
{
    nodo*seguidora=lista;
    if(seguidora!=NULL)
    {
        mostrarCanciones(seguidora);
        mostrarListaDeCanciones(seguidora->siguiente);
    }
}

nodo*buscarUltimo(nodo*lista)//retorna la dirección de memoria del último nodo de la lista.
{
    nodo*seguidora = lista;
    if(seguidora!= NULL)
    {
        while(seguidora->siguiente != NULL)//se evalua al siguiente y se detiene el bucle al llegar al último nodo.
        {
            seguidora=seguidora->siguiente;
        }
    }
    return seguidora;//direccion de memo. del ultimo nodo.
}

nodo*agregarAlFinal(nodo*Lista,nodo*NuevoVodo)
{
    if(Lista==NULL)//evaluo, si entra asigno el NN.
    {
        Lista=NuevoVodo;
    }
    else
    {
        nodo*ult=buscarUltimo(Lista);//busco el ultimo nodo.
        ult->siguiente=NuevoVodo;//Actualizo,hago que el ultimo apunte a mi NN.
    }
    return Lista;
}

nodo*eliminaUltimoNodo(nodo*lista)
{
    nodo*aux=lista;
    nodo*ante;
    while(aux->siguiente!=NULL)
    {
        ante=aux;
        aux=aux->siguiente;
    }
    free(aux);
    ante->siguiente=NULL;
    return lista;
}

nodo*eliminaPrimerNodo(nodo*lista)
{
    nodo*aux=lista;
    lista=lista->siguiente;
    free(aux);
    return lista;
}

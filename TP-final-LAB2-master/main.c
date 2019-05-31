#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"
#include "listas.h"

int main()
{
    nodoArbolM Mesa;
    int Idmesa=ElegirMesa();
    Mesa=EliminarUnNodoDeArbol(Mesa,Idmesa);//revisar, capaz en ves de eliminar, volverlo ocupado.
    celdaRestaurant Restaurantes[3];
    Restaurantes[0].restaurant={"Marikinha"};
    Restaurantes[1].restaurant={"Celestinha"};
    Restaurantes[2].restaurant={"Tinchinho"};

    return 0;
}
int ElegirMesa()
{
    int idmesa;
    printf("\n     Elija n° de Mesa que desea reservar :");
    scanf("%d",&idmesa);
    return idmesa;
}

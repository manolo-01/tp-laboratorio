#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"
#define QTY_CLIENTES 100
#define QTY_PUBLICACIONES 1000

int main()
{
    Cliente arrayC[QTY_CLIENTES];
    Publicacion arrayP[QTY_PUBLICACIONES];
    int menu;
    int auxiliarIdCliente;
    int auxiliarIdPublicacion;

    cliente_init(arrayC,QTY_CLIENTES);
    publicacion_init(arrayP,QTY_PUBLICACIONES);
    do
    {
        getValidInt("\n1.Alta de Cliente\n2.Baja de Cliente\n3.Modificar Cliente\n4.Publicar\n5.Pausar Publicacion\n6.Reanudar Publicacion\n7.Imprimir Clientes\n8.Imprimir Publicaciones\n9.Informar sobre Clientes\n10.Imformar sobre Publicaciones\n11.Salir\n","\nNo valida\n",&menu,1,11,1);
        switch(menu)
        {
            case 1:
                cliente_alta(arrayC,QTY_CLIENTES);
                break;
            case 2:
                cliente_mostrar(arrayC,QTY_CLIENTES);
                getValidInt("\nID?","\nNumero valida\n",&auxiliarIdCliente,0,QTY_CLIENTES,2);
                cliente_baja(arrayC,QTY_CLIENTES,auxiliarIdCliente);
                break;
            case 3:
                cliente_mostrar(arrayC,QTY_CLIENTES);
                getValidInt("\nID?","\nNumero valida\n",&auxiliarIdCliente,0,QTY_CLIENTES,2);
                cliente_modificacion(arrayC,QTY_CLIENTES,auxiliarIdCliente);
                break;
            case 4:
                cliente_mostrar(arrayC,QTY_CLIENTES);
                publicacion_alta(arrayP,QTY_PUBLICACIONES);
                break;
            case 5:
                publicacion_mostrar(arrayP,QTY_PUBLICACIONES);
                getValidInt("\nID publicacion","Error",&auxiliarIdPublicacion,0,1000,2);
                publicacion_modificacion(arrayP,QTY_PUBLICACIONES,auxiliarIdPublicacion);
                break;
            case 6:
                publicacion_mostrar(arrayP,QTY_PUBLICACIONES);

                publicacion_modificacion(arrayP,QTY_PUBLICACIONES,auxiliarIdPublicacion);
                break;
               case 7:
               // publicacion_alta()_mostrar(array,QTY);
                break;
            case 8:
                //cliente_alta()_ordenar(array,QTY,0);
                break;
            case 9:
                //cliente_alta()_mostrarDebug(array,QTY);
                break;
            case 10:
                break;
        }

    }while(menu != 11);

    return 0;
}

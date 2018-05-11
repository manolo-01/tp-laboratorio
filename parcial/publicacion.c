#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "publicacion.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1
#define ACTIVA 0
#define PAUSADA 1

static int buscarLugarLibre(Publicacion* array,int limite);
static int proximoId();

int publicacion_init(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty = 1;
        }
    }
    return retorno;
}

int publicacion_buscarPorId(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idPublicacion == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_baja(Publicacion* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = publicacion_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }
    return retorno;
}


int publicacion_mostrar(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
               printf("\n %d - %d - %d - %s - %d - %d",array[i].idPublicacion,array[i].idCliente,array[i].numeroDeRubro,array[i].textoDelAviso,array[i].estadoPublicacion,array[i].isEmpty);
            }
        }
    }
    return retorno;
}

int publicacion_mostrarDebug(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n %d - %d - %d - %s - %d - %d",array[i].idPublicacion,array[i].idCliente,array[i].numeroDeRubro,array[i].textoDelAviso,array[i].estadoPublicacion,array[i].isEmpty);
        }
    }
    return retorno;
}


int publicacion_alta(Publicacion* array,int limite)
{
    int retorno = -1;
    int idCliente;
    int numeroDeRubro;
    char textoDelAviso[64];
    int estadoPublicacion;
    int id;
    int indice;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = proximoId();

            if(!getValidInt("\nrubro?","Error",numeroDeRubro,0,100,2))
                    {
                         if(!getValidString("\nContenido del Aviso: ","Error","Overflow", textoDelAviso,64,2))
                        {
                            cliente_mostrar();
                            retorno = 0;
                            strcpy(array[indice].textoDelAviso,textoDelAviso);
                            array[indice].idPublicacion = id;
                            array[indice].isEmpty = OCUPADO;
                            array[indice].estadoPublicacion=ACTIVA;
                            array[indice].idCliente=idCliente;
                        }

                    }
        }
    }
    return retorno;
}



int publicacion_modificacion(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    indice = publicacion_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = -2;
        if(array[indice].estadoPublicacion==ACTIVA)
        {
            retorno = 0;
            printf("publicacion activa, desea pausarla?");
        }
        else
        {
            retorno=0;
            printf("publicacion pausada, desea activarla?");
        }


    }
    return retorno;
}


static int buscarLugarLibre(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}



int publicacion_ordenar(Publicacion* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Publicacion auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(array[i].isEmpty == OCUPADO && array[i+1].isEmpty == OCUPADO )
                    {
                        if((((array[i].idPublicacion<array[i+1].idPublicacion) && !orden) || (array[i].idPublicacion<array[i+1].idPublicacion) < 0 && orden)) //<------------
                        {
                            auxiliar = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}










































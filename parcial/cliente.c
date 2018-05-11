#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#define QTY 100
#define OCUPADO 0
#define LIBRE 1

static int buscarLugarLibre(Cliente* array,int limite);
static int proximoId();

int cliente_init(Cliente* array,int limite)
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

int cliente_buscarPorId(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idCliente == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_baja(Cliente* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = cliente_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }
    return retorno;
}


int cliente_mostrar(Cliente* array,int limite)
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
               printf("\n %s - %s - %s - %d - %d",array[i].nombre,array[i].apellido,array[i].cuit,array[i].idCliente,array[i].isEmpty);
            }
        }
    }
    return retorno;
}

int cliente_mostrarDebug(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n %s - %s - %s - %d - %d",array[i].nombre,array[i].apellido,array[i].cuit,array[i].idCliente,array[i].isEmpty);
        }
    }
    return retorno;
}


int cliente_alta(Cliente* array,int limite)
{
    int retorno = -1;
    char nombre[50];
    char apellido[50];
    char cuit[15];
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
            if(!getValidString("\nNombre? ","Error","Overflow", nombre,50,2))
            {
                if(!getValidString("\nApellido? ","Error","Overflow", apellido,50,2))
                {
                   getString("\ncuit",cuit);
                      {
                        retorno = 0;
                        strcpy(array[indice].nombre,nombre);
                        strcpy(array[indice].apellido,apellido);
                        strcpy(array[indice].cuit,cuit);
                        array[indice].idCliente = id;
                        array[indice].isEmpty = OCUPADO;
                    }
                }
            }
        }
    }
    return retorno;
}



int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    char apellido[50];
    char cuit[15];
    indice = cliente_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = -2;
        if(!getValidString("\nNombre?","Error","Overflow", nombre,50,2))
        {
            if(!getValidString("\napellido","Error","Overflow",apellido,50,2))
            {
                getString("\ncuit? ",cuit);
                retorno = 0;
                strcpy(array[indice].nombre,nombre);
                strcpy(array[indice].apellido,nombre);
                strcpy(array[indice].cuit,cuit);
            }

        }


    }
    return retorno;
}


static int buscarLugarLibre(Cliente* array,int limite)
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



int cliente_ordenar(Cliente* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Cliente auxiliar;

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
                        if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden)) //<------------
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










































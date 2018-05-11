#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "cliente.h"
#include "utn.h"

//Funciones privadas
static int proximoId(void);
//static int buscarPorId(Cliente* array,int limite, int id);
static int buscarLugarLibre(Cliente* array,int limite);

/** \brief
 * \param arrayC cliente*
 * \param limite int
 * \return int
 *
 */
int cliente_init(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayC[i].isEmpty=1;
        }
    }
    return retorno;
}

int cliente_mostrarDebug(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %s - %li - %d\n",arrayC[i].idCliente, arrayC[i].nombre, arrayC[i].apellido, arrayC[i].cuitCliente, arrayC[i].isEmpty);
        }
    }
    return retorno;
}

int cliente_mostrar(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !arrayC[i].estado)
                printf("[RELEASE] - %d - %s - %s - %ld - %d\n",arrayC[i].idCliente, arrayC[i].nombre, arrayC[i].apellido, arrayC[i].cuitCliente, arrayC[i].isEmpty);
        }
    }
    return retorno;
}

/*int cliente_alta(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    char buffer[50];
    char cuit[20];
    if(limite > 0 && arrayC != NULL)
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
            {
                retorno = 0;
                strcpy(arrayC[i].nombre,buffer);
                if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 40",buffer,40,2))
                {
                    strcpy(arrayC[i].apellido,buffer);
                    if(!getCuit("CUIT?", "CUIT no valido", cuit, 0, 10, 2))
                    strcpy(arrayC[i].nombre,cuit);
                }
                arrayC[i].idCliente = proximoId();
                arrayC[i].isEmpty = 0;
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}*/

int cliente_altaForzada(Cliente* arrayC, int limite, char* nombre, char* apellido, long int* cuit, int idCliente)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayC != NULL)
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayC[i].nombre,nombre);
            strcpy(arrayC[i].apellido,apellido);
            strcpy(arrayC[i].apellido,apellido);
            arrayC[i].idCliente = idCliente;
            arrayC[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int cliente_baja(Cliente* arrayC,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && arrayC[i].idCliente==id)
            {
                arrayC[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int cliente_modificacion(Cliente* arrayC,int limite, int id)
{
    int retorno = -1;
    int i;
    char buffer[50];
    if(limite > 0 && arrayC != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && arrayC[i].idCliente==id)
            {
                if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
                {
                    retorno = 0;
                    strcpy(arrayC[i].nombre,buffer);
                    //------------------------------
                    //------------------------------
                }
                else
                {
                    retorno = -3;
                }
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int cliente_ordenar(Cliente* arrayC,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

    if(limite > 0 && arrayC != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!arrayC[i].isEmpty && !arrayC[i+1].isEmpty)
                {
                    if((strcmp(arrayC[i].nombre,arrayC[i+1].nombre) > 0 && orden) || (strcmp(arrayC[i].nombre,arrayC[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = arrayC[i];
                        arrayC[i] = arrayC[i+1];
                        arrayC[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

static int buscarLugarLibre(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
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
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


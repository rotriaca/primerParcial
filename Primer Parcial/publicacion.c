#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "cliente.h"
#include "utn.h"

//Funciones privadas
static int proximoId(void);
static int buscarPorId(Publicacion* array,int limite, int id);
static int buscarLugarLibre(Publicacion* array,int limite);

/** \brief
 * \param arrayP Publicacion*
 * \param limite int
 * \return int
 *
 */
int publicacion_init(Publicacion* arrayP,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayP[i].isEmpty=1;
        }
    }
    return retorno;
}

int publicacion_mostrarDebug(Publicacion* arrayP,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %d - %s - %d\n",arrayP[i].idRubro, arrayP[i].idCliente, arrayP[i].textoAviso, arrayP[i].isEmpty);
        }
    }
    return retorno;
}

int publicacion_mostrar(Publicacion* arrayP,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!arrayP[i].isEmpty)
                printf("[RELEASE] - %d - %d - %s - %d\n",arrayP[i].idRubro, arrayP[i].idCliente, arrayP[i].textoAviso, arrayP[i].isEmpty);
                if(arrayP[i].estado == 0)
                    printf("Publicacion pausada");
                else if(arrayP[i].estado == 1)
                    printf("Publicacion activa");
        }
    }
    return retorno;
}

int publicacion_pausa(Publicacion* arrayP, int limite)
{
    int idPublicacion;
    scanf("%d", idPublicacion);
    if(idPublicacion == arrayP[i].idPublicacion)
    {
        arrayP[i].estado=0;
        return 0;
    }
    else
    {
        printf("Ingrese un id valido");
        break;
    }

    return -1;
}

int publicacion_reanudar(Publicacion* arrayP, char* msg, char* msgError, int limite)
{
    int idPublicacion;
    scanf("%d", idPublicacion);
    if(idPublicacion == arrayP[i].idPublicacion)
    {
        arrayP[i].estado=1;
        return 0;
    }
    else
    {
        printf("%s", msgError);
        break;
    }

    return -1;
}

int publicacion_alta(Publicacion* arrayP,int limite)
{
    int retorno = -1;
    int i;
    char buffer[50];
    int idAux;
    int idPubAux;
    if(limite > 0 && arrayP != NULL)
    {
        i = buscarLugarLibre(arrayP,limite);
        if(i >= 0)
        {
            if(!getValidInt("Ingrese ID de CLIENTE", "ID invalido, reingrese", &idAux, 0, 100, 2 ))
            {
                arrayP[i].idCliente = idAux;
                if(!getValidInt("Ingrese ID de RUBRO", "ID invalido, reingrese", &idPubAux, 0, 1000, 2 ))
                {
                    arrayP[i].idRubro = idPubAux;
                    if(!getValidString("\nIngrese descripcion ","\nDescripcion invalida","El maximo es 64",buffer,64,2))
                    {
                    retorno = 0;
                    strcpy(arrayP[i].textoAviso,buffer);
                    arrayP[i].idPublicacion = proximoId();
                    arrayP[i].isEmpty = 0;
                    arrayP[i].estado = 1;
                    printf("Los datos de la publicacion son: \n-%d\n-%d\n-%s\n-%d", arrayP[i].idCliente, arrayP[i].idRubro, arrayP[i].textoAviso, arrayP[i].idPublicacion);
                    }
                }

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
}


int publicacion_baja(Publicacion* arrayP,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayP[i].isEmpty && arrayP[i].idPublicacion==id)
            {
                arrayP[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}




int publicacion_modificacion(Publicacion* arrayP,int limite, int id)
{
    int retorno = -1;
    int i;
    char buffer[50];
    if(limite > 0 && arrayP != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayP[i].isEmpty && arrayP[i].idPublicacion==id)
            {
                if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
                {
                    retorno = 0;
                    strcpy(arrayP[i].textoAviso,buffer);
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

int publicacion_ordenar(Publicacion* arrayP,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;

    if(limite > 0 && arrayP != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!arrayP[i].isEmpty && !arrayP[i+1].isEmpty)
                {
                    if((strcmp(arrayP[i].textoAviso,arrayP[i+1].textoAviso) > 0 && orden) || (strcmp(arrayP[i].textoAviso,arrayP[i+1].textoAviso) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = arrayP[i];
                        arrayP[i] = arrayP[i+1];
                        arrayP[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

static int buscarLugarLibre(Publicacion* array,int limite)
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

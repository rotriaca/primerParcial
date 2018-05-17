#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"

/** \brief
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \return int
 *
 */
int cliente_init(ECliente* arrayCliente,int limiteCliente)
{
    int retorno = -1;
    int i;
    if(limiteCliente > 0 && arrayCliente != NULL)
    {
        retorno = 0;
        for(i=0; i<limiteCliente; i++)
        {
            arrayCliente[i].isEmpty=1;
        }
    }
    return retorno;
}

int cliente_mostrarDebug(ECliente* arrayCliente,int limiteCliente)
{
    int retorno = -1;
    int i;
    if(limiteCliente > 0 && arrayCliente != NULL)
    {
        retorno = 0;
        for(i=0; i<limiteCliente; i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",arrayCliente[i].idCliente, arrayCliente[i].nombre, arrayCliente[i].isEmpty);
        }
    }
    return retorno;
}

int cliente_mostrar(ECliente* arrayCliente,int limiteCliente)
{
    int retorno = -1;
    int i;
    if(limiteCliente > 0 && arrayCliente != NULL)
    {
        retorno = 0;
        for(i=0; i<limiteCliente; i++)
        {
            if(!arrayCliente[i].isEmpty)
                printf("\n-ID: %d -Nombre: %s -Apellido %s -CUIT: %s \n",arrayCliente[i].idCliente, arrayCliente[i].nombre, arrayCliente[i].apellido,arrayCliente[i].cuit);
        }
    }
    return retorno;
}

int cliente_alta(ECliente* arrayCliente,int limiteCliente)
{
    int retorno = -1;
    int i;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[12];
    if(limiteCliente > 0 && arrayCliente != NULL)
    {
        i = buscarLugarLibre(arrayCliente,limiteCliente);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","\nEl maximo son 50 letras",auxNombre,51,2))
            {
                if(!getValidString("\nApellido? ", "\nApellido no valido","\nEl maximo son 50 letras",auxApellido,51,2))
                {
                    if(!cliente_getCuit("\nIngrese su cuit: ","CUIT INVALIDO",auxCuit))
                    {
                        retorno = 0;
                        strcpy(arrayCliente[i].nombre, auxNombre);
                        strcpy(arrayCliente[i].apellido, auxApellido);
                        strcpy(arrayCliente[i].cuit,auxCuit);
                        printf("\n cuit:%s\n", arrayCliente[i].cuit);
                        //------------------------------
                        arrayCliente[i].idCliente = proximoIdCliente();
                        arrayCliente[i].isEmpty = 0;

                    }
                    else
                    {
                        retorno = -5;
                    }
                }
                else
                {
                    retorno = -4;
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


int cliente_baja(ECliente* arrayCliente,int limiteCliente, int id)
{
    int retorno = -1; // null exception
    int i;
    if(limiteCliente > 0 && arrayCliente != NULL)
    {
        retorno = -2; // cliente no existe
        for(i=0; i<limiteCliente; i++)
        {
            if(!arrayCliente[i].isEmpty && arrayCliente[i].idCliente==id)
            {
                arrayCliente[i].isEmpty = 1;
                printf("Cliente eliminado con exito\n");
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


int cliente_imprimirClientesConPublicacionesActivas(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicaciones,int limitePublicacion)
{
    int retorno = -1;
    int i,j;
    int flagActivas=0;
    if(limiteCliente > 0 && arrayCliente != NULL && limitePublicacion >0 && arrayPublicaciones !=NULL)
    {
        retorno = 0;
        for(i=0;i<limiteCliente;i++)
        {
            if(!arrayCliente[i].isEmpty)
            {
                printf("\n-ID: %d -Nombre: %s -Apellido %s -CUIT: %s ",arrayCliente[i].idCliente, arrayCliente[i].nombre, arrayCliente[i].apellido,arrayCliente[i].cuit);
                for(j=0;j<limitePublicacion;j++)
                {
                    if (arrayPublicaciones[j].idCliente==arrayCliente[i].idCliente && arrayPublicaciones[j].estado==0 )
                    {
                        flagActivas=1;
                         switch (arrayPublicaciones[j].rubro)
                        {
                        case 1:
                            printf("\n-CELULARES");
                            break;
                        case 2:
                            printf("\n-NOTEBOOKS");
                            break;
                        case 3:
                            printf("\n-TABLETS");
                            break;
                        }
                         printf("-DESCRIPCION: %s \n",arrayPublicaciones[j].descripcion);
                    }
                }
                if(flagActivas==0)
                    printf("\nEste cliente no tiene publicaciones activas");
            }
        }
    }
    return retorno;
}

int cliente_modificacion(ECliente* arrayCliente,int limiteCliente, int id)
{
    int retorno = -1; // null exception
    int i;
    char auxNombre[50];
    char auxApellido[50];
    char auxCuit[12];

    if(limiteCliente > 0 && arrayCliente != NULL)
    {
        for(i=0; i<limiteCliente; i++)
        {
            if(!arrayCliente[i].isEmpty && arrayCliente[i].idCliente==id)
            {
                if(!getValidString("\nNombre? ","\nEso no es un nombre","\nEl maximo son 50 letras",auxNombre,51,2))
                {
                    if(!getValidString("\nApellido? ", "\nApellido no valido","\nEl maximo son 50 letras",auxApellido,51,2))
                    {
                        if(!cliente_getCuit("\nIngrese su cuit: ","CUIT INVALIDO\n",auxCuit))
                        {
                            retorno = 0;
                            strcpy(arrayCliente[i].nombre, auxNombre);
                            strcpy(arrayCliente[i].apellido, auxApellido);
                            strcpy(arrayCliente[i].cuit,auxCuit);
                            //------------------------------
                            arrayCliente[i].isEmpty = 0;
                            break;

                        }
                        else
                        {
                            retorno = -5; // cuit invalido
                        }
                    }
                    else
                    {
                        retorno = -4; //apellido invalido
                    }
                }
                else
                {
                    retorno = -3; //nombre invalido
                }
            }
            else
            {
                retorno = -2; //no existe cliente
            }
        }
    }
    return retorno;
}

int cliente_ordenar(ECliente* arrayCliente,int limiteCliente, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    ECliente auxiliarEstructura;

    if(limiteCliente > 0 && arrayCliente != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0; i<limiteCliente-1; i++)
            {
                if(!arrayCliente[i].isEmpty && !arrayCliente[i+1].isEmpty)
                {
                    if((strcmp(arrayCliente[i].nombre,arrayCliente[i+1].nombre) > 0 && orden) || (strcmp(arrayCliente[i].nombre,arrayCliente[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = arrayCliente[i];
                        arrayCliente[i] = arrayCliente[i+1];
                        arrayCliente[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }
        while(flagSwap);
    }
    return retorno;
}

int buscarLugarLibre(ECliente* arrayCliente,int limiteCliente)
{
    int retorno = -1;
    int i;
    if(limiteCliente > 0 && arrayCliente != NULL)
    {
        for(i=0; i<limiteCliente; i++)
        {
            if(arrayCliente[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int proximoId = -1;

int proximoIdCliente()
{
    proximoId++;
    return proximoId;
}

int cliente_getCuit(char mensaje[], char mensajeError[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux) && strlen(aux)==11)
    {
        strcpy(input,aux);
        return 0;
    }
    else
    {
        printf(mensajeError);
    }
    return 1;
}


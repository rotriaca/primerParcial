#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"
#define PAUSADO 0
#define ACTIVO 1

static int proximoId = -1;


/** \brief
 * \param array EPublicacion*
 * \param limite int
 * \return int
 *
 */
int publicacion_init(EPublicacion* arrayPublicaciones,int limitePublicacion)
{
    int retorno = -1;
    int i;
    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        retorno = 0;
        for(i=0;i<limitePublicacion;i++)
        {
            arrayPublicaciones[i].isEmpty=1;
            arrayPublicaciones[i].estado=1;
        }
    }
    return retorno;
}

int publicacion_mostrarDebug(EPublicacion* arrayPublicaciones,int limitePublicacion)
{
    int retorno = -1;
    int i;
    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        retorno = 0;
        for(i=0;i<limitePublicacion;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",arrayPublicaciones[i].idPublicacion, arrayPublicaciones[i].descripcion, arrayPublicaciones[i].isEmpty);
        }
    }
    return retorno;
}

int publicacion_mostrar(EPublicacion* arrayPublicaciones,int limitePublicacion)
{
    int retorno = -1;
    int i;
    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        retorno = 0;
        for(i=0;i<limitePublicacion;i++)
        {
            if(!arrayPublicaciones[i].isEmpty)
                printf("[RELEASE] - %d - %s - %d\n",arrayPublicaciones[i].idPublicacion, arrayPublicaciones[i].descripcion, arrayPublicaciones[i].isEmpty);
        }
    }
    return retorno;
}

int publicacion_alta(EPublicacion* arrayPublicaciones,int limitePublicacion,ECliente* arrayCliente, int limiteCliente)
{
    int retorno = -1; //null exception
    int i;
    int auxId;
    int auxRubro;
    char auxDesc[65];
    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        i = publicacion_buscarLugarLibre(arrayPublicaciones,limitePublicacion);
        if(i >= 0)
        {
            if(!getValidInt("\nID de usuario? ","\nId invalido",&auxId,0,999,2))
            {
                for(i=0;i<limiteCliente;i++)
                {
                    if (auxId==arrayCliente[i].idCliente);
                     {

                        if(!getValidInt("\nIngrese el rubro: \n1-CELULARES \n2-NOTEBOOKS \n3-TABLETS\n ","Rubro no valido", &auxRubro,1,3,2))
                        {
                            if(!getValidString("\nIngrese descripcion de hasta 64 caracteres: ","Cadena no valida","Exceso de caracteres. MAX 64", auxDesc, 65, 2))
                            {
                                retorno = 0;
                                strcpy(arrayPublicaciones[i].descripcion,auxDesc);
                                arrayPublicaciones[i].idCliente=auxId;
                                arrayPublicaciones[i].rubro=auxRubro;
                                arrayPublicaciones[i].estado=0;
                                //------------------------------
                                //------------------------------
                                arrayPublicaciones[i].idPublicacion = proximoIdPublicacion();
                                arrayPublicaciones[i].isEmpty = 0;
                                break;
                            }

                        }
                     }
                }
                if (i==limiteCliente)
                    {
                        printf("ERROR NO EXISTE CLIENTE\n");
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

    }
    return retorno;
}


int publicacion_baja(EPublicacion* arrayPublicaciones,int limitePublicacion, int id)
{
    int retorno = -1;
    int i;
    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        retorno = -2;
        for(i=0;i<limitePublicacion;i++)
        {
            if(!arrayPublicaciones[i].isEmpty && arrayPublicaciones[i].idPublicacion==id)
            {
                arrayPublicaciones[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_modificacion(EPublicacion* arrayPublicaciones,int limitePublicacion, int id)
{
    int retorno = -1;
    int i;
    char buffer[51];
    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        retorno = -2;
        for(i=0;i<limitePublicacion;i++)
        {
            if(!arrayPublicaciones[i].isEmpty && arrayPublicaciones[i].idPublicacion==id)
            {
                if(!getValidString("\nDescripcion? ","\nEso no es una descripcion","El maximo es 50",buffer,51,2))
                {
                    retorno = 0;
                    strcpy(arrayPublicaciones[i].descripcion,buffer);
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

int publicacion_ordenar(EPublicacion* arrayPublicaciones,int limitePublicacion, int orden)
{
    int retorno = -1;
    int i;
    int flag=0;
    EPublicacion auxiliarEstructura;

    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        do
        {
            for(i=0;i<limitePublicacion-1;i++)
            {
                if(!arrayPublicaciones[i].isEmpty && !arrayPublicaciones[i+1].isEmpty)
                {
                    if((arrayPublicaciones[i].idCliente==arrayPublicaciones[i+1].idCliente && orden) || (arrayPublicaciones[i].idCliente==arrayPublicaciones[i+1].idCliente < 0 && !orden))
                    {
                        auxiliarEstructura = arrayPublicaciones[i];
                        arrayPublicaciones[i] = arrayPublicaciones[i+1];
                        arrayPublicaciones[i+1] = auxiliarEstructura;
                        flag= 1;
                    }
                }
            }
        }while(flag);
    }
    return retorno;
}

int publicacion_buscarLugarLibre(EPublicacion* arrayPublicaciones,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayPublicaciones != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayPublicaciones[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int publicacion_buscarIndicePorId(EPublicacion arrayPublicacion[],int limitePublicacion,int id)
{
    int i;
    int retorno = -1;
    if (arrayPublicacion != NULL && limitePublicacion >0)
    {
        for(i=0;i<limitePublicacion;i++)
            {
                if(arrayPublicacion[i].isEmpty == 0)
                {
                    if(arrayPublicacion[i].idPublicacion == id)
                    {
                        retorno = i;
                        break;
                    }
                }
            }
    }
    return retorno;
}

int proximoIdPublicacion(void)
{
    proximoId++;
    return proximoId++;
}


int publicacion_pausar(EPublicacion* arrayPublicaciones,int limitePublicacion)
{
    int retorno = -1;
    int i;
    int auxId;
    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        retorno = -2;
        for(i=0;i<limitePublicacion;i++)
        {
            if(!getValidInt("\nIngrese el ID: ","\nID no valido.", &auxId,0,999,2))
            {
                if(!arrayPublicaciones[i].isEmpty && arrayPublicaciones[i].idPublicacion==auxId && arrayPublicaciones[i].estado==0)
                {
                    {
                        retorno = 0;
                        arrayPublicaciones[i].estado=1;
                        printf("La publicacion ha sido pausada");
                    }
                   break;
                }
            }
        }
    }
    return retorno;
}

int publicacion_reanudar(EPublicacion* arrayPublicaciones,int limitePublicacion)
{
    int retorno = -1;
    int i;
    int auxId;
    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        retorno = -2;
        for(i=0;i<limitePublicacion;i++)
        {
            if(!getValidInt("\nIngrese el ID: ","\nID no valido.", &auxId,0,999,2))
            {
                if(!arrayPublicaciones[i].isEmpty && arrayPublicaciones[i].idPublicacion==auxId && arrayPublicaciones[i].estado==1)
                {

                    {
                        retorno = 0;
                        arrayPublicaciones[i].estado=0;
                        printf("La publicacion se ha reanudado");
                        //------------------------------
                        //------------------------------
                    }

                   break;
                }
            }
        }
    }
    return retorno;
}

int publicacion_imprimirPublicacionConCuit(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicaciones,int limitePublicacion)
{
    int flag = -1;
    int i,j;
    int retorno;
    publicacion_ordenar(arrayPublicaciones, limitePublicacion, 0);
    if(limiteCliente > 0 && arrayCliente != NULL && limitePublicacion >0 && arrayPublicaciones !=NULL)
    {

        for(i=0;i<limitePublicacion;i++)
        {
            if(!arrayPublicaciones[i].isEmpty && !arrayPublicaciones[i].estado)
            {
                printf(" -ID: %d -Rubro: %d -Estado: %d -Descripcion: %s \n",arrayPublicaciones[i].idPublicacion, arrayPublicaciones[i].rubro,arrayPublicaciones[i].estado, arrayPublicaciones[i].descripcion);
                for(j=0;j<limiteCliente;j++)
                {
                    if (arrayPublicaciones[i].idCliente==arrayCliente[j].idCliente && !arrayCliente[j].isEmpty)
                    {
                        printf("\n----------------------------------------------------------------\n");
                        printf("- CUIT: %s\n",arrayCliente[j].cuit);
                        retorno = 0;
                    }

                }
            }
        }
        if(flag == -1)
            printf("No hay publicaciones activas");
    }
    return retorno;
}







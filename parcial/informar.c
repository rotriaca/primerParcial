#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "informar.h"
#include "utn.h"

int info_listarPublicaciones(EPublicacion arrayPublicaciones[], ECliente arrayCliente[], int limitePublicacion, int limiteCliente)
{
    int retorno = -1, auxPubli, auxCliente, idPubli;

    printf("\nPUBLICACIONES ACTIVAS:\n");
    if (arrayCliente != NULL && arrayPublicaciones != NULL && limitePublicacion > 0 && limiteCliente > 0)
    {
        for(auxPubli=0; auxPubli<limitePublicacion; auxPubli++)
        {
            if(arrayPublicaciones[auxPubli].isEmpty == 0)
            {
                idPubli = arrayPublicaciones[auxPubli].idPublicacion;
                auxCliente = publicacion_buscarIndicePorId(arrayPublicaciones,limitePublicacion,idPubli);
                printf("Descripcion: %s, Rubro: %d, Id Cliente: %d, Nombre Cliente: %s, CUIT Cliente: %s\n\n",
                       arrayPublicaciones[auxPubli].descripcion,arrayPublicaciones[auxPubli].rubro,arrayCliente[auxCliente].idCliente,arrayCliente[auxCliente].nombre,arrayCliente[auxCliente].cuit);
                retorno = 0;
            }
            else
                printf("No se han cargado publicaciones.");
        }
    }
    return retorno;
}

int info_cantidadPorRubro(EPublicacion* arrayPublicaciones, int limitePublicaciones)
{
    int retorno=-1;
    int auxRubro;
    int i;
    int acumRubro;
    for(i=0; i<limitePublicaciones; i++)
    {
    if(!arrayPublicaciones[i].estado)
    {
        if(limitePublicaciones > 0 && arrayPublicaciones != NULL)
        {
            if(!getValidInt("\nIngrese el numero de Rubro:\n1- CELULARES.\n2- NOTEBOOKS.\n3- TABLETS. ","\nNumero no valido",&auxRubro,1,3,2))
            {
                for(i=0;i<limitePublicaciones;i++)
                {
                    if(arrayPublicaciones[i].rubro==auxRubro)
                    {
                        acumRubro++;
                    }
                }
                switch (auxRubro)
                {
                case 1:
                    printf("El Rubro CELULARES tiene %d publicaciones activas",acumRubro);
                    break;
                case 2:
                    printf("El Rubro NOTEBOOKS tiene %d publicaciones activas",acumRubro);
                    break;
                case 3:
                    printf("El Rubro TABLETS tiene %d publicaciones activas",acumRubro);
                    break;
                }
            }

        }
    }

    else
    {
        printf("\nERROR.DEBE CARGAR UNA PUBLICACION ANTES\n");
    }
    }
    return retorno;
}

int informe_cantidadPublicaciones(ECliente* arrayCliente, EPublicacion* arrayPublicaciones, int limiteCliente, int limitePublicacion, int id)
{
    int i;
    int maxPub=0;
    int maxPubActivas=0;
    int maxPubPausadas=0;
    int acumCliente, acumActivos, acumPausados;

    for(i=0;i<limitePublicacion-1;i++)
    {
        if(!arrayPublicaciones[i].isEmpty && !arrayPublicaciones[i+1].isEmpty)
        {
            if(arrayPublicaciones[i].idCliente==arrayPublicaciones[i+1].idCliente)
               {
                   acumCliente++;
                   if(!arrayPublicaciones[i].estado)
                        acumActivos++;
                   else
                        acumPausados++;
               }
            else
            {
                if(maxPub<acumCliente)
                {
                        maxPub=acumCliente;
                        if(arrayCliente[i].idCliente==arrayPublicaciones[i].idCliente)
                            printf("El cliente con mas publicaciones es: %s, %s, Id Nro %d", arrayCliente[i].apellido, arrayCliente[i].nombre, arrayCliente[i].idCliente);
                }
                if(maxPubActivas<acumActivos)
                {
                        maxPubActivas=acumActivos;
                        if(arrayCliente[i].idCliente==arrayPublicaciones[i].idCliente)
                            printf("El cliente con mas publicaciones ACTIVAS es: %s, %s, Id Nro %d", arrayCliente[i].apellido, arrayCliente[i].nombre, arrayCliente[i].idCliente);
                }
                if(maxPubPausadas<acumPausados)
                {
                        maxPubPausadas=acumPausados;
                        if(arrayCliente[i].idCliente==arrayPublicaciones[i].idCliente)
                            printf("El cliente con mas publicaciones PAUSADAS es: %s, %s, Id Nro %d", arrayCliente[i].apellido, arrayCliente[i].nombre, arrayCliente[i].idCliente);
                }

        }
    }
    }
return 0;
}


int info_rubroMasActivas(EPublicacion* arrayPublicaciones, int limitePublicaciones)
{
    int retorno=-1;
    int i;
    int acumCel=0;
    int acumNote=0;
    int acumTablet=0;
    for(i=0; i<limitePublicaciones; i++)
    {
    if(!arrayPublicaciones[i].estado)
    {
        if(limitePublicaciones>0 && arrayPublicaciones != NULL)
        {
            retorno=0;
            for(i=0;i<limitePublicaciones;i++)
            {
                switch(arrayPublicaciones[i].rubro)
                {
                    case 1:
                    {
                        acumCel++;
                        break;
                    }
                    case 2:
                    {
                        acumNote++;
                        break;
                    }
                    case 3:
                    {
                        acumTablet++;
                        break;
                    }
                    case 0:
                        continue;
                }
            }

            if(acumCel>acumNote && acumCel>acumTablet)
                printf("El Rubro con mas publicaciones activas es : CELULARES \n");
            else if(acumNote>acumCel && acumNote>acumTablet)
                printf("El Rubro con mas publicaciones activas es : NOTEBOOKS\n");
            else if(acumTablet>acumCel && acumTablet>acumNote)
                printf("El Rubro con mas publicaciones activas es : TABLETS\n");

            if(acumCel<acumNote && acumCel<acumTablet)
                printf("El Rubro con menos publicaciones activas es : CELULARES \n");
            else if(acumNote<acumCel && acumNote<acumTablet)
                printf("El Rubro con menos publicaciones activas es : NOTEBOOKS\n");
            else if(acumTablet<acumCel && acumTablet<acumNote)
                printf("El Rubro con menos publicaciones activas es : TABLETS\n");
            }
 }
}
 return retorno;

}

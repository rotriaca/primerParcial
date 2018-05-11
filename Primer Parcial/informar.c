#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "cliente.h"
#include "informar.h"
#include "utn.h"

int informarClientes(Cliente* arrayC, Publicacion* arrayP, int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        cliente_ordenar(arrayC, MAX_CLI, 0);
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !arrayP[i].isEmpty && !arrayC[i].estado)
            {
                if(arrayC[i].idCliente == arrayP[i].idCliente)
                {
                    printf("[RELEASE] - %d - %s - %s - %ld - %d\n",arrayC[i].idCliente, arrayC[i].nombre, arrayC[i].apellido, arrayC[i].cuitCliente, arrayC[i].isEmpty);
                    while
                    printf("[RELEASE] - %d - %s - %d\n",arrayP[i].idPublicacion, arrayP[i].textoAviso, arrayC[i].rubro);
                }
            }
        }
    }
    return retorno;
}

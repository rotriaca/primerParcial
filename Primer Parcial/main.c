#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"
#define QTY_CLI 100
#define QTY_PUB 1000

int main()
{
    Cliente arrayC[QTY_CLI];
    Publicacion arrayP[QTY_PUB];

    int menu;
    int auxiliarId;

    cliente_altaForzada(arrayC, QTY_CLI, "Juan", "Perez", 302117851, 0);
    cliente_altaForzada(arrayC, QTY_CLI, "Pedro", "Lopez", 30785963, 0);
    cliente_altaForzada(arrayC, QTY_CLI, "Laura", "Gomez", 30895411, 0);
    cliente_altaForzada(arrayC, QTY_CLI, "Luis", "Fulano", 309853121, 0);
    cliente_altaForzada(arrayC, QTY_CLI, "Pablo", "Piedra", 307453961, 0);

    cliente_init(arrayC,QTY_CLI);
    cliente_init(arrayP,QTY_PUB);

    do
    {
        getValidInt("1.Alta\n2.Baja\n3.Modificar\n4.Publicar\n5.Pausar publicacion\n6.Reanudar publicacion\n7.Imprimir\n8.Informar\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                //cliente_alta(arrayC, QTY_CLI);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_baja(arrayC,QTY_CLI,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_modificacion(arrayC,QTY_CLI,auxiliarId);
                break;
            case 4:
                cliente_mostrar(arrayC,QTY_CLI);
                break;
            case 5:
                publicacion_pausa("Ingrese id de la publicacion a pausar", "Error. Id no valido", QTY_PUB);
                break;
            case 6:
                publicacion_reanudar("Ingrese id de la publicacion a reanudar", "Error. Id no valido", QTY_PUB);
                break;
            case 7:
                informarClientes(Cliente* arrayC, Publicacion* arrayP, int limite)
                break;
        }

    }while(menu != 9);

    return 0;
}

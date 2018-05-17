#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"
#define QTY_CLIENTE 10
#define QTY_PUBLICACIONES 100

int main()
{
    ECliente arrayClientes[QTY_CLIENTE];
    EPublicacion arrayPublicaciones[QTY_PUBLICACIONES];
    int menu;
    int auxiliarId;
    cliente_init(arrayClientes,QTY_CLIENTE);
    publicacion_init(arrayPublicaciones, QTY_PUBLICACIONES);
    do
    {
        getValidInt("\n1.Alta Cliente\n2.Modificar dato de cliente \n3.Baja de cliente\n4.Publicar\n5.Pausar publicacion\n6.Reanudar publicacion\n7.Imprimir clientes\n8.Imprimir publicaciones\n9.Informar cliente\n10.Informar Publicaciones.\n11.Salir\n",
                    "\nIngreso invalido\n",&menu,1,11,1);
        switch(menu)
        {
            case 1:
                cliente_alta(arrayClientes,QTY_CLIENTE);
                break;
            case 2:
                cliente_mostrar(arrayClientes, QTY_CLIENTE);
                getValidInt("Ingrese ID a modificar","\nID invalido\n",&auxiliarId,0,200,2);
                cliente_modificacion(arrayClientes,QTY_CLIENTE,auxiliarId);
                break;
            case 3:
                cliente_mostrar(arrayClientes, QTY_CLIENTE);
                getValidInt("ID?","\nNumero no valido\n",&auxiliarId,0,200,2);
                cliente_baja(arrayClientes,QTY_CLIENTE,auxiliarId);
                break;
            case 4:
                cliente_mostrar(arrayClientes, QTY_CLIENTE);
                publicacion_alta(arrayPublicaciones, QTY_PUBLICACIONES, arrayClientes,QTY_CLIENTE);
                break;
            case 5:
                publicacion_mostrar(arrayPublicaciones,QTY_PUBLICACIONES);
                publicacion_pausar(arrayPublicaciones,QTY_PUBLICACIONES);
                break;
            case 6:
                cliente_mostrar(arrayClientes,QTY_CLIENTE);
                publicacion_reanudar(arrayPublicaciones,QTY_PUBLICACIONES);
                break;
            case 7:
                cliente_imprimirClientesConPublicacionesActivas(arrayClientes,QTY_CLIENTE,arrayPublicaciones,QTY_PUBLICACIONES);
                break;
            case 8:
                publicacion_imprimirPublicacionConCuit(arrayClientes,QTY_CLIENTE,arrayPublicaciones,QTY_PUBLICACIONES);
                break;
            case 9:

                break;
            case 10:
                info_cantidadPorRubro(arrayPublicaciones, QTY_PUBLICACIONES);
                info_rubroMasActivas(arrayPublicaciones, QTY_PUBLICACIONES);
                break;
        }

    }while(menu != 11);

    return 0;
}

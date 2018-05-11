#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct
{
    char textoAviso[64];
    int idCliente;
    int idRubro;
    int idPublicacion;
    int isEmpty;
    int estado;
}Publicacion;
#endif // PUBLICACION_H_INCLUDED

#include "cliente.h"

int publicacion_init(Publicacion* arrayP,int limite);
int publicacion_mostrar(Publicacion* arrayP,int limite);
int publicacion_mostrarDebug(Publicacion* arrayP,int limite);
int publicacion_alta(Publicacion* arrayP,int limite);
int publicacion_baja(Publicacion* arrayP,int limite, int id);
int publicacion_modificacion(Publicacion* arrayP,int limite, int id);
int publicacion_ordenar(Publicacion* arrayP,int limite, int orden);
int publicacion_pausa(Publicacion* arrayP, int limite, int idPublicacion);
//int buscarLugarLibre(Publicacion* arrayP,int limite);



#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED

#include "publicacion.h"
#include "cliente.h"

int info_rubroMasActivas(EPublicacion* arrayPublicaciones, int limitePublicaciones);
int info_cantidadPorRubro(EPublicacion* arrayPublicaciones, int limitePublicaciones);
int info_listarPublicaciones(EPublicacion arrayPublicaciones[], ECliente arrayCliente[], int limitePublicacion, int limiteCliente);
int info_cantidadPorRubro(EPublicacion* arrayPublicaciones, int limitePublicaciones);int informe_cantidadPublicaciones(ECliente* arrayCliente, EPublicacion* arrayPublicaciones, int limiteCliente, int limitePublicacion, int id);

#endif // INFORMAR_H_INCLUDED

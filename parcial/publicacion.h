#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct
{
    char descripcion[65];
    int idCliente;
    int rubro;
    int estado;
    //------------
    int idPublicacion;
    int isEmpty;
}EPublicacion;
#endif // PUBLICACION_H_INCLUDED


int publicacion_init(EPublicacion* array,int limite);
int publicacion_mostrar(EPublicacion* array,int limite);
int publicacion_mostrarDebug(EPublicacion* array,int limite);
//int publicacion_alta(EPublicacion* array,int limite);
int publicacion_modificacion(EPublicacion* array,int limite, int id);
int publicacion_ordenar(EPublicacion* array,int limite, int orden);
int publicacion_buscarLugarLibre(EPublicacion* arrayPublicaciones,int limite);
int publicacion_pausar(EPublicacion* array,int limite);
int publicacion_reanudar(EPublicacion* array,int limite);
int publicacion_buscarIndicePorId(EPublicacion* array,int limite, int id);
int publicacion_alta(EPublicacion* array,int limite, ECliente* arrayCliente, int LimiteCliente);
int publicacion_mostrarClientesConPublicacionesActivas(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicaciones,int limitePublicacion);
int publicacion_mostrarPublicacionesConCuitDelCliente(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicaciones,int limitePublicacion);
int proximoIdPublicacion();



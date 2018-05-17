#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    //------------
    char cuit[12];
    int idCliente;
    int isEmpty;
}ECliente;
#endif // CLIENTE_H_INCLUDED


int cliente_init(ECliente* array,int limiteCliente);
int cliente_mostrar(ECliente* array,int limiteCliente);
int cliente_mostrarDebug(ECliente* array,int limiteCliente);
int cliente_alta(ECliente* array,int limiteCliente);
int cliente_baja(ECliente* arrayCliente,int limiteCliente, int id);
int cliente_modificacion(ECliente* array,int limiteCliente, int id);
int cliente_ordenar(ECliente* array,int limiteCliente, int orden);
int buscarLugarLibre(ECliente* array, int limiteCliente);
int proximoIdCliente();
int cliente_getCuit(char mensaje[], char mensajeError[], char input[]);



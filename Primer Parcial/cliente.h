#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    long int cuitCliente;
    int idCliente;
    int isEmpty;
}Cliente;

#endif // CLIENTE_H_INCLUDED

int cliente_altaForzada(Cliente* arrayC, int limite, char* nombre, char* apellido, long int* cuit, int idCliente);
int cliente_alta(Cliente* arrayC,int limite);
int cliente_init(Cliente* arrayC,int limite);
int cliente_mostrarDebug(Cliente* arrayC,int limite);
int cliente_mostrar(Cliente* arrayC,int limite);
int cliente_baja(Cliente* arrayC,int limite, int id);
int cliente_modificacion(Cliente* arrayC,int limite, int id);
int cliente_ordenar(Cliente* arrayC,int limite, int orden);
long int getCuit(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,long int* resultado);

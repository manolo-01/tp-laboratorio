#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct
{
    int idPublicacion;
    int idCliente;
    int numeroDeRubro;
    char textoDelAviso[64];
    int estadoPublicacion;
    int isEmpty;
}Publicacion;
#endif // PUBLICACION_H_INCLUDED

int publicacion_init(Publicacion* array,int limite);
int publicacion_buscarPorId(Publicacion* array,int limite, int id);
int publicacion_baja(Publicacion* array,int limite, int id);

int publicacion_mostrar(Publicacion* array,int limite);
int publicacion_mostrarDebug(Publicacion* array,int limite);
int publicacion_alta(Publicacion* array,int limite);
int publicacion_modificacion(Publicacion* array,int limite, int id);
int publicacion_ordenar(Publicacion* array,int limite, int orden);




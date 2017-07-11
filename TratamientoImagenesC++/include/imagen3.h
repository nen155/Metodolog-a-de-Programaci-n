#ifndef _IMAGEN_H_
#define _IMAGEN_H_

struct Imagen {
	int fila, columna;
	unsigned char** fc;
};
//Reserva de recursos.
void Crear(Imagen& img, int f, int c);
// Devuelve el número filas de m
int Filas(const Imagen& img);
// Devuelve el número columnas de m
int Columnas(const Imagen& img);
// Hace img(i,j)=v
void Set(Imagen& img, int i, int j, unsigned char v);
// Devuelve img(i,j)
unsigned char Get(const Imagen& img, int i, int j);
// Libera recursos de m
void Destruir(Imagen& img);
// Carga imagen file en img
bool LeerImagen(const char file[], Imagen& img);
//Salva img en file
bool EscribirImagen(const char file[], const Imagen& img);

#endif

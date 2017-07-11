#include "imagenES.h"
#include "imagen.h"


//Reserva de recursos.
void Crear (Imagen& img, int f, int c){
	img.fila = f;
	img.columna = c;
	img.fc= new unsigned char[f*c];
}
// Devuelve el número filas de m
int Filas (const Imagen& img) {
	return img.fila;
}
// Devuelve el número columnas de m
int Columnas (const Imagen& img){
	return img.columna;
} 
// Hace img(i,j)=v
void Set (Imagen& img, int i, int j, unsigned char v){
	img.fc[i*img.columna+j] = v;
}
// Devuelve img(i,j)
unsigned char Get (const Imagen& img, int i, int j){
	return img.fc[i*img.columna+j];
}
// Libera recursos de m
void Destruir (Imagen& img){
	delete []img.fc;
} 
// Carga imagen file en img
bool LeerImagen(const char file[], Imagen& img){
	bool flag=false;
	if(LeerTipoImagen(file,img.fila,img.columna)==IMG_PGM){
		Crear(img,img.fila,img.columna);
		flag=LeerImagenPGM(file,img.fila,img.columna,img.fc);
	}
	else
		flag=false;
	return flag;
}
//Salva img en file
bool EscribirImagen(const char file[], const Imagen& img){
	return EscribirImagenPGM(file,img.fc,img.fila,img.columna);
}

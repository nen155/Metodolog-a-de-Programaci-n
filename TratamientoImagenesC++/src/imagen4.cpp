#include "imagenES.h"
#include "imagen4.h"

//Reserva de recursos.
void Crear (Imagen& img, int f, int c){
	int fila = 0;
	img.columna = c;
	img.lista = 0;
	for (; fila<f; fila++){
		Celda *aux = new Celda;
		aux->fila = new unsigned char[c];
		aux->sig= img.lista;
		img.lista = aux;
	}
	

}
// Devuelve el número filas de m
int Filas (const Imagen& img) {
	int fila = 0;
	Celda *aux = img.lista;
	while (aux != 0){
		aux = aux->sig;
		fila++;
	}
	return fila;
}
// Devuelve el número columnas de m
int Columnas (const Imagen& img){
	return img.columna;
} 
// Hace img(i,j)=v
void Set (Imagen& img, int i, int j, unsigned char v){
	Celda *aux = img.lista;
	int k = 0;
	while (k < i){
		aux = aux->sig;
		k++;
	}
	aux->fila[j] = v;
}
// Devuelve img(i,j)
unsigned char Get (const Imagen& img, int i, int j){
	Celda *aux = img.lista;
	int k = 0;
	while (k < i){
		aux = aux->sig;
		k++;
	}
	return aux->fila[j];
}
// Libera recursos de m
void Destruir (Imagen& img){
	while (img.lista != 0){
		Celda *aux = img.lista;
		img.lista = img.lista->sig;
		delete[]aux->fila;
		delete aux;
	}
} 
// Carga imagen file en img
bool LeerImagen(const char file[], Imagen& img){
	bool flag = false;
	int filas = 0;
	if(LeerTipoImagen(file,filas,img.columna)==IMG_PGM){
		Crear(img,filas,img.columna);
		unsigned char * buffer = new unsigned char[filas*img.columna];
		int buff = 0;
		flag= LeerImagenPGM(file,filas,img.columna,buffer);
		for (int i = 0; i < filas; i++){
			for (int j = 0; j < img.columna; j++,buff++){
				Set(img, i, j, buffer[buff]);
			}
		}
	}
	else
		flag=false;
	delete[]buffer;
	return flag;
}
//Salva img en file
bool EscribirImagen(const char file[], const Imagen& img){
	int filas = Filas(img);
	unsigned char * buffer = new unsigned char[filas*img.columna];
	bool flag = false;
	int buff = 0;
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < img.columna; j++, buff++){
			buffer[buff] = Get(img,i,j);
		}
	}
	flag = EscribirImagenPGM(file,buffer,filas,img.columna);
	delete[]buffer;
	return flag;
}

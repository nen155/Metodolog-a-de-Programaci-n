#include "imagenES.h"
#include "imagen3.h"

//Reserva de recursos.
void Crear (Imagen& img, int f, int c){
	img.fila = f;
	img.columna = c;
	img.fc = new unsigned char*[f];
	img.fc[0] = new unsigned char[f*c];
	for(int i = 1;i<f;i++){
		img.fc[i]= img.fc[i-1]+c;
	}
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
	img.fc[i][j] = v;
}
// Devuelve img(i,j)
unsigned char Get (const Imagen& img, int i, int j){
	return img.fc[i][j];
}
// Libera recursos de m
void Destruir (Imagen& img){
	delete[](img.fc[0]);
	delete []img.fc;
} 
// Carga imagen file en img
bool LeerImagen(const char file[], Imagen& img){
	bool flag = false;
	if(LeerTipoImagen(file,img.fila,img.columna)==IMG_PGM){
		Crear(img,img.fila,img.columna);
		unsigned char *buffer= new unsigned char[img.fila*img.columna];
		int buff = 0;
		flag= LeerImagenPGM(file,img.fila,img.columna,buffer);
		for (int i = 0; i < img.fila; i++){
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
	unsigned char *buffer = new unsigned char[img.fila*img.columna];
	bool flag = false;
	int buff = 0;
	for (int i = 0; i < img.fila; i++){
		for (int j = 0; j < img.columna; j++, buff++){
			buffer[buff] = Get(img,i,j);
		}
	}
	flag = EscribirImagenPGM(file,buffer,img.fila,img.columna);
	delete[]buffer;
	return flag;
}

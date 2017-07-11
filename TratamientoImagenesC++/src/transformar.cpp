#include "imagen.h"

void negativo(Imagen &img, const int &filas, const int &columnas){
	for (int f = 0; f < filas; f++){
		for (int c = 0; c < columnas; c++){
			Set(img, f, c, (255 - Get(img, f, c)));
		}
	}
}
void desplazar(Imagen &img, const int &filas, const int &columnas, int n){
	for (int f = 0; f < filas; f++){
		for (int c = 0; c < columnas; c++){
			Set(img, f, c, (Get(img, f, c) << n));
		}
	}
}

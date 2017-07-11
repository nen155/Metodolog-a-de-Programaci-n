#ifndef _TRANSFORMAR_H_
#define _TRANSFORMAR_H_
#include "imagen.h"

//Cambia los blancos por los negros y los negros por los blancos de una imagen dada
void negativo(Imagen &img, const int &filas, const int &columnas);

//Desplaza n bits la imagen hacia la izquierda
void desplazar(Imagen &img, const int &filas, const int &columnas, int n);

#endif

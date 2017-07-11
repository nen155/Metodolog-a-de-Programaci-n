#ifndef _PROCESAR_H_
#define _PROCESAR_H_
#include "imagen.h"
#include "transformacion.h"

void Procesar(Imagen &img,Transformaciones tr);

void negativo(Imagen &img, const int &filas, const int &columnas);

void desplazar(Imagen &img, const int &filas, const int &columnas, int n);
//Oculta el mensaje en la imagen.
// _____________________________________________________________________________

void ocultar(Imagen &img,char mensaje[]);
//Muestra el mensaje de la imagen que se le pase
// _____________________________________________________________________________

void revelar(const Imagen &img,char mensajeRevelado[]);

#endif

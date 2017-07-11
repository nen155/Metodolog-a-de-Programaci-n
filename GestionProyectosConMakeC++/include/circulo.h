#ifndef __CIRCULO_H_
#define __CIRCULO_H_

#include "punto.h"

using namespace std;

struct Circulo {
    Punto centro;
    double radio;
};
// Lee círculo en formato radio-centro, incluyendo '-' y leyendo "centro" con LeerPunto
Circulo LeerCirculo();

// Escribe círculo en formato radio-centro,  incluyendo '-' y escribiendo "centro" con EscribirPunto
void EscribirCirculo(Circulo c);

// Inicializa circulo c con centro y radio
void InicializarCirculo (Circulo& c, Punto centro, double radio);

// Devuelve del centro de c
Punto Centro (Circulo c);

// Devuelve el radio de c
double Radio (Circulo c);

// Devuelve el área del círculo c
double Area (Circulo c);

// Devuelve si p está en el interior del círculo c (distancia al centro menor que el radio)
bool Interior (Punto p, Circulo c);

// Devuelve la distancia de c1 a c2 (distancia entre los centros restándole los radios)
double Distancia (Circulo c1, Circulo c2);
#endif


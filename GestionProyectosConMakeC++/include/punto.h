#ifndef __PUNTO_H_
#define __PUNTO_H_

using namespace std;

// Definimos tipo Punto y Circulo ___________________________________________

struct Punto {
    double x,y;
};

// Funciones para manejar puntos __________________________________

// Lee un punto en el formato (x,y), incluyendo la lectura de '(' ',' y ')'
Punto LeerPunto();

// Escribe un punto en formato (x,y), incluyendo la escritura de '(' ',' y ')'
void EscribirPunto (Punto p);

// Inicializa un punto con dos valores cx cy
void InicializarPunto (Punto &p, double cx, double cy);

// Devuelve la coordenada X del punto p
double GetX (Punto p);

// Devuelve la coordenada Y del punto p
double GetY (Punto p);

// Devuelve la distancia euclídea entre p1 y p2
double Distancia (Punto p1, Punto p2);

// Devuelve el punto que está entre p1 y p2 (más cercano a igual distancia de p1 y p2)
Punto PuntoMedio (Punto p1, Punto p2);
#endif

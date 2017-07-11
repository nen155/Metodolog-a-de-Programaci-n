#include "punto.h"
#include <iostream>
#include <cmath> // sqrt, M_PI
using namespace std;


// Funciones para manejar puntos __________________________________

// Lee un punto en el formato (x,y), incluyendo la lectura de '(' ',' y ')'
Punto LeerPunto()
{
	char c;
	Punto p;
	cin>>c>>p.x>>c>>p.y>>c;
	return p;
}

// Escribe un punto en formato (x,y), incluyendo la escritura de '(' ',' y ')'
void EscribirPunto (Punto p)
{
	cout<<"("<<p.x<<","<<p.y<<")";
}

// Inicializa un punto con dos valores cx cy
void InicializarPunto (Punto &p, double cx, double cy)
{
	p.x = cx;
	p.y = cy;
}

// Devuelve la coordenada X del punto p
double GetX (Punto p)
{
	return p.x;
}

// Devuelve la coordenada Y del punto p
double GetY (Punto p)
{
	return p.y;
}

// Devuelve la distancia euclídea entre p1 y p2
double Distancia (Punto p1, Punto p2)
{
	return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}

// Devuelve el punto que está entre p1 y p2 (más cercano a igual distancia de p1 y p2)
Punto PuntoMedio (Punto p1, Punto p2)
{
	Punto p;
	p.x=(p1.x+p2.x)/2;
	p.y=(p1.y+p2.y)/2;
	return p;
}


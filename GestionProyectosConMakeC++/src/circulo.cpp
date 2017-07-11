#include "circulo.h"
#include <iostream>
#include <cmath> // sqrt, M_PI

using namespace std;

// Lee círculo en formato radio-centro, incluyendo '-' y leyendo "centro" con LeerPunto
Circulo LeerCirculo()
{
	char car;
	Circulo c;
	cin>>c.radio>>car;
	c.centro = LeerPunto();
	return c;
}

// Escribe círculo en formato radio-centro,  incluyendo '-' y escribiendo "centro" con EscribirPunto
void EscribirCirculo(Circulo c)
{
	cout<<c.radio<<"-";
	EscribirPunto(c.centro);
}

// Inicializa circulo c con centro y radio
void InicializarCirculo (Circulo& c, Punto centro, double radio)
{
	c.radio = radio;
	c.centro.x = centro.x;
	c.centro.y = centro.y;
}

// Devuelve del centro de c
Punto Centro (Circulo c)
{
	return c.centro;
}

// Devuelve el radio de c
double Radio (Circulo c)
{
	return c.radio;
}

// Devuelve el área del círculo c
double Area (Circulo c)
{
	return 2*M_PI*c.radio*c.radio;
}

// Devuelve si p está en el interior del círculo c (distancia al centro menor que el radio)
bool Interior (Punto p, Circulo c)
{
	bool flag=false;
	double d = Distancia(p,c.centro);
	if(d<=c.radio)
		flag=true;
	return flag;
}

// Devuelve la distancia de c1 a c2 (distancia entre los centros restándole los radios)
double Distancia (Circulo c1, Circulo c2)
{
	return (c1.radio - c2.radio);
}


#include <cstdlib>
#include "transformar.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
	int n=0;
	n = atoi(argv[1]);
	Imagen img;
	Crear(img, 0, 0);
	if (LeerImagen(argv[2], img)){
		desplazar(img, Filas(img), Columnas(img), n);
		if (EscribirImagen(argv[3], img))
			Destruir(img);
		else
			cout << "Error de escritura de la imagen";
	}
	else
		cout << "La imagen no se ha podido leer compruebe el nombre de la imagen";

}

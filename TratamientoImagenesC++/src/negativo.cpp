
#include "transformar.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
	Imagen img;
	Crear(img, 0, 0); 
	if(LeerImagen(argv[1], img)){
		negativo(img,Filas(img),Columnas(img));
		if(EscribirImagen(argv[2], img))
			Destruir(img);
		else
			cout << "Error de escritura de la imagen";
	}
	else
		cout << "La imagen no se ha podido leer compruebe el nombre de la imagen";

}

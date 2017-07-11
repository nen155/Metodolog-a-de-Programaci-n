#include "procesar.h"
#include <iostream>

using namespace std;

int main(int arg, char * argv[]){
	Imagen img(0,0);
	if(img.LeerImagen(argv[1])){
		Transformaciones tr;
		if(tr.LeerTransformacion(argv[2])){
			Imagen salidaimg(img);
			Procesar(salidaimg,tr);
			if(!salidaimg.EscribirImagen(argv[3]))
				cerr<<"Error de escritura de la imagen";
		}
		else
			cerr<<"Error de lectura de transformacion";
	}
	else
		cerr<<"Error de lectura de la imagen";
}

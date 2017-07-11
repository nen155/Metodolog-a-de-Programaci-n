#include "procesar.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
	
	Imagen img(0,0);

	if (img.LeerImagen(argv[1])){
		const int MAXSMS= 1000000;
		char mensajeRevelado[MAXSMS];
		revelar(img,mensajeRevelado);	
		cout << mensajeRevelado;
	}
	else
		cerr << "Error de escritura de la imagen";
}

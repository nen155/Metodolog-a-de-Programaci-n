#include "procesar.h"
#include <iostream>
#include <assert.h>

using namespace std;

int main(int argc, char * argv[]){
	Imagen img(0,0);
	if (img.LeerImagen(argv[1])){
		const int MAXSMS= 1000000;
		char mensajeAOcultar[MAXSMS];
		cin.get (mensajeAOcultar,100000,'\0');  
		Imagen imgmensaje(img);
		ocultar(imgmensaje,mensajeAOcultar);
		cout << "Ocultando...";
		if(!imgmensaje.EscribirImagen(argv[2]))
			cerr << "Error de escritura de la imagen";
	}
	else
		cerr << "Error de lectura de la imagen";
}

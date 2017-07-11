#include "transformacion.h"
#include <iostream>

using namespace std;

Transformaciones operator+(Transformaciones tr1, Transformaciones tr2){
	Transformaciones aux;
	for(int i=0;i<tr1.GetNumTrans();i++){
		aux.Set(i,tr1.Get(tr2.Get(i)));
	}
	return aux;
}

int main(int argc, char *argv[]){
	Transformaciones res;
	Transformaciones tr1;
	Transformaciones tr2;
	if(tr1.LeerTransformacion(argv[3])){
		if(tr2.LeerTransformacion(argv[4])){
			res = tr1 + tr2;
		}
		else
			cerr << "Error de lectura en la transformacion"<< argv[4] << endl;
	}
	else
		cerr << "Error de lectura en la transformacion" << argv[3] << endl;
	if(!res.EscribirTransformacion((char)argv[1][0],argv[2]))
		cerr << "Error de escritura de la transformacion" << argv[2] << endl;
}

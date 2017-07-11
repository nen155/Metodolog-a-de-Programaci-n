#include "generadores.h"

Transformaciones Negativo(){
	Transformaciones tr;
	for (int i = 0; i < tr.GetNumTrans(); i++){
		tr.Set(i,255 -i);
	}
	return tr;
}
Transformaciones Desplazar(int n=0){
	Transformaciones tr;
	for (int i = 0; i < tr.GetNumTrans(); i++){
		tr.Set(i,i<<n);
	}
	return tr;
}
Transformaciones Umbralizar(int v=0){
	Transformaciones tr;
	for (int i = 0; i < tr.GetNumTrans(); i++){
		if(i<=v)
			tr.Set(i,0);
		else
			tr.Set(i,255);
	}
	return tr;
}
Transformaciones Brillo(int d=0){
	Transformaciones tr;
	for (int i = 0; i < tr.GetNumTrans(); i++){
		if(i+d<0)
			tr.Set(i,0);
		else
			if(i+d>255)
				tr.Set(i,255);
			else
				tr.Set(i,i+d);
	}
	return tr;
}

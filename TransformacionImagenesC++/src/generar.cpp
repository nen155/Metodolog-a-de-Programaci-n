#include "transformacion.h"
#include "generadores.h"
#include <iostream>

using namespace std;

bool compareCadCEmilio(char * c1, char * c2){
	bool flag=true;
	int cnum1 = strlenEmilio(c1),cnum2= strlenEmilio(c2),total=0 ;
	if(cnum1 != cnum2)
		flag=false;
	for(; total<cnum1 && c1[total] == c2[total];total++);
	if(total!=cnum1)
		flag=false;
	return flag;
}
int montaEntero(char * c){
	int tam = strlenEmilio(c);
	int* nums = new int[tam];
	int numtotal = 0;
	for (int i = 0; i < tam; i++){
		nums[i] = (c[i]) - 48;
		for (int j = 0; j < tam - 1-i; j++){
			nums[i] = nums[i] * 10;
		}
		numtotal = numtotal + nums[i];
	}
	return numtotal;
}
int main(int argc, char *argv[]){
	if(argc==0){
		cout<<"Para generar una transformación debe escribir los siguientes comandos:\n"
		<<"generar <b ó t (donde b es el archivo en binario y t es texto)>"
		<<" <ruta y nombre del archivo> <transformación para guardar en el archivo> "
		<<"[parámetro dependiente de la transformación]\n"
		<<"Las transformaciones posibles son: \nnegativo \ndesplazar <numero de bits a"
		<<" desplazar de la imagen>\numbralizar <grado de umbralización>\n"
		<<"brillo <grado de brillo en la imagen>"<<endl;
	}
	else
	{
		Transformaciones tr;
		if(compareCadCEmilio(argv[3],(char *)"negativo")){
			tr = Negativo();
			tr.EscribirTransformacion((char)argv[1][0],argv[2]);
		}
		else{
			int num = montaEntero(argv[4]);
			if(compareCadCEmilio(argv[3],(char *)"desplazar")){
				if (num!=0)
					tr = Desplazar(num);
				tr.EscribirTransformacion((char)argv[1][0], argv[2]);
			}
			else
			{
				if(compareCadCEmilio(argv[3],(char *)"umbralizar")){
					if (num != 0)
						tr = Umbralizar(num);
					tr.EscribirTransformacion((char)argv[1][0], argv[2]);
				}
				else{
					if(compareCadCEmilio(argv[3],(char *)"brillo")){
						if (num != 0)
							tr = Brillo(num);
						tr.EscribirTransformacion((char)argv[1][0], argv[2]);
					}
					else{
						cerr<<"La transformacion no existe o está mal escrita pruebe con el comando generar sin parametros para la ayuda"<<endl;
					}
				}
			}
		}
				
	}
}

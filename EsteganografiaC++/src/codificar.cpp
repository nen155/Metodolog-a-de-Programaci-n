/**
  * @file codificar.cpp
  * @brief Fichero que contiene las funciones para codificar un mensaje en una imagen, tanto para introducirlo como para leerlo.
  * 
  * Permite la E/S de archivos de tipo PGM,PPM
  *
  */
#include "imagenES.h"
#include "codificar.h"
#include <iostream>
#include <cstring>

using namespace std;

//Para mostrarle mensajes al usuario por teclado
void lecturaTeclado(char nombre[],const int max,char mensaje[]){
	cout<<mensaje;
	cin.getline(nombre,max,'\n');
}

// _____________________________________________________________________________

bool compruebaLectura(char nombre[]){
	if(strlen(nombre)>100){
		cout<<"El mensaje tiene que ser de menos de 100 caracteres";
		return true;
	}
	else return false;
}

//Introduce en la variable bncolor el tipo de imagen leido.
// _____________________________________________________________________________

void lecturaTipoIMG(const char nombre[],TipoImagen &bncolor,int &filas,int &columnas){
	bncolor= LeerTipoImagen(nombre,filas,columnas);
}

//Dependiendo del tipo de imagen leido hace una lectura u otra y devuelve si la lectura ha tenido exito.
// _____________________________________________________________________________

bool lecturaIMG(const char nombre[],const TipoImagen bncolor,int &filas,int &columnas,unsigned char buffer[]){
	bool flag=false;
	switch(bncolor){
		case IMG_PGM:
			if(LeerImagenPGM(nombre,filas,columnas,buffer))
				flag=true;
			else
				flag=false;
		break;
		case IMG_PPM:
			if(LeerImagenPPM(nombre,filas,columnas,buffer))
				flag=true;
			else
				flag=false;
		break;
		case IMG_DESCONOCIDO:
			flag=false;
		break;
	return flag;
	}
}

// _____________________________________________________________________________

void ocultar(unsigned char imagen[],char mensaje[]){
	for(int i=0;i<strlen(mensaje);i++){
		for(int k=0;k<8;k++){
			//DESPLAZA A LA DERECHA EL ÚLTIMO BIT DE IMAGEN
			if(((imagen[k]<<7)&(mensaje[i]<<k))!=0){
				imagen[k]=imagen[k]|1; //HACE UN OR CON EL NUMERO 00000001 CON EL MENSAJE
			}else{
				imagen[k]=imagen[k]&~1; //HACE UN AND EL NUMERO 11111110
			}
		}
	}	
	
}

// _____________________________________________________________________________

void revelar(unsigned char imagen[],char mensajeRevelado[]){
	int i=0;
	do{
		mensajeRevelado[i]=0;//Pongo a 0 el caracter con el que voy a operar para que no haya basura
		//Recorro los 8 bytes primeros de la imagen
		for(int k=0;k<8;k++){
			mensajeRevelado[i]=((mensajeRevelado[i]>>k)|(imagen[k]<<7));//Desplazo el mensaje tantas posiciones como bytes haya recorrido y el byte de la imagen también lo desplazo para sólo tener algo de la forma 10000000
		}
		i++;

	}while(mensajeRevelado[i]!='\0');//Voy metiendo caracteres hasta llegar al caracter \0
}

// _____________________________________________________________________________

int main(){
	//Declaración de variables para utilizar durante la ejecución
	const int MAXBUFFER= 1000000;
	const int MAXNOMBRE= 100;
	char nombre_imagen[MAXNOMBRE];
	char nombreIMGSalida[MAXNOMBRE];//Nombre de la imagen de salida
	unsigned char buffer[MAXBUFFER];
	int filas,columnas;//Las filas y columnas de la imagen
	TipoImagen bncolor;//El tipo de imagen que es
	char mensaje[MAXNOMBRE];//EL mensaje que se ocultará o revelará de la imagen
	bool flag=true;//Para saber si falla la ocultación o revelación
	int n=0;
	do{
		cout<<"Introduce una opción:\n(1) Ocultar\n(2) Revelar\n(0) Exit\n";
		cin>>n;
		cin.ignore();
		switch(n){
		case 1:
			lecturaTeclado(nombre_imagen,MAXNOMBRE,(char *)"Introduce el nombre de la imagen para codificar el mensaje:");//Pido la imagen a usar
			lecturaTipoIMG(nombre_imagen,bncolor,filas,columnas);//Compruebo el tipo de imagen
			lecturaIMG(nombre_imagen,bncolor,filas,columnas,buffer);//Pido la imagen a usar
			lecturaTeclado(nombreIMGSalida,MAXNOMBRE,(char *)"Introduce el nombre de la imagen de salida:");//Pido el nombre de la imagen a la salida
			do{
				lecturaTeclado(mensaje,MAXNOMBRE,(char *)"Introduce el mensaje a ocultar:");//Pido el mensaje al usuario
			}while(compruebaLectura(mensaje)); //Compruebo que tenga menos de 100 caracteres
			cout<<"Ocultando...\n";
			ocultar(buffer,mensaje);
				if(bncolor==IMG_PGM){
					flag=EscribirImagenPGM(strcat(nombreIMGSalida,".pgm"),buffer,filas,columnas);
				}
				else if(bncolor==IMG_PPM){
					flag=EscribirImagenPPM(strcat(nombreIMGSalida,".ppm"),buffer,filas,columnas);
				}else flag=false;

				if(flag)
					cout<<"Ocultación con éxito!\n ¿Que más desea hacer?\n";
				else
					cout<<"Upps..El mensaje no se ha podido ocultar\n ¿Que más desea hacer?\n";
		break;
		case 2:
			lecturaTeclado(nombre_imagen,MAXNOMBRE,(char *)"Introduce el nombre de la imagen con el mensaje codificado:");//Pido la imagen a usar
			lecturaTipoIMG(nombre_imagen,bncolor,filas,columnas);//Compruebo el tipo de Imagen a descodificar
			lecturaIMG(nombre_imagen,bncolor,filas,columnas,buffer);//Pido la imagen a usar
			cout<<"Revelanado el mensaje...\n";
			revelar(buffer,mensaje);
			cout<<"El mensaje es: "<<mensaje <<"\n¿Que más desea hacer?\n";
		break;
		case 0:
		break;
		}	
	}while(n!=0);	
}


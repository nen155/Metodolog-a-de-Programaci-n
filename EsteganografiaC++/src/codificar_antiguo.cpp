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
#include <cmath>

using namespace std;
///PASAR AL MAIN
const int MAXBUFFER= 1000000;
const int MAXNOMBRE= 100;
char nombre_imagen[MAXNOMBRE];
unsigned char buffer[MAXBUFFER];
////PASAR AL MAIN

void lecturaNombreIMG(char nombre[]){
	cout<<"Introduce el nombre de la imagen codificada:";
	cin>>nombre;
}
void lecturaNombreIMG(){
	cout<<"Introduce el nombre de la imagen a leer:";
	cin>>nombre_imagen;
}
void lecturaMensaje(char mensaje[]){
	cout<<"Introduce el mensaje a ocultar:";
	cin>>mensaje;
}
void lecturaTipoIMG(TipoImagen &bncolor,int &filas,int &columnas){
	bncolor= LeerTipoImagen(nombre_imagen,filas,columnas);
}
bool lecturaIMG(const TipoImagen bncolor,int &filas,int &columnas){
	bool flag=false;
	switch(bncolor){
		case IMG_PGM:
			if(LeerImagenPGM(nombre_imagen,filas,columnas,buffer))
				flag=true;
			else
				flag=false;
		break;
		case IMG_PPM:
			if(LeerImagenPPM(nombre_imagen,filas,columnas,buffer))
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
unsigned char decimal(unsigned char num[]){
	unsigned char decimal=0;
	for(int i=0;i<num.length();i++){
		decimal = decimal + num[i]*pow(2,i);
	}
	return decimal;
}
void binario(unsigned char numeroaPasar,unsigned char numeroBin[]){
	short int i=0;
	while(numeroaPasar>1){
		numeroBin[i]=numeroaPasar%2;
		numeroaPasar=numeroaPasar/2;
		i++;
	}
}
bool ocultar(unsigned char imagen[],char mensaje[]){
	bool flag=true;
	unsigned char imagenBin[8];
	unsigned char mensajeBin[8];
	unsigned char totalimagenBin[imagen.length()];
	int indiceIMG=0;
	for(int k=0;k<mensaje.length();k++){
		binario(mensaje[k],mensajeBin);
		for(int l=0;l<mensajeBin.length();l++,indiceIMG++){
			binario(imagen[indiceIMG],imagenBin);
			imagenBin[7] = mensajeBin[l];
			totalimagenBin[l] = decimal(imagenBin);
		}
	}
	EscribirImagenPGM(nombreIMGSalida,totalimagenBin,filas,columnas);
	return flag;
}

bool revelar(unsigned char imagen[],char mensajeRevelado[]){
	bool flag=true;

	return flag;
}
int main(){
	int filas,columnas;
	TipoImagen bncolor;
	char mensaje[100];
	char nombreIMGSalida[100];
	int n=0;
	do{
		cout<<"Introduce una opción:\n(1) Ocultar\n(2) Revelar\n(0) Exit\n";
		cin>>n;
		switch(n){
		case 1:
			lecturaNombreIMG();
			lecturaTipoIMG(bncolor,filas,columnas);
			lecturaIMG(bncolor,filas,columnas);
			lecturaMensaje(mensaje);
			lecturaNombreIMG(nombreIMGSalida);
			cout<<"Ocultando...\n";
			if(ocultar(buffer,mensaje))
				cout<<"Ocultación con éxito!\n ¿Que más desea hacer?\n";
			else
				cout<<"Upps..El mensaje no se ha podido ocultar\n ¿Que más desea hacer?\n";
		break;
		case 2:
			lecturaNombreIMG();
			lecturaTipoIMG(bncolor,filas,columnas);
			lecturaIMG(bncolor,filas,columnas);
			cout<<"Revelanado el mensaje...\n";
			if(revelar(buffer,mensaje))
				cout<<"Mensaje revelado con éxito!\n ¿Que más desea hacer?\n";
			else
				cout<<"Upps..El mensaje no se ha podido revelar!\n ¿Que más desea hacer?\n";
		break;
		case 0:
		break;
		}	
	}while(n!=0);	
}


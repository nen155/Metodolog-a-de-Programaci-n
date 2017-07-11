 #include "procesar.h"

void Procesar(Imagen &img,Transformaciones tr){
	for (int f = 0; f < img.Filas(); f++){
		for (int c = 0; c < img.Columnas(); c++){
			img.Set(f, c, (tr.Get(img.Get(f, c))));
		}
	}
}

//Oculta el mensaje en la imagen.
// _____________________________________________________________________________

void ocultar(Imagen &img,char mensaje[]){
	int g = strlenEmilio(mensaje),k=0, i=0,n=0;
	for(;i<g;i++){
		for(int l=7;l>=0;k++,l--){
			if ((1 & (mensaje[i] >> l)) == 1){//Compruebo si el mensaje tiene un 1 desde el bit mas significativo hacia atrás
					img.Set(n,k,img.Get(n,k)|1); //HACE UN OR CON EL NUMERO 00000001 CON EL MENSAJE
			}else{
					img.Set(n,k,img.Get(n,k)&~1); //HACE UN AND EL NUMERO 11111110
			}
		}
		if (k == img.Columnas()){
			n++; k = 0;
		}
	}
	for (int j=0; j < 8; j++,k++){//Meto el cero de fin de frase
		img.Set(n,k,img.Get(n,k)&~1);
	}
	
}
//Muestra el mensaje de la imagen que se le pase
// _____________________________________________________________________________

void revelar(const Imagen &img,char* mensajeRevelado){
	int i=0,k=0,j=0;
	do{
		mensajeRevelado[i] = 0;
		for (int u = 0; u < 8; u++){
			
			if ((img.Get(j,k) & 1) == 1)//Compruebo si es un 1
				mensajeRevelado[i] = mensajeRevelado[i] | 1; //Añado el 1
			if (u<7) //Si es el ultimo caracter no desplazo los bits
				mensajeRevelado[i] = mensajeRevelado[i] << 1; 
			k++;
		}
		if (k == img.Columnas()){
			j++; k = 0;
		}
	}while(mensajeRevelado[i++]!='\0');//Hago el bucle mientras que no obtenga un 0
}

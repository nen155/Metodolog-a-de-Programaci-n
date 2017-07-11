#include "imagen.h"

		// Hace img(i,j)=v
		void Imagen::Set (int i, int j, unsigned char v){
			buffer[i*columnas+j] = v;
		} 
		// Devuelve img(i,j)
		unsigned char Imagen::Get (int i, int j) const{
			return buffer[i*columnas+j];
		} 
		// Carga img desde fichero “nombre”
		bool Imagen::LeerImagen(const char nombre[]){
			bool flag=false;
			if(LeerTipoImagen(nombre,filas,columnas)==IMG_PGM){
				buffer = new unsigned char[filas*columnas];
				flag = LeerImagenPGM(nombre,filas,columnas,buffer);
			}
			else
				flag=false;
			return flag;
		}
		// Salva img en nombre
		bool Imagen::EscribirImagen(const char nombre[]) const{
			return EscribirImagenPGM(nombre,buffer,filas,columnas);
		}
		// Constructor Copia
		Imagen::Imagen(const Imagen &img){
			if(img.buffer ==0){
				columnas = filas = 0;
				buffer = 0;
			}
			else
			{
				columnas = img.columnas;
				filas = img.filas;
				buffer = new unsigned char[filas*columnas];
				for(int i=0;i<filas;i++){
					for(int j=0;j<columnas;j++){
						Set(i,j,img.Get(i,j));
					}
				}
			}
		}
		Imagen::Imagen(){
			columnas = filas = 0;
			buffer = 0;
		}
		Imagen::Imagen(int f,int c){
			filas = f;
			columnas = c;
			buffer = new unsigned char[f*c];
		}
		Imagen::~Imagen(){
			delete[]buffer;
		}


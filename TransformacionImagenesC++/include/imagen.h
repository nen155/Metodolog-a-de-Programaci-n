/**
* @file imagen.h
* @brief Fichero cabecera para el uso de ficheros tipo imagen
*
* Permite la E/S de archivos de tipos PGM,PPM
*
*/

#ifndef _IMAGEN_H_
#define _IMAGEN_H_
#include "imagenES.h" 
class Imagen {
	private:
		int filas,columnas;
		unsigned char *buffer;
	public:
		/**
		* @brief Función Filas
		*
		* Devuelve el numero de filas total en el buffer de la imagen
		* @return El numero de filas.
		*
		* @see Columnas
		*/
		// Devuelve el número de filas de buffer
		int Filas () const{
			return filas;
		}
		/**
		* @brief Función Columnas
		*
		* Devuelve el numero de columnas total en el buffer de la imagen
		* @return El numero de columnas.
		*
		* @see Columnas
		*/
		// Devuelve el número de columnas de buffer
		int Columnas () const{
			return columnas;
		} 
		/**
		* @brief Función Set
		*
		* Pone un dato en la fila y columna del buffer de la imagen.
		*
		* @param i Fila donde queremos poner el dato.
		* @param j Columna donde queremos poner el dato.
		* @param v El dato que queremos asignar en el buffer de la imagen.
		*
		* @see Get
		*/
		void Set (int i, int j, unsigned char v); // Hace img(i,j)=v
		/**
		* @brief Función Get
		*
		* Obtiene el dato de la fila y columna del buffer de la imagen.
		*
		* @param i Fila de donde queremos obtener el dato.
		* @param j Columna de donde queremos obtener el dato.
		*
		*
		* @see Set
		*/
		unsigned char Get (int i, int j) const; // Devuelve img(i,j)
		/**
		* @brief Función Leer una imagen de disco
		*
		* Recibe como entrada un parámetro, con la ruta y el nombre de la imagen
		* y almacena en un buffer los bytes de esa imagen.
		* @param nombre Ruta del archivo y el nombre de la imagen ej: "d:\datos\lenna.pgm".
		* @return si ha  tenido éxito en la lectura.
		*
		* @see EscribirImagen
		*/
		bool LeerImagen(const char nombre[]); // Carga img desde fichero “nombre”
		/**
		* @brief Función Escribir una imagen en disco
		*
		* Recibe como entrada un parámetro, con la ruta y el nombre de la imagen
		* y escribe en disco la imagen resultante.
		* @param nombre Ruta del archivo y el nombre de la imagen ej: "d:\datos\lenna.pgm".
		* @return si ha  tenido éxito en la escritura.
		*
		* @see LeerImagen
		*/
		bool EscribirImagen(const char nombre[]) const; // Salva img en nombre
		/**
		* @brief Función Constructor copia
		*
		* Recibe como entrada un parámetro, con la imagen que se quiere copiar
		* y la copia en la imagen a la que se le asigne y la que haya sido construida con este construtor.
		* @param img Una imagen con los datos que se quieran copiar en otra.
		* @return Una imagen copia de la pasada por parámetro.
		*
		* @see Imagen
		*/
		Imagen(const Imagen &img);
		/**
		* @brief Función Constructor con parámetros
		*
		* Recibe como entrada dos parámetros, uno el total de filas y otro el total de columnas
		* y crea una imagen con el tamaño de fxc.
		* @param f El total de filas de la imagen.
		* @param c El total de columnas de la imagen.
		*
		* @see Imagen
		*/
		Imagen(int f,int c); //Constructor de imagen
		/**
		* @brief Función Constructor por defecto
		*
		* Crea una imagen con filas y columnas a 0 y el buffer a 0.
		*
		* @see ~Imagen
		*/
		Imagen(); //Construtor por defecto de imagen
		/**
		* @brief Función Destructor por defecto
		*
		* Borra la dirección donde apunta el puntero buffer.
		*
		* @see ~Imagen
		*/
		~Imagen(); //Destructor de imagen
};
#endif

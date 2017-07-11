#ifndef _TRANSFORMACION1_H_
#define _TRANSFORMACION1_H_
#include <fstream>
#include "imagen.h"

using namespace std;

class Transformaciones{
	private:
		int trans[256];
		char magica[8];
		int numtrans;
	public:
		/**
		* @brief Función Get Numero de Transformaciones
		*
		* Obtiene el numero de transformaciones total.
		*
		*
		* @return Un entero con el numero de transformaciones total.
		*
		*/
		int GetNumTrans() const{
			return numtrans;
		}
		/**
		* @brief Función Get
		*
		* Obtiene un dato de la posicion del array de transformaciones.
		*
		* @param n Posicion donde obtener poner el dato.
		*
		* @return Una transformacion del array.
		*
		* @see Set
		*/
		int Get(int n) const{
			return trans[n];
		}
		/**
		* @brief Función Set
		*
		* Pone un dato en la posicion del array de transformaciones.
		*
		* @param n Posicion donde queremos poner el dato.
		* @param t El dato que queremos asignar al array de transformaciones.
		*
		* @see Get
		*/
		void Set(int n, int t){
			trans[n] = t;
		}
		/**
		* @brief Función Leer la cabecera de la transformacion
		*
		* Recibe como entrada un parámetro, con el flujo para obtener los caracteres
		* necesarios hasta completar la cabecera "MP-TRF-X".
		* @param ifs El flujo de datos de tipo ifstream de lectura.
		* @return si ha  tenido éxito en la lectura.
		*
		* @see LeerTransformaciones
		*/
		bool LeerCabeceraTrans(ifstream &ifs);
		/**
		* @brief Función Leer el numero total de transformaciones
		*
		* Recibe como entrada un parámetro, con el flujo para obtener los caracteres
		* necesarios hasta completar la cabecera "256 " Se salta el caracter siguiente al número de
		* transformaciones.
		* @param ifs El flujo de datos de tipo ifstream de lectura.
		* @return si ha  tenido éxito en la lectura.
		*
		* @see LeerTransformaciones
		*/
		bool LeerNumTrans(ifstream &ifs);
		/**
		* @brief Función Comprobar binario o texto.
		*
		* Devuelve un caracter para comprobar si es Binaria la lectura o modo Texto.
		* @return Un caracter B o T dependiendo de si es binario el archivo o texto.
		*
		* @see LeerTransformaciones
		*/
		char CompruebaBinTex();
		/**
		* @brief Función Comprueba Fichero
		*
		* Comprueba si el fichero es correcto mirando su cabecera.
		* @return si tiene el formato correcto la cabecera.
		*
		* @see LeerTransformaciones
		*/
		bool CompruebaFich();
		/**
		* @brief Función Leer la transformacion en formato binario
		*
		* Recibe como entrada un parámetro, con el flujo y le asigna
		* al array de transformaciones los datos que haya leido de disco.
		* @param ifs El flujo de datos de tipo ifstream de lectura.
		* @return si ha  tenido éxito en la lectura.
		*
		* @see LeerTransformaciones
		*/
		bool LeerTrasnformacionesBin(ifstream &ifs);
		/**
		* @brief Función Leer la transformacion en formato texto
		*
		* Recibe como entrada un parámetro, con el flujo y le asigna
		* al array de transformaciones los datos que haya leido de disco.
		* @param ifs El flujo de datos de tipo ifstream de lectura.
		* @return si ha  tenido éxito en la lectura.
		*
		* @see LeerTransformaciones
		*/
		bool LeerTrasnformacionesText(ifstream &ifs);
		/**
		* @brief Función Leer la transformacion
		*
		* Recibe como entrada un parámetro, con el nombre y ruta de la transformacion
		* y utiliza los metodos necesarios para componer un objeto transformacion
		* con su formato correcto.
		* @param file El nombre y ruta de la imagen en disco.
		* @return si ha  tenido éxito en la lectura.
		*
		* @see LeerTransformaciones
		*/
		bool LeerTransformacion(const char file[]);
		/**
		* @brief Función Escribir la transformacion
		*
		* Recibe como entrada dos parámetros, uno con el nombre y ruta de la transformacion
		* y otro con el formato si es binario o texto el archivo a escribir en disco. 
		* 
		* @param bintext El formato del archivo 'B' ->Binario, 'T'->Texto.
		* @param file El nombre y ruta de la imagen en disco.
		* @return si ha  tenido éxito en la escritura.
		*
		* @see LeerTransformaciones
		*/
		bool EscribirTransformacion(const char &bintext,const char file[]);
		/**
		* @brief Función Constructor por defecto
		*
		* Asigna a numero de transformaciones a 0.
		*
		* @see Transformaciones
		*/
		Transformaciones();
		
};
/**
* @brief Función Longitud de una cadena
*
* @param cadena Cadena-c para medir su longitud.
*
* @return el numero de caracteres de la cadena.
*/
int strlenEmilio(char cadena[]);
#endif

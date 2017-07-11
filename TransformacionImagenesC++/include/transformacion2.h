#include <fstream>
#include "imagen.h"

#ifndef _TRANSFORMACION2_H_
#define _TRANSFORMACION2_H_

using namespace std;

class Transformaciones{
	private:
		int *trans;
		char magica[8];
		int numtrans;
	public:
		int GetNumTrans() const{
			return numtrans;
		}
		int Get(int n) const{
			return trans[n];
		}
		void Set(int n, int t){
			trans[n] = t;
		}

		bool LeerCabeceraTrans(ifstream &ifs);
		bool LeerNumTrans(ifstream &ifs);
		char CompruebaBinTex();
		bool LeerTrasnformacionesBin(ifstream &ifs);
		bool LeerTrasnformacionesText(ifstream &ifs);
		bool CompruebaFich();
		bool LeerTransformacion(const char file[]);
		bool EscribirTransformacion(const char &bintext,const char file[]);
		Transformaciones();
		Transformaciones(int num);
		Transformaciones(const Transformaciones &tr);
		Transformaciones& operator=(const Transformaciones &tr1);
		~Transformaciones();
		
};
int strlenEmilio(char cadena[]);
#endif

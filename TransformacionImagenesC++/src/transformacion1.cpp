#include "transformacion1.h"

int strlenEmilio(char cadena[]){
	int i=0;
	while(cadena[i]!='\0')
		i++;
	return i;
}
bool Transformaciones::LeerCabeceraTrans(ifstream &ifs){
	bool flag=true;
	int cont=0;
	char c = ifs.get();
	magica[cont++] = c;
	while(ifs.good() && cont!=8){
		c = ifs.get();
		magica[cont++] = c;
	}
	if(cont!=8)
		flag=false;
	return flag;
}
bool Transformaciones::LeerNumTrans(ifstream &ifs){
	bool flag=false;
	if(ifs){
		int n = 0;
		while (ifs.good()&&n!=256){
			ifs >> n;
			numtrans = n;
		}
		ifs.ignore();
		flag=true;
	}
	return flag;
}
char Transformaciones::CompruebaBinTex(){
	return magica[7];
}
bool Transformaciones::LeerTrasnformacionesBin(ifstream &ifs){
	bool flag = true;
	
	if (ifs) {
		ifs.read(reinterpret_cast<char*>(trans), sizeof(int)*256);
		ifs.close();
	}
	else
		flag = false;
	return flag;
}
bool Transformaciones::LeerTrasnformacionesText(ifstream &ifs){
	bool flag = true;
	int i=0;
	int n = 0;
	if (ifs) {
		while(ifs.good()){
			ifs>>n;
			Set(i++,n);
		}
  	}
	else
		flag=false;
  	return flag;
}
bool Transformaciones::CompruebaFich(){
	bool flag=false;
	int i=0,k=0;
	char* t= (char*) "MP-TRF-T";
	char* b= (char*) "MP-TRF-B";
	for(;i<strlenEmilio(magica) && (magica[i] == t[i]);i++);
	for(;k<strlenEmilio(magica) && (magica[k] == b[k]);k++);	
	if(k==8 || i==8)
		flag=true;
	
	return flag;
}
bool Transformaciones::LeerTransformacion(const char file[]){
	ifstream ifs(file, ios::binary | ios::in);
	bool flag=true;
	if(ifs){
		if(LeerCabeceraTrans(ifs)){
			if(LeerNumTrans(ifs)){
				if(CompruebaFich()){
					if (CompruebaBinTex() == 'B')
								flag = LeerTrasnformacionesBin(ifs);
					else if(CompruebaBinTex()=='T')
						flag = LeerTrasnformacionesText(ifs);
				}else
					flag=false;
			}
			else	
				flag=false;
		}
		else
			flag=false;
	}
	else
		flag=false;
				
	return flag;
}
bool Transformaciones::EscribirTransformacion(const char &bintext,const char file[]){
	bool flag = true;
	if(bintext=='b'){
		ofstream ofs(file, ios::out | ios::binary);
		ofs << "MP-TRF-B " << numtrans << "\n";
		ofs.write(reinterpret_cast<char*>(trans), sizeof(int)* 264);
		if(!ofs)
			flag=false;
		ofs.close();
	}
	else if(bintext =='t'){
		ofstream ofs(file,ios::out);
		ofs<<"MP-TRF-T "<<numtrans<<endl;
		for (int i = 0; i < numtrans; i++){
			ofs << trans[i];
			ofs << endl;
		}
		if(!ofs)
			flag=false;
		ofs.close();
	}
	return flag;
}
Transformaciones::Transformaciones(){
	numtrans=256;
}



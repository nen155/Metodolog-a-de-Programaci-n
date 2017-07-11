#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "Nombre" << setw(17) << "Apellidos" << setw(17) << "Edad" << setw(17) << "Estado" << endl;
	cout << "Javier" << setw(14) << "Moreno" << setw(18) << 20 << setw(17) << "S" << endl;
	cout << "Juan" << setw(16) << "Espejo" << setw(17) << 8 << setw(17) << "S" << endl;
	cout << "Antonio" << setw(16) << "Caballero" << setw(14) << 53 << setw(17) << "C" << endl;
	cout << "Jose" << setw(14) << "Cano" << setw(21) << 27 << setw(17) << "C" << endl;
	cout << endl;
	cout << setfill('_');
	cout << 123.456 <<  setw(14) << 26.467872 <<  setw(8) << 876.3876 << endl;
	cout << 17.26734 <<  setw(9) << 0.22 <<  setw(15)  << 18972.1  << endl;
	cout << 456.5 <<  setw(6)  << 2897.0 <<  setw(8) << 2832.3 << endl;
}

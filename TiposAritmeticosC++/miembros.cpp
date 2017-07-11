#include <iostream>;
#include <limits>;

using namespace std;

int main(){

	cout << "Maximo del char: "<< numeric_limits<char>::max() << "\n";
	cout << "Maximo del signed char: "<< numeric_limits<signed char>::max() << "\n";
	cout << "Maximo del unsigned char: "<< numeric_limits<unsigned char>::max() << "\n";
	cout << "Maximo del signed short int: "<< numeric_limits<signed short int>::max() << "\n";
	cout << "Maximo del signed int: "<< numeric_limits<signed int>::max() << "\n";
	cout << "Maximo del signed long int: "<< numeric_limits<signed long int>::max() << "\n";
	cout << "Maximo del unsigned short int: "<< numeric_limits<unsigned short int>::max() << "\n";
	cout << "Maximo del unsigned short int: "<< numeric_limits<unsigned short int>::max() << "\n";
	cout << "Maximo del float: "<< numeric_limits<float>::max() << "\n";
	cout << "Maximo del double: "<< numeric_limits<double>::max() << "\n";
	cout << "Maximo del char: "<< numeric_limits<char>::min() << "\n";
	cout << "Maximo del signed char: "<< numeric_limits<signed char>::min() << "\n";
	cout << "Maximo del unsigned char: "<< numeric_limits<unsigned char>::min() << "\n";
	cout << "Maximo del signed short int: "<< numeric_limits<signed short int>::min() << "\n";
	cout << "Maximo del signed int: "<< numeric_limits<signed int>::min() << "\n";
	cout << "Maximo del signed long int: "<< numeric_limits<signed long int>::min() << "\n";
	cout << "Maximo del unsigned short int: "<< numeric_limits<unsigned short int>::min() << "\n";
	cout << "Maximo del unsigned short int: "<< numeric_limits<unsigned short int>::min() << "\n";
	cout << "Maximo del float: "<< numeric_limits<float>::min() << "\n";
	cout << "Maximo del double: "<< numeric_limits<double>::min() << "\n";
	int i=numeric_limits<int>::max()+1;
	cout << "Numero max +1: " << i << "\n";
	int c =numeric_limits<int>::min()-1;
	cout << "Numero min -1: " << c << "\n";
}

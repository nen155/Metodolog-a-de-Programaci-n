#include <iostream>

using namespace std;

int main()
{
	int k,j;
	cout << "Dime un numero del 0 al 25: " ;
	cin >> k;
	j=k;
	k= k+97;
	j =j+65; 
	cout << (char)k << " " << (char)j << endl;
}

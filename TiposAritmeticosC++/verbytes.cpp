#include <iostream>

using namespace std;

int main(){
	char j;
	j=cin.get();
	while(j!='\n'){
		cout<<j<<" "<<(int)j<<endl;
		j=cin.get();
	}
}

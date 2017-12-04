
#include <iostream>

using namespace std;

int main(){
	

	char xp[5] = "Hello!";
	
	char * p = xp;

	xp++;

	cout << *p << endl;
	
	*xp++;

	cout << *p;
	return 0;
}

#include <string>
#include <iostream>
#include <fstream>
#include "hw4_aux.h"



using namespace std;



int main() {

	Anagram A;

	if (A.openFile( )) {
				
	A.loadArray();
	
	}
	else
		cout << "File could not be opened. Goodbye.";
	
	A.checkWord( );
	
	//system("pause");
}


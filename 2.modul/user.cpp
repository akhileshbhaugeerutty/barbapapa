#include "stack.hpp"
#include <iostream>

using namespace std;


int main()
{
	try{
		Stack::push('t');
		Stack::push('e');
		Stack::push('s');
		Stack::push('t');
	
		Stack::pop();
	
		cout << Stack::pop() << "\n";   // doit afficher 's'
	

		while(true)
			Stack::push('c');
	}
	catch(Stack::Overflow) {
		cout << "Error overflow \n";
	}
}


/* compilation séparée:

g++ -c stack.cpp
g++ -c user.cpp
g++ user.o stack.o 

*/

/* Remarque on peut aussi compiler directement avec 

g++ user.cpp stack.cpp

mais ce n'est pas dans l'esprit "prog modulaire"
*/ 


#include "stack.hpp"
#include <iostream>

using namespace std;


int main()
{
	try{
		Stack::stack s1 = Stack::create();
		Stack::push(s1,'t');
		Stack::push(s1,'e');
		
		Stack::stack s2 = Stack::create();
		
		Stack::push(s2,'s');
		Stack::push(s2,'t');
		
		Stack::pop(s2);
	
		cout << Stack::pop(s2) << "\n";   // doit afficher 's'
		

		Stack::destroy(s1);
		Stack::destroy(s2);
	}
	catch(Stack::Overflow) {
		cout << "Error overflow \n";
	}
	catch(Stack::Underflow) {
		cout << "Error underflow \n";
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


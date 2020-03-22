#include <iostream>
#include "stack.hpp"

using namespace std;
Stack s_var1(10);

void f(Stack& s_ref, int i)
{
	Stack s_var2(i);
	Stack* s_ptr = new Stack(3);
	
	s_ptr->push('d');
	s_ptr->push('e');
	s_ptr->push('f');
	s_ptr->affiche();
	delete s_ptr;
	s_var1.push('a');
	s_var1.pop();
	s_var2.push('b');
	s_ref.push('c');
	s_ref.affiche();
}

main(){
	try{
		s_var1.affiche();
		Stack s(5);
		s.push('r');
		s.affiche();
		f(s,5);
		s.affiche();
		s_var1.affiche();
	}
	catch(Stack::Bad_size)
		{cout << "Bad Size" << endl;}
	catch(Stack::Underflow)
		{cout << "Underflow" << endl;}
	catch(Stack::Overflow)
		{cout << "Overflow" << endl;}
}

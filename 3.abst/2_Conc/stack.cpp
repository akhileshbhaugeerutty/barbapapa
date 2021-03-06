#include "stack.hpp"
#include <iostream>

using namespace std;

Stack::Stack(int m){
  if(m > 100) throw(Bad_size());
  max_size = m;
  v = new char[max_size];
  top = 0;
  
}


Stack::~Stack(){
  delete[] v; //quand on a utilisé new
}

void Stack::push(char c){
  if (top > max_size-1) throw(Overflow());
  v[top] = c ;
  top++;
  
}

char Stack::pop(){
  top--;
  if (top < 0) throw(Underflow());
  return(v[top]);

}

void Stack::affiche(){
  for(int i = 0; i < top; i++){
    cout << v[i] << endl;
  }

}

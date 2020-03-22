#include "stack.hpp"

using namespace std;

namespace Stack{
  const int nb = 16;
  const int size = 100;
  struct Rep{
    char tab[size];
    int m = -1;
  };
  Rep stacks[nb];
  
}


Stack::stack Stack::create(){
  int i = 0;
  while(stacks[i].m != -1) i++;
  if(i==nb) throw(Overflow());
  stacks[i].m = 0;
  return(stacks[i])	
}

void Stack::destroy(stack s){
  s.m = -1;
}

void Stack::push(stack s, char c){
  if (s.m > size-1) throw(Overflow());
  s.tab[s.m] = c ;
  s.m++;
}
  

char Stack::pop(stack s){
  s.m--;
  if (s.m < 0) throw(Underflow());
  return(s.tab[s.m]);
}


  

#include "stack.hpp"

using namespace std;

namespace Stack{
  const int max = 10;
  char tab[max];
  int nb = 0;
  
   
    }



void Stack::push(char c){
  if (nb > max-1) throw(Overflow());
  tab[nb] = c ;
  nb++;
  
}

char Stack::pop(){
  nb--;
  if (nb < 0) throw(Overflow());
  return(tab[nb]);

}


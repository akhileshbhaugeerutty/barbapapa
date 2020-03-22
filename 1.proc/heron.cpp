#include <iostream>
#include <cmath>
using namespace std;


float racine(int x, float eps){
  float y = 10;
  int i = 0 ;
  while(eps < abs(y - x/y)){
    y = 0.5*(y + x/y);
    i++;
  }
  return(i);}

  
  
main(){
  cout << sqrt(144)<< endl;
  double  eps = 10e-9;
  cout << racine(144, eps)<< endl;


}


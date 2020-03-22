#include <iostream>
using namespace std;


void feig(float u, double x0, int n){
  int i = 0;
  double x = x0; 
  while(i < n){
    cout <<"x"<< i<< " = "<<  x << "\t" << endl;
    x = 1-u*x*x;
    i++;
  }
}




main(){
  float u;
  cout << "u = " ;
  cin >> u;
  float  x0;
  cout << "x0 = ";
  cin >> x0;
  int n;
  cout << "n = " ;
  cin >> n;
  feig(u, x0,n);
  
}


    
    
  

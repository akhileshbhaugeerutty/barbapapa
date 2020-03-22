#include <iostream>
#include <random>

using namespace std;

void alloc(int**,int);

main(){
  int **ppi;
  int n;
  cout << "n?="<<endl;
  cin>>n;
  alloc(ppi, n);
}


void alloc(int **ppi, int n){
  ppi = new int*[n];
  for (int i=0; i<n; i++){
    *(ppi+i) = new int[n];
  }
};



#include <iostream>
#include <cmath>
using namespace std;


void Pascal(int n){
  int **Pas;
  Pas = new int*[n];
  for (int i; i<n; i++){
    Pas[i] = new int[i+1];
    Pas[i][0] = Pas[i][i] = 1;
    for(int j = 1; j<i-1;j++){
      Pas[i][j] = Pas[i-1][j-1] + Pas[i-1][j];
    }
  }
};


void print(int **Pas, int n){
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cout << Pas[i][j] << '\t';
    }
    cout << endl;
  }
  cout << endl;
};

main(){
  int **Pas;
  int n = 6;
  Pas = Pascal(n);
  print(Pas,n);
}

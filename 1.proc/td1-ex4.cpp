#include <iostream>
#include <cmath>
using namespace std;

void exchange(int *x, int *y){
  int a = *y;
  *y = *x;
  *x = a;
}



int** alloc(int n){
  int** ppi = new int*[n];
  for (int i=0; i<n; i++){
    *(ppi+i) = new int[n];
  }
  return ppi;
};


void ralea(int **ppi, int n){
  srand(time(0));
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      ppi[i][j] = rand()%100;
};



void affiche(int **ppi, int n){
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cout << ppi[i][j] << '\t';
    }
    cout << endl;
  }
  cout << endl;
};

 
int maxi(int **ppi, int n){
  int max = ppi[0][0];
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (ppi[i][j] > max){
	max = ppi[i][j];}
    }
  }
  return(max);
};


main(){
  int **ppi;
  int n = 3;
  ppi = alloc(n);
  ralea(ppi, n);
  affiche(ppi,n);
  cout << maxi(ppi,n) << endl;

}


/*double  maximum(float *t){
  
  float max = t[0][0];
  for (int i = 0, i < 3, i++){
    for (int j = 0, j< 3; j++){
      if (t[i][j] > max){
	max = t[i][j];
      }
    }
  }
  return max;
}
*/

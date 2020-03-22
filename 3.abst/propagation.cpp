#include <iostream>
using namespace std;

/* La classe Board{} modelise un echiquier n x n cases.
La fonction initializ() determine les n cases malades initialement,
elles sont stockees dans le tableau b[i][j]=true si la case i+1,j+1 est malade
Exemple de sortie ecran:

n=4
Situation initiale:
1eme case malade ?
1 1
2eme case malade ?
2 3
3eme case malade ?
3 2
4eme case malade ?
4 4



Ensuite la fonction propag() propage la maladie aux cases ayant deux cases voisines malades
-- voisin signifie ici au-moins un cote en commun --

Exemple:
** Step 0 **
|X| | | |
| | |X| |
| |X| | |
| | | |X|
** Step 1 **
|X| | | |
| |X|X| |
| |X|X| |
| | | |X|
** Step 2 **
|X|X| | |
|X|X|X| |
| |X|X|X|
| | |X|X|
** Step 3 **
|X|X|X| |
|X|X|X|X|
|X|X|X|X|
| |X|X|X|
** Step 4 **
|X|X|X|X|
|X|X|X|X|
|X|X|X|X|
|X|X|X|X|


*/


class Board{
public:
	Board(int);
	void initializ();
        void propag();
    

private:
	int n;
	bool **b,**bb;
	
	void affich();
};

main(){
	int n;
	cout << "n = ";
	cin>>n;
	Board B(n);
	B.initializ();
	B.propag();

}

Board::Board(int m){
  n = m;
  /* b =  new bool[n][n];
     bb = new bool[n][n];*/

  b = new bool*[n];
  bb = new bool*[n];

  for(int i=0;i<n;i++){
    b[i] = new bool[n]; //on peut ecrire *(b+i)
    bb[i] = new bool[n];
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      b[i][j] = false; // *(*(b+i)+j)
      bb[i][j] = false;
    }
  }
}


void Board::initializ(){
  int x,y;
  for(int i=0; i<n; i++){
      cout << i+1 << "eme case malade?" << endl;
      cin >> x >> y;
      b[x-1][y-1] = true; 
 }
  affich();
}
 

void Board::affich(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      if(b[i][j] == false)
	cout << "| ";
      else
	cout << "|X" ;
    cout << "|" << endl;
  }
}


void Board::propag(){
  int s;
  bool test=true;
  int g = 1;
  while(test){

    test=false;

    for(int i=0;i < n; i++){
      for(int j=0;j < n; j++){
	if(i != 0 && i!=n-1 && j!=0 && j!=n-1){
	  s = b[i-1][j] + b[i+1][j] + b[i][j-1] + b[i][j+1];}

	else{
	  if(i==0){
	    if(j==0){
	      s = b[i+1][j] + b[i][j+1];}
	    else if(j==n-1){
	      s = b[i+1][j] + b[i][j-1];}
	    else{
	      s= b[i][j-1] + b[i][j+1] + b[i+1][j];}
	  }
	
	  if(i==n-1){
	    if(j==0){
	      s = b[i-1][j] + b[i][j];}
	    else if(j==n-1){
	      s = b[i-1][j] + b[i][j-1];}
	    else{
	      s= b[i][j-1] + b[i][j+1] + b[i-1][j];}
	  }

	  if(j==0){
	    if(i==0){
	      s = b[i+1][j] + b[i][j+1];}
	    else if(i==n-1){
	      s = b[i-1][j] + b[i][j+1];}
	    else{
	      s= b[i-1][j] + b[i][j+1] + b[i+1][j];}
	  }
	  if(j==n-1){
	    if(i==0){
	      s = b[i][j-1] + b[i+1][j];}
	    else if(i==n-1){
	      s = b[i-1][j] + b[i][j-1];}
	    else{
	      s= b[i-1][j] + b[i][j-1] + b[i+1][j];}
	  }
	}
      	
      if(s >= 2 && !b[i][j])
	bb[i][j] = test = true;
      }
    }

  
    for(int i=0;i < n; i++){
      for(int j=0;j < n; j++){
	if(bb[i][j]){
	  b[i][j] = true;
	  bb[i][j] = false;
	}
      }
    }
    cout << "Step " << g << endl ;
    affich();
    g++;
  }
}
   

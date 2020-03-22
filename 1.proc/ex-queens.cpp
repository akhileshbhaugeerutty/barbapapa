#include <iostream>

using namespace std;

/********************************************************************************************
                                                                         
Ce programme doit déterminer une solution du placement de n reines (queens Q) sur un échiquier
de taille n x n (échiquier normal cas n=8)

Aucune des reines ne doit en menacer une autre selon les règles classiques du jeu d'échec

Clairement, si c'est possible il doit y avoir exactement une reine par colonne

Les solutions sont codées au format x1 x2 x3 ... xn
où xi est la hauteur de la Reine de la ième colonne

La class Queen{} modelise l'echiquier

Exemples d'éxécution:
1)
n=4


| | |Q| |
|Q| | | |
| | | |Q|
| |Q| | |

2)
n=8


|Q| | | | | | | |
| | | | | | |Q| |
| | | | |Q| | | |
| | | | | | | |Q|
| |Q| | | | | | |
| | | |Q| | | | |
| | | | | |Q| | |
| | |Q| | | | | |




*******************************************************************************************/


class Queens{
public:
	Queens(int);
	void essayer(int);
	
private:
	int n;
	int *solution;
	bool *ligne,*diag,*diago;
	
	void affich();
};

main(){
	int n;
	cout << "n=";
	cin>>n;
	cout<<endl;
	Queens Q(n);
	Q.essayer(0);
}

Queens::Queens(int m){
  n = m;
  solution = new int[n];
  ligne = new bool[n];

  for (int i = 0; i <n; i++){
    solution[i] = n;
    ligne[i] = true;
  } // true = Libre
  
  diag = new bool[2*n - 1];
  diago = new bool[2*n-1];
  for (int i = 0; i<2*n-1; i++){
    diag[i] = diago[i] = true;
  }
}


void Queens::affich(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      if(solution[j] == i)
	cout << "|Q";
      else
	cout << "| " ;
    cout << "|" << endl;
  }
  cout<<endl;
}

void Queens::essayer(int j){
  for (int i=0; i<n; i++){
    if(ligne[i] && diag[i+j] && diago[n-1-i+j]){
	 solution[j] = i;
	 ligne[i] =  diag[i+j] = diago[n-1-i+j] = false;
	 if(j < n-1){
	   essayer(j+1);
	 }
	 else{
	   affich();
	   break;
	 }
	 ligne[i] =  diag[i+j] = diago[n-1-i+j] = true;
     }
  }
}

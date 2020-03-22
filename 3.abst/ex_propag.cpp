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
	cout << "n=";
	cin>>n;
	Board B(n);
	B.initializ();
	B.propag();
}

#include <iostream>

using namespace std;

struct compte{
	int b,n;
	int *nombre;
	void compter(int);
};

main(){
	int b,n;
	cout << "n=";
	cin>>n;
	cout<<endl;
	cout << "b=";
	cin>>b;
	cout<<endl;
	int* binaire;
	binaire=new int[n];
	compte compt;
	compt.n=n;
	compt.b=b;
	compt.nombre=binaire;
	compt.compter(0);
}

void compte::compter(int c){
	for (int i=0; i < b; i++){
		nombre[c]=i;
			if(c==n-1){
				for(int j=0;j<n;j++)
					cout << nombre[j] << " ";
				cout << endl;
			}
			else 
				compter(c+1);
	}
}


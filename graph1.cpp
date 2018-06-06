//masih dalam tahap pembelajaran harap dimaklumi terima kasih

#include<iostream>
#include<iomanip>
 
using namespace std;

void PrintMat(int **mat, int n)
{
	int i, j;
 
	cout<<"\n\n"<<setw(4)<<"";
	for(i = 0; i < n; i++)
		cout<<setw(3)<<"("<<i+1<<")";
	cout<<"\n\n";
 
	for(i = 0; i < n; i++)
	{
		cout<<setw(3)<<"("<<i+1<<")";
		for(j = 0; j < n; j++)
		{
			cout<<setw(4)<<mat[i][j];
		}
		cout<<"\n\n";
	}
}
 
int main()
{
	int i, v, e, j, v1, v2;
	char ulang;
 	
	do{
 		system("cls");
		cout<<"Masukkan jumlah vertex dalam graf : ";
		cin>>v;
 		
		int **graph;
		graph = new int*[v];
 		
		for(i = 0; i < v; i++){
			graph[i] = new int[v];
			for(j = 0; j < v; j++)graph[i][j] = 0;
		}
 		
		cout<<"\nMasukkan jumlah edge dalam graf : ";
		cin>>e;
 		
		for(i = 0; i < e; i++){
			cout<<"\nEdge "<<i+1<<" menghubungkan ";
			cout<<"Vertex(1): ";
			cin>>v1;
			cout<<"dengan Vertex(2): ";
			cin>>v2;
						
			graph[v1-1][v2-1] = 1;
			graph[v2-1][v1-1] = 1;
		}
	
		cout << "\nHasil dari graf adalah : "<<endl;
			
		PrintMat(graph, v);
		
		cout<<"\nApakah anda ingin mengulangi program?(y/n)  ";
     	cin>>ulang;
	}
	while(ulang=='y' || ulang=='Y');
}

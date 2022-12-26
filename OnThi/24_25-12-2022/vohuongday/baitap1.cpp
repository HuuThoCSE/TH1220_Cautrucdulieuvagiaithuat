#include "vohuongday.h"
void DnoioiDT(Graph g, int n, int e) {
	int i,j;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (g[i][j]==1 && CountEdge(g,n,e,i)==1 && i!=j)
			 	cout<<j<<'\t';
}


void Indinhc1 (Graph g, int n, int e){
	cout<<"Dinh co canh noi vs dinh treo la: "; 
	for(int i=1; i<=n; i++)
		if(CountEdge(g,n,e,i) == 1){	
			int j = 1; 
			while (j<=n && g[i][j]==0 && i!=j)
				j++;
			cout<<j<<'\t';
		}
}

void DinhNoiTreo(Graph g, int n, int e){
	for(int i=1; i<=n; i++){
		if(CountEdge(g,n,e,i)==1){
			for(int j=1; j<=n; j++){
				if(g[i][j]==1 && i!=j){
					cout<<j<<'\t';
					break;
				}
			}
		}
	}
}

main(){
	Graph g;
	int n, e;
	do{
		cout<<"Nhap so dinh cua do thi : "; cin>>n;
	} while(n<=0 || n>=maxn);
	Initialize(g, n, e);
	cout<<"=====DO THI VUA KHOI TAO====="<<endl;
	PrintGraph(g, n, e);
	cout<<"Nhap so canh cua do thi : "; cin>>e;
	ReadGraph(g, n, e);
	cout<<"=====DO THI VUA NHAP====="<<endl;
	PrintGraph(g, n, e);
	
//	int K;
//	cout << "Nhap so luong canh noi: "; cin >> K;
	cout<<"\nTH1: ";
	DnoioiDT(g, n, e);
	
	cout<<"\nTH2: ";
	Indinhc1(g, n, e);
	
	cout<<"\nTH3: ";
	DinhNoiTreo(g, n, e);
}

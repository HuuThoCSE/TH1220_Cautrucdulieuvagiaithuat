#include<iostream>
using namespace std;
const int maxn = 20;
typedef int Graph[maxn][maxn];

void Initialize(Graph &g, int n, int &e) {
int i, j;
for(i=1; i<=n; i++)
for(j=1; j<=n; j++)
if (i==j) g[i][j]=1;
else g[i][j]=0;
e=0;
}

void PrintGraph(Graph g, int n, int e) {
int i, j;
for(i=1; i<=n; i++){
 		for(j=1; j<=n; j++)
 			cout<<g[i][j]<<'\t';
 			cout<<endl;
 	}
}

void ReadGraph(Graph &g, int n, int e) {
int i, d1, d2;
for(i=1; i<=e; i++){
 		cout<<"Nhap dinh dau va dinh cuoi : "; cin>>d1>>d2;
g[d1][d2]=1;
g[d2][d1]=1;
 	}
}

//??m s? c?nh n?i c?a m?t ??nh
int CountEdge(Graph g, int n, int e, int d) { 	
int i, dem=0;
for(i=1; i<=n; i++)
 		if(g[d][i]==1) dem++;
return dem-1;
}




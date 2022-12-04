//chapter5_l4_p105
#include<iostream>
using namespace std;

// Khai bao CDTL Do thi
const int maxn = 20;
typedef int ElementType;
struct Node {
	ElementType Element;
	Node* Next;
};
typedef Node* List;
typedef List Graph[maxn];

//1. Khoi tao do thi rong (dc chính = 1) - Trong g[i] phai co i
void Initialize(Graph &g, int n, int &e){
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n;j++){
			g[i] = new Node;
			g[i]->Next->Element = i;
			g[i]->Next->Next = NULL;
		}	
	e=0;
}

//3. Them canh (= Them 2 cung (d1, d2) va (d2, d1)) - Goi 2 lan InsertArc
//void InsertEdge(Graph &g, int n, int &e, int d1, int d2){
//	g[d1][d2]=1;
//	g[d2][d1]=1;
//	e++;
//}

//4. Xoa  canh (= Xoa 2 cung (d1, d2) va (d2, d1)) - Goi 2 lan DeleteArc


//5. Dem So canh noi cua mot dinh
int CountEdge(Graph g, int n, int e, int d){
	int i, dem=0;
	for(i=1; i<=n; i++)
		if(g[d]->Element==1) dem++;
	return dem-1;
}

//6. Them dinh
void InsertVertice(Graph &g, int &n, int &e, int sc){
	int d;
	g[g+1] = new Node;
	g[n+1]->Next->Element = NULL;
	g[n+1]->Next->Next = NULL;
	for(int i=1; i<=sc; i++){
		cout << "Nhap dinh noi voi dinh moi: "; cin >> d;
		InsertEdge(g, n, e, n+1, d);
	}
	n++;
}

//7. Xoa dinh
void DeleteVertice(Graph &g; i<=n; i++){
	if (i!=d)
		DeleteEdge(g,n,i,d);
	else {
		Node &t = g[i]->Next;
		g[i]->Next = NULL;
		delete t;
	}
	for (i=d; i<= n+1; i++)
		g[i] = g[i+1];
	n--;
	for(i=1; i<=n; i++){
		t = g[i];
		while(t->Next!=NULL){
			if(t->Next->Element > d)
				t->Next->Element--;
			t=t->Next;
		}
	}
		
}

main(){
	Graph g;
	int n, e, d1, d2, d, sc;
	do {
		cout << "Nhap so dinh cua do thi: ";
		cin >> n;
	} while (n <= 0 || n >= maxn);
	Initialize(g, n, e);
	cout << "=====DO THI VUA KHOI TAO====="<< endl;
	PrintGraph(g, n, e);
	cout << "Nhap so canh cua do thi: ";
	cin >> e;
	ReadGraph(g, n, e);
	cout << "=====DO THI VUA NHAP====="<< endl;
	PrintGraph(g, n, e);
	cout << endl;
}



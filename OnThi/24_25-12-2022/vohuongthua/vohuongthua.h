#include<iostream>
using namespace std;

//Khai báo c?u trúc d? li?u
const int maxn = 20;
typedef int ElementType;
struct Node {
ElementType Element;
Node* Next;
};
typedef Node* List;
typedef List Graph[maxn];

//Kh?i t?o ?? th? r?ng
void Initialize(Graph &g, int n, int &e) {
for(int i=1; i<=n; i++) { 
 		g[i] = new Node; 
 		g[i]->Next = NULL;
 	} 
e=0;
}

//Xu?t ?? th?
void PrintGraph(Graph g, int n, int e) {
 	Node *t = new Node;
for(int i=1; i<=n; i++) {
 		cout<<"Dinh "<<i<<" : ";
 		t = g[i];
 		while(t->Next != NULL) {
 			cout<<t->Next->Element<<'\t';
 			t = t->Next;
 		}
 		cout<<endl;
 	}
}

//Thêm m?t cung
void InsertArc(Graph &g, int n, int &e, int d1, int d2) {
Node *t = new Node;
 	t->Element = d2;
 	t->Next = g[d1]->Next;
 	g[d1]->Next = t;
e++;
}


//Nh?p ?? th?:
void ReadGraph(Graph &g, int n, int e) {
 	int i, d1, d2, sc = e;
 	for(i=1; i<=sc; i++){
 		cout<<"Nhap cung di tu d1 den d2 : ";
cin>>d1>>d2;
InsertArc(g, n, e, d1, d2);
 	}
}

int CountArcFromVertice(Graph g, int n, int e, int d){ 
int dem = 0;
Node *t = g[d];
while(t->Next != NULL) {
 		dem++;
 		t = t->Next;
 	} 
return dem;
}

int CountArcToVertice(Graph g, int n, int e, int d){ 	
int i, dem = 0;
Node *t;
for(i=1; i<=n; i++){
 		t = g[i];
 		while(t->Next != NULL && t->Next->Element != d)
 			t = t->Next;
if(t->Next != NULL) dem++; 
 	} 
return dem;
}




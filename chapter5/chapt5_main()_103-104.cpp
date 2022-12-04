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

// Khoi tao do thi rong
void Initialize(Graph &g, int n, int &e){
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n;j++){
			g[i] = new Node;
			g[i]->Next = NULL;
		}	
	e=0;
}

// Them Mot cung
void InsertArc(Graph &g, int n, int &e, int d1, int d2){
	Node *t = new Node;
	t->Element = d2;
	t->Next = g[d1]->Next;
	g[d1]->Next = t;
	e++;
}

// Nhap Do thi
void ReadGraph(Graph &g, int n, int e){
	int i, d1, d2, cs=e;
	for(i=1; i<=cs; i++){
		cout << "Nhap dinh di tu d1 den d2: " <<endl;
		cin>>d1>>d2;
		InsertArc(g, n, e, d1, d2);
		system("cls");
	}
}

// Xuat Do thi
void PrintGraph(Graph g, int n, int e){
	Node *t = new Node;
	for(int i=1; i<=n; i++){
		cout << "Dinh " << i<<": ";
		t = g[i];
		while(t->Next != NULL){
			cout << t->Next->Element<<'\t';
			t = t->Next;
		}
		cout<<endl;
	}
		
}

// Xoa Mot cung
void DeleteArc(Graph &g, int n, int &e, int d1, int d2){
	Node *t =g[d1];
	while(t->Next != NULL && t->Next->Element != d2)
		t = t->Next;
	if(t->Next != NULL && t->Next->Element==d2){
		Node *p = t->Next;
		t->Next = p->Next;
		delete p;
		e--;
	}
}

// Dem So cung xuat phat tu mot dinh
int CountArcFromVertice(Graph g, int n, int e, int d){
	int dem=0;
	Node *t = g[d];
	while(t->Next != NULL){
		dem++;
		t=t->Next;
	}
	return dem;
}


// Them Mot dinh
void InsertVertice(Graph &g, int &n, int &e, int scxp, int scdd){
	int i, d;
	g[n+1] = new Node;
	g[n+1]->Next = NULL;
	for(i=1; i<=scxp; i++){
		cout << "Dinh moi di den dinh nao?";
		cin>>d;
		InsertArc(g, n, e, n+1, d);
	}
	for(i=1;i<=scdd;i++){
		cout << "Dinh nao di den dinh moi: ";
		cin>>d;
		InsertArc(g, n, e, d, n+1);
	}
}

// Dem So cung di den mot dinh
int CountArcToVertice(Graph g, int n, int e, int d){
	int i, dem = 0;
	Node *t;
	for(i=1; i<=n; i++){
		t=g[i];
		while(t->Next != NULL && t->Next->Element !=d)
			t = t->Next;
		if(t->Next != NULL) dem++;
	}
	return dem;
}

// Xoa Mot dinh
void DeleteVertice(Graph &g, int &n, int &e, int d){
	int i;
	e=e-CountArcFromVertice(g, n, e, d);
	for(i=1; i<=n; i++)
		if(i==d) g[i]->Next = NULL;
		else DeleteArc(g, n, e, i, d);
	for(i=d; i<=n-1; i++)
		g[i]=g[i+1];
	n--;
	for(i=1;i<=n;i++){
		Node *t = g[i];
		while(t->Next != NULL){
			if(t->Next->Element>d)
				t->Next->Element=t->Next->Element-1;
			t=t->Next;
		}
	}
}

main(){
	Graph g;
	int n, e, d1, d2, d, scxp, scdd;
	do{
		cout << "Nhap so dinh cua do thi: ";
		cin>>n;
	} while (n<=0||n>=maxn);
	
	Initialize(g, n, e);
	cout << "=====DO THI VUA KHOI TAO LA====="<<endl;
	PrintGraph(g, n, e);
	cout << "Nhap so cung cua do thi: "; cin >> e;
	ReadGraph(g, n, e);
	cout << "=====DO THI VUA NHAP LA====="<< endl;
	PrintGraph(g, n, e);
	cout << endl;
	cout << "Nhap cung can them: "; cin >> d1 >> d2;
	InsertArc(g, n, e, d1, d2);
	cout << "=====DO THI SAU KHI THEM CUNG LA====="<<endl;
	PrintGraph(g, n, e);
	cout << endl;
	cout << "Nhap cung can xoa: "; cin >> d1 >> d2;
	DeleteArc(g, n, e, d1, d2);
	cout << "=====DO THI SAU KHI XOA CUNG LA====="<<endl;
	PrintGraph(g, n, e);
	cout << endl;
	cout << "Nhap dinh can dem so cung: "; cin >> d;
	cout << "Dinh"<< d<<" co "<< CountArcFromVertice(g, n, e, d);
	cout << " cung xuat phat"<<endl;
	cout << "Dinh"<< d<<" co "<< CountArcToVertice(g, n, e, d);
	cout << " cung den" << endl;
	cout << "Nhap co cung xuat tu dinh moi: ";
	cin >> scxp;
	cout << "Nhap so cung di den dinh moi: ";
	cin >> scdd;
	InsertVertice(g, n, e, scxp, scdd);
	cout<<"=====DO THI SAU KHI THEM DINH LA====="<<endl;
	PrintGraph(g, n, e);
	cout << endl;
	cout << "Nhap dinh can xoa: "; cin >> d;
	DeleteVertice(g, n, e, d);
	cout << "=====DO THI SAU KHI XOA DINH LA====="<<endl;
	PrintGraph(g, n, e);
}

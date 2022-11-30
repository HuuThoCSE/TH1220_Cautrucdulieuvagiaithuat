#include<iostream>
using namespace std;
const int maxn = 20;
typedef int ElementType;
struct Node
{
	ElementType Element;
	Node* Next;
};
typedef Node* List;
typedef List Graph[maxn];
void Initialize(Graph &g, int n, int &e)
{
	for(int i=1; i<=n; i++)
	{
		 g[i] = new Node;
		 g[i]->Next = NULL;
	}
	e=0;
}
//them cung
void InsertArc(Graph &g, int n, int &e, int d1, int d2)
{
	Node *t = new Node;
	t->Element = d2;
	t->Next = g[d1]->Next;
	g[d1]->Next = t;
	e++;
}
//xoa cung
void DeleteArc(Graph &g, int n, int &e, int d1, int d2)
{ 
	Node *t = g[d1];
	while(t->Next != NULL && t->Next->Element != d2)
		t = t->Next;
	if(t->Next != NULL && t->Next->Element == d2)
	{ 
		Node *p = t->Next;
		t->Next = p->Next;
		delete p;
		e--;
	}
}
//dem cung xuat phat tu dinh
int CountArcFromVertice(Graph g, int n, int e, int d)
{ 
	int dem = 0;
	Node *t = g[d];
	while(t->Next != NULL)
	{
		dem++;
		t = t->Next;
	}
	return dem;
}
//dem cung di den dinh
int CountArcToVertice(Graph g, int n, int e, int d)
{ 
	int i, dem = 0;
	Node *t;
	for(i=1; i<=n; i++)
	{
		t = g[i];
		while(t->Next != NULL && t->Next->Element != d)
			t = t->Next;
		if(t->Next != NULL) dem++;
	}
	return dem;
}
//them dinh
void InsertVertice(Graph &g, int &n, int &e, int scxp, int scdd)
{ 
	int i, d;
	g[n+1]= new Node;
	g[n+1]->Next = NULL;
	for(i=1; i<=scxp; i++)
	{
		cout<<"Dinh moi di den dinh nao? ";
		cin>>d;
		InsertArc(g, n, e, n+1, d);
	}
	for(i=1; i<=scdd; i++)
	{
		cout<<"Dinh nao di den dinh moi? ";
		cin>>d;
		InsertArc(g, n, e, d, n+1);
	}
	n++;
}
//xoa dinh
void DeleteVertice(Graph &g, int &n, int &e, int d)
{ 
	int i;
	e=e-CountArcFromVertice(g, n, e, d);
	for(i=1; i<=n; i++)
		if(i==d) g[i]->Next = NULL;
		else DeleteArc(g, n, e, i, d);
	for(i=d; i<= n-1; i++)
		g[i] = g[i+1];
	n--;
	for(i=1; i<=n; i++)
	{
		Node *t = g[i];
		while(t->Next != NULL)
		{
			if(t->Next->Element > d) t->Next->Element = t->Next->Element - 1;
			t = t->Next;
		}
	}
}
//nhap
void ReadGraph(Graph &g, int n, int e)
{
	int i, d1, d2, sc = e;
	for(i=1; i<=sc; i++)
	{
		cout<<"Nhap cung di tu d1 den d2 : ";
		cin>>d1>>d2;
		InsertArc(g, n, e, d1, d2);
	}
}
//xuat
void PrintGraph(Graph g, int n, int e)
{
	Node *t = new Node;
	for(int i=1; i<=n; i++)
	{
		cout<<"Dinh "<<i<<" : ";
		t = g[i];
		while(t->Next != NULL)
	{
		cout<<t->Next->Element<<'\t';
		t = t->Next;
	}
	cout<<endl;
	}
}
//cho biet dinh co so cung DEN cac dinh khac nhieu nhat
void CdenDmax(Graph g, int n, int e)
{
	int max=CountArcFromVertice(g, n, e, 1);
	for (int i=2; i<=n; i++)
	{
		if (CountArcFromVertice(g, n, e, i)>max) max = CountArcFromVertice(g, n ,e ,i);
	}
	for (int i=1; i<=n; i++)
		if(max == CountArcFromVertice(g, n ,e ,i)) cout<<i<<'\t';
}
//cho biet dinh co so cug DEN TU cac dinh khac it nhat
void CdentuDmin(Graph g, int n, int e)
{
	int min=CountArcToVertice(g, n, e, 1);
	for (int i=2; i<=n; i++)
	{
		if (CountArcToVertice(g, n, e, i) < min) min = CountArcToVertice(g, n ,e ,i);
	}
	for (int i=1; i<=n; i++)
		if(min == CountArcToVertice(g, n ,e ,i)) cout<<i<<'\t';
}
//dem so khuyen co trong do thi
bool Check (List t, int d)
{
	while (t->Next!=NULL && t->Next->Element!=d)
		t=t->Next;
	if (t->Next!=NULL) return true;
	else return false;
}
int Demkhuyen(Graph g, int n, int e)
{
	int dem=0;
	for (int i=1; i<=n; i++)
		if(Check(g[i],i)==true) dem++;
	return dem;
}
//cho biet co bao nhieu dinh treo trong do thi
int DemTreo(Graph g, int n, int e)
{
	int dt=0;
	for (int i=1; i<=n; i++)
		if(CountArcToVertice(g, n ,e,i)==0 || CountArcFromVertice(g, n, e ,i)) dt++;
	return dt;	
}
//in ra dinh co cung den dinh d
void DcoCdenD(Graph g, int n, int e, int d)
{
	for (int i=1; i<=n; i++)
		if (Check(g[i],d)) cout<<i<<'\t';
}
main()
{ 
	 Graph g;
	 int n, e, d;
	 do
	 {
	 	cout<<"Nhap so dinh cua do thi : ";
		cin>>n;
	 }while(n<=0 || n>=maxn);
	 Initialize(g, n, e);
	 cout<<"=====DO THI VUA KHOI TAO LA====="<<endl;
	 PrintGraph(g, n, e);
	 cout<<"Nhap so cung cua do thi : "; cin>>e;
	 ReadGraph(g, n, e);
	 cout<<"=====DO THI VUA NHAP LA====="<<endl;
	 PrintGraph(g, n, e);
	 cout<<endl<<"Dinh co so cung den dinh khac nhieu nhat: ";
	 CdenDmax(g, n, e);
	 cout<<endl<<"Dinh co so cung den tu dinh khac it nhat: ";
	 CdentuDmin(g, n, e);
	 cout<<endl<<"So khuyen co trong do thi: "<<Demkhuyen(g, n, e);
	 cout<<endl<<"Co "<<DemTreo(g, n ,e)<<" dinh treo"<<endl;
	 cout<<"Nhap vao dinh d:";
	 cin>>d;
	 cout<<endl<<"Dinh co cung den dinh d: ";
	 DcoCdenD(g, n, e, d);	 
}

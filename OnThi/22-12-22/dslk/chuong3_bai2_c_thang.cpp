#include<iostream>
using namespace std;
typedef float ElementType;
struct Node
{
	ElementType Element;
	Node* Next;
};
typedef Node* Position;
typedef Node* List;

void MakeNullList(List &L)
{
	L=new Node;
	L->Next=NULL;
}

Position Last(List L)
{
	Position P=L;
	while(P->Next!=NULL)
		P=P->Next;
	return P;	
}

void InsertList(ElementType X,Position P,List &L)
{
	Position T=new Node;
	T->Element=X;
	T->Next=P->Next;
	P->Next=T;
}

void ReadList(List &L)
{
	ElementType X;
	do
	{
		cout<<"Nhap phan tu:";cin>>X;
		if(X!=0) InsertList(X,Last(L),L);
	}while(X!=0);
}

void PrintList(List L)
{
	if(L->Next==NULL) cout<<"Danh sach rong"<<endl;
	while(L->Next!=NULL)
	{
		cout<<L->Next->Element<<'\t';
		L=L->Next;
	}
}
void Delete_List(Position P,List &L)
{
	if(P->Next!=NULL)
	{
		Position T = P->Next;
		P->Next = T->Next;
		delete T;
	}
}
void Tach(List &Lc,List &Ll)
{
	if(Lc->Next==NULL) return ;
	Position P = Lc;
	while(P->Next!=NULL)
	{
		if((int)P->Next->Element%2!=0)
		{
			InsertList(P->Next->Element,Last(Ll),Ll);
			Delete_List(P,Lc);
		}
		else
			P=P->Next;
		
	}
	cout<<"-----DACH SACH LIEN KET CU-----"<<endl;
	PrintList(Lc);
	cout<<endl;
	cout<<"-----DACH SACH LIEN KET LE-----"<<endl;
	PrintList(Ll);
	cout<<endl;
}
void ThemDau(ElementType X, List &L)
{
	Position T=new Node;
	T->Element=X;
	T->Next=L->Next;
	L->Next=T;
}

void Tron(List &L,List L2, List L3)
{
	Position P=L2->Next;
	Position Q=L3->Next;
	while (P&&Q)
	{
		if(P->Element<=Q->Element)
		{
			ThemDau(P->Element,L);
			P=P->Next;
		}
		else{
			ThemDau(Q->Element,L);
			Q=Q->Next;
		}
	}
	while(P!=NULL)
	{
		ThemDau(P->Element,L);
		P=P->Next;
	}
	while (Q!=NULL)
	{
		ThemDau(Q->Element,L);
		Q=Q->Next;
	}
}
main()
{
	List L,L1,L2;
	MakeNullList(L);
	MakeNullList(L1);
	MakeNullList(L2);
	cout<<"-----NHAP DANH SACH LIEN KET-----"<<endl;
	ReadList(L1);
	cout<<"-----NHAP DANH SACH LIEN KET-----"<<endl;
	ReadList(L2);
	cout<<"-----DACH SACH LIEN KET-----"<<endl;
	PrintList(L1);
	cout<<endl;
	cout<<"-----DACH SACH LIEN KET-----"<<endl;
	PrintList(L2);
	cout<<endl;
	Tron(L,L1,L2);
	cout<<"-----DACH SACH LIEN KET SAU KHI TRON-----"<<endl;
	PrintList(L);
}


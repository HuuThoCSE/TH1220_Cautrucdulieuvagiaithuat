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
	L = new Node;
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
	Position T= new Node;
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
	else
	{
		while(L->Next!=NULL)
		{
			cout<<L->Next->Element<<'\t';
			L=L->Next;
		}
	}
}
void DeleteList(Position P,List &L)
{
	Position T;
	if(P->Next!=NULL)
	{
		T=P->Next;
		P->Next=T->Next;
		delete T;
	}
}
void XoaDau(List &L)
{
	Position P=L;
	DeleteList(P,L);
}
void InNhoNhat(List L)
{
	Position P=L->Next;
	Position min=L->Next;
	while(P->Next!=NULL)
	{
		if(P->Next->Element<=min->Element)
		{
			min=P->Next;
		}
		P=P->Next;
	}
	P=L;
	int d=1;
	while(P->Next!=NULL)
	{	
		if(P->Next->Element==min->Element)
		{
			cout<<d<<'\t';
		}
		d++;
		P=P->Next;
	}
}

void LoaiBo(List &L)
{
	Position P = L;
	Position Q;
	while(P->Next!=NULL)
	{
		Q=P->Next;
		while(Q->Next!=NULL)
		{
			if(P->Next->Element<Q->Next->Element)
				DeleteList(Q,L);
			else Q=Q->Next;	
		}
		P=P->Next;
	}
}
main()
{
	List L;
	ElementType X;
	MakeNullList(L);
	cout<<"------NHAP DANH SACH LIEN KET------"<<endl;
	ReadList(L);
	cout<<"-----DANH SACH LIEN KET-----"<<endl;
	PrintList(L);
	cout<<endl;
	XoaDau(L);
	cout<<"-----DANH SACH LIEN KET SAU KHI XOA PHAN TU DAU LA-----"<<endl;
	PrintList(L);
	cout<<endl;
	cout<<"Vi tri cac phan tu co noi dung nho nhat:"<<endl;
	InNhoNhat(L);
	cout<<endl;
	cout<<"-----DANH SACH SAU KHI LOAI BO CAC PHAN TU KHONG DUNG VI TRI-----"<<endl;
	LoaiBo(L);
	PrintList(L);
}

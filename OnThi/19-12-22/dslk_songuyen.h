#include<iostream>
using namespace std;

typedef int ElementType;
struct Node{
	ElementType Element;
	Node* Next;
};
typedef Node* Position;
typedef Node* List;

void MakeNullList(List &L){
	L=new Node;
	L->Next=NULL;
}

// Them mot phan tu
void InsertList(ElementType X, Position P, List &L){
	Position Temp;
	Temp=new Node;
	Temp->Element=X;
	Temp->Next=P->Next;
	P->Next=Temp;
}

// Xac dinh phan tu dau tien
Position First(List L){
	Position P=L->Next;
	return P;
}

// Xac dinh phan tu cuoi cung
Position Last(List L){
	Position P=L;
	while(P->Next!=NULL)
		P=P->Next;
	return P;
}

// Nhap DS
void ReadList(List &L){
	ElementType X;
	do {
		cout<<"Nhap noi dung phan tu: ";
		cin>>X;
		if(X!=0) InsertList(X, Last(L), L);
	}while(X!=0);
}

//Kiem tra DS rong
bool EmptyList(List L){
	return L->Next==NULL;
}

// In DS 
void PrintList(List L){
	if(EmptyList(L)!=0)
		cout<<"DS rong"<<endl;
	else
		while(L->Next!=NULL){
			cout<<L->Next->Element<<'\t';
			L=L->Next;
		}
}

// Xoa phan tu ngay sau P
ElementType Retrieve(Position P, List &L){
	if(P!=NULL)
		return P->Element;
	else
		return 0;
}

void DeleteList(Position &P, List &L){
	Position Temp;
	if(P->Next!=NULL){
		Temp=P->Next;
		P->Next=Temp->Next;
		delete Temp;
	}
}


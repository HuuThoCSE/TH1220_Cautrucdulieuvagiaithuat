#include<iostream>
using namespace std;

typedef float ElementType;
struct Node {
	ElementType Element;
	Node* Next;
};
typedef Node* Position;
typedef Node* List;

void MakeNullList(List &L){
	L=new Node;
	L->Next=NULL;
}

Position Last(List L){
	Position P=L;
	while(P->Next!=NULL)
		P=P->Next;
	return P;
}

void InsertList(ElementType X, Position P, List &L){
	Position Temp;
	Temp=new Node;
	Temp->Element=X;
	Temp->Next=P->Next;
	P->Next=Temp;
}

void ReadList(List &L){
	ElementType X;
	do {
		cout<<"Nhap noi dung phan tu: ";
		cin>>X;
		if(X!=0) InsertList(X, Last(L), L);
	} while(X!=0);
}

bool EmptyList(List L){
	return L->Next==NULL; 
}

void PrintList(List L){
	if(EmptyList(L)!=0)
		cout<<"Danh sach rong"<<endl;
	else
		while(L->Next!=NULL){
			cout<<L->Next->Element<<'\t';
			L=L->Next;
		}
}

Position First(List L){
	Position P=L;
	while(P->Next!=NULL)
		P=P->Next;
	return P;
}



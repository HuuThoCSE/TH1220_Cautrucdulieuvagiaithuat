// Chapter3_Lession5_p56

#include<iostream>
using namespace std;

// Khai bao DTDL
typedef int ElementType;

struct Node {
	ElementType Element;
	Node* Next;
};
typedef Node* List;
typedef Node* Position;

// Tao danh sach rong
void MakeNullList(List &L) {
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

// Kiem tra danh sach rong
bool EmptyList(List L){
	return L->Next==NULL;
}

// Nhap danh sach
void ReadList(List &L){
	ElementType X;
	do {
		cout << "Nhap noi dung phan tu: ";
		cin >> X;
		if (X!=0) InsertList(X, List(L), L);
	} while (X!=0);
}

// Xac dinh phan tu cuoi cung
Position Last(List L) {
	Position P;
	P=L;
	while(P->Next!=NULL)
		P=P->Next;
	return P;
}

// ===Copy DS
void CopyDS(List L, List &Lm){
	Position P=L;
	MakeNullList(Lm);
	while(P->Next!=NULL){
		InsertList(P->Next->Element, Last(Lm), Lm);
		P=P->Next;
	}
}

// In danh sach
void PrintList(List L){
	if(EmptyList(L)!=0)
		cout << "Danh sach rong"<<endl;
	else
		while(L->Next!=NULL) {
			cout << L->Next->Element<<'\t';
			L=L->Next;
		}
}

main() {
	List L, Lm; 
	Position P;
	ElementType X;
	
	// Tao List rong
	MakeNullList(L);
	MakeNullList(Lm);
	
	//Nhap List
	ReadList(L);
	
	// Ham copy
	CopyDS(L, Lm);
	
	// In List da dc copy
	cout << "Danh sach da duoc copy: " << endl;
	PrintList(Lm);
	
}

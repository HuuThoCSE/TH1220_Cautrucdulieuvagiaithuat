#include<iostream>
using namespace std;

//struct DaThuc {
//	int HeSo;
//	int SoMu;
//};

// Khai bao DTDL
typedef int ElementType;

struct Node {
	ElementType HeSo;
	ElementType SoMu;
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
void InsertList(ElementType HeSo, ElementType SoMu, Position P, List &L){
	Position Temp;
	Temp=new Node;
	Temp->HeSo=HeSo;
	Temp->SoMu=SoMu;
	Temp->Next=P->Next;
	P->Next=Temp;
}

// Kiem tra danh sach rong
bool EmptyList(List L){
	return L->Next==NULL;
}

// Xac dinh phan tu dau tien
Position First(List L){
	Position P;
	P=L->Next;
	return P;
}

// Xac dinh phan tu cuoi cung
Position Last(List L) {
	Position P;
	P=L;
	while(P->Next!=NULL)
		P=P->Next;
	return P;
}

// Xac dinh phan tu dung ngay truoc P
Position Previous(Position P, List L){
	Position Temp;
	if(P==L) return NULL;
	else {
		Temp = L;
		while (Temp->Next!=P) Temp=Temp->Next;
		return Temp;
	}
}

// Dinh vi mot phan tu
Position Locate(ElementType X, List L) {
	Position P;
	int found = 0;
	P=L;
	while(P->Next!=NULL && found==0){
		if(P->Next->HeSo==X)
			found = 1;
		else 
			P = P->Next;
	return P->Next;
	}
}

// Xoa phan tu ngay sau P
void DeleteList(Position P, List &L){
	Position Temp;
	if(P->Next!=NULL){
		Temp=P->Next;
		P->Next=Temp->Next;
		delete Temp;
	}
}

// Hoan doi vi tri
void Swap(ElementType &ELT1, ElementType &ELT2){
	ElementType Temp;
	Temp = ELT1;
	ELT1 = ELT2;
	ELT2 = Temp;
}

// Nhap danh sach
void ReadList(List &L){
	ElementType A, X;
	do {
		cout << "Nhap he so: ";
		cin >> A;
		cout << "Nhap so mu: ";
		cin >> X;
		cout << endl;
		if (X!=0) InsertList(A, X, List(L), L);
	} while (X!=0);
}

// In danh sach
void PrintList(List L){
	if(EmptyList(L)!=0)
		cout << "Danh sach rong"<<endl;
	else
		while(L->Next!=NULL) {
			cout << L->Next->HeSo << "x^" << L->Next->SoMu <<" + ";
			L=L->Next;
		}
}

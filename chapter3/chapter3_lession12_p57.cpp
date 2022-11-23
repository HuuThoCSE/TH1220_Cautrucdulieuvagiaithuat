#include<iostream>
using namespace std;

typedef int ElementType;

struct Node {
	ElementType HeSo;
	ElementType SoMu;
	Node* Next;
};

typedef Node* List;
typedef Node* Position;

//void Multi(List DTh1, List DTh2, List &DThKQ){
//	while(DTh1->Next!=NULL || DTh2->Next!=NULL){
//		InsertList(DTh1->HeSo*DTh2->HeSo, DTh1->SoMu*DTh2->SoMu, List(DThKQ), DThKQ);
//		DTh1=DTh1->Next;
//		DTh2=DTh2->Next;
//	}
//}

// Kiem tra danh sach rong
bool EmptyList(List L){
	return L->Next==NULL;
}

// Tao danh sach rong
void MakeNullList(List &L) {
	L=new Node;
	L->Next=NULL;
}

// Xac dinh phan tu cuoi cung
Position Last(List L) {
	Position P;
	P=L;
	while(P->Next!=NULL)
		P=P->Next;
	return P;
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

void XuLy(List &L){
	Position P, Q, E;
	P=L;
	while(P->Next!=NULL){
		Q=P->Next;
		while(Q->Next=NULL) {
			if(P->Next->SoMu==Q->Next->SoMu){
				P->Next->HeSo+=Q->Next->HeSo;
				E = Q->Next;
				Q->Next=Q->Next->Next;
				delete E;
			} else Q=Q->Next;
			
		}
		P=P->Next;
	}
}

void Tinh(List &L, List &L1, List &L2){
	Position P=L1;
	Position Q=L2;
	if(L1->Next==NULL || L2->Next==NULL)
		cout << "DS rong" << endl;
	while(P->Next!=NULL){
		while(Q->Next!=NULL){
			InsertList(P->Next->HeSo*Q->Next->HeSo, P->Next->SoMu + Q->Next->SoMu, Last(L), L);
			Q=Q->Next;
		}
		P=P->Next;
		Q=L2;
	}
//	SapxepGQ(L);
	XuLy(L);
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

main(){
	// Khai bao List
	List L1, L2, L;
	
	// Tao mang rong
	MakeNullList(L1);
	MakeNullList(L2);
	MakeNullList(L);
	
	// Nhap da thuc 1
	cout << "======Nhap da thuc 1: " << endl;
	ReadList(L1);
	
	// Nhap da thuc 2
	cout << "\n=====Nhap da thuc 2: " << endl;
	ReadList(L2);
	
	// Nhan hai Da thuc
	Tinh(L, L1, L2);
	
	// In ket qua
	PrintList(L);
}

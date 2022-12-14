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

// ==Ham dem so phan tu trong List
int Count(List L) {
	Position P;
	int dem=0;
	while(P->Next!=NULL && P != 1) {	
		P=P->Next;
		dem++;
	}
	return dem;
}

// Ghep danh sach 2 vao chih giua danh sach 1
void GhepHaiDS(List &L, List L2){
	int k;
	Position P;
	
	k = (int)Count(L)/2;
	cout << k;

	
	for(P=First(L); P < ; P=P->Next) {
		
	}
}

// Nhap danh sach
void ReadList(List &L){
	ElementType X;
	do {
		cout << "Nhap noi dung phan tu ["<< L <<"]: "; cin >> X;
		if (X!=0) InsertList(X, List(L), L);
	} while (X!=0);
	cout << endl;
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

main(){
	List L, L2;
	
	// Tao List NULL
	MakeNullList(L);
	MakeNullList(L2);
	
	// Them phan tu vao List
	ReadList(L);
	ReadList(L2);
	
	// Ghep DS 
	GhepHaiDS(L, L2);
	
	// Print List
	PrintList(L);
}

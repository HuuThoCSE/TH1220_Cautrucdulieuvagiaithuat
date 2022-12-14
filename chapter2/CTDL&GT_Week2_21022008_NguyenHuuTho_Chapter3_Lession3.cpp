// Chapter3_Lession3_p56

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

// Nhap danh sach
void ReadList(List &L){
	ElementType X;
	do {
		cout << "Nhap noi dung phan tu: ";
		cin >> X;
		if (X!=0) InsertList(X, List(L), L);
	} while (X!=0);
}

// Kiem tra danh sach rong
bool EmptyList(List L){
	return L->Next==NULL;
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

// ===Them dau
void ThemDau(ElementType X, List&L){
	Position t = new Node;
	t->Element=X;
	t->Next=L->Next;
	L->Next=t;
}

// ===Them DS
void TaoDS(List &L){
	int X;
	MakeNullList(L);
	do {
		cout << "Nhap noi dung phan tu vao dau DS: ";
		cin >> X;
		if (X!=0) ThemDau(X, L);
		
		cout << "DS sau khi them: ";
		PrintList(L);
		cout << endl;
	} while (X!=0);
}


main() {
	// Viet chuong trinh tao mot danh sach lien ket theo giai thuat [them vao dau danh sach], (moi nut chua mot so nguyen)
	List L; 
	Position P;
	ElementType X;
	
	// Tao DS rong
	MakeNullList(L);
	
	// Them phan tu vao dau DS
	TaoDS(L);
}

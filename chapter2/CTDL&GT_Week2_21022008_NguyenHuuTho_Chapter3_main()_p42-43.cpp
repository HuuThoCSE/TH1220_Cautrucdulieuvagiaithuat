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
		if(P->Next->Element==X)
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

// Nhap danh sach
void ReadList(List &L){
	ElementType X;
	do {
		cout << "Nhap noi dung phan tu: ";
		cin >> X;
		if (X!=0) InsertList(X, List(L), L);
	} while (X!=0);
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
	List L; 
	Position P;
	ElementType X, ND;
	MakeNullList(L);
	cout << "=====NHAP DANH SACH LIEN KET====="<<endl;
	ReadList(L);
	cout << "=====IN DANH SACH LIEN KET====="<<endl;
	PrintList(L);
	cout << "Phan tu dau tien trong danh sach la: ";
	cout << First(L)->Element<<endl;
	cout << "Phan tu cuoi cung trong danh sach la: ";
	cout << Last(L)->Element<<endl;
	cout << "Nhap noi dung phan tu can them: ";
	cin >> X;
	cout << "Ban muon them sau phan tu nao: ";
	cin >> ND;
	P=Locate(ND, L);
	if(P==NULL) cout << "Khong them duoc" << endl;
	else InsertList(X, P, L);
	cout << "Ban muon them truoc phan tu nao: ";
	cin >> ND;
	P=Locate(ND, L);
	P=Previous(P,L);
	if(P==NULL) 
		cout << "Khong them duoc" << endl;
	else 
		InsertList(X, P, L);
	cout << "=====DANH SACH LIEN KET SAU KHI THEM====="<<endl;
	PrintList(L);
	cout << "Ban muon xoa phan tu sau phan tu nao: ";
	cin >> ND;
	P = Locate(ND, L);
	if(P=NULL) 
		cout << "Khong xoa duoc"<<endl;
	else 
		DeleteList(P, L);
	cout << "=====DANH SACH LIEN KET SAU KHI XOA====="<<endl;
	PrintList(L);
}

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

// Tach 1 danh sach thanh 2 danh sach lung ung voi noi ung chan va le
void TachDSChanLe(ElementType X, List L) {
	Position P=L;
	List DS_Chan, DS_Le;
	MakeNullList(DS_Chan);
	MakeNullList(DS_Le);
	while(P->Next!=NULL) {
		if(P->Next->Element % 2 == 0){
			InsertList(P->Next->Element, Last(DS_Chan), DS_Chan);
		}
		
		else {
			InsertList(P->Next->Element, Last(DS_Le), DS_Le);
		}
		P=P->Next;
	}
}

main(){
	List L; 
	Position P;
	ElementType X;
	TachDSChanLe(X, L);
}

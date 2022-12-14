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

// Xoa tat ca ca phan tu X co trong danh sach
void XoaPhantuTrongList(ElementType X, List L){
	Position Temp;
	Temp=L;
	while(Temp->Next!=NULL){
		if(Temp->Next->Element==X)
			DeleteList(Teml)
		else
			Temp = Temp->Next;
	}
}

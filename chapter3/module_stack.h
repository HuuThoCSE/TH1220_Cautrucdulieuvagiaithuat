#include<iostream>
using namespace std;

// Khai bao CTDL Stack
typedef int ElementType;
struct Node {
	ElementType Element;
	Node* Next;
};
typedef Node* Position;
typedef Node* Stack;

// Tao ngan xep rong
void MakeNullStack(Stack &S){
	S=NULL;
}

// Kiem tra ngan xep rong
bool EmptyStack(Stack S){
	if(S==NULL) return true;
	else return false;
}

// Them mot phan tu
void Push(ElementType X, Stack &S){
	Position Temp;
	Temp=new Node;
	Temp->Element=X;
	Temp->Next=S;
	S=Temp;
}

// Tra ve gia tri cua phan tu o dinh ngan xep
ElementType Top(Stack S){
	if(EmptyStack(S)) return 0;
	else return S->Element;
}

// Xoa mot phan tu
void Pop(Stack &S){
	if(!EmptyStack(S)) {
		Position Temp=S;
		S=S->Next;
		delete Temp;
	}
}

// Nhap ngan xep
void ReadStack(Stack &S){
	ElementType X;
	do {
		cout << "Nhap noi dung phan tu: ";
		cin >> X;
		if(X!=0) Push(X,S);
	} while (X!=0);
}

// In va xoa ngan xep
void PrintStack(Stack &S){
	if(EmptyStack(S))
		cout << "Nhan xep rong"<<endl;
	else
		while(S!=NULL){
			cout << Top(S)<<'\t';
			Pop(S);
		}
}

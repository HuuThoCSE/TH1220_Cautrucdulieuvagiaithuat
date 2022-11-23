#include<iostream>
using namespace std;

// Khoi tao CTDL Queue
typedef int ElementType;
struct Node {
	ElementType Element;
	Node* Next;
};
typedef Node* Position;
struct Queue{
	Position Front, Rear;
};

// Khoi tao hang doi rong
void MakeNullQueue(Queue &Q){
	Q.Front=NULL;
	Q.Rear=NULL;
}

// Kiem tra hang doi rong
bool EmptyQueue(Queue Q){
	if(Q.Front==NULL && Q.Rear==NULL) return true;
	else return false;
}

// Them mot phan tu
void EnQueue(ElementType X, Queue &Q){
	if(EmptyQueue(Q)){
		Q.Rear=new Node;
		Q.Front=Q.Rear;
	}
	else {
		Q.Rear->Next=new Node;
		Q.Rear=Q.Rear->Next;
	}
	Q.Rear->Element=X;
	Q.Rear->Next=NULL;
}

// Tra ve gia tri cua phan tu o dau hang doi
ElementType FirstQueue(Queue Q){
	if(EmptyQueue(Q))
		return 0;
	else
		return Q.Front->Element;
}

// Xoa mot phan tu
void DeQueue(Queue &Q){
	if(!EmptyQueue(Q)){
		Position T;
		T=Q.Front;
		Q.Front=Q.Front->Next;
		if(Q.Front==NULL) Q.Rear=NULL;
		delete T;
	}
}

// Nhap hang doi
void ReadQueue(Queue &Q){
	ElementType X;
	do{
		cout << "Nhap noi dung phan tu: ";
		cin >> X;
		if(X!=0) EnQueue(X, Q);
	} while (X!=0);
}

// In va xoa hang doi
void PrintQueue(Queue &Q){
	if(EmptyQueue(Q))
		cout << "Hang rong"<<endl;
	else
		while(!EmptyQueue(Q)){
			cout <<FirstQueue(Q)<<'\t';
			DeQueue(Q);
		}
}

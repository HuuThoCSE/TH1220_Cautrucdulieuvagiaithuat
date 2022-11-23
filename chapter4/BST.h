#include<iostream>
using namespace std;

// Khai bao CTDL cay BST
typedef int Info;
struct BST_Node {
	Info Key;
	BST_Node* Left;
	BST_Node* Right;
};

typedef BST_Node* BST_Type;

// Khoi tao cay rong
void Intialize(BST_Type &BST){
	BST = NULL;
}

// Tao moi mot nut
BST_Type Create_Node(Info NewData){
	BST_Type BSTNode = new BST_Node;
	if(BSTNode != NULL){
		BSTNode->Left = NULL;
		BSTNode->Right = NULL;
		BSTNode->Key = NewData;
	}
	return BSTNode;
}

// Them gia tri vao mot Node
void Read_Tree(BST_Type &BST){
	Info X;
	cout << "Bat cua cay: "; cin >> X;
	if(X!=0){
		BST_Type BT;
		BT = Create_Node(X);
		BST = BT;
		cout << "Nhap con trai cua " << X << " : ";
		Read_Tree(BST->Left);
		cout << "Phan con phai cua " << X << " : ";
		Read_Tree(BST->Right);
	} else {
		BST=NULL;
	}
}

// Them mot nut
void Add_Node(BST_Type &BST, Info NewData){
	if(BST == NULL){
		BST = new BST_Node;
		if(BST != NULL){
			BST->Left = NULL;
			BST->Right = NULL;
			BST->Key = NewData;
		}
	} else {
	if(BST->Key == NewData)
		return;
	else 
		if(BST->Key > NewData)
			Add_Node(BST->Left, NewData);
		else 
			Add_Node(BST->Right, NewData);
	}
}

// Tim kiem mot nut
BST_Type Searching(BST_Type BST, Info SearchData){
	BST_Type CurNode = BST;
	while(CurNode != NULL && CurNode->Key != SearchData)
		if(CurNode->Key > SearchData)
			CurNode = CurNode->Left;
		else 
			CurNode = CurNode->Left;
	return CurNode;
}

// Duyet qua tat ca cac nut trong cay
void LRootR_Traverse(BST_Type BST){
	if(BST == NULL)
		return;
	LRootR_Traverse(BST->Left);
	cout << BST->Key << '\t';
	LRootR_Traverse(BST->Right);
}

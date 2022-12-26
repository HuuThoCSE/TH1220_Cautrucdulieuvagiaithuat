#include<iostream>
using namespace std;

//C?u tr�c d? li?u
typedef int Info;
struct BST_Node { 
Info Key; 
BST_Node* Left; 
BST_Node* Right; 
}; 
typedef BST_Node* BST_Type;

//Kh?i t?o c�y (C�y r?ng)
void Initialize(BST_Type &BST) { 
BST = NULL;
}

//Th�m m?t n�t (Th�m n�t con tr�i v� con ph?i)
void Add_Node(BST_Type &BST, Info NewData){ 
if(BST == NULL){
BST = new BST_Node;
if(BST != NULL){
BST->Left = NULL; 
BST->Right = NULL; 
BST->Key = NewData; 
 		}
}
 	else //BST != NULL
 		if(BST->Key == NewData) return;
else 
if(BST->Key > NewData) 
Add_Node(BST->Left, NewData);
else
Add_Node(BST->Right, NewData);
}

// Nh?p c�y b?ng h�m Add_node 
void Read_Tree(BST_Type &BSTree){
	Info X;
	cout<<"Nhap nut goc:";cin>>X;
	Add_Node(BSTree,X);
	while(X!=0){
		cout<<"Nhap noi dung phan tu tiep theo cua cay(Nhap 0 de ket thuc): ";cin>>X;
		if(X!=0)
			Add_Node(BSTree,X);
	}
}

void LRootR_Traverse(BST_Type BST){
	if(BST == NULL)
		return;
	LRootR_Traverse(BST->Left);
	cout << BST->Key << '\t';
	LRootR_Traverse(BST->Right);
}



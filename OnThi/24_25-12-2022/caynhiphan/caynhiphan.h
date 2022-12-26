#include<iostream>
using namespace std;

// Khai báo c?u trúc d? li?u
typedef int Info;
struct BinT_Node {
	Info Key;
	BinT_Node* Left; 
	BinT_Node* Right;
};
typedef BinT_Node* BinT_Type;

//Kh?i t?o cây
void Initialize(BinT_Type &BTree) {
	BTree = NULL;
}

//T?o m?i m?t nút
BinT_Type Create_Node(Info NewData) {
 	BinT_Type BTnode = new BinT_Node;
 	if(BTnode != NULL)
 	{
 		BTnode->Left = NULL;
 		BTnode->Right = NULL;
 		BTnode->Key = NewData;
	}
	return BTnode;
}

void Read_Tree(BinT_Type &BTree){ 
	Info X;
 	cin>>X;
 	if(X!=0){
 		BinT_Type BT;
 		BT = Create_Node(X);
 		BTree = BT;
 		cout<<"Nhap con trai cua "<<X<<" : ";
 		Read_Tree(BTree->Left);
 		cout<<"Nhap con phai cua "<<X<<" : ";
 		Read_Tree(BTree->Right);
 	} else 
BTree=NULL;
}	

void LRootR_Traverse(BinT_Type BTree) { 
	if(BTree == NULL)
		return;
	LRootR_Traverse(BTree->Left);
	cout << BTree->Key << '\t';
	LRootR_Traverse(BTree->Right);
} 

int Tree_Height(BinT_Type BTree) {
	if(BTree == NULL)
	return 0;
	int HTL = Tree_Height(BTree->Left);
	int HTR = Tree_Height(BTree->Right);
	if(HTL > HTR)
		return HTL + 1;
	else
		return HTR + 1;
}





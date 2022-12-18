#include<iostream>
using namespace std;

// Khai bao CTDL
typedef float Info;
struct BinT_Node{
	Info Key;
	BinT_Node* Left;
	BinT_Node* Right;
};
typedef BinT_Node* BinT_Type;

// Khoi tao cay
void Initialize(BinT_Type &BTree){
	BTree=NULL;
}

// Tao moi mot nut
BinT_Type Create_Node(Info NewData){
	BinT_Type BTnode = new BinT_Node;
	if(BTnode != NULL){
		BTnode->Left=NULL;
		BTnode->Right=NULL;
		BTnode->Key=NewData;
	}
	return BTnode;
}

// Nhap cay nhi phan
void Read_Tree(BinT_Type &BTree){
	Info X;
	cin>>X;
	if(X!=0){
		BinT_Type BT;
		BT = Create_Node(X);
		BTree = BT;
		cout<<"Nhap con trai cua "<<X<<": ";
		Read_Tree(BTree->Left);
		cout<<"Nhap con phai cua "<<X<<": ";
		Read_Tree(BTree->Right);
	} else BTree=NULL;
}

// Duyet qua tat cac cac nut trong cay theo thu tu Left - Root - Right
void LRootR_Traverse(BinT_Type BT){
	if(BT == NULL) return;
	LRootR_Traverse(BT->Left);
	cout<<BT->Key<<'\t';
	LRootR_Traverse(BT->Right);
}

// NutBatMot
int NutBatMot(BinT_Type BT){
	if(BT==NULL) return 0;
	if(BT->Left == NULL && BT->Right!=NULL) return 1;
	if(BT->Left != NULL && BT->Right==NULL) return 1;
	NutBatMot(BT->Left);
	NutBatMot(BT->Right);
}

main(){
	BinT_Type BT;
	Initialize(BT);
	cout<<"=====NHAP CAY NHI PHAN: \n";
	Read_Tree(BT);
	cout<<"=====IN CAY NI PHAN (LNR): \n";
	LRootR_Traverse(BT);
	cout<<"So nut bat 1: "<<NutBatMot(BT);
}

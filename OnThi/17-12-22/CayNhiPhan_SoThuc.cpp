#include<iostream>
using namespace std;

// Khai bao CTDL
typedef int Info;
struct BinT_Node{
	Info Key;
	BinT_Node* Left;
	BinT_Node* Right;
};
typedef BinT_Node* BinT_Type;

// Khoi tao cay
void Initialize(BinT_Type &BT){
	BT = NULL;
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

// De qui, de duyet cay nhi phan theo thu tu Left - Root - Right
void LRootR_Traverse(BinT_Type BTree){
	if(BTree == NULL) return;
	LRootR_Traverse(BTree->Left);
	cout<<BTree->Key<<'\t';
	LRootR_Traverse(BTree->Right);
}

// Dem so nut bat 1
int DemNutBat1(BinT_Type BTree){
	if(BTree->Left == NULL && BTree->Right == NULL) return 0;
	else if (BTree->Left != NULL && BTree->Right == NULL || BTree->Left == NULL && BTree->Right != NULL) return 1;
	return DemNutBat1(BTree->Left)+DemNutBat1(BTree->Right);
}

// In cac nut bat 1
void InNutBat1(BinT_Type BTree){
	if(BTree != NULL) {
		if (BTree->Left != NULL && BTree->Right == NULL || BTree->Left == NULL && BTree->Right != NULL) cout<<BTree->Key<<"\t";
		else {
			InNutBat1(BTree->Left);
			InNutBat1(BTree->Right);
		}
	}
}

// In cac nut nam muc M
void InNutMucM(BinT_Type BTree,int M,int muc=1){
	if(BTree == NULL) return;
	if (muc==M) cout<<BTree->Key<<"\t";
	else if(M>muc) {
		muc++;
		InNutMucM(BTree->Left, M, muc);
		InNutMucM(BTree->Right, M, muc);
	}
}

void MucNutLonNhat(BT, muc=1){
	
}

main(){
	BinT_Type BT;
	int M;
	Initialize(BT);
	cout<<"======NHAP CAY NHI PHAN: \n";
	Read_Tree(BT);
	cout<<"======CAY NHI PHAN: \n";
	LRootR_Traverse(BT);
	// Dem so nut bat 1
	cout<<"\nCo "<< DemNutBat1(BT)<<" bat 1 \n";
	// In cac nut bat 1
	cout<<"=====CAC NUT BAT 1: \n";
	InNutBat1(BT);
	cout<<"\nNhap vao M: "; cin>>M;
	cout<<"=====CAC NUT MUC M: \n";
	// In cac nut nam o muc M
	InNutMucM(BT, M);
	// Nut lon nhat nam o vi tri
	cout<<"Nut lon nhat nam o muc: "; MucNutLonNhat(BT);
};

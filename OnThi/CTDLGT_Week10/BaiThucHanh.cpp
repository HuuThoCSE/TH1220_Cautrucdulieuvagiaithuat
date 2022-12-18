// BST  K(l) < K(N) < K(R)
#include<iostream>
using namespace std;

// Khai bao CTDL
typedef int Info;
struct BST_Node{
	Info Key;
	BST_Node* Left;
	BST_Node* Right;
};

typedef BST_Node* BST_Type;

// Khoi tao cay
void Initialize(BST_Type &BST){
	BST=NULL;
}

// Tao moi mot nut
BST_Type Create_Node(Info NewData){
	BST_Type BSTnode = new BST_Node;
	if(BSTnode != NULL){
		BSTnode->Left = NULL;
		BSTnode->Right = NULL;
		BSTnode->Key = NewData;
	}
	return BSTnode;
}

// Nhap cay BST
void Read_Tree(BST_Type &BST){
	Info X;
	cin>>X;
	if(X!=0){
		BST_Type BT;
		BT = Create_Node(X);
		BST = BT;
		cout<<"Nhap con trai cua "<<X<<": ";
		Read_Tree(BST->Left);
		cout<<"Nhap con phai cua "<<X<<": ";
		Read_Tree(BST->Right);
	} else BST=NULL;
}

// Duyet qua tat cac cac nut trong cay theo thu tu Left - Root - Right
void LRootR_Traverse(BST_Type BST){
	if(BST == NULL) return;
	LRootR_Traverse(BST->Left);
	cout<<BST->Key<<'\t';
	LRootR_Traverse(BST->Right);
}

void RootToMin(BST_Type BST){
	while(BST!=NULL){
		cout<<BST->Key<<'\t';
		BST=BST->Left;
	}
}

// Dem so nut co khoa nho hon hoac bang k
void NodeThanK(BST_Type BST,int K){
	if(BST!=NULL){
		if(BST->Key==K) LRootR_Traverse(BST->Left);
		else if(BST->Key<K) NodeThanK(BST->Right, K);
		else {
			NodeThanK(BST->Left, K);
			cout<<BST->Key<<'\t';
			LRootR_Traverse(BST->Key);
		}
	}
}

// Nut lon nhat nam o muc nao trong cay
void MucCuaNutLonNhat(){
	
}

main(){
	BST_Type BST;
	Initialize(BST);
	cout<<"=====NHAP CAY NHI PHAN:"<<endl;
	Read_Tree(BST);
	
	cout<<"\n===== IN CAY THEO CACH LNR: \n";
	LRootR_Traverse(BST);
	
	cout<<"\n=====In cac nut tren truong di tu goc den nut nho nhat: \n";
	RootToMin(BST);
	
	cout<<"Nhap K vao: "; cin>>K;
	NodeThanK(BST, K);
	
	MucCuaNutLonNhat(BST);
	
}

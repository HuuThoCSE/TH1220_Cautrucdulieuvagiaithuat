#include "caynhiphan.h"
void InNutMucK1(BinT_Type BTree, int k){
	if(BTree != NULL){
		k--;
		if(BTree->Left != NULL)
			InNutMucK1(BTree->Left,k);
		if(k == 0)
			cout<<BTree->Key <<'\t';
		if(BTree->Right != NULL)
			InNutMucK1(BTree->Right,k);
	}	
} 

void InNutMucK(BinT_Type BTree, int K){
	if(BTree!=NULL){
		if(K==1){
			cout<<BTree->Key<<'\t';
			return;
		} else {
			InNutMucK(BTree->Left, K-1);
			InNutMucK(BTree->Right, K-1);
		}
	}
}


main(){
	BinT_Type BT;
	Initialize(BT);
	Read_Tree(BT);
	LRootR_Traverse(BT);
	
//	cout<<"\nNut muc k: ";
	int k = 2;
	cout<<endl;
	InNutMucK(BT, k);
	cout<<endl;
	InNutMucK1(BT, k);
}

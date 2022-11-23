#include "BST.h"
// In tu goc den nut K
void RootToK(BST_Type BST, Info K){
	if(BST != NULL){
		cout << BST->Key << '\t';
		if(BST->Key > K) RootToK(BST->Left, K);
		else if (BST->Key < K) RootToK(BST->Right, K);
	}
}

// Cach 2:
void RootToK(BST_Type BST, Info K){
	BST_Type  p=BST;
	while(p!=NULL && p->Key!=K){
		cout <<p->Key<<'\t';
		if(p->Key)
		....
		else if(p->Key < K) p=p->Right;
	}
	if(p!=NULL) cout << K;
}
main(){
	RootToK(BST);	
}

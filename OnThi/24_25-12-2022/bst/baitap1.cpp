#include "bst.h"

void KeyMin(BST_Type BST){
	if(BST!=NULL){
		if(BST->Left==NULL && BST->Right==NULL) cout << BST->Key;
		else KeyMin(BST->Left);
	}
}

void Min(BST_Type BST_Tree ){
	if(BST_Tree->Left==NULL){
		cout<< BST_Tree->Key;
	}
	Min(BST_Tree->Left);
}


main(){
	BST_Type BST;
	Initialize(BST);
	Add_Node(BST,1);
	Add_Node(BST,2);
	Add_Node(BST,3);
	Add_Node(BST,4);
	Add_Node(BST,5);
	Add_Node(BST,6);
	Add_Node(BST,7);
	Add_Node(BST,8);
	Add_Node(BST,9);
	LRootR_Traverse(BST);
	cout<<"\nMin:";KeyMin(BST);
	cout<<"\nMin:";
	Min(BST);
	
}

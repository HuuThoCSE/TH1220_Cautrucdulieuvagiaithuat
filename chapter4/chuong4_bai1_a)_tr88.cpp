#include "module_tree.h"

void InLa(BinT_Type BTree){
	if(BTree == NULL) return ;
	else if(BTree->Left==NULL && BTree->Right==NULL)
		cout << BTree->Key << '\t';
	else InLa(BTree->Left); InLa(BTree->Right);
}

main(){
	BinT_Type BT;
 	cout<<"=====NHAP CAY NHI PHAN====="<<endl;
 	Initialize(BT);
 	Read_Tree(BT);
 	
 	// In Tree
 	cout<<"==CAY NHI PHAN:=="<<endl;
 	LRootR_Traverse(BT);
 	
 	
}

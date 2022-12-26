#include "caynhiphan.h"
void Inla(BinT_Type BTree){
	if (BTree!=NULL)
	if(BTree->Left == NULL && BTree->Right == NULL)
		cout << BTree->Key <<'\t';
	else {
		Inla(BTree->Left);
		Inla(BTree->Right);
	}		
} // C?u trúc rõ ràng h?n

main(){
	BinT_Type BT;
	Initialize(BT);
	Read_Tree(BT);
	LRootR_Traverse(BT);
	
	cout<<"\nNut la: ";
	Inla(BT);
}

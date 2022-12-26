#include "caynhiphan.h"
int DemB2 (BinT_Type BTree){
	if(BTree == NULL){
		return 0;
	}else if(BTree->Left!=NULL && BTree->Right!=NULL){
			return 1+DemB2(BTree->Left)+DemB2(BTree->Right);
		}else return DemB2(BTree->Left)+DemB2(BTree->Right);
}

int DemB1(BinT_Type BTree){
	if (BTree==NULL) return 0;
	else 
 	    if(BTree->Left!=NULL&&BTree->Right==NULL || BTree->Left==NULL&&BTree->Right!=NULL)
 		    return 1+DemB1(BTree->Left)+DemB1(BTree->Right);
	    else DemB1(BTree->Left)+DemB1(BTree->Right);
}


main(){
	BinT_Type BT;
	Initialize(BT);
	Read_Tree(BT);
	LRootR_Traverse(BT);
	
	cout<<"\nB1: "<<DemB1(BT)<<endl;
	cout<<"\nB2: "<<DemB2(BT)<<endl;
}

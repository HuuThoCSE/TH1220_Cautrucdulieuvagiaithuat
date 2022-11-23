#include "module_tree.h"
// In la thuoc muc K -> BS TSHT la muc = 1
void INLaMucK(BTree_Type BTree, int K, int muc = 1){
	if (BTree != NULL)
		if(       muc == K)
			if(Là lá) cout << BTree->Key << "\t";
		else { // muc < K  
			InLaMucK(BTree->Left, K, muc+1); // Muc < K
			InLaMucK(BRree->Right, K, muc+1);
		}
}
main(){
	// In la
}

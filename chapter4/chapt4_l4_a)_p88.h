#include "BST.h"
// Noi dung cua nut nho nhat
void ValueMinInBST(BST_Type BST){
	int ValueMin = 0;
	if(BST == NULL)
		return;
	ValueMinInBST(BST->Left);
		if(ValueMin > BST->Key)
			ValueMin = BST->Key;
	ValueMinInBST(BST->Right);
}

void PrintValueMin(BST_Type BST){
	if(BST == NULL)
		return;
	LRootR_Traverse(BST->Left);
	
	cout << BST->Key << '\t';
	
	LRootR_Traverse(BST->Right);
}

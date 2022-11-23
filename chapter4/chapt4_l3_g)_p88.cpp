// chapt4_l3_g)_p88
	// in nut ND>K 8 9
void NutLHK(BST_Type BST_Tree,Info K){
	if(BST_Tree!=NULL){
		if(BST_Tree->Key==K) LRootR_Travelling (BST_Tree->Right);
		else if (BST_Tree->Key<K) NutLHK (BST_Tree->Right,K);
		else (BST_Tree->Right,K);
			cout<<BST_Tree->Key<<'\t';
			LRootR_Travelling(BST_Tree->Right);
	}
}

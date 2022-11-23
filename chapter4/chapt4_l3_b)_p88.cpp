//3b in tu K =>goc 7 7 6 8 5
void KToRoot (BST_Type BST_Tree,Info K){
	if (BST_Tree != NULL){		
		if (BST_Tree->Key<K) RootToK (BST_Tree->Right,K);
		else RootToK (BST_Tree->Left,K);
		cout<<BST_Tree->Key<<'\t';
	}
}


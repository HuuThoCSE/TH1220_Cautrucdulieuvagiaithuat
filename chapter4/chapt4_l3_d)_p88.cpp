// chapt4_l3_d)_p88
	// In tu min ve goc
void MintoRoot(BST_Type BST){
	if(BST != NULL){
		MinToRoot(BST->Left);
		cout << BST->Key<<'\t';
	}
}

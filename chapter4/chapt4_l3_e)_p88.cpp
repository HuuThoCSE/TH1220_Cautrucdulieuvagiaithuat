// chapt4_l3_e)_p88
	// In tu min den max

//3e in tu Min => Max 1 2 3 5 8 9
void MinToMax (BST_Type BST_Tree){
	if (BST_Tree!=NULL){
		MinToRoot (BST_Tree);
		RootoMax (BST_Tree->Right);
	}
}

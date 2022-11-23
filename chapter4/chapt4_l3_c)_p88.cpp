// chapt4_l3_c)_p88
	// In tu goc den max
void RootToMax(BST_Type BST){
	BST_Type p=BST;
	while(p!=NULL){
		cout << p->Key << '\t';
		p=p->Right;
	}
}

void RootToMaxDQ(BST_Type BST){
	if(BST != NULL){
		cout << BST->Key<< '\t';
		RootToMaxDQ(BST->Right);
	}
}

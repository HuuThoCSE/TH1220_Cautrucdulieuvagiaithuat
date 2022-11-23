#include "BST.h"
#include "chapt4_l4_a)_p88.h"
main(){
	BST_Type BST;
	cout << "======= NHAP CAY NHI PHAN =======" << endl;
	Intialize(BST);
	Read_Tree(BST);
	cout << "\n======= IN CAY NHI PHAN THEO CACH LNR =======" << endl;
	LRootR_Traverse(BST);
	cout << endl;
}

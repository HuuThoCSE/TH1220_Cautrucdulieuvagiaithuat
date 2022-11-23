#include "BST.h"
// 3
// 5 3 2 1 0 0 0 4 0 0 8 6 7 0 0 9 0 0 0
main(){
	Info X, K;
	BST_Type BST;
	cout << "======= NHAP CAY NHI PHAN =======" << endl;
	Intialize(BST); // X-X
	Read_Tree(BST);
	cout << "\n======= IN CAY NHI PHAN THEO CACH LNR =======" << endl;
	LRootR_Traverse(BST);
	cout << endl;
	cout << "======= TIM KIEM MOT NUT =======" << endl;
	cout << "Nhap vao 1 nut ma ban muon tim kiem: "; cin >> K;
	Searching(BST, K);
	cout << "======= THEM VAO MOT NUT =======" << endl;
	Info Y;
	cout << "Nhap gia tri vao 1 nut: "; cin >> Y;
	Add_Node(BST, Y);
}

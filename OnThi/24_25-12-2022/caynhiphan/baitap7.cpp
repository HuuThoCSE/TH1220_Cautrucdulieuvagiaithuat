#include "caynhiphan.h"

int FindLongestPath(BinT_Type BTree) {
if (BTree == NULL) return 0;
	int left_path = FindLongestPath(BTree->Left);
	int right_path = FindLongestPath(BTree->Right);
	return max(left_path, right_path) + 1;
}

long ChieuDaiTrong(BinT_Type BTree, int muc)
{
	if (BTree==NULL)
		return 0;
	else
		return muc+ChieuDaiTrong(BTree->Left,muc+1)+ChieuDaiTrong(BTree->Right,muc+1);
}

long ChieuDaiTrong1(BinT_Type BTree, int muc)
{
	if (BTree==NULL)
		return 0;
	else
		return muc+ChieuDaiTrong1(BTree->Left,muc+1)+ChieuDaiTrong1(BTree->Right,muc+1);
}



main(){
	BinT_Type BT;
	Initialize(BT);
	Read_Tree(BT);
	LRootR_Traverse(BT);
	
	cout<<"\nTH1: "<<FindLongestPath(BT);
	cout<<"\nTH2: "<<ChieuDaiTrong(BT, 1);
	cout<<"\nTH3: "<<ChieuDaiTrong1(BT, 1);
}

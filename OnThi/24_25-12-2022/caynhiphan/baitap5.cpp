#include "caynhiphan.h"

int sumOddNodes(BinT_Type BTree) {
  if (BTree == NULL) return 0;
  int sum = 0;
  if (BTree->Key % 2 == 1) sum += BTree->Key;
  return sum + sumOddNodes(BTree->Left) + sumOddNodes(BTree->Right);
} // T?t h?n

Info Sum(BinT_Type BTree)
{
	if (BTree==NULL)
		return 0;
	if(BTree->Key%2!=0)
		return BTree->Key + Sum(BTree->Left) + Sum(BTree->Right);
	else
		return Sum(BTree->Left) + Sum(BTree->Right);
}

Info Sum1(BinT_Type BTree)
{
	if (BTree==NULL)
		return 0;
	if(BTree->Key%2!=0)
		return BTree->Key+Sum1(BTree->Left)+Sum1(BTree->Right);
	else
		return Sum1(BTree->Left)+Sum1(BTree->Right);
}

main(){
	BinT_Type BT;
	Initialize(BT);
	Read_Tree(BT);
	LRootR_Traverse(BT);
	
	cout<<"\nTH1: "<<sumOddNodes(BT)<<endl;
	cout<<"\nTH2: "<<Sum(BT)<<endl;
	cout<<"\nTH3: "<<Sum1(BT)<<endl;
}

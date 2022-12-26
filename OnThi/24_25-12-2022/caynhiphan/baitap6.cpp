#include "caynhiphan.h"

void FindNodesPerLevel(BinT_Type BTree, int nodesPerLevel[], int level) {
if (BTree == NULL) return;
nodesPerLevel[level]++;
FindNodesPerLevel(BTree->Left, nodesPerLevel, level+1);
FindNodesPerLevel(BTree->Right, nodesPerLevel, level+1);
} // T?t h?n

int FindLevelWithMostNodes(BinT_Type BTree) {
// T?o m?t m?ng ?? l?u s? nút t?i m?i m?c

int nodesPerLevel[100] = {0};

// S? d?ng hàm duy?t theo t?ng m?c ?? ??m s? nút t?i m?i m?c
FindNodesPerLevel(BTree, nodesPerLevel, 0);

// Tìm m?c có s? nút l?n nh?t
int maxLevel = 0;
for (int i = 0; i < 100; i++) {
if (nodesPerLevel[i] > nodesPerLevel[maxLevel]) {
maxLevel = i;
}
}

return maxLevel;
}

int Demnutmuck (BinT_Type BTree, int k, int muc = 1){
if(BTree == NULL)	
	return 0 ;
else if(muc == k) return 1 ;
	else return Demnutmuck(BTree->Left,k,muc+1) +Demnutmuck(BTree->Right,k,muc+1) ;
}


void Inmucnhieunut (BinT_Type BTree)
{
	int cc = Tree_Height(BTree);
	int max = Demnutmuck(BTree,1,1);
	for( int i = 2; i <= cc; i++)
		if(max < Demnutmuck(BTree,i,1))	
			max = Demnutmuck(BTree,i,1);
	cout << "Cac muc co so nut nhieu nhat la: "; 
	for( int i = 1; i <= cc; i++)
		if(Demnutmuck(BTree,i,1 == max ))
			cout<<i<<'\t'; 
}

main(){
	BinT_Type BT;
	Initialize(BT);
	Read_Tree(BT);
	LRootR_Traverse(BT);
	
	cout<<"\nTH1: ";FindLevelWithMostNodes(BT);
	cout<<"\nTH2: ";Inmucnhieunut(BT);
}

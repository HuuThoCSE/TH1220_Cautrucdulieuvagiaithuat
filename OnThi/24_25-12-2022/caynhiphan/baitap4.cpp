#include "caynhiphan.h"
Info findMaxNode(BinT_Type BTree) {
  if (BTree == NULL) return INT_MIN;  // tr? v? giá tr? nh? nh?t có th? c?a ki?u d? li?u Info

  Info max = BTree->Key;
  Info LMax = findMaxNode(BTree->Left);
  Info RMax = findMaxNode(BTree->Right);

  if(LMax > max) max=LMax;
  if(RMax > max) max=RMax;
  return max;
}

Info MAX(Info a, Info b, Info c)
{
	Info t;
	if(a>b) t = a;
	else t = b;
	if(c>t) t = c;
	return t; 
}

Info NutMax(BinT_Type BTree){
	if(BTree == NULL) return 0;
	else return MAX(BTree-> Key, NutMax(BTree -> Left), NutMax(BTree->Right));
}
Info Max11(BinT_Type BTree){
	if (BTree==NULL)
		return 0;
	Info v1=Max11(BTree->Left);
	Info v2=Max11(BTree->Right);
	Info v=BTree->Key;
	if (v<v1) v=v1;
	if (v<v2) v=v2;
	return v;
}


main(){
	BinT_Type BT;
	Initialize(BT);
	Read_Tree(BT);
	LRootR_Traverse(BT);
	
	cout<<"\nTH1: "<<findMaxNode(BT)<<endl;
	cout<<"\nTH2: "<<NutMax(BT)<<endl;
	cout<<"\nTH3: "<<Max11(BT)<<endl;
}

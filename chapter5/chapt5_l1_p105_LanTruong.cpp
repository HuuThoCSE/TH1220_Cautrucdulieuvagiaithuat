#include<iostream>
using namespace std;
typedef int Info;
struct BinT_Node
{
	Info Key;
	BinT_Node* Left;
	BinT_Node* Right;
};
typedef BinT_Node* BinT_Type;
void Initialize(BinT_Type &BTree)
{
	BTree = NULL;
} 
BinT_Type Create_Node(Info NewData)
{
	BinT_Type BTnode = new BinT_Node;
	if(BTnode != NULL)
	{
		BTnode->Left = NULL;
		BTnode->Right = NULL;
		BTnode->Key = NewData;
	}
	return BTnode;
}
void Read_Tree(BinT_Type &BTree)
{ 
	Info X;
	cin>>X;
	if(X!=0)
	{
		BinT_Type BT;
		BT = Create_Node(X);
		BTree = BT;
		cout<<"Nhap con trai cua "<<X<<" : ";
		Read_Tree(BTree->Left);
		cout<<"Nhap con phai cua "<<X<<" : ";
		Read_Tree(BTree->Right);
	}
	else BTree=NULL;
}
//in cac nut la
Info Nut_La(BinT_Type BTree)
{ 
	if(BTree != NULL)
	{
		if(BTree->Left==NULL && BTree->Right==NULL) cout<<BTree->Key<<'\t';
		else
		{
			Nut_La(BTree->Left);
			Nut_La(BTree->Right);	
		}
	
	}
}
//in cac con trai
void Nut_R(BinT_Type BTree)
{
	if(BTree != NULL)
	{
		if (BTree->Left != NULL) cout<<BTree->Left->Key<<'\t';
		Nut_R(BTree->Left);
		Nut_R(BTree->Right);
	}
		
}
//in cac nut nam tren muc K, muc thuong co gia tri 1 
Info Nut_K(BinT_Type BTree,int K, int M)
{
	if(BTree != NULL)
	{
		if(M==K) cout<<BTree->Key<<'\t';
		else 
			if (M<K) 
			{
				Nut_K(BTree->Left,K,M+1);
				Nut_K(BTree->Right,K,M+1);
			}
	}
	
}
//dem so nut bac 2
Info Dem_B2(BinT_Type BTree)
{
	if(BTree == NULL) return 0; 
	if(BTree->Left!=NULL && BTree->Right!=NULL) 
		return 1 + Dem_B2(BTree->Left) + Dem_B2(BTree->Right);
	else
		return Dem_B2(BTree->Left)+Dem_B2(BTree->Right);
	
}
//cho biet noi dung cua nut Max
Info Max(Info a,Info b,Info c)
{
     Info t;
     if(a>b) return t=a;
     else 
	 	return t=b;
     if(c>t && t==c) return t;
}
Info Nut_Max(BinT_Type BTree)
{
     if(BTree == NULL) return 0;
	 else 
	    return Max(BTree->Key,Nut_Max(BTree->Left),Nut_Max(BTree->Right));
}
//tong cac nut la nut le
Info Tong_Le(BinT_Type BTree)
{
    if(BTree != NULL) return 0;
	else 
	{
		if (BTree->Key%2==0) 
        	return BTree->Key+Tong_Le(BTree->Left)+Tong_Le(BTree->Right);
    	else
	    	return Tong_Le(BTree->Left)+Tong_Le(BTree->Right);
	}
}
// Xay dung ham Tinh chieu cao cua cay
Info Tree_Height(BinT_Type BTree)
{
   	if(BTree != NULL) return 0;
    int HTL=Tree_Height(BTree->Left);
    int HTR=Tree_Height(BTree->Right);
    if(HTL>HTR) return HTL+1;
    else return HTR+1;
}
//in ra muc co so nut nhieu nhat
Info inmucnucmax(BinT_Type BTree)
{
	Info cc=Tree_Height(BTree);
	Info max=Nut_K(BTree,1,1); 
	for (int i=2; i<=cc; i++)
		if (Nut_K(BTree,i,1) > max) cout<<i<<'\t';
 } 
//tinh chieu dai duong di trong
long Chieu_dai(BinT_Type BTree, int M)
{
    if(BTree == NULL) return 0;
    else
		return M+Chieu_dai(BTree->Left,M+1)+Chieu_dai(BTree->Right,M+1);
} 
main()
{
	BinT_Type BT;
	cout<<"NHAP CAY NHI PHAN  ";
	Initialize(BT);
	Read_Tree(BT);
	cout<<"CAC NUT LA NUT LA: ";
	Nut_La(BT);
	cout<<endl<<"CAC NUT LA NUT CON TRAI CUA CAY: ";
	Nut_R(BT);
	int K;
	cout<<endl<<"Nhap muc K: ";
	cin>>K;
	cout<<endl<<"CAC NUT LA NUT NAM TREN MUC K: ";Nut_K(BT,K,1);
	cout<<endl<<"SO NUT BAC 2 CUA CAY LA: "<<Dem_B2(BT);
	cout<<endl<<"NOI DUNG CUA NUT MAX LA: "<<Nut_Max(BT);
	cout<<endl<<"TONG CAC NUT LE LA: "<<Tong_Le(BT);
	cout<<endl<<"MUC CO SO NUT NHIEU NHAT: "<<inmucnucmax(BT);
	cout<<endl<<"CHIEU DAI DUONG DI TRONG: "<<Chieu_dai(BT,0);
}

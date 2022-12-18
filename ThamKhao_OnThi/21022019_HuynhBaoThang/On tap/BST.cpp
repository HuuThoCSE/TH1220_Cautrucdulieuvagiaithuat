#include<iostream>
using namespace std;
typedef int Info;
struct BST_Node{
	Info Key;
	BST_Node* Right;
	BST_Node* Left;
};
typedef BST_Node* BST_Type;
void Initialize(BST_Type &BST)
{
	BST = NULL;
}
void Add_BST_Node(BST_Type &BST,Info NewData)
{
	if(BST==NULL)
	{
		BST = new BST_Node;
		if(BST!=NULL)
		{
			BST->Key = NewData;
			BST->Left = NULL;
			BST->Right = NULL;
		}
	}
	else
	{
		if(BST->Key == NewData)	return;
		else if(BST->Key > NewData)
			Add_BST_Node(BST->Left,NewData);
		else
			Add_BST_Node(BST->Right,NewData);
	}
}
void LNR(BST_Type BST)
{
	if(BST==NULL) return;
	LNR(BST->Left);
	cout<<BST->Key<<'\t';
	LNR(BST->Right);
}
void ReadTree(BST_Type &BST)
{
	Info X;
	cout<<"Nhap nut goc: ";cin>>X;
	Add_BST_Node(BST,X);
	while(X!=0)
	{
		cout<<"Nhap phan tu tiep theo: ";cin>>X;
		if(X!=0)
			Add_BST_Node(BST,X);
	}
}
//In nut goc den nut nho nhat
void InRootToMin(BST_Type BST)
{
	BST_Type P = BST;
	while(P->Left!=NULL)
	{
		cout<<P->Key<<'\t';
		P=P->Left;
	}
	if(P->Left==NULL)
		cout<<P->Key;
	cout<<endl;
}
//Dem so nut co khoa <= K
int Count_Node(BST_Type BST)
{
	if(BST==NULL) return 0;
	int L = Count_Node(BST->Left);
	int R = Count_Node(BST->Right);
	return (1 + R + L);
}
int Dem(BST_Type BST,Info K)
{
	int dem = 0;
	if(BST==NULL) return 0;
	if(BST->Key <=K)
	{
		dem++;
		dem+=Count_Node(BST->Left);
	}
	if(BST->Key>K)
	{
		Dem(BST->Left,K);
	}
	return dem;		
}
main()
{
	BST_Type BST;
	Info K;
	Initialize(BST);
	cout<<"-----NHAP BST-----"<<endl;
	ReadTree(BST);
	cout<<"------DUYET CAY THEO LNR-----"<<endl;
	LNR(BST);
	cout<<endl;
	cout<<"In tu goc den nut lon nho nhat"<<endl;
	InRootToMin(BST);
	cout<<"Nhap K: ";cin>>K;
	cout<<"Co "<<Dem(BST,K)<<" co nut nho hon bang "<<K<<endl;
	
}

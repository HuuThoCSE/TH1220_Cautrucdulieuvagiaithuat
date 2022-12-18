#include<iostream>
using namespace std;
typedef int Info;
struct BST_Node
{
	Info Key;
	BST_Node* Left;
	BST_Node* Right;
};
typedef BST_Node* BST_Type;

void Initialize(BST_Type &BST)
{
	BST=NULL;
}
void LNR(BST_Type BST)
{
	if(BST==NULL) return;
	LNR(BST->Left);
	cout<<BST->Key<<'\t';
	LNR(BST->Right);
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
void ReadTree(BST_Type &BST)
{
	Info X;
	cout<<"Nhap nut goc:";cin>>X;
	Add_BST_Node(BST,X);
	while(X!=0)
	{
		cout<<"Nhap noi dung phan tu tiep theo cua cay(Nhap 0 de ket thuc): ";cin>>X;
		if(X!=0)
			Add_BST_Node(BST,X);
	}
}
//In nut goc den nho nhat
//De Quy
void InRootToMin(BST_Type BST)
{
	if(BST!=NULL)
	{
		cout<<BST->Key<<'\t';
		InRootToMin(BST->Left);
	}
	
}
//Khong de quy
void InRootToMin1(BST_Type BST)
{
	BST_Type P = BST;
	while(P->Left!=NULL)
	{
		cout<<P->Key<<'\t';
		P=P->Left;
	}
	if(P->Left==NULL)
		cout<<P->Key;
}
//Dem so nut co khoa <= K
int Dem(BST_Type BST,Info K)
{
	int dem = 0;
	if(BST==NULL) return 0;
	else if(BST->Key>K)
		dem+=Dem(BST->Left,K);
	else
	{
		dem++;
		dem+=Dem(BST->Left,K);
		dem+=Dem(BST->Right,K);
	}
	return dem;	
}
//Cho biet nut lon nhat nam o muc nao
int Muc(BST_Type BST)
{
	BST_Type P = BST;
	int dem=1;
	while(P->Right!=NULL)
	{
		P=P->Right;
		dem++;
	}
	return dem;
}
main()
{
	BST_Type BST;
	Info K;
	Initialize(BST);
	cout<<"------NHAP CAY BST-----"<<endl;
	ReadTree(BST);
	cout<<"-----CAY BST DUYET THEO LNR-----"<<endl;
	LNR(BST);
	cout<<endl;
	cout<<"Cac nut tren duong di tu nut GOC den nut NHO NHAT la:"<<endl;
	InRootToMin1(BST);
	cout<<endl;
	cout<<"Nhap K: ";cin>>K;
	cout<<"Co "<<Dem(BST,K)<<" nut co khoa nho hon hoac bang "<<K<<endl;
	cout<<"Nut lon nhat nam o muc "<<Muc(BST)<<" trong cay";
}

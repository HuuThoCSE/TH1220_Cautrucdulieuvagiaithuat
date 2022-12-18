//Cay BT
//Nhap cay
//Duyet LNR
//Dem so nut bac 1
//In cac nut nam o muc M
//Cho biet nut lon nhat nam o muc nao trong cay
//Ham main
#include<iostream>
using namespace std;
typedef float Info;
struct BT_Node
{
	Info Key;
	BT_Node* Left;
	BT_Node* Right;
};
typedef BT_Node* BT_Type;
void Iniatialize(BT_Type &BT)
{
	BT = NULL;
}
BT_Type Create_Node(Info NewData)
{
	BT_Type Node = new BT_Node;
	if(Node!=NULL)
	{
	Node->Key=NewData;
	Node->Right=NULL;
	Node->Left=NULL;
	}
}
void LNR(BT_Type BT)
{
	if(BT==NULL) return;
	LNR(BT->Left);
	cout<<BT->Key<<'\t';
	LNR(BT->Right);
}
void ReadTree(BT_Type &BT)
{
	Info X;
	cin>>X;
	if(X!=0)
	{
		BT_Type Node = Create_Node(X);
		BT = Node;
		cout<<"Nhap cay con cua  ben trai cua "<<X<<": ";
		ReadTree(BT->Left);
		cout<<"Nhap cay con cua ben phai cua "<<X<<": ";
		ReadTree(BT->Right);
	}
	else BT=NULL;
}

int Muc(BT_Type BT)
{
	int dem = 1;
	if(BT==NULL) return 0;
	int lcur = Muc(BT->Left);
	int rcur = Muc(BT->Right);
	int cur = BT->Key;
	if(lcur > cur)
	{
		dem+=1;
		cur = lcur;
	}
	if(rcur > cur)
	{
		dem+=1;
		cur = rcur;
	}
	return dem;
}
main()
{
	BT_Type BT;
	Info K;
	Iniatialize(BT);
	cout<<"-----NHAP CAY BT-----"<<endl;
	ReadTree(BT);
	cout<<"------DUYET CAY BT THEO LNR-----"<<endl;
	LNR(BT);
	cout<<endl;
	cout<<Muc(BT);
}

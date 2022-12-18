#include <iostream>
using namespace std;
typedef float Info;
struct BinT_Node{
	Info Key;
	BinT_Node* Left;
	BinT_Node* Right;
};
typedef BinT_Node* BinT_Type;
void TaoNull(BinT_Type &BT){
	BT==NULL;
}
BinT_Type TaoNode(Info Data){
	BinT_Type BT = new BinT_Node;
	if(BT!=NULL){
		BT->Left=NULL;
		BT->Right=NULL;
		BT->Key=Data;
	}
	return BT;
}
void ReadBT(BinT_Type &BT){
	Info x;
	cin>>x;
	if(x!=0){
		BinT_Type BTTemp=TaoNode(x);
		BT=BTTemp;
		cout<<"Nhap con trai cua "<<x<<": ";
		ReadBT(BT->Left);
		cout<<"Nhap con phai cua "<<x<<": ";
		ReadBT(BT->Right);
	}else BT=NULL;
}
void LNR(BinT_Type BT){
	if(BT==NULL)
		return;
	LNR(BT->Left);
	cout<<BT->Key<<" ";
	LNR(BT->Right);
}
float DemNutBac1(BinT_Type BT){
	if(BT==NULL)
		return 0;
	float a,b;
	a=b=0;
	a=DemNutBac1(BT->Left);
	b=DemNutBac1(BT->Right);
	if((BT->Left!=NULL&&BT->Right==NULL)||(BT->Left==NULL&&BT->Right!=NULL))
		return 1;
	return a+b;
}
void InNutM(BinT_Type BT,int M,int i=0){
	if(BT==NULL)
		return;
	if(M==i){
		cout<<BT->Key<<" ";
	}else if(M>i){
		i++;
		InNutM(BT->Left,M,i);
		InNutM(BT->Right,M,i);
	}
}
Info TimMax(BinT_Type BT){
	if(BT==NULL)
		return 0;
	Info Max=BT->Key;
	if(Max<TimMax(BT->Left))
		Max=TimMax(BT->Left);
	if(Max<TimMax(BT->Right))
		Max=TimMax(BT->Right);
	return Max;
}
void MaxOMuc(BinT_Type BT, Info Dt, int i=0){
	if(BT->Key==Dt)
		cout<<i<<" ";
	else MaxOMuc(BT,Dt,i++);
}
main(){
	BinT_Type BT;
	TaoNull(BT);
	cout<<"Nhap cay: ";
	ReadBT(BT);
	cout<<"Cay vua nhap:\n";
	LNR(BT);
	cout<<"\nSo nut bat 1:"<<DemNutBac1(BT);
	cout<<"\nNhap muc M:";
	int M;
	cin>>M;
	InNutM(BT,M);
	Info a=TimMax(BT);
	cout<<"Max:";
	MaxOMuc(BT,a);
}

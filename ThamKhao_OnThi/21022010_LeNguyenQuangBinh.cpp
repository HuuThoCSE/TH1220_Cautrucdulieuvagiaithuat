#include <iostream>
using namespace std;
typedef int ElementType;
struct Node{
	ElementType Element;
	Node* Next;
};
typedef Node* Position;
typedef Node* List;
void MakeNullList(List &l){
	l=new Node;
	l->Next=NULL;
}
Position Last(List l){
	Position P=l;
	while(P->Next!=NULL)
		P=P->Next;
	return P;
}
void Nhap1PT(ElementType E,Position P,List &l){
	Position temp=new Node;
	temp->Element=E;
	temp->Next=P->Next;
	P->Next=temp;
}
void NhapNpt(List &l){
	ElementType temp;
	do{
		cout<<"Nhap phan tu:";
		cin>>temp;
		if(temp!=0)
			Nhap1PT(temp,Last(l),l);
	}while(temp!=0);
}
void Them1ptCuoi(ElementType X,List &l){
	if(X!=0){
		Position temp=l,temp2;
		temp=Last(l);
		temp2=new Node;
		temp2->Element=X;
		temp2->Next=temp->Next;
		temp->Next=temp2;
	}
}
void InList(List l){
	if(l->Next!=NULL){
		Position P=l;
		while(P->Next!=NULL){
			cout<<P->Next->Element<<" ";
			P=P->Next;
		}
	}
	else cout<<"Danh sach rong!";
}
void VtriCuaPTMax(List l){
	if(l->Next!=NULL){
		Position temp=l->Next;
		int max=temp->Element;
		while(temp->Next!=NULL){
			if(max<temp->Next->Element)
				max=temp->Next->Element;
			temp=temp->Next;
		}
		int dem=0;
		temp=l;
		while(temp->Next!=NULL){
			if(max==temp->Next->Element)
				cout<<dem<<" ";
			dem++;
			temp=temp->Next;
		}
	}
	else cout<<"Danh sach rong nen khong co phan tu lon nhat!";
}
void XoaPTkoDungVT(List &l){
	if(l->Next!=NULL){
		Position temp=l->Next;
		while(temp->Next!=NULL){
			if(temp->Element>temp->Next->Element){
				temp->Next=temp->Next->Next;
			}
			else temp=temp->Next;
		}
	}
}
main(){
	List L;
	MakeNullList(L);
	cout<<"Nhap noi dung cac phan tu voi 0 la dung viec nhap:\n";
	NhapNpt(L);
	cout<<"Danh sach vua nhap la:\n";
	InList(L);
	ElementType X;
	cout<<"\n\nNhap phan tu x:";
	cin>>X;
	Them1ptCuoi(X,L);
	cout<<"Vi tri cua pt co noi dung lon nhat la:\n";
	VtriCuaPTMax(L);
	XoaPTkoDungVT(L);
	cout<<"\n\nDanh sach sau khi xoa cac phan tu khong dung vi tri:\n";
	InList(L);
}

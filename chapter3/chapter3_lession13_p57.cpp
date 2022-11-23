#include "module_list_int.h"
void ThemX(ElementType X, List &L)
{
	Position P=L;
	while(P->Next!=NULL && P->Next->Element<X)
	{
		P=P->Next;
	}
	InsertList(X, P, L);
}
main(){
	List L;
	MakeNullList(L);
	Position P;
	ElementType X;
	MakeNullList (L);
	cout<<"=====NHAP DANH SACH LIET KET====="<<endl;
	ReadList(L);
	cout<<"=====IN DANH SACH LIEN KET====="<<endl;	
	PrintList (L);
	cout<<endl;
	cout<<"Nhap noi dung phan tu muon them: ";
	cin>>X;
	ThemX(X, L);
	cout<<"===DANH SACH SAU KHI THEM==="<<endl;
	PrintList(L);
}

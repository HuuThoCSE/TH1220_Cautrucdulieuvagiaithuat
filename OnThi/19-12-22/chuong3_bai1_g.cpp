// Chuong 1 - bai 1 - f
#include "dslk_songuyen.h"
// In tu X xuat hien o lan thu K den cuoi DS
void TachDSChanLe(List L, List &LC, List &LL){
	MakeNullList(LC);
	MakeNullList(LL);
	Position P=L;
	while(P->Next!=NULL){
		if(P->Next->Element%2==0)
			InsertList(P->Next->Element, Last(LC), LC);
		else
			InsertList(P->Next->Element, Last(LL), LL);
		P=P->Next;
	}
}
main(){
	List L, LC, LL;
	MakeNullList(L);
	
	// Nhap DS
	ReadList(L);
	
	// In DS
	cout<<"DS 1: ";
	PrintList(L);

	// Continue...
	TachDSChanLe(L, LC, LL);
	cout<<"\nDS chan: "; PrintList(LC);
	cout<<"\nDS le: "; PrintList(LL);
}

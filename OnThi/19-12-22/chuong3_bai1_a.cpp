// Chuong 1 - bai 1 - a
#include "dslk_songuyen.h"
// Them 1 phan tu vao sau Y xuat hien sau cung
void AddLastY(ElementType X, ElementType Y, List &L){
	Position q, P= L;
	while(P->Next!=NULL){
		if(P->Next->Element==Y)
			q=P->Next;
		P=P->Next;
	}
	if(q!=NULL) InsertList(X, q, L);
}
main(){
	List L;
	MakeNullList(L);
	
	// Nhap DS
	ThemDauDS(1);
	
	// In DS
	cout<<"DS 1: ";
	PrintList(L);

	// Continue...
	int X, Y;
	cout<<"\nNhap vao gia tri X: "; cin>>X;
	cout<<"\nNhap vao vi tri them sau Y: "; cin>>Y;
	AddLastY(X, Y, L);
	cout<<"\nDS sau khi them: "; 
	PrintList(L);
}

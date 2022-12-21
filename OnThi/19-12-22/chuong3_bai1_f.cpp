// Chuong 1 - bai 1 - f
#include "dslk_songuyen.h"
// In tu X xuat hien o lan thu K den cuoi DS
void PrintListInXToEnd(ElementType X, ElementType K, List &L){
	Position q, P=L;
	int dem=0;
	while(P->Next!=NULL && dem<K){
		if(P->Next->Element==X) dem++;
		q=P;P=P->Next;
	}
	if(dem==K) PrintList(q);
}
main(){
	List L;
	MakeNullList(L);
	
	// Nhap DS
	ReadList(L);
	
	// In DS
	cout<<"DS 1: ";
	PrintList(L);

	// Continue...
	int X, K;
	cout<<"\nNhap Gia tri in tu X: "; cin>>X;
	cout<<"\nNhap Lan thu K: "; cin>>K;
	
	cout<<"\nDS: \n"; 
	PrintListInXToEnd(X, K, L);
}

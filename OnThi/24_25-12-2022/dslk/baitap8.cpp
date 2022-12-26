#include "dslk_songuyen.h"
void TachdS(List &L,List &Lm){
	Position P=L;
	while(P->Next!=NULL){
		InsertList(P->Next->Element,Last(Lm),Lm);
		DeleteList(P,L);
		if(P->Next!=NULL) 
			P=P->Next;
	}
}

main(){
	List L;
	List Lm;
	MakeNullList(L);
	MakeNullList(Lm);
	ThemDau(5, L);
	ThemDau(4, L);
	ThemDau(3, L);
	ThemDau(2, L);
	ThemDau(3, L);
	ThemDau(1, L);
	cout<<"DS: "; PrintList(L);
	cout<<"\nDSLm: "; PrintList(Lm);
	
//	LocDs(L);
	Tachds(L, Lm);
	cout<<"\nDS: "; PrintList(L);
	cout<<"\nDSLm: "; PrintList(Lm);
}

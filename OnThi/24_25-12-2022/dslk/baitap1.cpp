#include "dslk_songuyen.h"
void ThemsauYCC(ElementType X, ElementType Y, List &L){ 
	Position P=L, Temp=NULL;
	while(P->Next != NULL){
		if(P->Next->Element == Y)
			Temp=P->Next;
		P=P->Next;	
	}
	if(Temp!=NULL) InsertList(X,Temp,L);
}


void ThemsauYsaucung(ElementType X, ElementType Y, List &L){
	Position P=L, Temp=NULL;
	while(P->Next!=NULL){
		if(P->Next->Element==Y)
			Temp=P->Next;
		P=P->Next;
	}	
	if (Temp!=NULL) InsertList(X,Temp,L);
}


main(){
	List L;
	MakeNullList(L);
	ThemDauDS(5, L);
	ThemDauDS(4, L);
	ThemDauDS(3, L);
	ThemDauDS(2, L);
	ThemDauDS(1, L);
	cout<<"DS: "; PrintList(L);
	
	ThemsauYCC(5, 3, L);
//	ThemsauYsaucung(5, 3, L);
	
	cout<<"\nDS: "; PrintList(L);
}

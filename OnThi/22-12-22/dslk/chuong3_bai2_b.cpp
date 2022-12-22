#include "dslk_sothuc.h"
// Sap xep ds giam dan
void SapXepGiamDan(List L){
	Position P=L, Q;
	while(P->Next->Next!=NULL){
		Q=P->Next;
		while(Q->Next!=NULL){
			if(P->Next->Element<Q->Next->Element){
				ElementType temp = P->Next->Element;
				P->Next->Element = Q->Next->Element;
				Q->Next->Element = temp;
			}
			Q=Q->Next;
		}
		P=P->Next;
	}
}

void Mix2DSGiamDan(List L1, List L2, List &L){
	SapXepGiamDan(L1);
	SapXepGiamDan(L2);
	MakeNullList(L);
	Position P=L1, Q=L2;
	while(P->Next!=NULL && Q->Next != NULL){
		if(P->Next->Element > Q->Next->Element){
			InsertList(P->Next->Element, Last(L), L);
			P=P->Next;
		} else {
			InsertList(Q->Next->Element, Last(L), L);
			Q=Q->Next;
		}
	}
	while(P->Next!=NULL){
		InsertList(P->Next->Element, Last(L), L);
		P=P->Next;
	}
	while(Q->Next!=NULL){
		InsertList(Q->Next->Element, Last(L), L);
		Q=Q->Next;
	}
}

main(){
	List L1, L2, L;
	MakeNullList(L1);
	MakeNullList(L2);
	ReadList(L1);
	ReadList(L2);
	PrintList(L1);
	PrintList(L2);
	
	// Tron 2 DS co thu tu giam dan thanh 1 DS co thu tu gam dan
	Mix2DSGiamDan(L1, L2, L);

	cout<<"\nDS sau khi tron: \n";
	PrintList(L);
}

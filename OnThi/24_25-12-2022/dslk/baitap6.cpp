#include "dslk_songuyen.h"
void SapXepTangDan(List &L){
	Position P=L, Q;
	while(P->Next->Next!=NULL){
		Q=P->Next;
		while(Q->Next!=NULL){
			if(P->Next->Element > Q->Next->Element){
				ElementType temp = P->Next->Element;
				P->Next->Element = Q->Next->Element;
				Q->Next->Element = temp;
			}
			Q=Q->Next;
		}
		P=P->Next;
	}
}

void SapXepGiamDan(List &L){
	Position P=L, Q;
	while(P->Next->Next!=NULL){
		Q=P->Next;
		while(Q->Next!=NULL){
			if(P->Next->Element < Q->Next->Element){
				ElementType temp = P->Next->Element;
				P->Next->Element = Q->Next->Element;
				Q->Next->Element = temp;
			}
			Q=Q->Next;
		}
		P=P->Next;
	}
}

void Tron2(List L1, List L2, List &L3){
	SapXepTangDan(L1);
	SapXepTangDan(L2);
	L3=L1;
	Last(L3)->Next=L2->Next;
	SapXepGiamDan(L3);
}

void MixLists(List L1, List L2, List &L3) {
	SapXepTangDan(L1);
	SapXepTangDan(L2);

    Position P1 = L1, P2 = L2;
    while (P1->Next != NULL || P2->Next != NULL) {
        if(P1->Next != NULL && (P2->Next==NULL || P1->Next->Element > P2->Next->Element)) {
            InsertList(P1->Next->Element, Last(L3), L3);
            P1=P1->Next;
        }else{
            InsertList(P2->Next->Element, Last(L3), L3);
            P2=P2->Next;
        }
    }
}

void Tron(List &L,List L2, List L3)
{
	Position P=L2->Next;
	Position Q=L3->Next;
	while (P&&Q){
		if(P->Element<=Q->Element){
			ThemDau(P->Element,L);
			P=P->Next;
		}
		else{
			ThemDau(Q->Element,L);
			Q=Q->Next;
		}
	}
	while(P!=NULL){
		ThemDau(P->Element,L);
		P=P->Next;
	}
	while (Q!=NULL){
		ThemDau(Q->Element,L);
		Q=Q->Next;
	}
}



main(){
	List L1, L2, L3;
	MakeNullList(L1);
	MakeNullList(L2);
	MakeNullList(L3);
	ThemDau(1, L1);
	ThemDau(2, L1);
	ThemDau(3, L1);
	ThemDau(4, L1);
	
	ThemDau(6, L2);
	ThemDau(7, L2);
	ThemDau(8, L2);
	ThemDau(9, L2);
	cout<<"DS1: "; PrintList(L1);
	cout<<"\nDS2: "; PrintList(L2);
	
//	MixLists(L1, L2, L3);
//	Tron2(L1, L2, L3);
	Tron(L3, L1, L2);
	cout<<"\nDS3: "; PrintList(L3);
}

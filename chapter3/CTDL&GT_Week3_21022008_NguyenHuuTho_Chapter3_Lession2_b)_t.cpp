// Chuong3.Cau2.b.Tr56.t
#include "ListFloat.h"
void Chuong3Cau2bTr56(List L){
	while(P!=NULL && Q!=NULL){
		if(P->Element > Q->Element){
			InsertList(P->Element, Last(L), L);
			P=P->Next;
		} else {
			InsertList(Q->Element, Last(L), L);
			Q=Q->Next;
		}
		while (P!=NULL){
			InsertList(___);
			P=P->Next;
		}
		while (Q!=NULL){
			InsertList(___);
			Q=Q->Next;
		}
	}
}

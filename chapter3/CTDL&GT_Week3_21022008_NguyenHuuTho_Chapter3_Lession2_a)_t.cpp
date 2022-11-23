#include "ListFloat.h"
void SXTangDan(List L){
	Position P=L->Next, Q;
	while(P->Next!=NULL){
		Q = P->Next;
		while(Q!=NULL){
			if(P->Element > Q -> Element)
				swap(P->Element,Q->Element);
			Q=Q->Next;
		}
		P = P->Next;
	}
}

main(){
	#include "DataTest.h"
	DataTest();
	SXTangDan();
}

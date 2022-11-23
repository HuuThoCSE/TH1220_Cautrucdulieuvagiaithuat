// Chuong3.Cau2.d.Tr56.t
#include "ListFloat.h"
ElementType Min(List L){
	if(L->Next==NULL) return 0;
	else {
		Position P;
		ElementType Min = L->Next->Element;
		P=L->Next->Next;
		while(P!=NULL){
			if(Min > P->Element)
				Min = P->Element;
			P=P->Next;
		}
		return Min;
	}
}
main(){
	Min(L);
}

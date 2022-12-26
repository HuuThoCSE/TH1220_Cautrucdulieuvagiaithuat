#include "dslk_songuyen.h"
void DeleteXatK(ElementType X, int K, List &L) {
    int count = 0;
    Position P = L;
    while (P->Next != NULL) {
        count++;
        if (P->Next->Element == X && count == K) {
            DeleteList(P, L);
            break;
        }
        P = P->Next;
    }
}

void XoaX(ElementType X, int K, List &L){
	Position P=L;
	Position T;
	int d=0;
	while(P->Next!=NULL && d<K){
		if(P->Next->Element==X){
			 d++;
			 T=P;	
			}
		P=P->Next;}
	if(d==K) DeleteList(T,L);
}


main(){
	List L;
	MakeNullList(L);
	ThemDauDS(5, L);
	ThemDauDS(4, L);
	ThemDauDS(3, L);
	ThemDauDS(2, L);
	ThemDauDS(3, L);
	ThemDauDS(1, L);
	cout<<"DS: "; PrintList(L);
	DeleteXatK(3, 2, L);
//	XoaX(3, 2, L);
	cout<<"\nDS: "; PrintList(L);
}

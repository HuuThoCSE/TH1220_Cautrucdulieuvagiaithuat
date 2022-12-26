#include "dslk_songuyen.h"
void AddBeforeYatK(ElementType X, ElementType Y, int K, List &L){
    int dem = 0;
    Position P=L;
    while (P->Next != NULL) {
        dem++;
        if (P->Next->Element == Y && dem == K) {
            InsertList(X, P, L);
            break;
        }
        P = P->Next;
    }
}

void Them(ElementType X, ElementType Y, int K, List &L){
	Position P=L, T;
	int d=0;
	while (P->Next!=NULL && d<K){
		if(P->Next->Element==Y){
			d++;
			T=P;
		}
		P=P->Next;
	}
	if(d==K) InsertList(X,T,L);
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
	
//	AddBeforeYatK(5, 3, 2, L);
	Them(5, 3, 2, L);
	
	cout<<"\nDS: "; PrintList(L);
}

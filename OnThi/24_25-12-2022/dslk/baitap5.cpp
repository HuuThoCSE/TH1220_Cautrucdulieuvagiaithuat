#include "dslk_songuyen.h"
void IntuXtoiK (ElementType X, int k, List L){
	Position P=L, Q;
	int dem = 0; 
	while(P->Next != NULL && dem < k){
		if(P->Next->Element == X) dem++;
		Q=P;
		P=P->Next;
	}
	if(dem == k) PrintList(Q);
}	

void IntuXlanK(ElementType X, int K, List L)
{
	Position T, P=L;
	int d=0;
	while(P->Next!=NULL && d<K)
	{
		if(P->Next->Element==X)
			d++;
		P=P->Next;
		if(d==K){
			P=Previous(P,L);
			PrintList(P);
		}
	}
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
	
	cout<<"\nDS: ";
	IntuXtoiK(3, 2, L);
//	IntuXlanK(3, 2, L);
//	cout<<"\nDS: "; PrintList(L);
}

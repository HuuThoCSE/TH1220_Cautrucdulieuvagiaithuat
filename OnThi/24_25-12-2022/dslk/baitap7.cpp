#include "dslk_songuyen.h"
ElementType MinDs(List L){
	Position P=L;
	ElementType Min=P->Next->Element;
	while(P->Next!=NULL){
		if(P->Next->Element<Min)
			Min=P->Next->Element;
		P=P->Next;
	}
	return Min;
}

ElementType MinDs1(List L){
	Position P=L;
	if (EmptyList(L)== true) cout<< "Danh sach rong";
	else{
		ElementType min=P->Next->Element;
		while(P->Next!=NULL){
			if(P->Next->Element < min)
				min=P->Next->Element;
			P=P->Next;
		}
		return min; 
	}
}



main(){
	List L;
	MakeNullList(L);
	ThemDau(5, L);
	ThemDau(4, L);
	ThemDau(3, L);
	ThemDau(2, L);
	ThemDau(3, L);
	ThemDau(1, L);
	cout<<"DS: "; PrintList(L);
	
	cout<<"\nMix: "<<MinDs(L);
	cout<<"\nMix: "<<MinDs1(L);
}

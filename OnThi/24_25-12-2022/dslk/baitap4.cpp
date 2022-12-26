#include "dslk_songuyen.h"
void PrintToX(ElementType X, List L) {
    Position P=L;
    bool flag = false;
    while (P->Next != NULL) {
        if (P->Next->Element == X) {
            flag = true;
        }
        if (flag) {
            cout << P->Next->Element << '\t';
        }
        P = P->Next;
    }
}

void IndenX(ElementType X, List L){
	Position P=L;
	Position T;
	while(P->Next!=NULL){
		if(P->Next->Element==X) T=P->Next;
		P=P->Next;
	} 
	P=L;
	while(P->Next!=T){
		cout<<P->Next->Element<<'\t';
		P=P->Next;
	} 
	cout<<T->Element;
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
	PrintToX(2, L);
//	IndenX(2, L);
//	cout<<"\nDS: "; PrintList(L);
}

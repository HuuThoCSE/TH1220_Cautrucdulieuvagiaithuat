// Chuong 1 - bai 1 - d
#include "dslk_songuyen.h"
// Ghep ds 2 vao chinh giua ds 1
void GhepDS(List L2, List &L){
	Position P=L;
	int count = 0, d=0;
	while(P->Next!=NULL){
		P=P->Next;
		count++;
	}
	P=L;
	while(P->Next!=NULL){
		P=P->Next;
		d++;
		if(d==(int)count/2){
			Last(L2)->Next=P->Next;
			P->Next=First(L2);
		}
	}
}
main(){
	List L, L2;
	MakeNullList(L);
	MakeNullList(L2);
	// Nhap DS
	ReadList(L);
	cout<<"Nhap DS 2:\n";
	ReadList(L2);
	// In DS
	cout<<"DS 1: ";
	PrintList(L);
	cout<<"\nDS 2: ";
	PrintList(L2);

	// Continue...
	GhepDS(L2, L);
	cout<<"\nDS sau khi ghep: "; 
	PrintList(L);
}

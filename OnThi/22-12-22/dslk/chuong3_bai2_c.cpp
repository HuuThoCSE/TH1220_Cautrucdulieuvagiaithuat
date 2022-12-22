#include "dslk_sothuc.h"

void ThemDau(ElementType X, List &L)
{
	Position T=new Node;
	T->Element=X;
	T->Next=L->Next;
	L->Next=T;
}

void Tron(List &L,List L2, List L3)
{
	Position P=L2->Next;
	Position Q=L3->Next;
	while (P&&Q)
	{
		if(P->Element<=Q->Element)
		{
			ThemDau(P->Element,L);
			P=P->Next;
		}
		else{
			ThemDau(Q->Element,L);
			Q=Q->Next;
		}
	}
	while(P!=NULL)
	{
		ThemDau(P->Element,L);
		P=P->Next;
	}
	while (Q!=NULL)
	{
		ThemDau(Q->Element,L);
		Q=Q->Next;
	}
}


main(){
	List L1, L2, L;
	MakeNullList(L1);
	MakeNullList(L2);
	ReadList(L1);
	ReadList(L2);
	cout<<"DS1: "; PrintList(L1);
	cout<<"\nDS2: "; PrintList(L2);
	
	// Tron 2 DS co thu tu tang dan thanh 1 DS co thu tu gam dan
	Tron(L, L1, L2);

	cout<<"\nDS sau khi tron: \n";
	PrintList(L);
}

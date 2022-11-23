#include "ListFloat.h"
// 2a
void Ascending(List &L)
{
	Position P, Q;
	ElementType Temp;
	P = L->Next;
	
	while (P->Next != NULL)
	{
		Q = P->Next;
		while (Q != NULL)
		{
			if ( Retrieve(P, L) > Retrieve(Q, L) )
			{
				Temp = P->Element;
				P->Element = Q->Element;
				Q->Element = Temp;
			}
			Q = Next(Q, L);
		}
		P = Next(P, L);
	}
}

main(){

}

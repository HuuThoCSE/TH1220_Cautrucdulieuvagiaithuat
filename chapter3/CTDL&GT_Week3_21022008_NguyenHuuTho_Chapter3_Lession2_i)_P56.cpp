#include "ListFloat.h"
float TongBSK(List L, int K){
	Position P=L;
	float s=0;
	
	while (P->Next != NULL)
	{
		if ( int(P->Next->Element) % K == 0 )
			s = s + P->Next->Element;
		P = P->Next;
	}
	return s;
}

main(){
	int K;
	List L;
	do {
		cout << "Nhap k="; cin >> K;
	} while (K<=0);
	TongBSK(L, K);
}

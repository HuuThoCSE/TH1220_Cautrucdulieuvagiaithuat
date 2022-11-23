// Chuong3.Cau2.g.Tr56.t
#include "ListFloat.h"
void Chuong3_Cau2_g_Tr56_t(){
	m = Min(L); vt = 1;
	Position P=L;
	while(P->Next->Element!=m){
		P=P->Next; vt++;
	}
	return vt;
}

main(){

}

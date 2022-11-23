#include "ListFloat.h"
void NhapDS(List DSSV, int g) {
	Posion P = DSSV; int i = 0;
	while(i!=g){
		cout << "Nhap phan tu thu" << i + 1 << ": ";
		cout << "Ho va Ten: "; cin >> P->HoTen;
		cout << "MSSV: "; cin >> P->MSSV;
		P->Next = new Node;
		P=P->Next;
		i++;
	}
}


main(){

}

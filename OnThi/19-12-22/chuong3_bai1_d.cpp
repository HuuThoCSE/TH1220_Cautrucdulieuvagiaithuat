// Chuong 1 - bai 1 - d
#include "dslk_songuyen.h"
// Xoa tat ca phan tu X co trong danh sach
void DeleteAllPhanTu(ElementType X, List &L){
	Position P=L, Temp;
    while (P->Next != NULL) {
        if (P->Next->Element != X) {
            P = P->Next;
        } else {
            DeleteList(P, L);
        }
    }
}

main(){
	List L;
	MakeNullList(L);
	// Nhap DS
	ReadList(L);
	// In DS
	PrintList(L);
	
	// Continue...
	cout<<"\nNhap so nguyen X: ";
	int X;
	cin >> X;
	if (!EmptyList(L)) {
        DeleteAllPhanTu(X, L);
        cout<<"=====DS SAU KHI XOA SO NGUYEN "<<X<<": \n";
        PrintList(L);
    } else {
        cout << "Danh sach rong, khong the xoa phan tu" << endl;
    }
}

// Cau10.b
void XuatDS (List DSSV){
	Posion P=DSSV; 
	int i = 0;
	while(P!=NULL){
		cout << "THONG TIN CUA SINH VIEN " << i + 1 << "la:" << endl;
		cout << "Ho ten: " << P->HoTen;
		cout << "MSSV: " << P->MSSV;
	}
}

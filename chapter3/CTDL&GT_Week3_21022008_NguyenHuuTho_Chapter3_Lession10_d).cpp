// Chuong3.Cau10.d
void AddLastI(List &DSSV, int i){
	Position P = DSSV;
	int d=0;
	Temp = new Node;
	while(P!=NULL){
		if(d==i){
			Temp->HoTen = HoTen;
			Temp->MSSV = MSSV;
			Temp->Next = P->Next;
			P->Next = Tem;
		}
		P=P->Next;
		d++;
	}
	
}

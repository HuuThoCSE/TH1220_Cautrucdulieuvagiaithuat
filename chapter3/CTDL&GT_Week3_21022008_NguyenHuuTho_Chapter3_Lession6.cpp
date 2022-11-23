// Chuong3.Cau6.Tr56
void LocDS(List &ds){
	Posion P=ds, Px=ds;
	while(P->Next!=NULL){
		while(Px != NULL){
			if(P->Element==Px->Next->Element){
				PxNext = Px->Next->Next;
			}
			Px = Px->Next;
		}
		P=P->Next;
	}
}

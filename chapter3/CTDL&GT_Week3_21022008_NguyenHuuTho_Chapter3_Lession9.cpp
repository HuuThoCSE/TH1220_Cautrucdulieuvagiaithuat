// Chuong3.Cau9.Tr56
void TachDS(List &dsc, List &dsm){
	Posion P=dsc, Pc=dsm;
	int d=1;
	while(P!=NULL){
		if(d%2==0){
			Temp = New Node;
			Temp->Element = P->Element;
			Pc->Element=Temp->Element;
			P->Element = P->Next->Element;
			P->Next=P->Next->Next;
		}
		P=P->Next;
		Pc=Pc->Next;
		d++;
	}
}
main(){
	TachDS(L, L2);	
}

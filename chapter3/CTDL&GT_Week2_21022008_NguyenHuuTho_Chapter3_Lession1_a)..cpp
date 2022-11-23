void ThemSauY(ElementType X, ElementType Y, List &L){
	Position Temp=NULL, P;
	P=L;
	while(P->Next!=NULL){
		if(P->Next->Element==Y)
			Temp = P->Next;
	}
	if(Temp!=NULL) InsertList(X, Tem, L);
}

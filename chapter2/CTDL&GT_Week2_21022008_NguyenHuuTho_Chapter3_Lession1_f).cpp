// Khai bao DTDL
typedef int ElementType;

struct Node {
	ElementType Element;
	Node* Next;
};
typedef Node* List;
typedef Node* Position;

// In tu X xuat hien o lan thu K den cuoi danh sach
void IntuXlanK(ElementType X, int k, List L){
	Position T, P=L;
	int d = 0;
	while(P->Next!=NULL && d<k){
		if(P->Next->Element==X) {
			d++;
			P=P->Next;
			if(d==k) {
				P=Previous(P, L);
				PrintList(P);
			}
		}
	}
}

//chapter5_l2_a, b, c, d, e_p105
// Do thi huu huong thua
#include "UndireGraph.h"

// a) Cho biet dinh co so cung den cac dinh khac nhieu nhat
void DinhCoSoCungDenCacDinhKhacMax(Graph g, int n, int e){
	int SoCungMax = CountArcFormVertice(g, n, e, 1);
	for(int i=2; i<=n; i++){
		if(SoCungMax < CountArcFormVertice(g, n, e, i))
			SoCungMax = CountArcFormVertice(g, n, e, i);
	}
	
	cout << "So cung nhieu nhat la: " << SoCungMax << endl;
	
	cout << "Dinh co so cung den cac dinh khac nhieu nhat la: ";
    for(int i=1; i<=n; i++){
        if (SoCungMax == CountArcFormVertice(g, n, e, i))
            cout<< i << '\t';
    }
    cout<<endl;
}

// b) Cho biet dinh co so cung den tu cac dinh khac it nhat
void DinhCoSoCungDenTuDinhKhacMin(Graph g, int n, int e){
	int SoCungMin = CountArcToVertice(g, n, e, 1);
	for(int i=2; i<=n; i++){
		if(SoCungMin > CountArcToVertice(g, n, e, i))
			SoCungMin = CountArcToVertice(g, n, e, i);
	}
	cout << "So cung it nhat la: " << SoCungMin << endl;
	
	cout << "Dinh co so cung den tu cac dinh khac it nhat la: ";
    for(int i=1; i<=n; i++){
        if (SoCungMin == CountArcToVertice(g, n, e, i))
            cout<< i << '\t';
    }
    cout<<endl;
}

// c) Dem so khhuyen co trong do thi
int SoKhuyenCoTrongDoThi(Graph g, int n, int e){
	int dem=0;
	for(int i=1; i<=n; i++){
		Node *t=g[i];
		while(t->Next != NULL && t->Next->Element !=i)
			t = t->Next;
		if(t->Next != NULL) dem++;
	}
	return dem;
}

// d) Cho biet co bao nhieu dinh treo trong do thi
int CountDinhTreo(Graph g, int n, int e){
	int dem=0;
	for(int i=1; i<=n ; i++){
		Node *t = g[i];
		if(CountArcToVertice(g,n,e,i) == 1 && t->Next==NULL)
			dem++;
	}
	return dem;
}

// e) In ra cac dinh co cung den dinh d
void CacCungDenDiem(Graph g, int n, int e, int d){
	cout << "Cac cung den diem " <<d<< " la: ";
	for(int i=1; i<=n; i++){
		Node *t=g[i];
		while(t->Next != NULL && t->Next->Element !=d)
			t = t->Next;
		if(t->Next != NULL) cout << i << '\t';
	}
	cout << endl;
}

// f) In ra cac cap dinh co tong so cung xuat phat va cung den bang nhau
void CapDinhCoTongSoCungXuatPhatVaCungDenBanNhau(Graph g, int n, int e){
	cout << "Cac cap dinh co tong so cung xuat phat va so cung den bang nhau: "<< endl;
	for(int i=1 ; i<=n-1; i++){
		int Sum1 = CountArcFormVertice(g, n, e, i) + CountArcToVertice(g, n, e, i);
		int Sum2 = CountArcFormVertice(g, n, e, j) + CountArcToVertice(g, n, e, j);
		if (Sum1 == Sum2)
			cout <<i<<"-" <<j<<'\n';
	}
	cout << endl;
}

// g) Dem xem co bao nhieu dinh co so cung xuat phat bang so cung den
int DinhCoSoCungXPBangSoCungD(Graph g, int n, int e){
	int dem=0;
	for(int i=1 ; i<=n; i++){
		if(CountArcFormVertice(g, n, e, i) == CountArcToVertice(g, n, e, i))
			dem++;
	}
	return dem;
}

main() {
	Graph g;
	int n, e, d1;
	while (true) {
		do {
			cout << "Nhap so dinh cua do thi: ";
			cin >> n;
		} while (n <= 0 || n >= maxn);
		Initialize(g, n, e);
		cout << "=====DO THI VUA KHOI TAO====="<< endl;
		PrintGraph(g, n, e);
		cout << "Nhap so canh cua do thi: ";
		cin >> e;
		ReadGraph(g, n, e);
		cout << "=====DO THI VUA NHAP====="<< endl;
		PrintGraph(g, n, e);
		cout << endl;
		DinhCoSoCungDenCacDinhKhacMax(g, n, e);
		DinhCoSoCungDenTuDinhKhacMin(g, n, e);
		cout <<"So khuyen co trong do thi la: " << SoKhuyenCoTrongDoThi(g, n, e) << endl;
		cout <<"Co " << CountDinhTreo(g, n, e) << " dinh treo trong do thi." <<endl;
		cout << "Nhap mot diem (de liet ke cac cung den diem do): "; cin >> d1;
		CacCungDenDiem(g, n, e, d1);
		CapDinhCoTongSoCungXuatPhatVaCungDenBanNhau(g, n, e);
		cout << "Co " << DinhCoSoCungXPBangSoCungD(g, n, e) << " dinh co so cung xuat phat bang so cung den." <<endl;
//		DinhCoSoCungXPBangSoCungD(g, n, e);
		cout << "---------------------------------"<<endl;
	}
}

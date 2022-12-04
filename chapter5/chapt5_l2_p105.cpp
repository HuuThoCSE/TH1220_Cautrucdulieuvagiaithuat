//chapter5_l2_a, b, c, d, e_p105
// Do thi huu huong thua
#include<iostream>
using namespace std;

// Khai bao CDTL Do thi
const int maxn = 20;
typedef int ElementType;
struct Node {
	ElementType Element;
	Node* Next;
};
typedef Node* List;
typedef List Graph[maxn];

// Khoi tao do thi rong
void Initialize(Graph &g, int n, int &e){
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n;j++){
			g[i] = new Node;
			g[i]->Next = NULL;
		}	
	e=0;
}

// Xuat Do thi
void PrintGraph(Graph g, int n, int e){
	Node *t = new Node;
	for(int i=1; i<=n; i++){
		cout << "Dinh " << i<<": ";
		t = g[i];
		while(t->Next != NULL){
			cout << t->Next->Element<<'\t';
			t = t->Next;
		}
		cout<<endl;
	}
}

// Them Mot cung
void InsertArc(Graph &g, int n, int &e, int d1, int d2){
	Node *t = new Node;
	t->Element = d2;
	t->Next = g[d1]->Next;
	g[d1]->Next = t;
	e++;
}

// Nhap Do thi
void ReadGraph(Graph &g, int n, int e){
	int i, d1, d2, cs=e;
	for(i=1; i<=cs; i++){
		cout << "Nhap dinh di tu d1 den d2: " <<endl;
		cin>>d1>>d2;
		InsertArc(g, n, e, d1, d2);
		system("cls");
	}
}


// Them Mot dinh
void InsertVertice(Graph &g, int &n, int &e, int scxp, int scdd){
	int i, d;
	g[n+1] = new Node;
	g[n+1]->Next = NULL;
	for(i=1; i<=scxp; i++){
		cout << "Dinh moi di den dinh nao?";
		cin>>d;
		InsertArc(g, n, e, n+1, d);
	}
	for(i=1;i<=scdd;i++){
		cout << "Dinh nao di den dinh moi: ";
		cin>>d;
		InsertArc(g, n, e, d, n+1);
	}
}

// Dem So cung xuat phat tu mot dinh
int CountArcFormVertice(Graph g, int n, int e, int d){
	int dem=0;
	Node *t = g[d];
	while(t->Next != NULL){
		dem++;
		t=t->Next;
	}
	return dem;
}

// Dem So cung di den mot dinh
int CountArcToVertice(Graph g, int n, int e, int d){
	int i, dem = 0;
	Node *t;
	for(i=1; i<=n; i++){
		t=g[i];
		while(t->Next != NULL && t->Next->Element !=d)
			t = t->Next;
		if(t->Next != NULL) dem++;
	}
	return dem;
}

// Xoa Mot cung
void DeleteArc(Graph &g, int n, int &e, int d1, int d2){
	Node *t =g[d1];
	while(t->Next != NULL && t->Next->Element != d2)
		t = t->Next;
	if(t->Next != NULL && t->Next->Element==d2){
		Node *p = t->Next;
		t->Next = p->Next;
		delete p;
		e--;
	}
}

// Xoa Mot dinh
void DeleteVertice(Graph &g, int &n, int &e, int d){
	int i;
	e=e-CountArcFormVertice(g, n, e, d);
	for(i=1; i<=n; i++)
		if(i==d) g[i]->Next = NULL;
		else DeleteArc(g, n, e, i, d);
	for(i=d; i<=n-1; i++)
		g[i]=g[i+1];
	n--;
	for(i=1;i<=n;i++){
		Node *t = g[i];
		while(t->Next != NULL){
			if(t->Next->Element>d)
				t->Next->Element=t->Next->Element-1;
			t=t->Next;
		}
	}
}


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
int SoKhuyen(Graph g, int n, int e){
	int dem=0;
	for(int i=1; i<=n; i++){
		Node *t=g[i];
		while(t->Next != NULL && t->Next->Element !=i)
			t = t->Next;
		if(t->Next != NULL) dem++;
	}
	return dem;
}

// c.Cach2: Tach
bool Co_Chua(List p, int x){
	List t = p;
	while(t -> Next != NULL && t->Next->Element!=x)
		t = t->Next;
	if(t->Next != NULL) return true;
	else return false;
}

int Dem_Khuyen(Graph g,int n,int e){
	int dem=0;
	for(int i=1; i<= n; i++)
		if(Co_Chua(g[i], i)== true) dem++;
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

// d.Cach2
int Count_DinhTreo(Graph g, int n, int e){
	int dem=0;
	for(int i=1; i<=n ; i++){
		if(CountArcToVertice(g,n,e,i) == 1 && CountArcFormVertice(g,n,e,i) == 0)
			dem++;
	}
	return dem;
}

// e) In ra cac dinh co cung den dinh d
void CacCungDenDiem(Graph g, int n, int e, int d){
	cout << "Cac dinh co cung den dinh " <<d<< " la: ";
	for(int i=1; i<=n; i++){
		Node *t=g[i];
		while(t->Next != NULL && t->Next->Element !=d)
			t = t->Next;
		if(t->Next != NULL) cout << i << '\t';
	}
	cout << endl;
}

// e.Cach 2
void CacCungDenDiem2(Graph g, int n, int e, int d){
	cout << "Cac dinh co cung den dinh " <<d<< " la: ";
	for(int i=1; i<=n; i++){
		if(Co_Chua(g[i], d)==true) 
			cout << i << '\t';
	}
	cout << endl;
}

// f) In ra cac cap dinh co tong so cung xuat phat va cung den bang nhau
//void CapDinhCoTongSoCungXuatPhatVaCungDenBanNhau(Graph g, int n, int e){
//	cout << "Cac cap dinh co tong so cung xuat phat va so cung den bang nhau: "<< endl;
//	for(int i=1 ; i<=n-1; i++){
//		int Sum1 = CountArcFormVertice(g, n, e, i) + CountArcToVertice(g, n, e, i);
//		int Sum2 = CountArcFormVertice(g, n, e, j) + CountArcToVertice(g, n, e, j);
//		if (Sum1 == Sum2)
//			cout <<i<<"-" <<j<<'\n';
//	}
//	cout << endl;
//}

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
		cout <<"1. So khuyen co trong do thi la: " << SoKhuyen(g, n, e) << endl;
		cout <<"2. So khuyen co trong do thi la: " << Dem_Khuyen(g, n, e) << endl;
		cout <<"Co " << CountDinhTreo(g, n, e) << " dinh treo trong do thi." <<endl;
		cout << "Nhap mot diem (de liet ke cac cung den diem do): "; cin >> d1;
		CacCungDenDiem(g, n, e, d1);
		CacCungDenDiem2(g, n, e, d1);
//		CapDinhCoTongSoCungXuatPhatVaCungDenBanNhau(g, n, e);
		cout << "Co " << DinhCoSoCungXPBangSoCungD(g, n, e) << " dinh co so cung xuat phat bang so cung den." <<endl;
//		DinhCoSoCungXPBangSoCungD(g, n, e);
		cout << "---------------------------------"<<endl;
	}
}

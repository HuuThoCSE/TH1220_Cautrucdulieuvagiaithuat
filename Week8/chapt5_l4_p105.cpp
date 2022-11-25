//chapter5_l4_p105
#include "UndireGraph.h"

main(){
	Graph g;
	int n, e, d1, d2, d, sc;
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
	
	// b) Them mot canh.
	cout << "Nhap canh can them: ";
	cin >> d1 >> d2;
	InsertEdge(g, n, e, d1, d2);
	cout << "=====DO THI SAU KHI THEM CANH====="<<endl;
	PrintGraph(g, n, e);
	cout<<endl;
	
	// c) Xoa mot canh
	cout<<"Nhap dinh can xoa: ";
	cin>>d;
	DeleteVertice(g, n, e, d);
	cout<<"=====DO THI SAU KHI XOA DINH====="<<endl;
	PrintGraph(g, n, e);
	
	// d) Dem so canh noi cua mot dinh
	int point;
	cout << "Nhap 1 dinh can dem so canh noi: "; cin >> point;
	cout << "Diem" <<point<<" co " CountEdge(g, n, e, point) << " canh noi."
	
}


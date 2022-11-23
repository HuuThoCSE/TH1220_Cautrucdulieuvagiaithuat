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
	// b)
	cout << "Nhap canh can them: ";
	cin >> d1 >> d2;
	InsertEdge(g, n, e, d1, d2);
	cout << "=====DO THI SAU KHI THEM CANH====="<<endl;
	PrintGraph(g, n, e);
	cout<<endl;
	cout<<"Nhap dinh can dem so canh: ";
	cin>>d;
	cout<<"Dinh "<<d<<" co "<<CountEdge(g, n, e, d);
	cout<<" canh noi"<<endl;
	cout<<"Nhap so canh noi cua dinh moi: ";
	cin>>sc;
	InsertVertice(g, n, e, sc);
	cout<<"=====DO THI SAU KHI THEM DINH====="<<endl;
	PrintGraph(g, n, e);
	cout<<endl;
	cout<<"Nhap dinh can xoa: ";
	cin>>d;
	DeleteVertice(g, n, e, d);
	cout<<"=====DO THI SAU KHI XOA DINH====="<<endl;
	PrintGraph(g, n, e);
}


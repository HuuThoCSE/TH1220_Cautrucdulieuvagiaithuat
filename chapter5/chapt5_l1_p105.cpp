// chapt5_l1_p105
#include "UndireGraph.h"

// 1a. Dinh co Canh noi la K
void C1a(Graph g,int n,int e,int K){
	cout << "Cac dinh co Canh noi la " <<K<<": ";
	for(int i=1; i<=n; i++){
		if(CountEdge(g, n, e, i)==K)
			cout << i << '\t';
	}
	cout<<endl;
}

// 1b. In ra dinh co Canh noi voi d
void C1b(Graph g,int n,int e,int d){
	cout << "Cac dinh co so Canh noi voi dinh "<<d<<" la: ";
	for(int j=1; j<=n; j++)
		if(g[d][j]==1 && d!=j)
			cout<<j<<'\t';
	cout<<endl;
}

// 1c. Cho bien 2 dinh d1, d2 co Canh noi khong?
bool C1c(Graph g,int n,int e,int d1, int d2){
	if(g[d1][d2]==1 && g[d2][d1]==1)
		return true;
	else 
		return false;
}

// 1d. Dem so dinh treo
int CountDinhTreo(Graph g, int n, int e){
	int dem=0;
	for(int i=1; i<=n; i++){
		if(CountEdge(g, n, e, i)==1)
			dem++;
	}
	return dem;
}

//1.e)In ra cac dinh co canh noi vs cac dinh treo
void DinhNoiVoiDinhTreo(Graph g, int n, int e)
{
    for(int i=1 ; i<=n ; i++){
        if(CountEdge(g , n, e, i)==1)
        for( int j=1 ; j<=n ; j++){ // Lam thu voi While
            if(g[i][j]==1 && i!=j)
            {
                cout<<j<<'\t';
                break;
            }
        }
    }
}

main(){
	Graph g;
	int n, e;
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
	
	// 1a. 
	int K;
	cout << "Nhap so luong canh noi: "; cin >> K;
	C1a(g, n, e, K);
	
	// 1b. 
	int d;
	cout << "Nhap vao mot dinh (de in ra cac dinh noi): "; cin >> d;
	C1b(g, n, e, d);
	
	// 1c. 
	int d1, d2;
	cout << "Nhap vao 2 dinh (de xem giua chung co canh noi hay khong): "; cin >> d1 >> d2;
	cout << "Giua "<<d1<<" va "<<d2<<": ";
	if (C1c(g, n, e, d1, d2))
		cout << "Co canh noi.";
	else 
		cout << "Khong co canh noi.";
	cout<<endl;
			
	// 1d.
	cout << "Co "<<CountDinhTreo(g, n, e) << " dinh treo trong do thi. ";
	
	// 1e. 
	cout<<"Dinh co canh noi vs dinh treo: ";
    DinhNoiVoiDinhTreo(g,n,e);
}

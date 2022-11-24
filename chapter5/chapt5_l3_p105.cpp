#include <iostream>
using namespace std;

// Khai bao CTDL
const int maxn = 20;
typedef int Graph[maxn][maxn];

// Khoi tao do thi rong
void Initialize(Graph &g, int n, int &e){
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n;j++)
			g[i][j]=0;
	e=0;
}

// Xuat Do thi
void PrintGraph(Graph g, int n, int e){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			cout<<g[i][j]<<'\t';
		cout<<endl;
	}
}

// Them Mot cung
void InsertArc(Graph &g, int n, int &e, int d1, int d2){
	g[d1][d2] = 1;
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

// Xoa Mot cung
void DeleteArc(Graph &g, int n, int &e, int d1, int d2){
	g[d1][d2] = 0;
	e--;
}


// Dem so cung xuat phat tu mot dinh
int CoutCungTuDinh(Graph &g, int n, int &e, int d){
	int dem=0;
	for(int i=1; i<=n; i++){
		if(g[d][i]==1)
			dem++;
	}
	return dem;
}


// Dem so cung xuat phat tu mot dinh
int CoutCungDenDinh(Graph &g, int n, int &e, int d){
	int dem=0;
	for(int i=1; i<=n; i++){
		if(g[i][d]==1)
			dem++;
	}
	return dem;
}

// Them Mot dinh
void InsertVertice(Graph &g, int &n, int &e, int scxp, int scdd){
	int i, d;
	for(i=1; i<=n+1; i++){
		g[i][n+1]=0;
		g[n+1][i]=0;
	}
	
	for(i=1; i<=scxp; i++){
		cout << "Dinh moi di den dinh nao: ";
		cin>>d;
		InsertArc(g, n, e, n+1, d);
	}
	
	for(i=1;i<=scdd;i++){
		cout << "Dinh nao di den dinh moi: ";
		cin>>d;
		InsertArc(g, n, e, d, n+1);
	}
	n++; // se tot hon
}


void DeleteDinh(Graph &g, int &n, int &e, int d){
	int i, j;
	for(i=1; i<=n; i++){
		if(g[d][i] == 1){
			g[d][i] = 0;
			e--;
		}
			
	}
	
	for(i=1; i<=n; i++){
		if(g[i][d] == 1){
			g[i][d] = 0;
			e--;
		}
	}
	
	for(i=d; i<=n-1; i++)
		for(j=1; j<=n; j++)
			g[i][j]=g[i+1][j];
	for(i=1; i<=n-1; i++)
		for(j=d;j<=n-1; j++)
			g[i][j]=g[i][j+1];
}

main(){
	Graph g;
	int n, e, d, d1, d2; // e: So cung
	
	while (true){
		int luachon;
		cout << "Menu: " << endl;
		cout << "1. Nhap do thi." << endl;
		cout << "2. In Do thi." << endl;
		cout << "3. Xoa 1 cung." << endl;
		cout << "4. Dem so cung xuat phat tu mot dinh." << endl;
		cout << "5. Dem so cung di den tu mot dinh." << endl;
		cout << "6. Them dinh." << endl;
		cout << "7. Xoa mot dinh." << endl;
		cout << "8. Thoat." << endl;
		cout << "Su lua chon cua ban: "; cin >> luachon;
		system("cls");
		switch (luachon){
			case 1:
				do {
					cout << "Nhap so dinh cua do thi: ";
					cin >> n;
				} while (n <= 0 || n >= maxn);
				Initialize(g, n, e);
				cout << "=====DO THI VUA KHOI TAO====="<< endl;
				PrintGraph(g, n, e);
				
				cout << "Nhap so canh cua do thi: ";
				cin >> e;
				system("cls");
				ReadGraph(g, n, e);
			case 2:
				cout << "=====DO THI VUA NHAP====="<< endl;
				PrintGraph(g, n, e);
				cout << endl;
				system("pause");
				break;
			case 3: 
				cout << "Nhap cung can xoa: "; cin>>d1>>d2;
				DeleteArc(g, n, e, d1, d2);
				
				cout << "=====DO THI====="<< endl;
				PrintGraph(g, n, e);
				cout << endl;
				system("pause");
				break;
			case 4:
				int d3;
				cout << "Nhap dinh (de dem so cung xuat phat): "; cin >> d3;
				cout << "Co " << CoutCungTuDinh(g, n, e, d3)<< " cung xuat phat tu dinh "<<d3<<endl;	
				system("pause");
				break;
			case 5:
				int d4;
				cout << "Nhap dinh (de dem so cung di den dinh): "; cin >> d4;
				cout << "Co " << CoutCungDenDinh(g, n, e, d4) << " cung den tu dinh " << d4 << endl;
				system("pause");
				break;
			case 6:
				int d5, d6, scxp, scdd;
				cout << "Nhap so cung xuat tu dinh moi: "; cin >> scxp;
				cout << "Nhap so cung di den dinh moi: "; cin >> scdd;
				InsertVertice(g, n, e, scxp, scdd);
				
				cout << "=====DO THI====="<< endl;
				PrintGraph(g, n, e);
				cout << endl;
				system("pause");
				break;
			case 7:
				cout << "Nhap dinh can xoa: "; cin >> d;
				DeleteDinh(g, n, e, d);
				
				cout << "=====DO THI SAU KHI XOA====="<< endl;
				PrintGraph(g, n, e);
				system("pause");
				break;
			case 8: 
				return false;
			system("pause");
		}
		system("cls");
	}
}

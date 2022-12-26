#include "vohuongthua.h"
int DinhCoSoCungXPBangSoCungD(Graph g, int n, int e){
	int dem=0;
	for(int i=1 ; i<=n; i++){
		if(CountArcFromVertice(g, n, e, i) == CountArcToVertice(g, n, e, i))
			dem++;
	}
	return dem;
}

int DemDinhCoCungXPbangCungDen (Graph g, int n, int e){
	int dem = 0; 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if (i!=j && i<j && CountArcFromVertice(g,n,e,i) == CountArcToVertice(g,n,e,j))
				dem++; 
	return dem; 
}


main(){
	Graph g;
	int n, e, d1, d2, d, scxp, scdd;
	do{
	cout<<"Nhap so dinh cua do thi : "; cin>>n;
	} while(n<=0 || n>=maxn);
	
	Initialize(g, n, e);
	
	cout<<"=====DO THI VUA KHOI TAO LA====="<<endl;
	PrintGraph(g, n, e);
	cout<<"Nhap so cung cua do thi : "; cin>>e;
	ReadGraph(g, n, e);
	
	cout<<"=====DO THI VUA NHAP LA====="<<endl;
	PrintGraph(g, n, e);
	cout<<endl;
	
	cout<<"\nTH1: "<<DinhCoSoCungXPBangSoCungD(g, n, e); //3
	cout<<"\nTH2: "<<DemDinhCoCungXPbangCungDen(g, n, e);
}

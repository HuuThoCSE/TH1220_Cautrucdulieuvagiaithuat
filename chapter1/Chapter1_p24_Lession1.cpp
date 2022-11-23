#include<iostream>
#include<math.h>
using namespace std;
bool KTra_SoChinhPhuong(int n){
	if(sqrt(n)==(int)sqrt(n))
		return true;
	else 
		return false;
}

long Tong_ChPh_DauTien(int n) {
	long S=0;
	for(int i=1; i <= n; i++)
		S=S+i*i;
	return S;	
} 

long Tong_ChPh_NguyenDuong_DauTien(int n){
	long S=0;
	for (int i=1; i <=n; i++)
		if(KTra_SoChinhPhuong(i))
			S=S+i;
	return S;
}

void In_Cac_So_La_BoiSo_Cua_K_Trong_N_SoNguyenDuong_DauTien(int K, int N){
	for (int i=1; i <= N; i++)
		if(i%K==0)
			cout << i;
}
main(){
	int n, N, K;
	do {
		cout << "Nhap vao 1 so nguyen duong: "; cin >> n;
	} while(n < 0);
	
	// Chapter1_p24_Lession1_Cau a)
	if(KTra_SoChinhPhuong(n)) 
		cout << "So " << n << " la so chinh phuong.\n\n";
	else
		cout << "So " << n << " khong la so chinh phuong.\n\n";
	
	// Chapter1_p25_Lession1_Cau b). Tinh tong N so ChPh dau tien.
	cout << "Nhap vao N so chinh phuong dau tien: "; cin >> N;
	cout << "Tong so chinh phuong dau tien cua " << N << " la " << Tong_ChPh_DauTien(N);
	
	// Chapter1_p25_Lession1_Cau b.2). Tinh tong cac so ChPh trong N so nguyen duong dau tien.
	cout << "\n\n";
	cout << "Tong so chinh phuong nguyen duong dau tien: " << Tong_ChPh_NguyenDuong_DauTien(N) << endl;
	
	// Chapter1_p25_Lession1_d). In ra cac so la boi so cua K trong N so nguyen duong dau tien.
	cout << "\nNhap vao so K: "; cin >> K;
	In_Cac_So_La_BoiSo_Cua_K_Trong_N_SoNguyenDuong_DauTien(K, N);
}

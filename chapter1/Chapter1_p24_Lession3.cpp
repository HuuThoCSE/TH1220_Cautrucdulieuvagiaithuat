#include<iostream>
using namespace std;
void NhapDoDai_Mang(int &m, int &n){
	do {
		cout << "Nhap vao do dai mang m hang n cot: "; cin >> m >> n;
	} while (m< 0 || m > 100 || n < 0 || n > 100);
}

void NhapMang(float arr[][100], int m, int n){
	for(int i=0; i < m; i++) {
		for(int j=0; j < n; j++) {
			cout << "arr[" << i << "]["<< j <<"]= "; cin >> arr[i][j];
		}
	cout << endl;
	}	
}

void InMang(float arr[][100], int m, int n){
	for(int i=0; i < m; i++){
		for(int j=0; j < n; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}

void Tong_2_MaTra(int m, int n, float arr[][100], float arr2[][100],float arr3[][100]){
	cout << "Tong 2 ma tran." << endl;
	for(int i=0; i < m; i++){
		for(int j=0; j < n; j++) {
			arr3[i][j] = arr[i][j]+arr2[i][j];
		}	
	}
}

void Tich_2_MaTra(int m, int n, float arr[][100], float arr2[][100], float arr3[][100]){
	cout << "Tich 2 ma tran." << endl;
	for(int i=0; i < m; i++){
		for(int j=0; j < n; j++) {
			arr3[i][j] = arr[i][j]*arr2[i][j];
		}	
	}
}

bool KTra_2_MaTran_BangNhau(int m, int n, float arr[][100], float arr2[][100]){
	for(int i=0; i < m; i++){
		for(int j=0; j < n; j++) {
			if(arr[i][j] != arr2[i][j]) return false;
		}	
	}
}
main(){
//	float arr[100][100] = {{6,5,8}, {7,8,9}, {3,2,5}}, arr2[100][100] = {{3,4,4}, {6,8,2}, {9,8,5}}, arr3[100][100], arr4[100][100];
	float arr[100][100], arr2[100][100] , arr3[100][100], arr4[100][100];
	int m = 3, n = 3;
	NhapDoDai_Mang(m, n);
	cout << endl;
	
	// Chapter1_p24_Lession3_a)
	NhapMang(arr, m, n);
	NhapMang(arr2, m, n);
	
	// Chapter1_p24_Lession3_b)
	InMang(arr, m, n);
	cout << endl;
	InMang(arr2, m, n);
	cout << endl;
	
	// Chapter1_p24_Lession3_c). Tinh tong 2 ma tran
	Tong_2_MaTra(m, n, arr, arr2, arr3);
	InMang(arr3, m, n);
	cout << endl;
	
	// Chapter1_p24_Lession3_d). Tinh tich 2 ma tran
	Tich_2_MaTra(m, n, arr, arr2, arr4);
	InMang(arr4, m, n);
	cout << endl;
	
	// Chapter1_p24_Lession3_e). Kiem tra 2 ma tran bang nhau
	if(KTra_2_MaTran_BangNhau(m, n, arr, arr2))
		cout << "Hai ma tran bang nhau.";
	else 
		cout << "Hai ma tran khong bang nhau.";
	
}

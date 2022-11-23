#include<iostream>
using namespace std;
void NhapDoDai_Mang(int &n){
	do {
		cout << "Nhap vao do dai mang 1 chieu: "; cin >> n;
	} while (n < 0 || n > 100);
}

void NhapMang_Khong_DeQui(int arr[],int n){
	for(int i=1; i <= n; i++) {
		cout << "arr[" << i << "]= "; cin >> arr[i];
	}
	cout << endl;
}

void NhapMang_DeQui(int arr[], int n, int i){
	if(i <= n){
		cout << "arr[" << i << "]= "; cin >> arr[i];
		NhapMang_DeQui(arr, n, i+1);
	}
}

void InMang_Khong_DeQui(int arr[],int n){
	for(int i=1; i <= n; i++)
		cout << arr[i] << "\t";
	cout << "\n" <<endl;
}

void InMang_DeQui(int arr[], int n, int i){
	if(i <= n)
		cout << arr[i] << "\t";
	InMang_DeQui(arr, n, i+1);
}

void ThemPhanTu_VaoMang_O_ViTri(int arr[], int &n,int X,int vt){
	n++;
	for(int i=n; i >= vt; i--)
		arr[i] = arr[i-1];
	arr[vt] = X;
	cout << endl;
}

main(){
	int arr[100], i, n, X, vt, Choose_NhapMang, Choose_XuatMang;
	// Nhap do dai mang
	NhapDoDai_Mang(n);
	
	// Chapter1_p24_Lession2_a) Nhap mang_Khong_DeQui
	cout << "\nNhap mang theo: " << endl;
	cout << "1. Khong De qui." << endl;
	cout << "2. De qui." << endl;
	do {
		cout << "Su lua chon cua ban: "; cin >> Choose_NhapMang;
	} while (Choose_NhapMang < 1 || Choose_NhapMang > 2);
	cout << endl;
	
	switch (Choose_NhapMang){
		case 1:
			NhapMang_Khong_DeQui(arr,n);
			break;
		case 2:
			NhapMang_DeQui(arr,n, 1);
			break;
	}
		
	// Chapter1_p24_Lession2_b) In mang_Khong_DeQui
	cout << "\nIn mang theo: " << endl;
	cout << "1. Khong De qui."  << endl;
	cout << "2. De qui." << endl;
	do {
		cout << "Su lua chon cua ban: "; cin >> Choose_XuatMang;
	} while (Choose_XuatMang < 1 || Choose_XuatMang > 2);
	cout << endl;
	
	switch (Choose_XuatMang){
		case 1:
			InMang_Khong_DeQui(arr,n);
			break;
		case 2:
			InMang_DeQui(arr,n, 1);
			break;
	}
	
	// Chapter1_p24_Lession2_c) Them 1 phan tu vao mang tai vi tri vt
	cout << "Nhap vi tri can them vao: "; cin >> vt;
	cout << "Nhap gia tri can them vao: "; cin >> X;
	ThemPhanTu_VaoMang_O_ViTri(arr, n, X, vt);
	
	// Chapter1_p24_Lession2_b) In mang_Khong_DeQui
	InMang_Khong_DeQui(arr, n); 
}

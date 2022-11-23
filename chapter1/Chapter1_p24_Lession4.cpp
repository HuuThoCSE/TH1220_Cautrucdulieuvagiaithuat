#include<iostream>
#include<string.h>
using namespace std;

void NhapDoDai_Mang(int &n){
	do {
		cout << "Nhap vao do dai mang 1 chieu: "; cin >> n;
	} while (n < 0 || n > 100);
}

void NhapMang(int arr[],int n){
	for(int i=0; i < n; i++) {
		cout << "arr[" << i << "]= "; cin >> arr[i];
	}
	cout << endl;
}

void InMang(int arr[], int n){
	cout << "In mang: " <<endl;
	for(int i=0; i < n; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

void SapXep_Mang_TheoThuTu_TangDan_Khong_DeQui(int arr[], int n){
	int dem;
	for(int i= 0; i < n-1; i++)
		for (int j= i+1; j < n; j++)
			if(arr[i] > arr[j]) {
				dem = arr[i];
				arr[i] = arr[j];
				arr[j] = dem; 
			}
}
// Building...
void SapXep_Mang_TheoThuTu_TangDan_DeQui(int arr[], int n){
	int dem;
	for(int i= 0; i < n-1; i++)
		for (int j= i+1; j < n; j++)
			if(arr[i] > arr[j]) {
				dem = arr[i];
				arr[i] = arr[j];
				arr[j] = dem; 
			}
}

int Dem_SoTu_CoTrong_Chuoi_Khong_DeQui(char* arr_str){
	int dem;
	if(arr_str[0]==' ') 
		dem = 0;
	else 
		dem = 1;
	
	for(int i = 0; i < strlen(arr_str)-1; i++)
		if(arr_str[i]==' ' && arr_str[i+1] != ' ') dem++;
		
	return dem;
}
// Building...
int Dem_SoTu_CoTrong_Chuoi_DeQui(char arr_str[], int dem,int i, bool status){
	if(i < strlen(arr_str)) {
//		if(arr_str[i]==' ' && arr_str[i+1] != ' ') dem++;
		if(arr_str[i] != ' ' && status == true)  
		return 	Dem_SoTu_CoTrong_Chuoi_DeQui(arr_str, dem, i+1, status);
	}
}

main(){
	int arr[100], n, Choose_Sapxep_TangDan, Choose_Dem_SoTu_Trong_Chuoi;
	char arr_str[200] ="  Khoa  Cong Nghe Thong   ";
//	char arr_str[200] ="Khoa Cong Nghe Thong  tin hoa ha mem me";
//	char arr_str[200];
//	
//	NhapDoDai_Mang(n);
//	NhapMang(arr, n);
//	InMang(arr, n);
//
//	// Chapter1_p24_Lession4_d) Sap xep mang theo thu tu tang dan
//	cout << "\nSap xep mang tang dan theo: " << endl;
//	cout << "1. Khong De qui." << endl;
//	cout << "2. De qui." << endl;
//	do {
//		cout << "Su lua chon cua ban: "; cin >> Choose_Sapxep_TangDan;
//	} while (Choose_Sapxep_TangDan < 1 || Choose_Sapxep_TangDan > 2);
//	cout << endl;
//	
//	switch (Choose_Sapxep_TangDan){
//		case 1:
//			SapXep_Mang_TheoThuTu_TangDan_Khong_DeQui(arr, n);
//			break;
//		case 2:
//			SapXep_Mang_TheoThuTu_TangDan_DeQui(arr, n);
//			break;
//	}
//	
//	InMang(arr, n);
//	cout << endl;
	
	// Chapter1_p24_Lession4_e)
	cout << "Chuoi: " << arr_str << endl;
//	cin.ignore(1);
//	cout << "Nhap chuoi: "; cin.getline(arr_str, 200);
	cout << "\nDem so tu co trong chuoi. Theo: " << endl;
	cout << "1. Khong De qui." << endl;
	cout << "2. De qui." << endl;
	do {
		cout << "Su lua chon cua ban: "; cin >> Choose_Dem_SoTu_Trong_Chuoi;
	} while (Choose_Dem_SoTu_Trong_Chuoi < 1 || Choose_Dem_SoTu_Trong_Chuoi > 2);
	cout << endl;
	
	switch (Choose_Dem_SoTu_Trong_Chuoi){
		case 1:
			cout << "Co " << Dem_SoTu_CoTrong_Chuoi_Khong_DeQui(arr_str) << " tu trong chuoi.";
			break;
		case 2:
			cout << "Co " << Dem_SoTu_CoTrong_Chuoi_DeQui(arr_str, 0, 0, true) << " tu trong chuoi.";
			break;
	}
}

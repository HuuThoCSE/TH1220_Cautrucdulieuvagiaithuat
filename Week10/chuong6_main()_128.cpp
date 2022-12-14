// PP Dia chi mo -> PP thu bac 2
#include<iostream>
using namespace std;

// Khai bao CTDL
#define NULLKEY 0
#define M 13
struct Node {
	int Key;
};
Node Hash[M];
int N = 0; // Bien toan cuc chi so phan tu hien co trong bang

// Ham bw
int HF(int k){
	return (k%M);
}

// Khoi tao
void Initialize(){
	for(int b=0; b<M; b++)
		Hash[b].Key = NULLKEY;
}

// In Bw 
void Print_Hash(){
	for(int b=0; b<M; b++)
		cout<<"Bucket "<<b<<": "<<Hash[b].Key<<endl;
}

// Kiem tra BBw day
bool Full(){
	return (N == M-1);
}

// Kiem tra bang bam rong
bool Empty(){
	return (N == 0 ? true : false);
}

// Tao ra chi so de tim vi tri trong
int G(int i){
	return i*i;
}

// Tim kiem mot khoa trong BBw
int Search(int k){
	if(Empty()) return M;
	int b = HF(k), vt = b, i = 0;
	while(Hash[vt].Key != NULLKEY && Hash[vt].Key != k){
		i++; // Xu ly dung do
		vt = (b +G(i)) % M;
	}
	if(Hash[vt].Key == k) return vt;
	else return M;
}

// Them mot khoa vao bang bam
int Insert(int k){
	int b = HF(k);
	int vt = b, i = 0;
	if(Full()){
		cout<<"Bang bam day, khong them duoc"<<endl;
		return M;
	}
	if(Search(k)<M){
		cout<<"Khoa da co, khong them nua"<<endl;
		return M;
	}
	while(Hash[vt].Key != NULLKEY) {// Xu ly dung do
		i++;
		vt = (b+G(i))%M;
	}
	Hash[vt].Key = k;
	N = N +1;
	return vt;
}

// Nhap BBw
void Read_Hash(){
	int k;
	do {
		cout<<"Nhap khoa vao bang bam: "; cin>>k;
		if(k!=0) Insert(k);
	}while(k!=0);
}

// Xoa mot BBw
void Remove(int k){
	int vt = Search(k);
	if(vt < M) {
		Hash[vt].Key = NULLKEY;
		N--;
	} else cout<<"khong co khoa nay"<<endl;
}

main(){
	int k;
	Initialize();
	Print_Hash();
	Read_Hash();
	Print_Hash();
	cout<<"Nhap khoa can tim: "; cin>>k;
	int vt = Search(k);
	if(vt == M)
		cout<<"Khong co khoa "<<k<<" trong bang bam"<<endl;
	else
		cout<<"Khoa "<<k<<" nam o vi tri"<<vt<<endl;
	cout<<"Nhap khoa can xoa:"; cin>>k;
	Remove(k);
	Print_Hash();
}

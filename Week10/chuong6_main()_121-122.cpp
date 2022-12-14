// PPnoi ket -> PP noi ket hop nhat
#include<iostream>
using namespace std;

// Khai bao CTDL
#define NULLKEY 0
#define M 11
struct Node {
	int Key;
	int Next;
};
Node Hash[M];
int available = M-1;

// Ham bam
int HF(int k){
	return (k%M);
}

// Khoi tao BBw 
void Initialize(){
	for(int b=0; b<M; b++){
		Hash[b].Key = NULLKEY;
		Hash[b].Next = -1;
	}
}

// Tm kiem mot khoa trong bang bam
int Search(int k){
	int b = HF(k);
	while(k != Hash[b].Key && Hash[b].Next != -1)
		b = Hash[b].Next;
	if(Hash[b].Next == k)
		return b; // Tim thay
	else
		return M; // Khong tim thay
}

// Chon vi tri trong cuoi o bang bam
int Get_Available(){
	while(Hash[available].Key != NULLKEY)
		available--;
	return available;
}

// Them mot khoa vao bang bam
int Insert(int k){
	int b, j;
	b = Search(k);
	if(b!=M){
		cout << "Khoa da co, khong them duoc"<<endl;
		return b;
	}
	b = HF(k);
	while(Hash[b].Next != -1)
		b = Hash[b].Next;
	if(Hash[b].Key == NULLKEY) // Khong co dung do
		j = b;
	else {
		j = Get_Available();
		if(j<0){
			cout<<"Bang bam day, khong the them \n";
			return j;
		} else {
			Hash[b].Next = j;
		}
		Hash[j].Key = k;
		return j;
	}
}

// In BBw
void Print_Hash(){
	for(int b=0;b<M;b++){
		cout<<"Bucket "<<b<<": "<<Hash[b].Key<<'\t';
		cout<<Hash[b].Next<<endl;
	}
}

// Nhap BBw
void Read_Hash(){
	int k;
	do{
		cout<<"Nhap khoa vao bang bam: ";
		cin>>k;
		if(k!=0) Insert(k);
	} while(k!=0);
}

// Xoa mot khoa khoi bang bam
void Remove(int k){
	int b = HF(k), bo = -1;
	int vt = Search(k);
	if(vt == M)
		cout << "Khong co khoa nay"<<endl;
	else {
		if(vt=b){
			if(Hash[vt].Next==-1){
				Hash[vt].Key = NULLKEY;
				if(available<vt) available = vt;
			} else {
				int t = Hash[b].Next;
				Hash[b].Key = Hash[t].Key;
				Hash[t].Key = NULLKEY;
				Hash[t].Next = -1;
				if(available <t) available = t;
			}
		} else {
			while(Hash[b].Key != k){
				bo = b;
				b = Hash[b].Next;
			}
			if(Hash[b].Next == -1)
				Hash[bo].Next = -1;
			else {
				Hash[bo].Next = Hash[b].Next;
				Hash[b].Next = -1;
			}
			Hash[b].Key = NULLKEY;
			if(available<b) available = b;
		}
	}
}


main(){
	int k;
	Initialize();
	Print_Hash();
	Read_Hash();
	Print_Hash();
	cout<<"Nhap khoa can tim:";cin>>k;
	int vt = Search(k);
	if(vt==M)
		cout<<"Khong co khoa "<<k<<"trong bang bam \n";
	else
		cout<<"Khoa "<<k<<" nam o vi tri "<<vt<<" trong bang \n";
	cout<<"Phan khoa can xoa: "; cin>>k;
	Remove(k);
	Print_Hash();
}

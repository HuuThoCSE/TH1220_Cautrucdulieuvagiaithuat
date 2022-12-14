// PPnoi ket -> PP noi ket truc tiep
#include<iostream>
using namespace std;

// Khai bao Cau truc du lieu Bang bam
# define M 5
struct Node {
	int Key;
	Node* Next;
};

// Khao bao kieu con tro chi danh sanh lien ket
typedef Node* Bucket;

// Khai bao mang bucket chua M con tro dau cua M bucket
Bucket Hash[M];

// Ham bam
int HF(int k){
	return (k%M);
}

// Khoi tao Bang bam
void Initialize(){
	for(int b=0;b<M;b++){
		Hash[b] = new Node;
		Hash[b]->Next = NULL;
	}
}

// Duyet cac khoa trong mot bucket
void Traverse_Bucket(int b){
	Bucket p = Hash[b];
	while(p->Next != NULL){
		cout << p->Next->Key<<'\t';
		p = p->Next;
	}
}

// Duyet tat ca cac khoa trong Bang Bam
void Traverse(){
	for(int b=0;b<M;b++){
		cout << "Bucket "<<b<<": ";
		Traverse_Bucket(b); // Goi ham: Duyet cac khoa trong mot bucket
		cout<<endl;
	}
}

// Tim mot khoa trong bang bam
bool Search(int k){
	Bucket p;
	int b = HF(k);
	p = Hash[b];
	while(p->Next != NULL && p->Next->Key < k)
		p = p->Next;
	if(p->Next != NULL && p->Next->Key == k)
		return true;
	else
		return false;
}

// Kiem tra bucket rong
bool Empty_Bucket(int b){
	return(Hash[b]->Next == NULL);
}

// Them mot khoa vao Bucket
void Insert_Bucket(int b, int k){
	Bucket t = new Node;
	t->Key = k;
	if(Empty_Bucket(b) || k < Hash[b]->Next->Key){ // Goi ham: Kiem tra bucket rong
		t->Next = Hash[b]->Next;
		Hash[b]->Next = t;
	} else {
		Bucket p = Hash[b];
		while(p->Next != NULL && p->Next->Key < k)
			p = p->Next;
		t->Next = p->Next;
		p->Next = t;
	}
}

// Them mot khoa vao bang bam
void Insert(int k){
	int b = HF(k); // Goi ham: Ham bam
	if(!Search(k)) Insert_Bucket(b, k); //Goi ham: Tim mot khoa trong bang bam, Them mot khoa vao Bucket
}

// Nhap Bang bam
void Read_Hash(){
	int k;
	do {
		cout << "Nhap khoa vao bang bam: ";
		cin>>k;
		if(k!=0) Insert(k); // Goi ham: Them mot khoa vao bang bam
	} while(k != 0);
}

// Xoa mot khoa ra khoi BBw
void Remove(int k){
	int b = HF(k);
	Bucket p = Hash[b];
	while(p->Next != NULL && p->Next->Key < k)
		p = p->Next;
	if(p->Next == NULL || p->Next->Key != k)
		cout << "Khong co khoa nay"<<endl;
	else{
		Bucket t = p->Next;
		p->Next = t->Next;
		delete t;
	}
}

// Xoa cac khoa trong mot bucket
void Clear_Bucket(int b){
	Bucket t;
	while(Hash[b]->Next != NULL){
		t = Hash[b]->Next;
		Hash[b]->Next = t->Next;
		delete t;
	}
}

// Xoa tat ca khoa trong BBw
void Clear(){
	for(int b=0; b<M; b++)
		Clear_Bucket(b);
}
main(){
	int k, b;
	Initialize(); // Goi ham: Khoi tao Bang bam
	Traverse(); // Goi ham: Duyet tat ca cac khoa trong Bang Bam
	Read_Hash(); // Goi ham: Nhap Bang bam
	Traverse();
	cout << "Nhap khoa can tim: ";
	cin>>k;
	if(Search(k))
		cout << "Co khoa "<<k<<" trong bang bam"<< endl;
	else 
		cout << "Khong co khoa "<<k<<" trong ban bam"<<endl;
	cout << "Nhap khoa can xoa:";
	cin>>k;
	Remove(k); // Goi ham: Xoa mot khoa ra khoi BBw
	Traverse();
	cout << "Ban muon xoa bucket nao?";
	cin>>b;
	Clear_Bucket(b); // Goi ham: Xoa cac khoa trong mot bucket
	Traverse();
	cout<<"Bang bam sau khi xoa:"<<endl;
	Clear();
	Traverse();
}

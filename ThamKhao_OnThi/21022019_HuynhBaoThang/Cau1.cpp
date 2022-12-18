#include<iostream>
using namespace std;
#define M 5
struct Node
{
	int Key;
	Node* Next;
};
typedef Node* Bucket;
Bucket Hash[M];
int HF(int K)
{
	return (K%M);
}
void Initialize()
{
	for(int b =0;b<M;b++)
	{
		Hash[b] = new Node;
		Hash[b]->Next=NULL;
	}
}
// ktra mot bucket rong
bool Empty_Bucket(int b)
{
	return (Hash[b]->Next==NULL);
}
//Ktra bang bam rong
bool Empty()
{
	for(int b=0;b<M;b++)
		if(!Empty_Bucket(b))
			return false;
		return true;
}
//Tim mot khoa trong bang bam
bool Search(int K)
{
	Bucket p;
	int b = HF(K);
	p = Hash[b];
	while(p->Next!=NULL && p->Next->Key < K)
		p=p->Next;
	if(p->Next!=NULL && p->Next->Key == K)
		return true;
	else
		return false;
}
//Them mot khoa vao bucket
void Insert_Bucket(int b , int K)
{
	Bucket T = new Node;
	T->Key = K;
	if(Empty_Bucket(b) || K<Hash[b]->Next->Key)
	{
		T->Next = Hash[b]->Next;
		Hash[b]->Next = T;
	}
	else
	{
		Bucket P = Hash[b];
		while(P->Next!=NULL && P->Next->Key < K)
			P = P->Next;
		T->Next = P->Next;
		P->Next = T; 
	}
}
//Them mot khoa vao bang bam
void Insert(int K)
{
	int b = HF(K);
	if(!Search(K))
		Insert_Bucket(b,K);
}
//Xoa mot khoa khoi bang bam
void Remove(int K)
{
	int b = HF(K);
	Bucket p = Hash[b];
	while(p->Next!=NULL && p->Next->Key < K)
		p = p->Next;
	if(p->Next==NULL || p->Next->Key != K)
		cout<<" Khong co khoa nay"<<endl;
	else
	{
		Bucket t = p->Next;
		p->Next = t->Next;
		delete t;
	}
}
//Xoa cac khoa trong mot bucket
void Clear_Bucket(int b)
{
	Bucket t;
	while (Hash[b]->Next!=NULL)
	{
		t = Hash[b]->Next;
		Hash[b]->Next = t->Next;
		delete t;
	} 
}
// xoa tat ca cac khoa trong bang bam
void Clear()
{
	for(int b=0 ;b<M;b++)
		Clear_Bucket(b);
}
//Duyet cac khoa trong mot bucket
void Traverse_Bucket(int b)
{
	Bucket p = Hash[b];
	while(p->Next!=NULL)
	{
		cout<<p->Next->Key<<'\t';
		p = p->Next;
		
	}
}
//Duyet tat cac cac khoa trong bang bam
void Traverse()
{
	for(int b=0 ; b<M; b++)
	{
		cout<<"Bucket "<<b<<": ";
		Traverse_Bucket(b);
		cout<<endl;
	}
}
//Nhap bang bam
void Read_Hash()
{
	int K;
	do
	{
		cout<<"Nhap khoa vao bang bam:";
		cin>>K;
		if(K!=0) Insert(K);
	}while(K!=0);
}
//ham main
main()
{
	int K,b;
	Initialize();
	Traverse();
	Read_Hash();
	Traverse();
	cout<<"Nhap khoa can tim:";
	cin>>K;
	if(Search(K))
		cout<<"Co khoa "<<K<<" trong bang bam"<<endl;
	else
		cout<<"Khong co khoa "<<K<<" trong bang bam"<<endl;
	cout<<"Nhap khoa can xoa:";
	cin>>K;
	Remove(K);
	Traverse();
	cout<<"Ban muon xoa bucket nao?";
	cin>>b;
	Clear_Bucket(b);
	cout<<"Bang bam sau khi xoa 1 bucket:"<<endl;
	Traverse();
	cout<<"Bang bam sau khi xoa:"<<endl;
	Clear();
	Traverse();
}

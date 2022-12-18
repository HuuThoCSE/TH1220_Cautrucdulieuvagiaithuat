#include<iostream>
using namespace std;
#define NULLKEY 0
#define M 13
struct Node{
	int Key;
};
Node Hash[M];
int N=0;
//ham bam
int HF(int K)
{
	return (K%M);
}
void Initialize()
{
	for(int b=0;b<M;b++)
		Hash[b].Key = NULLKEY;
}
//kiem trang bang bam rong
bool Empty()
{
	return(N==0);
}
//Kiem tra bang bam day
bool Full()
{
	return(N==M-1);
}
//Ham tao ra chi so de tim vi tri trong
int G(int i)
{
	return i;
}
//Tim kiem mot khoa trong bang bam
int Search(int K)
{
	if(Empty())	return M;
	int b = HF(K),vt=b,i=0;
	while(Hash[vt].Key!=NULLKEY && Hash[vt].Key != K)
	{
		i++;
		vt = (b+G(i)) % M;
	}
	if(Hash[vt].Key == K)
		return vt;
	else
		return M;
}
//Them mot khoa vao bang bam
int Insert(int K)
{
	int b = HF(K);
	int vt = b, i =0;
	if(Full())
	{
		cout<<"Bang bam day, khong them duoc"<<endl;
		return M;
	}
	if(Search(K)<M)
	{
		cout<<"Khoa da co, khong them nua"<<endl;
		return M;
	}
	while(Hash[vt].Key!=NULLKEY)
	{
		i++;
		vt = (b+G(i))%M;
	}
	Hash[vt].Key = K;
	N = N+1;
	return vt;
}
//Xoa mot khoa khoi bang bam
void Remove(int K)
{
	int vt = Search(K);
	if(vt < M)
	{
		Hash[vt].Key =NULLKEY;
		N--;
	}
	else
		cout<<"Khong co khoa nay"<<endl;
}
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
void Print_Hash()
{
	for(int b=0;b<M;b++)
		cout<<"Bucket "<<b<<": "<<Hash[b].Key<<endl;
}
main()
{
	int K;
	Initialize();
	Print_Hash();
	Read_Hash();
	Print_Hash();
	cout<<"Nhap khoa can tim:";cin>>K;
	int vt = Search(K);
	if(vt == M)
		cout<<"Khong co khoa "<<K<<" trong bang bam"<<endl;
	else
		cout<<"Khoa "<<K<<" nam o vi tri "<<vt<<endl;
	cout<<"Nhap khoa can xoa:";cin>>K;
	Remove(K);
	Print_Hash();
}


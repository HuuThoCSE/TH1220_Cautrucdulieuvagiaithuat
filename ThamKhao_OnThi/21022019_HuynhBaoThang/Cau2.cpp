#include<iostream>
using namespace std;
#define NULLKEY 0
#define M 11
struct Node{
	int Key;
	int Next;
};
int HF(int K)
{
	return (K%M);
}
Node Hash[M];
int available = M - 1;
void Initialize()
{
	for(int b = 0;b < M ;b++)
	{
		Hash[b].Key = NULLKEY;
		Hash[b].Next = -1;
	}
}
bool Empty()
{
	for(int b=0;b<M;b++)
		if(Hash[b].Key!=NULLKEY)
			return false;
		return true;
}
//Tim kiem mot khoa trong bang bam
int Search(int K)
{
	int b = HF(K);
	while(K!=Hash[b].Key && Hash[b].Next!=-1)
		b = Hash[b].Next;
	if(Hash[b].Key==K)
		return b; //Tim thay
	else
		return M; //Khong tim thay
}
//Chon vi tri trong cuoi bang
int Get_Available()
{
	while(Hash[available].Key!=NULLKEY)
		available --;
	return available;
}
//Them mot khoa vao bang bam
int Insert(int K)
{
	int b,j;
	b = Search(K);
	if(b!=M)
	{
		cout<<"Khoa da co, khong them duoc"<<endl;
		return b;
	}
	b = HF(K);
	while(Hash[b].Next!=-1)
		b = Hash[b].Next;
	if(Hash[b].Key == NULLKEY) // khong co dung do
		j = b;
	else
	{
		j = Get_Available();
		if(j<0)
		{
			cout<<"Bang bam day, khong the them"<<endl;
			return j;
		}
		else
			Hash[b].Next = j;
	}
	Hash[j].Key = K;
	return j;
}
//Xoa mot khoa khoi bang bam
void Remove(int K)
{
	int b = HF(K), bo = -1;
	int vt = Search(K);
	if(vt == M)
		cout<<"Khong co khoa nay"<<endl;
		else
		{
			if(vt==b)
			{
				if(Hash[vt].Next==-1)
				{
					Hash[vt].Key = NULLKEY;
					if(available < vt)
						available = vt;
				}
				else
				{
					int t = Hash[b].Next;
					Hash[b].Key = Hash[t].Key;
					Hash[b].Next = Hash[t].Next;
					Hash[t].Key = NULLKEY;
					Hash[t].Next = -1;
					if(available<t)	
						available = t;
				}
			}
			else
			{
				while(Hash[b].Key!=K)
				{
					bo = b;
					b = Hash[b].Next;
				}
				if(Hash[b].Next == -1)
					Hash[bo].Next = -1;
				else
				{
					Hash[bo].Next = Hash[b].Next;
					Hash[b].Next = -1;
				}
				Hash[b].Key = NULLKEY;
				if(available < b)
					available = b;
			}
		}
}
//Nhap bang
void Read_Hash()
{
	int K;
	do
	{
		cout<<"Nhap khoa vao bang bam: ";
		cin>>K;
		if(K!=0) Insert(K);
	}while(K!=0);
}
//In bang bam
void Print_Hash()
{
	for(int b=0;b<M;b++)
	{
		cout<<"Bucket "<<b<<": "<<Hash[b].Key<<'\t';
		cout<<Hash[b].Next<<endl;
	}
}
main()
{
	int K;
	Initialize();
	Print_Hash();
	Read_Hash();
	Print_Hash();
	cout<<"Nhap khoa can tim";cin>>K;
	int vt = Search(K);
	if(vt==M)
		cout<<"Khong co khoa "<<K<<" trong bang bam"<<endl;
	else
		cout<<"Khoa "<<K<<" nam o vi tri "<<vt<<" trong bang"<<endl;
	cout<<"Nhap khoa can xoa:";cin>>K;
	Remove(K);
	Print_Hash(); 
}

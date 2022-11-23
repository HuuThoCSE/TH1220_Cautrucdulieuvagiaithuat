#include "ListFloat.h"
// 2b.1
void Descending(List &L)
{
	Position P, Q;

	P = L->Next;
	
	while (P->Next != NULL)
	{
		Q = P->Next;
		while (Q != NULL)
		{
			if ( Retrieve(P, L) < Retrieve(Q, L) )
			{
				Temp = P->Element;
				P->Element = Q->Element;
				Q->Element = Temp;
			}
			Q = Next(Q, L);
		}
		P = Next(P, L);
	}
}

// 2b.2
void MixDes(List LD1, List LD2, List &LD3)
{
	Position P, Q;
	MakeNullList(LD3);
	
	// Truong hop 2 ds bang nhau
	while (P->Next != NULL && Q->Next != NULL)
	{
		if (P->Next->Element > Q->Next->Element)
		{
			InsertList(P->Next->Element, Last(LD3), LD3);
			P = P->Next;
		}
		else 
			InsertList(Q->Next->Element, Last(LD3), LD3);
			Q = Q->Next;
	}

	// Truong hop LD1 dai hon
	while (P->Next != NULL && Q->Next == NULL)
	{
		P=First(LD1);
		InsertList(P->Next->Element, Last(LD3), LD3);
	}
	
	// Truong hop LD2 dai hon
	while (P->Next == NULL && Q->Next != NULL)
	{
		Q=First(LD2);
		InsertList(Q->Next->Element, Last(LD3), LD3);
	}
}

// 2d
ElementType NDMin (List L)
{
	ElementType min = L->Next->Element;
	
	while (L->Next != NULL)
	{
			if (min > L->Next->Element) 
				min = L->Next->Element;
			L = L->Next;
	}	
	return min;
}

// 2g.1
void Xoaphantugiong(List &L)
{
	ElementType SS = L->Next->Element;

	while (L->Next != NULL)
	{
		if (L->Next->Element == SS)
			DeleteList(L->Next, L);
		L = L->Next;
	}
}

// 2g.2
ElementType Vitriphantumin(List L)
{
	int dem=0;
	ElementType min = L->Next->Element;
	
	while (L->Next != NULL)
		{
			if (min > L->Next->Element) 
				min = L->Next->Element;
			L = L->Next;
			dem++;
		}	
	dem = int(dem);
	return dem;
}

// 2i
ElementType Nguyenboiso(int k, List L)
{
	Position P=L;
	float s=0;
	
	while (P->Next != NULL)
	{
		if ( int(P->Next->Element) % k == 0 )
			s = s + P->Next->Element;
		P = P->Next;
	}
	return s;
}

main()
{
	int k;
	List L, G1, G2, G3;
	Position P, Q;
	
	// Nhap, in danh sach lien ket ElementType
	MakeNullList(L);
	cout << "NHAP DANH SACH LIEN KET L" << endl;
	ReadList(L);
	cout << "\nIN DANH SACH LIEN KET L" << endl;
	PrintList(L);
	
	// 2g
	Xoaphantugiong(L);
	cout << endl;
	PrintList(L);

	cout << endl << "\nPhan tu co noi dung nho nhat o vi tri thu ";
	cout << Vitriphantumin(L) << " trong list.";

	// 2a
	Ascending(L);
	cout << endl << "\nIN DANH SACH LIEN KET L TANG DAN" << endl;
	PrintList(L);

	// 2d
	cout << endl << "\nPhan tu nho nhat trong danh sach L: " << NDMin(L) << endl;
	
	// 2i
	do
	{
		cout << "\nNhap k can tim boi so: ";
		cin >> k;
	} while (k > 0);

	cout << "\nTong phan tu co phan nguyen la boi so cua k: ";
	cout << Nguyenboiso(k, L);
	
	
//	// 2b
//	MakeNullList(G1);
//	
//	cout << endl << "NHAP DANH SACH LIEN KET GIAM DAN G1\n";
//	ReadList(G1);
//	
//	Descending(G1);
//	cout << "IN DANH SACH LIEN KET GIAM DAN G1\n";
//	PrintList(G1);
//	
//	MakeNullList(G2);
//	
//	cout << endl << "NHAP DANH SACH LIEN KET GIAM DAN G2\n";
//	ReadList(G2);
//	
//	Descending(G2);
//	cout << "IN DANH SACH LIEN KET GIAM DAN G2\n";
//	PrintList(G2);
//	
//	MixDes(G1, G2, G3);
//	cout << "IN DANH SACH LIEN KET GIAM DAN G3\n";
//	PrintList(G3);	
}

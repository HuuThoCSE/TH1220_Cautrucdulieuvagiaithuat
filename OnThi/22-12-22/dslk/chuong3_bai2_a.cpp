#include "dslk_sothuc.h"
void XapXepTangDan(List &L){
	Position P=L, q;
	while(P->Next->Next!=NULL){
		q=P->Next;
		while(q->Next != NULL) {
			if(q->Next->Element>q->Next->Element){
				float t = P->Next->Element;
				P->Next->Element=q->Next->Element;
				q->Next->Element=t;
			}
			q=q->Next;
		}
	P=P->Next;
	}
}

//void merge(List &L, int left, int mid, int right) {
//    // Tao hai Ds tim và cheo cac phan tu cua L vao nhung Ds nay
//    List leftList, rightList;
//    int n1 = mid - left + 1;
//    int n2 = right - mid;
//    for (int i = 0; i < n1; i++)
//        leftList[i] = L[left + i];
//    for (int j = 0; j < n2; j++)
//        rightList[j] = L[mid + 1 + j];
//
//    // Gop 2 DS tam thanh L
//    int i = 0, j = 0, k = left;
//    while (i < n1 && j < n2) {
//        if (leftList[i] <= rightList[j]) {
//            L[k] = leftList[i];
//            i++;
//        }
//        else {
//            L[k] = rightList[j];
//            j++;
//        }
//        k++;
//    }
//
//	// Neu con phan tu trong DS tam trai, thi chep tat ca cac phan tu con lai vao L
//	while (i < n1) {
//		L[k] = leftList[i];
//		i++;
//		k++;
//	}
//	
//	// Neu con phan tu trong DS tam phai, thi chep tat ca cac phan tu con lai vao L
//	while (j < n2) {
//    	L[k] = rightList[j];
//    	j++;
//    	k++;
//	}
//}
//
//void mergeSort(List &L, int left, int right) {
//	if (left < right) {
//	// Tim vi tri giua danh sach
//	int mid = left + (right - left) / 2;
//
//	// Sap xep cac phan tu trong hai nua trai va phai cua DS
//    mergeSort(L, left, mid);
//    mergeSort(L, mid + 1, right);
//
//    // Gop hai nua trai va phai thanh mot DS da sap xep
//    merge(L, left, mid, right);
//	}
//}

//void merge(List &L, int left, int mid, int right) {
//// Tính d? dài c?a hai danh sách t
//int i, j, k;
//int n1 = mid - left + 1;
//int n2 = right - mid;
//// T?o ra hai danh sách t?m
//ElementType *leftList = new ElementType[n1];
//ElementType *rightList = new ElementType[n2];
//// Chép ph?n t? t? L vào hai danh sách t?m
//for (i = 0; i < n1; i++) {
//	leftList[i] = L[left + i];
//}
//for (j = 0; j < n2; j++) {
//rightList[j] = L[mid + 1 + j];
//}
//// G?p hai danh sách t?m l?i vào L
//i = 0;
//j = 0;
//k = left;
//while (i < n1 && j < n2) {
//if (leftList[i] <= rightList[j]) {
//L[k] = leftList[i];
//i++;
//} else {
//L[k] = rightList[j];
//j++;
//}
//k++;
//}
//// Chép các ph?n t? còn l?i t? leftList vào L
//while (i < n1) {
//L[k] = leftList[i];
//i++;
//k++;
//}
//// Chép các ph?n t? còn l?i t? rightList vào L
//while (j < n2) {
//L[k] = rightList[j];
//j++;
//k++;
//}
//delete [] leftList;
//delete [] rightList;
//}
//
//void mergeSort(List &L, int left, int right) {
//if (left < right) {
//int mid = left + (right - left) / 2;
//// S?p x?p danh sách trái
//mergeSort(L, left, mid);
//// S?p x?p danh sách ph?i
//mergeSort(L, mid + 1, right);
//// G?p hai danh sách dã s?p x?p
//merge(L, left, mid, right);
//}
//}
//
//// Hàm s?p x?p danh sách có th? t? tang d?n
//void sortList(List &L) {
//mergeSort(L, 0, length(L) - 1);
//}

void SapXepTangDan1(List &L){
	Position P=L, Q;
	while (P->Next->Next!=NULL){
		Q=P->Next;
		while (Q->Next!=NULL){
			if (P->Next->Element>Q->Next->Element){
				ElementType temp = P->Next->Element;
				P->Next->Element = Q->Next->Element;
				Q->Next->Element = temp;
			}
			Q=Q->Next;
		}
		P=P->Next;
	}
}

main(){
	List L;
	MakeNullList(L);
	ReadList(L);
	PrintList(L);
	
	// Sap xep DS co thu tu tang dan
	SapXepTangDan1(L);
	
	cout<<"\nDS sau khi sap xep tang dan: \n";
	PrintList(L);
}

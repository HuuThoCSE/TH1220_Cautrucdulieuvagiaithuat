#include "module_stack.h"

// Chuyen 10 -> 2
void converDectoBin(int Dec, Stack &S, Stack S2){
	int Du;
	while(Dec!=0){
		Push(Dec%2, S);
		Dec/=2;
	}
	
	while(S!=NULL){
//		cout << Top(S)<<'\t';
		Push(Top(S), S2);
		Pop(S);
	}
	
	while(S2!=NULL){
//		cout << Top(S2)<<'\t';
		Push(Top(S), S);
		Pop(S2);
	}
}

main(){
	int Dec;
	Stack S, S2;
	MakeNullStack(S);
	MakeNullStack(S2);
	cout << "Nhap so thap phan: "; cin >> Dec;
	
	// Doi tu 10 -> 2
	converDectoBin(Dec, S, S2);
	
	// In
	PrintStack(S);
}

#include<iostream>
#include<cstring>
using namespace std;
int Hash_ASCII(char* s){
	int M = 5;
	int t = s[0]%M;
	for (int i = 1; i<strlen(s); i++)
		t = (t*10 + s[i])% M;
	return t;
}

main(){
	char stk;
	stk = 'ABC';
	Hash_ASCII(stk);
}

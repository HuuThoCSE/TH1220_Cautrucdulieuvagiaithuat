#include "module_stack.h"
main(){
	Stack S;
	MakeNullStack(S);
	cout << "=====NHAP NGAN XEP====="<<endl;
	ReadStack(S);
	cout << "=====IN NGAN XEP====="<<endl;
	PrintStack(S);
	cout<<endl;
}

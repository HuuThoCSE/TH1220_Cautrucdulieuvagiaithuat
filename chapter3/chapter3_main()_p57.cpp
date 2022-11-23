#include "module_queue.h"
main(){
	Queue Q;
	MakeNullQueue(Q);
	cout << "=====NHAP HANG DOI====="<<endl;
	ReadQueue(Q);
	cout << "=====IN HANG DOI====="<<endl;
	PrintQueue(Q);
	cout<<endl;
}

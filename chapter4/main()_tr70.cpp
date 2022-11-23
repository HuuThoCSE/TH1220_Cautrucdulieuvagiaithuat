#include "module_tree.h"
main() {
	BinT_Type BT;
 	cout<<"=====NHAP CAY NHI PHAN====="<<endl;
 	Initialize(BT);
 	Read_Tree(BT);
 	cout<<"=====IN CAY NHI PHAN THEO CACH LNR====="<<endl;
 	LRootR_Traverse(BT);
 	cout<<endl;
 	Info X;
 	cout<<"Ban muon them vao nut trai nhat la bao nhieu:";
 	cin>>X;
 	Add_Left(BT, X);
 	cout<<"==CAY NHI PHAN SAU KHI THEM NUT TRAI=="<<endl;
 	LRootR_Traverse(BT);
 	cout<<"\nChieu cao cua cay la: "<<Tree_Height(BT);
 	cout<<"\nCay co "<<Count_Node(BT)<<" nut"<<endl;
}

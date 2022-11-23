main(){
	int K;
	BST_Type BST;
	cout<<"=====NHAP CAY NHI PHAN TIM KIEM====="<<endl;
	Initialize(BST);
	Read_Tree(BST);
	cout<<"=====CAY NHI PHAN TIM KIEM DA NHAP====="<<endl;
	LRootR_Travelling(BST);
	cout<<endl;
	cout<<"Nhap vao K: "<<endl;
	cin>>K;
	cout<<"In tu goc den K La: ";
	RootToK(BST,K);
	cout<<endl;
	cout<<"In tu K den goc la: ";
	KToRoot(BST,K);
	cout<<endl;
	cout<<"In tu MIN ve goc: "<<endl;
	MinToRoot(BST);
	cout<<endl;
	cout<<"Min to Max: "<<endl;
	MinToMax(BST);
	cout<<endl;
	cout<<"Noi dung lon hon K: "<<endl;
	NutLHK(BST,K);
}

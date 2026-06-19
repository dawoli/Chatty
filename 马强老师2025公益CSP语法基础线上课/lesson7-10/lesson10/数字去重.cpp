#include<iostream>
using namespace std;
int main(){
	//n个盲盒，1~20
	int n,x;
	bool a[101]={};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]=1;
	}
	for(int i=1;i<=100;i++)
		if(a[i]==1)
			cout<<i<<' ';
	
	return 0;
}

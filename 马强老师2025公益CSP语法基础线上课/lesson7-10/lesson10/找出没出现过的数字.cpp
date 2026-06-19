#include<iostream>
using namespace std;
int main(){
	//n个盲盒，1~20
	int n,x;
	bool a[21]={};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]=1;
	}
	for(int i=1;i<=20;i++)
		if(a[i]==0)
			cout<<i<<' ';
	
	return 0;
}

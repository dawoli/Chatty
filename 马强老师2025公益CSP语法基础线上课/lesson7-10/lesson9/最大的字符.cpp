#include<iostream>
using namespace std;
int main(){
	int n;
	char a[60]={};
	char c=0;
	int p=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	//最大字符及位置
	for(int i=0;i<n;i++){
		if(a[i]>c){
			c=a[i];
			p=i;
		}
	}
	for(int i=n-1;i>=p;i--)
		a[i+1]=a[i];
	
	a[p]=0;
	for(int i=0;i<=n;i++)
		cout<<a[i]<<' ';
	return 0;
}

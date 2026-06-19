#include<iostream>    
using namespace std;
int main(){
	int n,x,a[10]={};
	cin>>n;
	int i=1;
	while(i<=n){
		cin>>x;
		a[x]++;
		i++;
	}
	i=0;
	while(i<=9){
		cout<<a[i]<<' ';
		i++;
	}
}

#include <bits/stdc++.h>
using namespace std;
int a[110],x;
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<100;i++){
		cin>>a[i];
	}
	x=a[0];
	int num=0;
	sort(a,a+100);
	
	////////////////////////////
//	for(int i=0;i<100;i++){
//		cout<<a[i]<<" ";
//	}cout<<endl<<endl;
	////////////////////////////
	
	for(int i=99;i>=0;i--){
		if(a[i]==x){
			num=100-i;
			break;
		}
	}
	
	////////////////////////////
//	cout<<num<<endl<<endl;
	////////////////////////////
	if(num%m)
		cout<<num/m+1<<" ";
	else
		cout<<num/m<<" ";
	if((num/m)/2){
		if(num%n)
			cout<<num%n;
		else
			cout<<n;
		return 0;
	}
	if(num%n)
		cout<<num%n+m-1;	
	else
		cout<<n+m-1;
	return 0;
} 

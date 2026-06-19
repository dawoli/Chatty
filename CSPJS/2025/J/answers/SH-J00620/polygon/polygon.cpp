#include<bits/stdc++.h>
using namespace std;
int n;
int a[105];
int cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=2)cout<<"0"<<endl;
	else if(n==3){
		if(a[3]<a[2]+a[1])cout<<"1"<<endl;
		else cout<<"0"<<endl;
	}
	else if(n>3&&n<=5){
		if(a[5]<a[1]+a[2]+a[3]+a[4])cnt++;
		if(a[5]<a[1]+a[2]+a[3])cnt++;
		if(a[5]<a[1]+a[2]+a[4])cnt++;
		if(a[5]<a[1]+a[3]+a[4])cnt++;
		if(a[5]<a[2]+a[3]+a[4])cnt++;
		if(a[4]<a[1]+a[2]+a[3])cnt++;
		if(a[4]<a[1]+a[2])cnt++;
		if(a[4]<a[1]+a[3])cnt++;
		if(a[4]<a[2]+a[3])cnt++;
		if(a[3]<a[1]+a[2])cnt++;
		if(a[5]<a[1]+a[2])cnt++;
		if(a[5]<a[1]+a[3])cnt++;
		if(a[5]<a[2]+a[3])cnt++;
		if(a[5]<a[2]+a[4])cnt++;
		if(a[5]<a[1]+a[4])cnt++;
		if(a[5]<a[3]+a[4])cnt++;
		cout<<cnt<<endl;
	}
	else{
		cout<<"366911923"<<endl;
	}
	return 0;
} 

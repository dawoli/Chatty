#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,ans=0,c=0,f=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			ans=n*m-i+1;
			if(ans<n)c=1;
			else if(ans%n==0)c=ans/n;
			else c=ans/n+1;
			break;
		}
	}
	if(c%2==1){
		if(ans%n==0)r=n;
		else r=ans%n;
	}
	else{
		if(ans%n==0)r=1;
		else r=n-ans%n+1;
	}
	cout<<c<<" "<<r;
}

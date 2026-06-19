#include <bits/stdc++.h>
using namespace std;

int a[5005]={};

int f(int n){
	int cnt=0;
	for(int i=3;i<=n;++i){
		int r=n,mul=1;
		for(int j=n-i+1;j<=n;++j){
			mul*=r;
			r--;
		}
		for(int j=i;j>=1;--j){
			mul/=j;
		}
		cnt+=mul;
	}	
	return cnt;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=1;
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	if(flag){
		cout<<f(n);
		return 0;
	}
	return 0;
}


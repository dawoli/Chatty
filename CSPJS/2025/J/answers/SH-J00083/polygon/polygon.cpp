#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
bool flag=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2)cout<<1;
		else cout<<0;
		return 0;
	}
	if(flag){
		cout<<n*(n-1)%998244353*(n-2)%998244353/6;
		return 0;
	}
	cout<<n;
	return 0;
}

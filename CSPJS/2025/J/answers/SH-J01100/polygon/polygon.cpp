#include<bits/stdc++.h>
using namespace std;
int a[10010],b[10010],book[10010];
int n,c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m=0,flag=1,ma=0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		m+=a[i];
		ma=max(ma,a[i]);
		if(a[i]!=1)flag=0;
	}
	if(flag) {
		cout<<n-2;
		return 0;
	}
	else if(n<=3) {
		if(m>2*ma)cout<<1;
		else cout<<0;
	}
	return 0;
}

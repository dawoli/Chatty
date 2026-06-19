#include<bits/stdc++.h>
using namespace std;
const int N=5009;
const int MOD=998244353;
int n,cnt,a[N],res;
int mul(int n){
	int ans=1;
	for(int i=2;i<=n;i++) ans=(ans*i)%MOD;
	return ans;
}
int C(int n,int m){
	return mul(n)/((mul(m)*mul(n-m))%MOD);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	if(n==3){
		int z=max(a[1],max(a[2],a[3]));
		int x=min(a[1],min(a[2],a[3]));
		int y=a[1]+a[2]+a[3]-x-z;
		if(x+y>z) cout<<1;
		else cout<<0;
		return 0;
	}
	if(cnt==n){
		for(int i=3;i<=n;i++)
			res=(res+C(n,i))%MOD;
		cout<<res;
	}
	return 0;
}

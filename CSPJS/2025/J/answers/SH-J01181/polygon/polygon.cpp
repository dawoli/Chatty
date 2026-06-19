#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+10,mod=998244353;
ll a[N],n,ans,k[N];
ll qpow(ll a,ll b){
	a%=mod;
	ll c=1;
	while(b){
		if((b&1)==1)
			c=c*a%mod;
		b=b>>1;
		a=a*a%mod;
	}
	return c;
}
ll Cnm(ll m){
	ll u=k[n]*qpow(k[m],mod-2)%mod*qpow(k[n-m],mod-2)%mod;
	return u;
}
void dfs(int pl,int num,int add){
	if(num>a[pl] && add>=2)
		ans++;
	if(pl==n)
		return;
	dfs(pl+1,num+a[pl],add+1);
	if(ans>=mod) ans-=mod;
	dfs(pl+1,num,add);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	else if(a[n]==1){
		k[0]=1;
		for(int i=1;i<=n;i++)
			k[i]=k[i-1]*i%mod;
		for(int i=3;i<=n;i++)
			ans=(ans+Cnm(i))%mod;
		cout<<ans;
	}
	else{
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}

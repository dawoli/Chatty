#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=5005,mod=998244353;
ll n,a[N],g[N*5000],mxA=0,s[N*4];
void solveBF(){
	g[0]=1;
	for(ll i=1;i<=mxA*n;++i){
		g[i]=0;
	}
	ll ans=0;
	for(ll i=1;i<=n;++i){
		for(ll j=mxA*n;j>=a[i];--j){
			if(i>=3&&j+a[i]>2*a[i]){
				ans+=g[j];
				ans%=mod;
			}
			g[j]+=g[j-a[i]];
			g[j]%=mod;
		}
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<"\n";
}
void solvea1(){
	ll ans=1;
	for(ll i=1;i<=n;++i){
		ans=(ans*2)%mod;
	}
	ans--;
	ans-=n;
	ans=(ans%mod+mod)%mod;
	ans-=(n*(n-1)/2)%mod;
	ans=(ans%mod+mod)%mod;
	cout<<ans<<"\n";
}
void solve(){
	g[0]=1;
	ll MxNum=min(mxA*n,10001ll);
	for(ll i=1;i<=MxNum;++i){
		g[i]=0;
	}
	ll ans=0;
	for(ll i=1;i<=n;++i){
		for(ll j=MxNum;j>=a[i];--j){
			if(i>=3&&j+a[i]>2*a[i]){
				ans+=g[j];
				ans%=mod;
			}
			if(j==MxNum){
				g[MxNum]=g[MxNum]*2%mod;
				s[MxNum]=0;
				g[MxNum]=(g[MxNum]+s[j-a[i]+1])%mod;
			}
			g[j]+=g[j-a[i]];
			g[j]%=mod;
			if(j<MxNum){
				s[j]=(s[j+1]+g[j])%mod;
			}
		}
		for(ll j=a[i]-1;j>=0;--j){
			s[j]=(s[j+1]+g[j])%mod;
		}
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<"\n";
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		mxA=max(mxA,a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=500&&mxA<=100)solveBF();
	else if(mxA<=1)solvea1();
	else solve();
	return 0;
}

#include<bits/stdc++.h>
#define NN 5005
#define MOD 998244353
typedef long long ll;
using namespace std;
ll n,a[NN],pre[NN],ans;
ll up2n(ll x){
	ll t=1;
	for(ll i=1;i<=x;i++) t=t*2%MOD;
	return t;
}
ll f(ll x){
	ll t=1;
	for(ll i=1;i<=x;i++) t*=i;
	return t;
}
ll C(ll N,ll M){
	M=min(M,N-M);
	return (f(N)%MOD)/((f(M)%MOD)*f(N-M)%MOD)%MOD;
}
void dfs1(ll x,ll sum,ll mxid,ll mnsum){
	if(sum>mnsum){
		ans+=up2n(mxid-x);
		ans%=MOD;
		return;
	}
	for(ll i=x+1;i<=mxid;i++) dfs1(i,sum+a[i],mxid,mnsum);
}
void dfs2(ll x,ll sum,ll mxid,ll mnsum){
	if(sum>mnsum){
		ans+=up2n(mxid-x);
		ans%=MOD;
		return;
	}
	if(sum+pre[mxid]-pre[x]<=mnsum) return;
	for(ll i=x+1;i<=mxid;i++) dfs1(i,sum+a[i],mxid,mnsum);
}
void S1_10(){
	for(ll i=3;i<=n;i++) if(pre[i-1]>a[i]) dfs1(0,0,i-1,a[i]);
	cout<<(ans+MOD)%MOD;
}
bool all1(){
	for(ll i=1;i<=n;i++) if(a[i]!=1) return 0;
	return 1;
}
void S15_20(){
	for(ll i=3;i<=n;i++) ans=(ans+C(n,i))%MOD;
	cout<<(ans+MOD)%MOD;
}
void Luck(){
	for(ll i=3;i<=n;i++) if(pre[i-1]>a[i]) dfs1(0,0,i-1,a[i]);
	cout<<(ans+MOD)%MOD;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],pre[i]=pre[i-1]+a[i];
	sort(a+1,a+1+n);
	if(n<=20) S1_10();				//40pts
	else if(all1()) S15_20();		//24pts
	else Luck();					//¿¨Ë®Êý¾Ý
	return 0;
}

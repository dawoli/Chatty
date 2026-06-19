#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a0[100009],c[100009];
ll T;
ll x[4],a[100009];
bool d[30][100009];
vector<ll> x[100009];
ll solvebfbf(ll k){
	ll nK=log2(k)+1;
	for(ll p=1;p<=nK;p++){
		
	}
}
void solvebf(){
	ll T;
	scanf("%lld",&T);
	for(ll i=1;i<=T;i++){
		for(ll j=0;j<4;j++) scanf("%lld",&x[i]);
		for(ll j=1;j<=n;j++) a[i]=a0[i]^x[i%4];
		ll ans=0;
		for(ll j=1;j<=m;j++) ans^=solvebfbf(c[j]);
	}
}
void solve(){
	
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a0[i]);
	for(ll i=1;i<=m;i++) scanf("%lld",&c[i]);
	ll K=ceil(log2(n));
	for(ll p=1;p<=K;p++){
		for(ll j=1;j<=1<<(K-p);j++){
			char c;
			cin>>c;
			d[p][j]=c-'0';
		}
	}
	if(n<=8&&m<=8) solvebf();
	else solve();
	return 0;
}

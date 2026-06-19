#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
ll n,k,q;
ll l[100009],r[100009],c[100009];
vector<ll> s[100009];
bool ifr1(){
	for(ll i=1;i<=q;i++) if(r[i]>1) return 0;
	return 1;
}
bool ok[2000009];
void solver1(){
	for(ll i=1;i<=n;i++){
		ll last1=-1e9;
		for(ll j=0;j<l[i];j++){
			if(j-last1+1<=k) ok[s[i][j]]=1;
			if(s[i][j]==1) last1=j;
		}
	}
	for(ll i=1;i<=q;i++) printf("%lld\n",ok[c[i]]);
}
//void solvel20(){
//	for(ll i=1;i<=n;i++)
//}
void ultra_solve(){
	for(ll i=1;i<=q;i++){
		printf("1\n");
	}
}
void solve(){
	scanf("%lld%lld%lld",&n,&k,&q);
	ll suml=0;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&l[i]);
		suml+=l[i];
		s[i].resize(l[i]);
		for(ll j=0;j<l[i];j++)
			scanf("%lld",&s[i][j]);
	}
	for(ll i=1;i<=q;i++) scanf("%lld%lld",&r[i],&c[i]);
	if(ifr1()) solver1();
//	else if(suml<=20) solvel20(); 
	else ultra_solve();
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%lld",&T);
	while(T--) solve();
	return 0;
}

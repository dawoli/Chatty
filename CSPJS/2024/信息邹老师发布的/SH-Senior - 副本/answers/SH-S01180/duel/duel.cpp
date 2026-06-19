#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
ll n,cnt[N],sbit[N];
ll LSB(ll x){
	return x&(-x);
}
void add(ll x,ll k){
	while(x<N){
		sbit[x]+=k;
		x+=LSB(x);
	}
}
ll sum(ll x){
	ll ans=0;
	while(x){
		ans+=sbit[x];
		x-=LSB(x);
	}
	return ans;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		ll r;
		scanf("%lld",&r);
		cnt[r]++;
		add(r,1);
	}
	ll ans=n;
	for(ll i=2;i<N;i++){
		ll s=sum(i-1);
		if(s==0) continue;
		ll k=cnt[i]-s;
		if(k<0){
			add(i-1,-cnt[i]);
			ans-=cnt[i];
		}
		else{
			add(i-1,-s);
			ans-=s;
		}
	}
	printf("%lld",ans);
	return 0;
}


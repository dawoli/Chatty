#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e5+5;
ll n,ans;
multiset<ll> s,s2;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	ans=n;
	for(ll i=1;i<=n;i++){
		ll a;
		scanf("%lld",&a);
		s.insert(a);
		s2.insert(a);
	}
	for(ll a:s){
		auto it=s2.upper_bound(a);
		if(it!=s2.end()){
			ans--;
			s2.erase(it);
		}
	}
	printf("%lld",ans);
	return 0;
}

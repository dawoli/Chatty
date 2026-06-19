#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5+9;

ll n, r[N];

bool r_2(){
	for(ll i=1; i<=n; i++)
		if(r[i]>2) return 0;
	return 1;
}
ll cnt2[3];
void solve2(){
	for(ll i=1; i<=n; i++)
		cnt2[r[i]]++;
	ll qs = min(cnt2[1], cnt2[2]);
	cout<<n-qs;
}

ll cnt[N], mxr=0;

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	cin>>n;
	for(ll i=1; i<=n; i++) cin>>r[i];
	for(ll i=1; i<=n; i++) mxr = max(mxr, r[i]);
	
	if(r_2()){
		solve2();
		return 0;
	}
	
	for(ll i=1; i<=n; i++) cnt[r[i]]++;
	
	ll ans = n;
	for(ll i=mxr,tt=0; i>=1; i--){
		ll qs = min(tt, cnt[i]); ans-=qs;
		tt-=qs;
		tt+=cnt[i]; 
	}
	
	cout<<ans;
	
	return 0;
}
